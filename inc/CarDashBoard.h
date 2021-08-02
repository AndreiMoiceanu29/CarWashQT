#ifndef H_CAR_DASHBOARD
#define H_CAR_DASHBOARD
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QCloseEvent>
#include "Car.h"
#include "AddCarMenu.h"
#include "CarWashDashBoard.h"
#include "MakeReservationMenu.h"
#include "Service.h"
#include "IPublisher.h"
class MainGUI;
class CarDashBoard: public QWidget, public IPublisher
{
	Q_OBJECT
	QWidget *mainWin;
	QWidget *btnGroup;

	QLabel *headerLbl;

	QListWidget *carsList;

	QVBoxLayout *mainLayout;
	QHBoxLayout *btnsLayout;

	QPushButton *addCarBtn;
	QPushButton *updateCarBtn;
	QPushButton *deleteCarBtn;
	QPushButton *undoChangeBtn;
	QPushButton *redoChangeBtn;
	QPushButton *makeReservationBtn;
	QPushButton *openCarWashDashboard;
	Service* service;
	std::list<IObserver *> observers;

public:
	CarDashBoard();
	CarDashBoard(Service*);
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void reloadList(std::vector<Car>);
	void closeEvent(QCloseEvent*);
	void attach(IObserver *);
	void dettach(IObserver *);
	void notify();

	~CarDashBoard();
signals:
	void requestDeleteCar(int id);
	void requestDeleteCarWash(int id);
	void requestAddCar(Car&);
	void requestAddCarWash(CarWash& );
	void requestUpdateCar(Car&, Car&);
	void requestUpdateCarWash(CarWash&, CarWash&);
	void requestMakeAReservation(int, int);
	void requestNotify();
public slots:
	void handleAddCar();
	void handleUpdateCar();
	void handleDeleteCar();
	void handleOpenCarDashBoard();
	void handleMakeReservation();
};

#endif