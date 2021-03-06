#pragma once
#include "GaPCH.h"
#include "utils/RefCounted.h"
#include "component/Component.h"
#include "utils/TimeStep.h"

class Component;
typedef Ref<Component> ComponentRef;

class Level;
typedef Ref<Level> LevelRef;

class Entity : public RefCounted
{
protected:
	LevelRef m_Level;
public:
	Entity();
	virtual ~Entity();

	void AddComponent(Component* component);

	virtual void OnInit(Level* level);
	virtual void OnUpdate(TimeStep timeStep);

	template<typename T>
	T* GetComponent();

	LevelRef GetLevel() const;
};

typedef Ref<Entity> EntityRef;