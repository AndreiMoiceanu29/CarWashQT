#ifndef H_CHOOSE_FILE
#define H_CHOOSE_FILE
#include <QLineEdit>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QRadioButton>
#include <string>
#include <QCloseEvent>
class ChooseFileView: public QWidget
{
	Q_OBJECT
	QWidget *form;

	QVBoxLayout *mainLayout;
    QFormLayout *layoutForm;

    QLineEdit   *carDbNameTxt;
    QLineEdit   *carWashDbNameTxt;

    QPushButton *okBtn;

public:
	ChooseFileView();
	void initializeComponents();
	void renderGUI();
	void initializeSignals();
	void closeEvent(QCloseEvent*);
	~ChooseFileView();
signals:
     void settingsProvided(std::string carDb, std::string carWashDb);
	
};

#endif