#pragma once
#include "GaPCH.h"
#include "utils/Common.h"

class Texture;
class Shader;

class Resource {
public:
	enum class ResourceType { NONE = 0, SHADER = 1, TEXTURE = 2 };
private:
	struct ResourceStore 
	{
		ResourceType type;
		void* pointer;
	};

	Resource() {}
public:
	static Texture* LoadTexture(const String& name, const String& path);
	static Shader* LoadShader(const String& name, const String& filePath);

	static void* Get(const String& name);

	template<typename T>
	static T* GetAs(const String& name) 
	{
		ResourceStore resource = s_ResourceMap[name];
		if (resource.type != T::GetType())
			return nullptr;
			
		return (T*)resource.pointer;
	}

	template<typename T>
	static T* Load(const String& name) 
	{
		T* resource = new T(path.c_str());
		s_ResourceMap[name] = { T::GetType(), resource };
		return resource;
	}

	typedef std::unordered_map<String, ResourceStore> ResourceMap;
private:
	static ResourceMap s_ResourceMap;
public:
	static inline ResourceMap& GetResourceMap() { return s_ResourceMap; }
};