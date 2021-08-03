#include "sort.h"
#include <algorithm>
namespace sort_utils{
	bool compareCarsByName(Car a, Car b,bool isDesc = false){
	if(!isDesc)
		return (a.getName() > b.getName());
	else
		return (a.getName() < b.getName());
	}

	bool compareCarsByOwner(Car a, Car b, bool isDesc = false){
		if(!isDesc)
			return (a.getOwner() > b.getOwner());
		else
			return (a.getOwner() < b.getOwner());
	}

	bool compareCarsByPlate(Car a, Car b, bool isDesc = false){
		if(!isDesc)
			return (a.getPlateNumber() > b.getPlateNumber());
		else	
			return (a.getPlateNumber() < b.getPlateNumber());
	}

	
}

namespace filter_utils{
	std::vector<Car> filter(std::vector<Car> cars, std::string filter,bool (*matchFun)(Car,std::string)){
		std::vector<Car> filteredCars;
		for(auto car : cars){
			if(matchFun(car,filter)){
				filteredCars.push_back(car);
			}
		}
		return filteredCars;
	}

	bool matchCarsByName(Car car, std::string filter){
		if(filter == "")
			return true;
        return (toLower(car.getName().toStdString()).find(toLower(filter)) != std::string::npos);
	}

	bool matchCarsByOwner(Car car, std::string filter){
		if(filter == "")
			return true;
        return (toLower(car.getOwner().toStdString()).find(toLower(filter)) != std::string::npos);
	}

	bool matchCarsByPlateNumber(Car car, std::string filter){
		if(filter == "")
			return true;
        return (toLower(car.getPlateNumber().toStdString()).find(toLower(filter)) != std::string::npos);
	}
	bool isInArray(Car car, std::vector<Car> cars){
		for(auto carItem : cars){
			if(car.getId() == carItem.getId()){
				return true;
			}
		}
		return false;
	}
	std::vector<Car> combineFilteredCars(std::vector<Car> f1, std::vector<Car> f2, std::vector<Car> f3){
		std::vector<Car> combined;
		for(auto car : f1){
			if(isInArray(car,f2) && isInArray(car,f3)){
				combined.push_back(car);
			}
		}
		return combined;
	}
	std::string toLower(std::string my_str){
		transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);
		return my_str;
	}

}
