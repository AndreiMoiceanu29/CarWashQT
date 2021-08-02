#include "Service.h"
#include <vector>
#include <iostream>
#include <list>
Service::Service(){}

Service::Service(Validator dataVal, IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carRepo = carRepository;
	this->carWashRepo = carWashRepository;
	this->dataValidator = dataVal;
}

Service::Service(IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carWashRepo = carWashRepository;
	this->carRepo = carRepository;
}

void Service::createCar(Car car){
	this->dataValidator.validateCar(car,this->getAllCars(),false);
	Car* myCar = new Car(car.getName(),car.getOwner(),car.getPlateNumber(),car.getId());
	this->carRepo->addEntity(myCar);
}

Car Service::readCar(int id){
	this->dataValidator.validateIdForCar(id,this->getAllCars());
	Car car = *this->carRepo->getEntity(id);

	return car;
}

Car Service::updateCar(Car oldCar, Car newCar){
	Car *carPtr = this->carRepo->getEntity(oldCar.getId());
	this->dataValidator.validateCar(newCar,this->getAllCars(),true);
	carPtr->setName(oldCar.getName());
	carPtr->setOwner(oldCar.getOwner());
	carPtr->setPlateNumber(oldCar.getPlateNumber());
	Car *updatedCarPtr = this->carRepo->updateEntity(carPtr, carPtr);
	Car updatedCar = *updatedCarPtr;
	return updatedCar;
}

Car Service::deleteCar(int id){
	this->dataValidator.validateIdForCar(id, this->getAllCars());
	Car* deletedCarPtr = this->carRepo->deleteEntity(id);
	Car deletedCar = *deletedCarPtr;
	deletedCarPtr->notify();
	delete deletedCarPtr;

	return deletedCar;
}

void Service::createCarWash(CarWash carWash){
	CarWash* carWashPtr = new CarWash(carWash);
	this->dataValidator.validateCarWash(carWash,this->getAllCarWashes(),false);
	this->carWashRepo->addEntity(carWashPtr);
}

CarWash Service::readCarWash(int id){
	this->dataValidator.validateIdForCarWash(id, this->getAllCarWashes());
	CarWash carWash = *this->carWashRepo->getEntity(id);

	return carWash;
}

CarWash Service::updateCarWash(CarWash oldCarWash, CarWash newCarWash){
	CarWash* carWash = this->carWashRepo->getEntity(oldCarWash.getId());
	
	this->dataValidator.validateCarWash(newCarWash,this->getAllCarWashes(),true);
	carWash->setName(newCarWash.getName());
	carWash->setOwner(newCarWash.getOwner());
	
	CarWash *updatedCarWashPtr = this->carWashRepo->updateEntity(carWash, carWash);
	CarWash updatedCarWash = *updatedCarWashPtr;


	return updatedCarWash;
}


CarWash Service::deleteCarWash(int id){
	this->dataValidator.validateIdForCarWash(id,this->getAllCarWashes());
	CarWash* deletedCarWashPtr = this->carWashRepo->deleteEntity(id);
	CarWash deletedCarWash = *deletedCarWashPtr;
	std::vector<int> carIds = deletedCarWash.getCarIds();
	for(auto carId: carIds){
		Car *car = this->carRepo->getEntity(carId);
		Car *newCar = new Car(*car);
		newCar->dettach(deletedCarWashPtr);
		car = this->carRepo->updateEntity(car,newCar);
		delete car;
	}

	delete deletedCarWashPtr;
	return deletedCarWash;
}

void Service::makeReservation(int carId, int carWashId){
	this->dataValidator.validateIdForCar(carId,this->getAllCars());
	this->dataValidator.validateIdForCarWash(carWashId,this->getAllCarWashes());

	// ADD CAR TO CARWASH
	CarWash* oldWash = this->carWashRepo->getEntity(carWashId);
	CarWash* newWash = new CarWash(*oldWash);

	std::vector<int> carIds = this->carWashRepo->getEntity(carWashId)->getCarIds();
	carIds.push_back(carId);
	newWash->setCarIds(carIds);
	oldWash = this->carWashRepo->updateEntity(oldWash, newWash);
	delete oldWash;

	// ADD CAR OBSERVABLE
	Car* oldCar = this->carRepo->getEntity(carId);
	Car* newCar = new Car(*oldCar);


	for(auto carwash: this->carWashRepo->getAllEntities()){
		if(carwash->getId() == carWashId){
			newCar->attach(carwash);
		}
	}

	oldCar = this->carRepo->updateEntity(oldCar, newCar);
	delete oldCar;
}

std::vector<CarWash> Service::getAllCarWashes(){
	std::vector<CarWash> carWashes;
	std::list<CarWash*> entities = this->carWashRepo->getAllEntities();
	for(auto entity: entities){
		carWashes.push_back(*entity);
	}
	return carWashes;
}

std::vector<Car> Service::getAllCars(){
	std::vector<Car> cars;
	std::list<Car*> entities = this->carRepo->getAllEntities();
	for(auto entity: entities){
		cars.push_back(*entity);
	}
	return cars;
}

Service::~Service(){
	delete carRepo;
	delete carWashRepo;
}