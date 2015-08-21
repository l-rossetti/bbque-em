#include "event_list_viewer.h"
#include "event_manager.h"
#include "ui_event_list_viewer.h" // --> generated from uictool from .ui file to use setupUi function
#include <QSortFilterProxyModel>

EventListViewer::EventListViewer(QWidget *parent) : QWidget(parent),
    ui(new Ui::EventListViewer)
{

    ui->setupUi(this);
}

EventListViewer::EventListViewer(bbque::EventWrapper *wrapper, QWidget *parent) : QWidget(parent),
    ui(new Ui::EventListViewer)
{

    ui->setupUi(this);
    EventListViewer::setupTable( wrapper );
}

EventListViewer::~EventListViewer()
{
    delete ui;
}

void EventListViewer::setupTable(bbque::EventWrapper *wrapper)
{
    //std::vector<bbque::Event> events;
    // filter used to sort the table rows by clicking the table headers
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel( wrapper );
    ui->tableView->setModel(proxyModel);
    //ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
}

