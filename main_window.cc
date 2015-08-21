#include "main_window.h"
#include "ui_main_window.h"  // --> generated from uictool from .ui file to use setupUi function
#include "event_list_viewer.h"
#include <iostream>

//// DOC --> http://doc.qt.io/qt-5/gettingstartedqt.html

// constructor
// before ':' MainWindow constructor signature
// after ':'  call the QMainWindow constructor, which is the base class for MainWindow
// after ','  creates the UI class instance and assigns it to the ui member (initialization list)
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //    ui = new Ui::MainWindow(); //--> ui can be initialized here removing from above
    ui->setupUi(this);
    MainWindow::setupUIConnections();
}

MainWindow::MainWindow(EventListViewer *eventViewer, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //    ui = new Ui::MainWindow(); //--> ui can be initialized here removing from above
    ui->setupUi(this);
    MainWindow::setupUIConnections();
    ui->mainlayout->addWidget(eventViewer ,0,0);
}

// destructor
MainWindow::~MainWindow()
{
    std::cout << "\nDestructor called: MainWindow obj deleted.\n" << std::endl;
    delete ui;
}

void MainWindow::setupUIConnections()
{
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}
