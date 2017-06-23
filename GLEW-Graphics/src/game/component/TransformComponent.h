#pragma once
#include "Component.h"
#include "math/mat4.h"

class TransformComponent : public Component
{
public:
	mat4 Transform;

public:
	TransformComponent(const mat4& transform);

	static Component::Type* GetStaticType()
	{
		static Component::Type type = { "Transform" };
		return &type;
	}

	inline virtual const Component::Type* GetType() const override { return GetStaticType(); }

};