#include <QtGui>
#include <math.h>
#include <iostream>

class render : public QFrame
{
	Q_OBJECT
	int chbpos;
	char* text;
	int flag;
	int a;
	QPointF mass[5200];

  public:
   render(QWidget *parent=0) : QFrame(parent),chbpos(0),text("1000/(x[0]^2)"),flag(0),a(30) {}
   void paintEvent(QPaintEvent*);
   //void takemas(double []);

signals:
   void emitstr(QString);

  public slots:
	  void calc(QString);
	  void scale(int);
	  void chk(int);

}; 

//#endif // GCPLOT_ALPHA