#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QCloseEvent>
class MakeReservationMenu: public QWidget
{
	Q_OBJECT

	QWidget *mainWindow;
	QVBoxLayout *mainLayout;

	QLabel *carIdLbl;
	QLineEdit *carIdTxt;

	QLabel *carWashIdLbl;
	QLineEdit *carWashIdTxt;

	QFormLayout *formLayout;
	QWidget *form;

	QPushButton *submitBtn;
public:
	MakeReservationMenu();
	void initializeComponents();
	void initializeSignals();
	void renderGUI();
	void clearInputs();
	void closeEvent(QCloseEvent*);
	~MakeReservationMenu();
	
signals:
	void requestMakeAReservation(int carId, int carWashId);
	void closeSignal();
};
