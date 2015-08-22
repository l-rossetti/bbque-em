/*
 * Copyright (C) 2014  Politecnico di Milano
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//// DOC --> http://doc.qt.io/qt-5/gettingstartedqt.html

#include "main_window.h"
#include "ui_main_window.h"  // --> generated from uictool from .ui file to use setupUi function
#include "event_list_viewer.h"
#include <iostream>
#include <QSplitter>
#include <QPlainTextEdit>

// constructor
// before ':' MainWindow constructor signature
// after ':'  call the QMainWindow constructor, which is the base class for MainWindow
// after ','  creates the UI class instance and assigns it to the ui member (initialization list)
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //    ui = new Ui::MainWindow(); //--> ui can be initialized here removing from above
    ui->setupUi(this);
    addSplitter();
    setupUIConnections();
}

MainWindow::MainWindow(EventListViewer *eventViewer, QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //    ui = new Ui::MainWindow(); //--> ui can be initialized here removing from above
    ui->setupUi(this);
    addSplitter();
    setupUIConnections();
    splitter->addWidget(eventViewer);
}

// destructor
MainWindow::~MainWindow()
{
    std::cout << "\nDestructor called: MainWindow obj deleted.\n" << std::endl;
    delete ui;
}

void MainWindow::addSplitter(){
    splitter = new QSplitter();
    splitter->setOrientation(Qt::Vertical);
    ui->mainlayout->addWidget(splitter);
}

void MainWindow::setupUIConnections()
{
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
}
