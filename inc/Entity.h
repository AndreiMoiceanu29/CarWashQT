
#ifndef H_ENTITY
#define H_ENTITY
#include<QObject>
class Entity: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int entityId READ getId WRITE setId);
protected:
    int entityId;
public:
	Entity();
	int getId();
	//Seteaza un id. Acesta trebuie sa fie pozitiv. Pentru id < 0 => id = 0
	void setId(int);
	~Entity();
	
};
#endif
