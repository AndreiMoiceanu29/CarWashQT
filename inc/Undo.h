//#include "Service.h"
#ifndef H_UNDO
#define H_UNDO
#include "Car.h"
class Service;
class Undo
{
public:
	virtual void doUndo() = 0;
	virtual void doRedo() = 0;
	virtual ~Undo(){}
	
};

class AddCarUndo: public Undo
{
	Service& service;
	Car car;

public:
	AddCarUndo(Service&, Car);
	void doUndo();
	void doRedo();
	~AddCarUndo();
	
};

class DeleteCarUndo: public Undo
{
	Service& service;
	Car car;
public:
	DeleteCarUndo(Service&,Car);
	void doUndo();
	void doRedo();
	~DeleteCarUndo();

};

class UpdateCarUndo: public Undo
{
	Service& service;
	Car oldCar;
	Car newCar;
public:
	UpdateCarUndo(Service&, Car, Car);
	void doUndo();
	void doRedo();
	~UpdateCarUndo();
};
#endif