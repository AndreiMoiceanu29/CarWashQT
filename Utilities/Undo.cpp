#include "Undo.h"
#include "Service.h"
#include "Car.h"
#include <QDebug>
AddCarUndo::AddCarUndo(Service& service, Car car) : service{service}, car{car}{}

void AddCarUndo::doUndo(){
	this->service.deleteCar(car.getId());
}
void AddCarUndo::doRedo(){
    this->service.createCar(QVariant::fromValue(&this->car));
}

AddCarUndo::~AddCarUndo(){}

DeleteCarUndo::DeleteCarUndo(Service& service, Car car) : service{service}, car{car}{}
void DeleteCarUndo::doUndo(){

    this->service.createCar(QVariant::fromValue(&this->car));

}
void DeleteCarUndo::doRedo(){
	this->service.deleteCar(this->car.getId());
}

DeleteCarUndo::~DeleteCarUndo(){}

UpdateCarUndo::UpdateCarUndo(Service& service, Car oldCar, Car newCar) : service{service}, oldCar{oldCar}, newCar{newCar}{}

void UpdateCarUndo::doUndo(){
    this->service.updateCar(QVariant::fromValue(&newCar),QVariant::fromValue(&oldCar));
}
void UpdateCarUndo::doRedo(){
    this->service.updateCar(QVariant::fromValue(&oldCar),QVariant::fromValue(&newCar));
}

UpdateCarUndo::~UpdateCarUndo(){}
