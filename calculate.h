#ifndef _calculate_h_
#define _calculate_h_

#include <QtGui>

class Scalc : public QObject {
Q_OBJECT
	int chbpos;
public:
    Scalc(QObject *parent=0) : QObject(parent), chbpos(0){};

public slots:
	//void chbslot(int);
	void takechar(QString);
	//void takechar(char*);

};
#endif  //_calculate_h_
