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

#ifndef EVENTLISTVIEWER_H
#define EVENTLISTVIEWER_H

#include <QWidget>
#include "event_wrapper.h"

namespace Ui {
class EventListViewer;
}

class EventListViewer : public QWidget
{
    Q_OBJECT
    static const int COLUMN_NUM = 5;

public:
    explicit EventListViewer(QWidget *parent = 0);
    explicit EventListViewer(bbque::EventWrapper *wrapper, QWidget *parent = 0);
    ~EventListViewer();

    void setupTable(bbque::EventWrapper *wrapper);

private:
    Ui::EventListViewer *ui;
};

#endif // EVENTLISTVIEWER_H
