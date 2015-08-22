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

