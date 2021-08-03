#ifndef H_SORT_H
#define H_SORT_H
#include "Car.h"
#include <vector>
namespace sort_utils{
	bool compareCarsByName(Car a, Car b,bool isDesc);

	bool compareCarsByOwner(Car a, Car b, bool isDesc);

	bool compareCarsByPlate(Car a, Car b, bool isDesc);

	template <typename T>
	std::vector<T> sort(bool(*compFunc)(T ,T ,bool), std::vector<T> entities, bool isDesc){
		for(int i=0; i<entities.size() - 1;i++){
			for(int j=0;j<entities.size() -i - 1;j++){
				if(compFunc(entities[j],entities[j+1],isDesc)){
					T aux = entities[j];
					entities[j] = entities[j+1];
					entities[j+1] = aux;
				}
			}
		}
		return entities;
	}
}

namespace filter_utils{
	std::vector<Car> filter(std::vector<Car> cars, std::string filter,bool (*matchFun)(Car,std::string));

	bool matchCarsByName(Car car, std::string filter);
	bool matchCarsByOwner(Car car, std::string filter);

	bool matchCarsByPlateNumber(Car car, std::string filter);
	bool isInArray(Car car, std::vector<Car>);
	std::vector<Car> combineFilteredCars(std::vector<Car>,std::vector<Car>,std::vector<Car>);
	std::string toLower(std::string);
}
#endif