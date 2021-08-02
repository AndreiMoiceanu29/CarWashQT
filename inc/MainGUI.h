#ifndef H_MAIN_GUI
#define H_MAIN_GUI
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QRadioButton>
#include "Service.h"
#include "RepoFactory.h"
#include "FactorySettings.h"
#include "IRepository.h"
#include "Validator.h"
#include "ChooseFileView.h"
#include "CarDashBoard.h"
#include <vector>
#include <QCloseEvent>
class MainGUI: public QWidget
{
	Q_OBJECT

	Service *service;

	FactorySettings settingsCar;
	FactorySettings settingsCarWash;

	RepoFactory<Car*> *carFactory;
	RepoFactory<CarWash*> *carWashFactory;

	IRepository<Car*> *carRepo;
	IRepository<CarWash*> *carWashRepo;

	Validator dataValidator;


	QWidget *form;
	

	QVBoxLayout *mainLayout;
	QFormLayout *formLayout;

	QLabel *headerLbl;
	QLabel *memoryLbl;
	QLabel *fileLbl;

	QRadioButton *memoryBtn;
	QRadioButton *fileBtn;

	QPushButton *runBtn;

	ChooseFileView* fileView;


public:
	MainGUI();
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void initializeRepo();
	void closeEvent(QCloseEvent*);
	~MainGUI();
signals:
	void repoUpdated(std::vector<Car>);


	
};
#endif