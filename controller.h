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

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <QMainWindow>
#include "event_manager.h"
#include "event_list_viewer.h"
#include "model.h"
#include "main_window.h"

//namespace ctrl {

class Controller
{
public:
    /**
                 * @brief Constructor
                 *///// DOC --> http://doc.qt.io/qt-5/gettingstartedqt.html

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
    inline const MainWindow &getMainWindow()
    {
        return mainWindow;
    }

    inline EventListViewer &getEventListViewer()
    {
        return eventViewer;
    }

private:

    MainWindow mainWindow;
    EventListViewer eventViewer;
    bbque::Model model;

    void setupEventListViewer();
    void setupGraphViewer();
};
//} // namespace ctrl
#endif // CONTROLLER_H_
