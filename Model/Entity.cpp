#include "Entity.h"

Entity::Entity(){}

int Entity::getId(){ return this->entityId; }
void Entity::setId(int entityId){ 
	
    this->entityId = entityId;
}


Entity::~Entity(){}
