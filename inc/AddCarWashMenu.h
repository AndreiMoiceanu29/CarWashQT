#ifndef H_ADD_CARWASH_MENU
#define H_ADD_CARWASH_MENU
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QLineEdit>
#include "CarWash.h"
#include <vector>
#include <string>
#include <QCloseEvent>
class AddCarWashMenu: public QWidget
{
	Q_OBJECT

	QVBoxLayout *mainLayout;

	QLabel *header;

	QWidget *form;
	QFormLayout *formLayout;

	QLabel *carWashNameLbl;
	QLineEdit *carWashNameTxt;

	QLabel *carWashOwnerLbl;
	QLineEdit *carWashOwnerTxt;


	QLabel *carWashIdLbl;
	QLineEdit *carWashIdTxt;

	QPushButton *submitBtn;

	bool isUpdating;
	CarWash oldCarWash;


public:
	AddCarWashMenu();
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void setIsUpdating(bool);
	void setOldCarWash(CarWash&);
	void displayErrors(std::vector<std::string>);
	void clearInputs();
	void closeEvent(QCloseEvent*);
	~AddCarWashMenu();
signals:
	void requestUpdate(CarWash &oldCarWash, CarWash& newCarWash);
	void requestAddCarWash(CarWash &carWash);
public slots:
	void sendCarWashData();
	
	
};



#endif