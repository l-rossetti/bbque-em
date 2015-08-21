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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include "event_manager.h"
#include "event_wrapper.h"
#include "event_list_viewer.h"
#include "main_window.h"

//namespace ctrl {

class Controller
{
public:
    /**
                 * @brief Constructor
                 */
    Controller();

    /**
                 * @brief Destructor
                 */
    ~Controller();

    /**
                 * @brief Get the Controller instance
                 */
    static Controller &GetInstance();

    MainWindow *SetupMainWindow();

    //            void setMainWindow(const MainWindow & mainWindow)
    //            {

    //                this->mainWindow = mainWindow;
    //            }
    const MainWindow &getMainWindow()
    {
        return mainWindow;
    }

private:
    MainWindow mainWindow;
    EventListViewer eventViewer;

};
//} // namespace ctrl
#endif // CONTROLLER_H
