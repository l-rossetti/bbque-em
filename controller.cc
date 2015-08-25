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

    //bbque::EventManager *manager = &bbque::EventManager::GetInstance();
    //manager->InitializeArchive(bbque::Event("mod1","type1",12));
    //manager->Push(bbque::Event("mod1","type1",76));

    bbque::EventManager em = bbque::EventManager::GetInstance();
    bbque::Event event("init1","type1",666);
    em.InitializeArchive(event);
    bbque::Event event1("pp2", "demo2", 199);
    em.Push(event1);

    //TODO: fix model with metods to get the vector of events
    //bbque::EventWrapper *wrapper = manager->Deserialize(); //get wrapper via manager

    bbque::EventWrapper ew = em.Deserialize();

    std::vector<bbque::Event> events = ew.GetEvents();
    //bbque::Event *e = &events.front();
    //std::string module = e->GetModule();

    if(events.size()>0)
        std::cout << "events.size is >0" << std::endl;
    else {
        std::cout << "events.size is 0 --> adding a mock event" << std::endl;
        //wrapper->AddEvent(bbque::Event("mock_event","mock_type",0));
    }

    //getEventListViewer().setupTable(model);
}

void Controller::setupGraphViewer(){
    //TODO: future implementation
}
