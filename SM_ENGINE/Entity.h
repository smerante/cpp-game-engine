#pragma once
#include <SDL.h>
#include <type_traits>
#include <vector>

class Entity
{
private:
	uint32_t _componentMask;
	static std::vector<Entity> _entityList;
	Entity();
	Entity(size_t _ID);
	size_t _ID;
public:
	static std::vector<Entity>& getEntityList();
	static Entity& create();
	
	size_t getID();
	~Entity();

	uint32_t getComponentMask();


	template<typename C>
	C& addComponent()
	{
		static_assert(std::is_base_of< Component< C >, C >::value,
			"ERROR: Can only add Component Types to Entities!"
			);
		_componentMask = _componentMask | C::getMask();
		return getComponent<C>();
	}

	template<typename C>
	C& getComponent()
	{
		static_assert(std::is_base_of< Component< C >, C >::value,
			"ERROR: Can only get Component Types from Entities!"
			); 
		return C::getComponentWithEntityID(_ID);
	}
	template<typename C>
	void removeComponenent()
	{

	}

	
};

