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
#include "Undo.h"
Q_DECLARE_METATYPE(Car)
Q_DECLARE_METATYPE(CarWash)
class Service: public QObject
{

    Q_OBJECT
    Q_DISABLE_COPY(Service)
    Q_PROPERTY(QVariant cars READ cars NOTIFY loadCars)
    Q_PROPERTY(QVariant carWashes READ carWashes NOTIFY loadCarWashes)
    Q_PROPERTY(QVariant filteredCars READ filteredCars NOTIFY carsFiltered);
	IRepository<Car*>* carRepo;
	IRepository<CarWash*>* carWashRepo;
    QList<QObject*> filteredCarsV;
	Validator dataValidator;
    static Service* instance;
    std::vector<Undo*> actions;
    std::vector<Undo*> redos;
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
    void sortByName(bool);
    void sortByOwner(bool);
    void sortByPlate(bool);

    QVariant cars();
    QVariant filteredCars();
    QVariant carWashes();
    void filter(QString f1, QString f2, QString f3);
    void setFileRepo(QString carPath, QString carWashPath);
    std::vector<CarWash> getAllCarWashes();
    std::vector<Car> getAllCars();


    void addUndoAction(Undo* action);

        void undo();
        void redo();
        void freeRedo();
        bool undoEmpty();
        bool redoEmpty();

signals:
    void loadCars();
    void loadCarWashes();
    void carsFiltered();
    void throwError(QString error);


};

#endif
