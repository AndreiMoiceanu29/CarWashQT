#include "CarWash.h"
#include <vector>
#include <string>
CarWash::CarWash(){}
CarWash::CarWash(QString carWashName, QString carWashOwner, int carWashId){
	this->name = carWashName;
	this->owner = carWashOwner;
    this->entityId = carWashId;
}

CarWash::CarWash(const CarWash& obj){
    this->name = obj.name;
    this->owner = obj.owner;
    this->entityId = obj.entityId;
    this->carIds = obj.carIds;
}

CarWash& CarWash::operator=(const CarWash &obj){
    this->name = obj.name;
    this->owner = obj.owner;
    this->entityId = obj.entityId;
    this->carIds = obj.carIds;
}

QString CarWash::getName(){ return this->name; }
void CarWash::setName(QString carWashName){ this->name = carWashName; }

QString CarWash::getOwner(){ return this->owner; }
void CarWash::setOwner(QString carWashOwner){ this->owner = carWashOwner; }



std::vector<int> CarWash::getCarIds(){ return this->carIds; }
void CarWash::setCarIds(std::vector<int> carIdsList){ this->carIds = carIdsList; }

void CarWash::update(int carId){
	for(unsigned int i=0;i<this->carIds.size();i++){
		if(carIds[i] == carId){
			carIds.erase(carIds.begin() + i);
			break;
		}
	}
}

CarWash::~CarWash(){}
