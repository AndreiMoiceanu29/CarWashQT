#ifndef H_CAR
#define H_CAR

#include <string>
#include <QObject>
#include <QString>
#include <list>
#include "IPublisher.h"
#include "Entity.h"
class Car: public Entity, public IPublisher
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName );
    Q_PROPERTY(QString owner READ getOwner WRITE setOwner);
    Q_PROPERTY(QString plateNumber READ getPlateNumber WRITE setPlateNumber);
    Q_PROPERTY(int entityId READ getId WRITE setId);
private:
    QString name;
    QString owner;
    QString plateNumber;
	std::list<IObserver *> observers;
	
public:
	Car();
    Car(const Car&);
    Car(QString,QString,QString,int);
    Car& operator=(const Car&);

    QString getName();
    void setName(QString);
    QString getOwner();
    void setOwner(QString);
    QString getPlateNumber();
    void setPlateNumber(QString);
	
	void attach(IObserver *);
	void dettach(IObserver *);
	void notify();

	~Car();

	
	
};



#endif
