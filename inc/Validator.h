#ifndef H_VALIDATOR
#define H_VALIDATOR
#include "Car.h"
#include <vector>
#include <string>
#include <QObject>
#include <QStringList>
#include "CarWash.h"
class Validator: public QObject
{
    Q_OBJECT
private:
	bool hasSpecifiedLength(std::string,unsigned int,unsigned int);
	bool hasNoSpecialCharacters(std::string);
    void validPlateNumber(std::string,QStringList&);
public:
	Validator();
    Validator& operator=(const Validator&);
	void validateCar(Car&, std::vector<Car>,bool);
	void validateCarWash(CarWash&, std::vector<CarWash>,bool);
	void validateIdForCar(int, std::vector<Car>);
	void validateIdForCarWash(int, std::vector<CarWash>);

	
	
};
#endif
