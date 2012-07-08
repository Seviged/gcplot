#include <QtGui>
#include "stdio.h"
int a=10;
class MyWidget : public QWidget
{
  public:
   MyWidget(QWidget * parent=0) : QWidget(parent) {}
  
   void  paintEvent(QPaintEvent*) {
     QPainter painter(this);
	 painter.setRenderHint(QPainter::Antialiasing, true);
	 painter.setBrush(QColor(255, 255, 255));
	 painter.setPen(QPen(QColor(130,135,144),1));
	 painter.drawRect(0,0, 650, 460);
	 painter.setPen(QPen(QColor(0,0,0),1/a));
	 painter.setWindow(-325/a,-230/a, 650/a, 460/a);
	 painter.drawLine(QPointF(-325/a,0),QPointF(650/a,0));
	 painter.drawLine(QPointF(0,-230/a),QPointF(0,460/a));
	  float i=0,y,x=-(((100*a)/2)*0.1),x1,y1;
	  while (i<100*a)
	  {
		  y=(x*x);
		  y=-y;
		  painter.setPen(QPen(QColor(0,0,0),1/a));
		  painter.setRenderHint(QPainter::Antialiasing, true);
		  if (x!=-(((100*a)/2)*0.1))
		  {
				painter.drawLine(QPointF(x,y),QPointF(x1,y1));
		  }
		  	x1=x;
			y1=y;
		  x+=0.1;
		  i++;
	  }
   } 
}; 
 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QWidget window;
	 QSpinBox *spinbox = new QSpinBox(&window);
     QLabel *label = new QLabel(QApplication::translate("windowlayout", "Name:"));
	 QWidget *line = new QWidget(&window);
	 QLineEdit *lineEdit2 = new QLineEdit();
	 MyWidget widget(&window);
	 spinbox->setValue(a);
     QPainter painter;
	 QScrollArea *scrollLeft = new QScrollArea(&window);
	 QScrollArea *scrollRight = new QScrollArea(&window);
	 QPushButton *button = new QPushButton(
     QApplication::translate("childwidget", "Press me"), &window);
	 QLineEdit *lineEdit = new QLineEdit(
	 QApplication::translate("childwidget", "Enter formule"), &window);
	 lineEdit->setGeometry(175,480, 650, 40);
	 scrollLeft->setGeometry(10,10, 155, 580);
	 widget.setGeometry(175,10, 650, 460);
	 //QObject::connect(spinbox, SIGNAL(valueChanged(int)), widget, SLOT(update()));
	 spinbox->setGeometry(835,10,155,20);
	 spinbox->setRange(1, 100);//rechange
	 a = spinbox->value();
	 scrollRight->setGeometry(835,110, 155, 480);
	 line->setGeometry(175,10, 650, 460);
	 button->setGeometry(175,530, 650, 40);
     window.setWindowTitle(
     QApplication::translate("windowlayout", "Window layout"));
	 window.setFixedSize(1000, 600);
	 window.show();
     return app.exec();
 }