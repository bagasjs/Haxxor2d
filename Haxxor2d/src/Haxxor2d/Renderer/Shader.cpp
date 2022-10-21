#include "Core.h"
#include "Shader.h"

#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

namespace hb2d
{
	Shader::Shader(const std::string& filepath)
		: m_FilePath(filepath), m_RendererID(0)
	{
		ShaderProgramSource source = ParseShader(filepath);
		m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
	}

	Shader::~Shader()
	{
		GL_CALL(glDeleteProgram(m_RendererID));
	}


	void Shader::Bind() const
	{
		GL_CALL(glUseProgram(m_RendererID));
	}

	void Shader::Unbind() const
	{
		GL_CALL(glUseProgram(0));
	}

	void Shader::SetUniform1i(const std::string& name, int value)
	{
		GL_CALL(glUniform1i(GetUniformLocation(name), value));
	}

	void Shader::SetUniform1f(const std::string& name, float value)
	{
		GL_CALL(glUniform1f(GetUniformLocation(name), value));
	}

	void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		GL_CALL(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		if(m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];

		GL_CALL(int location = glGetUniformLocation(m_RendererID, name.c_str()));
		if(location == -1)
			printf("Warning: uniform %s doesn't exist!\n", name.c_str());

		m_UniformLocationCache[name] = location;
		return location;
	}

	ShaderProgramSource Shader::ParseShader(const std::string& filepath)
	{
		std::ifstream stream(filepath);

		enum ShaderType
		{
			NONE = -1,
			VERTEX = 0,
			FRAGMENT = 1
		};

		std::string line;
		std::stringstream ss[2];
		ShaderType type = ShaderType::NONE;

		while(std::getline(stream, line))
		{
			if(line.find("#shader") != std::string::npos)
			{
				if(line.find("vertex") != std::string::npos)
					type = ShaderType::VERTEX;
				else if(line.find("fragment") != std::string::npos)
					type = ShaderType::FRAGMENT;
			}
			else
			{
				ss[(int) type] << line << "\n";
			}
		}

		return { ss[0].str(), ss[1].str() };
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
	{
		GL_CALL(unsigned int id = glCreateShader(type));
		const char* src = source.c_str();
		GL_CALL(glShaderSource(id, 1, &src, nullptr));
		GL_CALL(glCompileShader(id));

		int result;
		GL_CALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

		if(result == GL_FALSE)
		{
			int length;
			GL_CALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
			char* message = (char*) alloca(length * sizeof(char));
			GL_CALL(glGetShaderInfoLog(id, length, &length, message));
			// spdlog::error("Failed to compile shader {} ", (type == GL_VERTEX_SHADER) ? "vertex" : "fragment");
			GL_CALL(glDeleteShader(id));
			return 0;
		}

		return id;
	}


	int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
	{
		GL_CALL(unsigned int program = glCreateProgram());
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

		GL_CALL(glAttachShader(program, vs));
		GL_CALL(glAttachShader(program, fs));
		GL_CALL(glLinkProgram(program));
		GL_CALL(glValidateProgram(program));

		GL_CALL(glDeleteShader(vs));
		GL_CALL(glDeleteShader(fs));

		return program;
	}	
}
