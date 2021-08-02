#ifndef H_LOGIN_FORM
#define H_LOGIN_FORM
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QFormLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QLineEdit>
#include <QCloseEvent>
#include "MainGUI.h"
class LoginForm: public QWidget
{
	
	QVBoxLayout *mainLayout;

	QFormLayout *formLayout;
	QWidget *form;

	QLabel *usernameLbl;
	QLineEdit *usernameTxt;

	QLabel *passwordLbl;
	QLineEdit *passwordTxt;

	QPushButton *loginBtn;



public:
	LoginForm();
	void initializeComponents();
	void renderGUI();
	void initializeSignals();
	void closeEvent(QCloseEvent*);
	~LoginForm();
	
};
#endif