#include <iostream>
#include <QtGui>
#include <QtOpenGL>
#include "version.h"
#include "window.h"
//#include "dfuncs.h"
#include "shape.h"


//------------------------------------------------------------------------------------
// Creates and initializes the main window for application
//------------------------------------------------------------------------------------
Window::Window(QWidget *parent):QDialog(parent),number(1)
{
	//Setup application interface. Creates all the required components and sliders.
    ui = new Ui::frmMain;
    ui->setupUi(this);

    //We need to attach our m_glWidget to glWidgetArea
    //All our drawings will be on glWidgetArea
   //glWidgetArea->setWidget(&mGLWidget);
}

//void Window::resizeEvent( QResizeEvent * )
//{
//  cerr << "new size "<< width() SEP height() NL;
//  //m_glWidget->resizeGL(width(), height());
// // qttsnk->setGeometry(width()-320,  110, 100,  100);
//}

Window::~Window()
{
    delete ui;
}

void Window::aboutBut()
{
    QString title="QtOpenGl-2 ";
    QString mess = "QtOpenGl-basic by Brian Wyvill Release Version: " + QString::number(MY_VERSION);
    QMessageBox::information( this, title, mess, QMessageBox::Ok );
}

//bool Window::checkData(QString tempStr, double *num)
//{
//    bool validate;
////no error message
//    *num = tempStr.toDouble(&validate);
//    if (validate == false) *num =0.0;
//    return validate;
//}

//void Window::txt0()
//{
//    double a;
//    if ( checkData(mat[0], &a) ) cerr << "data ok  ";
//    cerr << "a="<<a NL;
//}

//void Window::txt0(QString a)
//{
//    mat[0]=a;
//}

//void Window::txt9(QString a)
//{
//    mat[9]=a;
//    cerr << "Input string\n";
//}

//void Window::txt99()
//{
//    double a;
//    if ( checkData(mat[9], &a) ) cerr << "9data ok  ";
//    cerr << "a="<<a NL;
//     QMessageBox::information( this, "QtGl: ", mat[9], QMessageBox::Ok );
//}

//void Window::txt1()
//{
//    double a;
//    if ( checkData(mat[1], &a) ) cerr << "data ok  ";
//        cerr << "a="<<a NL;
//}

//void Window::txt1(QString a)
//{
//    mat[1]=a;
//}

void Window::pressmebut()
{
    std::cerr << "Don't press me!";
}


void Window::transferShape()
{
    getSeq();
    if(s1 == s2 == s3 == 0)
    {
        if(!stack.isEmpty()){
            cleanStack();
        }
        storeMat();
        ui->widget->transfer(stack.top());
        cleanStack();


    }else{
        int i = 1;
        stackBack = stack;

        if(s1 != 0){
            if(i = s1){
                 ui->widget->transfer(stackBack.top());
            }else{

                stackBack.pop();
                i++;
            }
        }

        i = 1;
        stackBack = stack;
        if(s2 != 0){
            if(i = s2){
                 ui->widget->transfer(stackBack.top());
            }else{
                stackBack.pop();
                i++;
            }
        }

        i = 1;
        stackBack = stack;
        if(s3 != 0){
            if(i = s3){
                 ui->widget->transfer(stackBack.top());
            }else{
                stackBack.pop();
                i++;
            }
        }
    }
}




void Window::storeMat()
{
  // QString str= QString::number(number);
   ui->textEdit->insertPlainText("Matrix is saved");
  // stack.push()
   QTransform myMat(ui->set_00->value(),ui->set_01->value(),ui->set_02->value(),
                    ui->set_10->value(),ui->set_11->value(),ui->set_12->value(),
                    ui->set_20->value(),ui->set_21->value(),ui->set_22->value());
   stack.push(myMat);

}


void Window::cleanStack()
{
    stack.clear();
    ui->textEdit->insertPlainText("stack is cleaned");
    getTheMultiplySeq();

}

void Window::getSeq()
{
    s1 = ui->o1->value();
    s2 = ui->o2->value();
    s3 = ui->o3->value();
}

void Window::getTheMultiplySeq()
{
   // qDebug() <<  ui->lineEdit->text() << sizeof(mSeq);

}
























