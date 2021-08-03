#ifndef H_SERVICE
#define H_SERVICE

#include "CarWash.h"
#include "Car.h"
#include "MemoryRepository.h"
#include "Validator.h"
#include <QObject>
#include <QQmlEngine>
#include <QVariant>
#include <QVector>
#include <QVariantList>
Q_DECLARE_METATYPE(Car)
Q_DECLARE_METATYPE(CarWash)
class Service: public QObject
{

    Q_OBJECT
    Q_DISABLE_COPY(Service)
    Q_PROPERTY(QList<QObject*> cars READ cars NOTIFY loadCars)
    Q_PROPERTY(QList<QObject*> carWashes READ carWashes NOTIFY loadCarWashes)
	IRepository<Car*>* carRepo;
	IRepository<CarWash*>* carWashRepo;
	Validator dataValidator;
    static Service* instance;
public:
    ~Service();
    static Service* GetInstance();
    static QObject* qmlInstance(QQmlEngine *engine, QJSEngine* scriptEngine){
        Q_UNUSED(engine);
        Q_UNUSED(scriptEngine);
        return new Service;
    }
private:
	Service();
	Service(IRepository<Car*>*, IRepository<CarWash*>*);
	Service(Validator, IRepository<Car*>*, IRepository<CarWash*>*);
    void connectSignals();


public slots:
    void createCar(QVariant carV);
	Car readCar(int id);
    Car updateCar(QVariant oldCarV, QVariant newCarV);
	Car deleteCar(int id);

    void createCarWash(QVariant);
	CarWash readCarWash(int id);
    CarWash updateCarWash(QVariant odlCarWashV, QVariant newCarWashV);
	CarWash deleteCarWash(int id);

	void makeReservation(int carId, int carWashId);

    QList<QObject*> cars();
    QList<QObject*> carWashes();
	
    std::vector<CarWash> getAllCarWashes();
    std::vector<Car> getAllCars();




signals:
    void loadCars();
    void loadCarWashes();


};

#endif
