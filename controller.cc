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

#include "controller.h"

Controller::Controller() {}

Controller::~Controller() {

}

Controller &Controller::GetInstance() {
    static Controller instance;
    return instance;
}

MainWindow* Controller::SetupMainWindow(){

    setupEventListViewer();
    setupGraphViewer();

    mainWindow.getSplitter()->addWidget(new EventListViewer); // &graphViewer in future implementation
    mainWindow.getSplitter()->addWidget(&eventViewer);

    return &mainWindow;
}


void Controller::setupEventListViewer(){

    std::vector<bbque::Event> events = model.GetEvents();

    if(events.size()>0)
        std::cout << "events.size is >0" << std::endl;
    else {
        std::cout << "events.size is 0 --> adding a mock event" << std::endl;
        //wrapper->AddEvent(bbque::Event("mock_event","mock_type",0));
    }

    eventViewer.setupTable(&model);
}

void Controller::setupGraphViewer(){
    //TODO: future implementation
}
