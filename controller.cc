#include "controller.h"

Controller::Controller() {}

Controller::~Controller() {

}

Controller& Controller::GetInstance() {
    static Controller instance;
    return instance;
}


MainWindow* Controller::SetupMainWindow(){

    bbque::EventManager *manager = &bbque::EventManager::GetInstance();
    manager->InitializeArchive(bbque::Event("mod1","type1",12));
    manager->Push(bbque::Event("mod1","type1",76));

    bbque::EventWrapper *wrapper = manager->Deserialize(); //get wrapper via manager

    std::vector<bbque::Event> events = wrapper->GetEvents();
    bbque::Event *e = &events.front();
    //std::string module = e->GetModule();
    if(events.size()>0)
        std::cout << "events.size is >0" << std::endl;
    else
        std::cout << "events.size is 0" << std::endl;

    wrapper->setParent(&eventViewer);
    eventViewer.setParent(&mainWindow);
    eventViewer.setupTable(wrapper);
    return &mainWindow;

}
