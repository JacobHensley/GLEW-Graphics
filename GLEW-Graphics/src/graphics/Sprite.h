#pragma once

#include "RefCounted.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Sprite : RefCounted 
{
private:
	friend class Renderer2D;
private:
	static VertexBuffer* m_VertexBuffer;
	static IndexBuffer* m_IndexBuffer;
	static Shader* m_Shader;
private:
	vec4 m_Color;
	const Texture* m_Texture;
public:
	Sprite();
	Sprite(const vec4& color);
	Sprite(const Texture* texture);
	
	inline const vec4& GetColor() const { return m_Color; }
	inline const Texture* GetTexture() const { return m_Texture; }
private:
	void Init();
public:
	static void Shutdown();
};