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
