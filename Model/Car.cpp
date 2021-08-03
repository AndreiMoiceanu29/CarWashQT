#include "Car.h"
#include "Entity.h"
#include <string>
Car::Car(){}
Car::Car(QString carName, QString carOwner,QString plateNum, int carId){
	this->name = carName;
	this->owner = carOwner;
	this->plateNumber = plateNum;
    setId(carId);

}

Car::Car(const Car& obj){
    this->name = obj.name;
    this->owner = obj.owner;
    this->plateNumber = obj.plateNumber;
    this->setId(obj.entityId);
}

Car& Car::operator=(const Car& obj){
    this->name = obj.name;
    this->owner = obj.owner;
    this->plateNumber = obj.plateNumber;
    this->entityId = obj.entityId;
    return *this;
}

QString Car::getName(){ return this->name; }
void Car::setName(QString carName){ this->name = carName;}

QString Car::getOwner(){ return this->owner;}
void Car::setOwner(QString carOwner){ this->owner = carOwner;}

QString Car::getPlateNumber(){ return this->plateNumber;}
void Car::setPlateNumber(QString plateNum){ this->plateNumber = plateNum;}

void Car::attach(IObserver *obs){
	this->observers.push_back(obs);
}
void Car::dettach(IObserver *obs){
	this->observers.remove(obs);
}

void Car::notify(){
	std::list<IObserver *>::iterator it = this->observers.begin();
	while(it != observers.end()){
        (*it)->update(this->entityId);
		++it;
	}
}



Car::~Car(){
	
}
