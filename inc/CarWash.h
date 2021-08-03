#ifndef H_CAR_WASH
#define H_CAR_WASH

#include <string>
#include <vector>
#include <QObject>
#include "Entity.h"
#include "IObserver.h"

class CarWash: public Entity, public IObserver
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName);
    Q_PROPERTY(QString owner READ getOwner WRITE setOwner);
    Q_PROPERTY(int entityId READ getId WRITE setId);
    Q_PROPERTY(std::vector<int> carIds READ getCarIds WRITE setCarIds);
private:
    QString name;
    QString owner;
	
	std::vector<int> carIds;
public:
	CarWash();
    CarWash(const CarWash&);
    CarWash(QString, QString, int);
    CarWash& operator=(const CarWash&);

    QString getName();
    void setName(QString);
    QString getOwner();
    void setOwner(QString);
	
	std::vector<int> getCarIds();
	void setCarIds(std::vector<int>);
	void update(int);
	~CarWash();

	
	
};

#endif
