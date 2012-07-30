#include "calculate.h"
#include <QtGui>
#include "pars.h"

void Scalc::takechar(QString str)
{
	TParser parser;
	QByteArray ar = str.toAscii();
	char* text=ar.data();
	//char* as=ar.data();
		  try
	  {
		  parser.Compile(text);
		  int i=0;
		  double xx = -260.0;
		  double nya[5201];
		  if (chbpos==0)
		  {
			  while(i!=5201)
			  {
				  parser.Evaluate(xx);
				  nya[i] = parser.GetResult();
				  i++;
				  xx+=0.1;
			  }
		  }
		  else
		  {
			  parser.Evaluate();
			  double pbs = parser.GetResult();
				QLabel* lb = new QLabel;
				lb->setNum(pbs);
				lb->show();
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
      }  
}


/*#include "calculate.h"
#include <QtGui>
#include "pars.h"

void Scalc::takechar(QString str)
{
	TParser parser;
	QByteArray ar = str.toAscii();
	char* text=ar.data();
		  try
	  {
		  parser.Compile(text);
		  int i=0;
		  double x = -260.0;
		  double nya[5201];
		  while(i!=5201)
		  {
			  parser.Evaluate(x);
			  nya[i] = parser.GetResult();
			  i++;
			  x+=0.1;
		  }
		  double pbs = parser.GetResult();
		  	QLabel* lb = new QLabel;
			lb->setNum(pbs);
			lb->show();
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
      }  
}*/