#pragma once
#include "GaPCH.h"
#include "utils/Common.h"
#include "utils/FileUtils.h"
#include "math/math.h" 
#include "utils/Resource.h"
#include "graphics/shaders/ShaderUniform.h"

struct ShaderSource;

class Shader
{
public:
	Shader(const String& filePath);
	~Shader();

	void ParseUniforms();
	void PushUniform(ShaderUniform* uniform);
	void PrintUniforms();

	void Bind();
	void Unbind();

	void SetTextureIDs(const String& name);

	int GetUniformLocation(const String& name);

	inline std::vector<ShaderUniform*>& GetUniforms() { return m_Uniforms; };

	void SetUniform1i(const String& name, int value);
	void SetUniform1iv(const String& name, int* value, int count);
	void SetUniform1f(const String& name, float value);
	void SetUniform2f(const String& name, const vec2& vec);
	void SetUniform3f(const String& name, const vec3& vec);
	void SetUniformVec4(const String& name, const vec4& vec);

	void SetUniform4f(const String& name, float x, float y, float z, float w);
	void SetUniformMat4(const String& name, const mat4& matrix);

	inline uint GetID() const { return m_ShaderID; }
	static inline Resource::ResourceType GetType() { return Resource::ResourceType::SHADER; }
private:
	uint m_ShaderID;
	String m_FilePath;
	ShaderSource ParseShader(const String& filePath);
	int CompileShader(uint shader, const String& shaderSrc);
	uint Load();
	std::vector<ShaderUniform*> m_Uniforms;
	std::unordered_map<String, int> m_UniformLocationCache;
};