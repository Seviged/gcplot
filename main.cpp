//�� ������� Ctrl Alt Delete! �����!
//��������� � �������� ������� ������������� ������������ ������, ������� ���!
//���� ����������: �� ����� �����
//GTK - ����������, ����������� ������ QT.
//����������� ������� �������, �������� ���������, ��������� ����������, � �������� ������� ��� �������� ������� ����� � ���� ��� ���
//GCPlot - Graphical Calculation plotter
//��������� ���������� �������� �� ������ ������� y=f(x)
//������ 1.0_beta
//����������� 75% �������������������� ������������ �������.
//������ ��������)))

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
	 //������ ����� ����������� ��������� �������� � ������, ������ 8 ���� �������� �� ���������� �������� �������� ����� ������������ ������
	 //�������� � ������������� � ���������������, ��������� ����
	 QObject::connect(spinbox, SIGNAL(valueChanged(int)), &widget, SLOT(scale(int)));
	 QObject::connect(spinbox, SIGNAL(valueChanged(int)), myline, SLOT(emitsig()));
	 QObject::connect(myline, SIGNAL(returnPressed()), myline, SLOT(emitsig()));
	 QObject::connect(myline, SIGNAL(givechar(QString)), &widget, SLOT(calc(QString)));
	 QObject::connect(chb, SIGNAL(stateChanged(int)), &widget, SLOT(chk(int)));
	 QObject::connect(&widget, SIGNAL(emitstr(QString)), myline, SLOT(takestr(QString)));
	 //����� ���������� ��������� ����
     window.setWindowTitle(
         QApplication::translate("GCPLOT", "GCPLOT"));
	 window.setFixedSize(742, 562);
	 window.show();
     return app.exec();
 }



