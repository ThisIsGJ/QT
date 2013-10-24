//-------------------------------------------------------------------------------------------
//  University of Bath Computer Science Department
//	FrameWork for OpenGL application under QT
//  Course title: Introduction Computer Graphics
//-------------------------------------------------------------------------------------------
gjgjgjggjgj
#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QColorDialog>
#include "ui_MainWindow.h"
#include "glwidget.h"
#include <QTransform>

class GLWidget;

//Create a window and load the components from generated code ui_MainWindow.h
class Window : public QDialog, public Ui::frmMain
{
    Q_OBJECT;

public:
    //Constructor
    Window(QWidget *parent = 0);
    ~Window();
private:
    //GLWidget instance---by storing an instance, the widget is automatically created
    //and cleared up when the Window class is instantiated (i.e. no need for new/delete)
    GLWidget mGLWidget;
    Ui::frmMain *ui;

    int number;\
    QStack<QTransform> stack; 
    QStack<QTransform> stackBack;

private slots:
    void aboutBut();
    void pressmebut();
    void storeMat();
    void transferShape();
    void cleanStack();


protected:
    // void  resizeEvent(QResizeEvent * );
};


#endif
