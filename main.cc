#include "main_window.h"
#include <QApplication>
#include "controller.h"
int main(int argc, char *argv[])
{
    QApplication progr(argc, argv); // this is the main object for a Qt application that controls my program

    Controller *controller;
    controller = & Controller::GetInstance();
    MainWindow * mainWindow = controller->SetupMainWindow();

    mainWindow->show();

    return progr.exec();
}
