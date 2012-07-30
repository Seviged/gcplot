#include <QtGui>
#include "render.h"
#include "pars.h"
#include <iostream>

void render::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QColor(255, 255, 255));
	painter.setPen(QPen(QColor(130,135,144),1));
	painter.drawRect(0,0, 512,512);
	painter.setWindow(-256,-256, 512, 512);

	int i = 0,x1=0,y1=0,x2=0,y2=0,var,shc=1;
	while(i!=26)
	{
		//qDebug() << "lol";
		painter.setPen(QPen(QColor(20,100,10,200),1));
		painter.drawText(3,10,"0,0");
		painter.drawText(245,10,"X");
		painter.drawText(3,-245,"Y");
		if (a > 50)
		{
			painter.setPen(QPen(QColor(20,100,10,200),1));
			painter.drawText(x1+3,10,QString::number(i));
			painter.drawText(x2+3,10,QString::number(-i));
			painter.drawText(3,y1+10,QString::number(-i));
			painter.drawText(3,y2+10,QString::number(i));
		}
		painter.setPen(QPen(QColor(130,135,144,150),1));
		if ((i%5 == 0)&&(x1 != 0)&&(y1 != 0))
		{
			painter.setPen(QPen(QColor(20,100,10,200),1));
			painter.drawText(x1+3,10,QString::number(shc*5));
			painter.drawText(x2+3,10,QString::number(-(shc*5)));
			painter.drawText(3,y1+10,QString::number(-(shc*5)));
			painter.drawText(3,y2+10,QString::number(shc*5));
			shc++;
		}
		if ((x1 == 0)||(y1 == 0))
		{
			painter.setPen(QPen(QColor(20,100,10),1));
		}

		painter.drawLine(QPointF(x1,256),QPointF(x1,-256));
		painter.drawLine(QPointF(-256,y1),QPointF(256,y1));
		x1+=a;
		y1+=a;
		painter.drawLine(QPointF(x2,256),QPointF(x2,-256));
		painter.drawLine(QPointF(-256,y2),QPointF(256,y2));
		x2-=a;
		y2-=a;
		i++;
		update();

	}

	painter.setRenderHint(QPainter::Antialiasing, true);
		painter.setPen(QPen(QColor(0,0,0)));
		if(flag == 1)
		{
			int val=0;
			while(val<5195)
			{
				painter.drawLine(mass[val],mass[val+1]);
				val++;
				//qDebug() << mass[val];
			}
		}
		

}

void render::calc(QString str)
{
	TParser parser;
	QByteArray ar = str.toAscii();
	text=ar.data();
		double x = -256,y;
try
	  {
		  //text="x[0]^2";
		  parser.Compile(text); 
		  if(chbpos==0)
		  {
				for (int i = 0; i < 5200; i++)
				{
					x+=0.1;
					parser.Evaluate(x);
					y = parser.GetResult();
					y = -y;
					mass[i]=QPointF(x*a,y*a);
					//qDebug() << mass[i];
				}
				flag=1;
				update();
		  }
		  else
		  {
			  parser.Evaluate();
			  QString res; 
			  res.setNum(parser.GetResult());
			  //str+"="+res;
			  emit emitstr(str+"="+res);
		  }
}
catch(TError error)
      {
		  QErrorMessage *err = new QErrorMessage();
		  QString str = " at position ";
		  QString slt;
		  slt.setNum(error.pos);
		  QString qwerty = error.error + str + slt;
		  err->showMessage(qwerty);
		  err->show();
		  flag=0;
      }  

}

void render::scale(int num)
{
	//a=num+30;
	a=num+10;
	update();
}

void render::chk(int num)
{
	chbpos=num;
	update();
}