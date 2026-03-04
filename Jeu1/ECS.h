#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentTypeID = std::size_t;
constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;



/// <summary> Returns a new ComponentTypeID </summary>
inline ComponentTypeID getNewComponentTypeID()
{
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

/// <summary> Returns the unique CompontID of the specified Component </summary>
template <typename T> inline ComponentTypeID getComponentTypeID() noexcept
{
	static ComponentTypeID typeID = getNewComponentTypeID();
	return typeID;
}

class Component
{
public:
	Entity* entity; // Points to the Entity that owns this Component

	virtual void init() {}
	virtual void update() {}
	virtual void render(){}

	virtual ~Component() {}
};

class Entity {
private:
	std::string name;
	bool active;
	/*
		Not sure why we need this vector in addition to the ComponentArray below
		I think "components" has the ownership of the components and "componentArray" is used for quick access
	*/
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	Entity(std::string entityName)
		:name(entityName), active(true), components{}, componentArray{}, componentBitSet{}
	{

	}

	void update()
	{
		for (auto& c : components) c->update();
	}

	void render()
	{
		for (auto& c : components) c->render();
	}

	bool isActive() const { return active; }

	const std::string& getName() const { return name; }
	
	/// <summary> Resets "active" so that the Manager calls the destructor </summary>
	void destroy() { active = false; }

	template <typename T>
	bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}

	/// <summary> Creates and add a new Component of type T to the Entity </summary>
	/// <typeparam name="T"> Type of the Component </typeparam>
	/// <typeparam name="...TArgs"> Types of the arguments of T constructor </typeparam>
	/// <param name="...mArgs"> Arguments of T constructor </param>
	/// <returns> Reference to the new Component</returns>
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		ComponentTypeID id = getComponentTypeID<T>();

		std::unique_ptr<Component> comp = std::make_unique<T>(std::forward<TArgs>(mArgs)...);
		comp->entity = this;
		comp->init();


		componentArray[id] = comp.get();
		components.emplace_back(std::move(comp));
		componentBitSet[id] = true;

		return *static_cast<T*>(componentArray[id]);
	}

	template <typename T>
	T& getComponent() const
	{
		auto comp = componentArray[getComponentTypeID<T>()];
		return *static_cast<T*>(comp);
	}
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

public:
	void update()
	{
		for (auto& e : entities) e->update();
	}

	void render()
	{
		for (auto& e : entities) e->render();
	}

	/// <summary> Destroys all the unactive entities </summary>
	void refresh()
	{
		// Puts the elements to keep at the beginning of the vector and returns an iterator to the first element to erase
		auto it = std::remove_if(std::begin(entities), std::end(entities), 
			[](const std::unique_ptr<Entity>& mEntity) { return !mEntity->isActive(); }
			);
		entities.erase(it, std::end(entities)); // actual erasement
	}

	Entity& addEntity(std::string entityName)
	{
		std::unique_ptr<Entity> newEntity = std::make_unique<Entity>(entityName);
		entities.emplace_back(std::move(newEntity));

		return *entities.back();
	}
};
