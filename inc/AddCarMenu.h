#ifndef H_ADD_CAR_MENU
#define H_ADD_CAR_MENU
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QLineEdit>
#include "Car.h"
#include <vector>
#include <string>
#include <QCloseEvent>

class AddCarMenu: public QWidget
{
	Q_OBJECT

	QVBoxLayout *mainLayout;

	QLabel *header;

	QWidget *form;
	QFormLayout *formLayout;

	QLabel *carNameLbl;
	QLineEdit *carNameTxt;

	QLabel *carOwnerLbl;
	QLineEdit *carOwnerTxt;

	QLabel *carPlateLbl;
	QLineEdit *carPlateTxt;

	QLabel *carIdLbl;
	QLineEdit *carIdTxt;

	QPushButton *submitBtn;

	bool isUpdating;
	Car oldCar;


public:
	AddCarMenu();
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void setIsUpdating(bool);
	void setOldCar(Car&);
	void displayErrors(std::vector<std::string>);
	void clearInputs();
	void closeEvent(QCloseEvent*);
	~AddCarMenu();
signals:
	void requestUpdate(Car &oldCar, Car& newCar);
	void requestAddCar(Car &car);
	
	
};



#endif