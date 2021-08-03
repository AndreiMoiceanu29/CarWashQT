#include "Service.h"
#include <vector>
#include <iostream>
#include <list>
#include <QDebug>
Service::Service(){
    this->carRepo = new MemoryRepository<Car*>();
    this->carWashRepo = new MemoryRepository<CarWash*>();
}

Service::Service(Validator dataVal, IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carRepo = carRepository;
	this->carWashRepo = carWashRepository;
	this->dataValidator = dataVal;
}

Service::Service(IRepository<Car*> *carRepository, IRepository<CarWash*> *carWashRepository){
	this->carWashRepo = carWashRepository;
	this->carRepo = carRepository;
}

Service* Service::GetInstance(){
    if(!instance){
        instance = new Service();

    }else{
        return instance;
    }
}

void Service::createCar(QVariant carV){
    Car* carPtr = carV.value<Car*>();
    Car car = *carPtr;
    if(carV.canConvert<Car*>()){
        qDebug() << "Can Convert";
    }
    qDebug() << car.getName();
	this->dataValidator.validateCar(car,this->getAllCars(),false);
	Car* myCar = new Car(car.getName(),car.getOwner(),car.getPlateNumber(),car.getId());
	this->carRepo->addEntity(myCar);
    qDebug() << "Added car";
    emit loadCars();
}

Car Service::readCar(int id){
	this->dataValidator.validateIdForCar(id,this->getAllCars());
	Car car = *this->carRepo->getEntity(id);

	return car;
}

Car Service::updateCar(QVariant oldCarV, QVariant newCarV){
    Car* oldCarPtr = oldCarV.value<Car*>();
    Car* newCarPtr = newCarV.value<Car*>();
    Car oldCar = *oldCarPtr;
    Car newCar = *newCarPtr;
	Car *carPtr = this->carRepo->getEntity(oldCar.getId());
	this->dataValidator.validateCar(newCar,this->getAllCars(),true);
	carPtr->setName(oldCar.getName());
	carPtr->setOwner(oldCar.getOwner());
	carPtr->setPlateNumber(oldCar.getPlateNumber());
	Car *updatedCarPtr = this->carRepo->updateEntity(carPtr, carPtr);
	Car updatedCar = *updatedCarPtr;
    emit loadCars();
	return updatedCar;
}

Car Service::deleteCar(int id){
	this->dataValidator.validateIdForCar(id, this->getAllCars());
	Car* deletedCarPtr = this->carRepo->deleteEntity(id);
	Car deletedCar = *deletedCarPtr;
	deletedCarPtr->notify();
	delete deletedCarPtr;
    emit loadCars();
	return deletedCar;
}

void Service::createCarWash(QVariant carWashV){

    CarWash* carWashPtr = carWashV.value<CarWash*>();
    CarWash carWash = *carWashPtr;
	this->dataValidator.validateCarWash(carWash,this->getAllCarWashes(),false);
	this->carWashRepo->addEntity(carWashPtr);
    emit loadCarWashes();
}

CarWash Service::readCarWash(int id){
	this->dataValidator.validateIdForCarWash(id, this->getAllCarWashes());
	CarWash carWash = *this->carWashRepo->getEntity(id);

	return carWash;
}

CarWash Service::updateCarWash(QVariant oldCarWashV, QVariant newCarWashV){

    CarWash *oldCarWashPtr = oldCarWashV.value<CarWash*>();
    CarWash* newCarWashPtr = newCarWashV.value<CarWash*>();
    CarWash oldCarWash = *oldCarWashPtr;
    CarWash newCarWash = *newCarWashPtr;
    CarWash* carWash = this->carWashRepo->getEntity(oldCarWash.getId());
	this->dataValidator.validateCarWash(newCarWash,this->getAllCarWashes(),true);
	carWash->setName(newCarWash.getName());
	carWash->setOwner(newCarWash.getOwner());
	
	CarWash *updatedCarWashPtr = this->carWashRepo->updateEntity(carWash, carWash);
	CarWash updatedCarWash = *updatedCarWashPtr;

    emit loadCarWashes();
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
    emit loadCarWashes();
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
    emit loadCarWashes();
}

std::vector<CarWash> Service::getAllCarWashes(){
	std::vector<CarWash> carWashes;
	std::list<CarWash*> entities = this->carWashRepo->getAllEntities();
	for(auto entity: entities){
		carWashes.push_back(*entity);
	}
	return carWashes;
}

QVariantList Service::cars(){
    QVariantList cars;
    std::vector<Car> allCars = getAllCars();
    for(auto  car: allCars){
        cars.append(QVariant::fromValue(car));
    }
    return cars;
}

QVariantList Service::carWashes(){
    QVariantList carWashes;
    std::vector<CarWash> allCarWashes = getAllCarWashes();
    for(auto carWash: allCarWashes){
        carWashes.append(QVariant::fromValue(carWash));
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
