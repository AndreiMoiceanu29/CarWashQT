#ifndef H_CARWASH_DASHBOARD
#define H_CARWASH_DASHBOARD
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QCloseEvent>
#include "CarWash.h"
#include "Service.h"
#include "AddCarWashMenu.h"
#include "IObserver.h"

class CarWashDashBoard: public QWidget, public IObserver
{
	Q_OBJECT
	Service* service;
	QWidget *mainWin;
	QWidget *btnGroup;

	QLabel *headerLbl;

	QListWidget *carWashesList;

	QVBoxLayout *mainLayout;
	QHBoxLayout *btnsLayout;

	QPushButton *addCarWashBtn;
	QPushButton *updateCarWashBtn;
	QPushButton *deleteCarWashBtn;
	QPushButton *undoChangeBtn;
	QPushButton *redoChangeBtn;


public:
	CarWashDashBoard();
	CarWashDashBoard(Service*);
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void reloadList(std::vector<CarWash>);
	void closeEvent(QCloseEvent*);
	void update(int);
	~CarWashDashBoard();
signals:
	void requestDettach();
	void requestNotify();

public slots:
	void updateCarWash();
	void deleteCarWash();
	void addCarWash();
};

#endif