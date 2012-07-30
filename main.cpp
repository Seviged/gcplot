//За Великий Ctrl Alt Delete! Аминь!
//Проверено и одобрено орденом программистов христианской церкви, демонов нет!
//Язык разработки: СИ Крест Крест
//GTK - лжерелигия, используйте святой QT.
//Разработано Зиничем Романом, Дмитрием Макаровым, Викторией Арсеньевой, в качестве проекта для практики первого курса в МИЭМ НИУ ВШЭ
//GCPlot - Graphical Calculation plotter
//Программа построения графиков на основе функции y=f(x)
//Версия 1.0_beta
//Реализовано 75% недокументированного технического задания.
//Наташа привееет)))

#include "render.h"
#include "StartDialog.h"
#include <QtGui>
#include <math.h>



 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QWidget window;
     QLabel *label = new QLabel(QApplication::translate("windowlayout", "Scale:"),&window);
	 QCheckBox *chb = new QCheckBox(QApplication::translate("windowlayout", "Calc mode"),&window);
	 mle *myline = new mle(&window);
	 render widget(&window);
     QPainter painter;
	 QSlider *spinbox = new QSlider(Qt::Horizontal,&window);
	 spinbox->setValue(30);
	 widget.setGeometry(10,10, 512, 512);
	 myline->setGeometry(10,532,512,20);
	 myline->setText("Enter expession");
	 myline->createStandardContextMenu();
	 myline->selectAll();
	 label->setGeometry(532,10,200,20);
	 chb->move(532,535);
	 spinbox->setGeometry(567,10,165,20);
	 spinbox->setRange(1, 200);
	 //Святое место определения механизма сигналов и слотов, унёсший 8 дней практики на реализацию передачи значений между экземплярами класса
	 //изменять с осторожностью и благословлением, церковная зона
	 QObject::connect(spinbox, SIGNAL(valueChanged(int)), &widget, SLOT(scale(int)));
	 QObject::connect(spinbox, SIGNAL(valueChanged(int)), myline, SLOT(emitsig()));
	 QObject::connect(myline, SIGNAL(returnPressed()), myline, SLOT(emitsig()));
	 QObject::connect(myline, SIGNAL(givechar(QString)), &widget, SLOT(calc(QString)));
	 QObject::connect(chb, SIGNAL(stateChanged(int)), &widget, SLOT(chk(int)));
	 QObject::connect(&widget, SIGNAL(emitstr(QString)), myline, SLOT(takestr(QString)));
	 //конец защищенной церковной зоны
     window.setWindowTitle(
         QApplication::translate("GCPLOT", "GCPLOT"));
	 window.setFixedSize(742, 562);
	 window.show();
     return app.exec();
 }



