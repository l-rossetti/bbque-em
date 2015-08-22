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

/** DOC
model-view con qt --> http://doc.qt.io/qt-4.8/model-view-programming.html#creating-new-models
good QTableModel ex --> http://www.meetingcpp.com/index.php/br/items/an-introduction-into-qt-part-3.html
other QTableModel ex --> http://stackoverflow.com/questions/18964377/using-qtableview-with-a-model
other QTableModel ex --> http://www.informit.com/articles/article.aspx?p=1405547&seqNum=3
QTableWidget vs QTableView --> http://stackoverflow.com/questions/15290932/qtablewidget-vs-qtableview
*/

#include "event_wrapper.h"

using namespace bbque;

EventWrapper::EventWrapper(std::vector<Event> &events, QObject *parent):QAbstractTableModel(parent)
{
    this->events = events;
//    Event *e = new Event("module2", "type1", 1);
//    Event *e1 = new Event("module2", "type2", 2);
//    events.push_back(*e);
//    events.push_back(*e1);
//    delete e;
//    delete e1;
}
EventWrapper::~EventWrapper()
{

}
int EventWrapper::rowCount(const QModelIndex & /*parent*/) const
{
    return events.size();
}

int EventWrapper::columnCount(const QModelIndex & /*parent*/) const
{
    return MAX_COLS;
}

QVariant EventWrapper::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if ((unsigned) index.row() >= events.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole){
        switch (index.column()) {
        case ID:
            return index.row();
        case MODULE:
            return QString::fromStdString(events[index.row()].GetModule());
            break;
        case VALUE:
            return events.at(index.row()).GetValue();
            break;
        case TYPE:
            return QString::fromStdString(events[index.row()].GetType());
            break;
        default:
            return QVariant();
            break;
        }
    }
    else
        return QVariant();
}

QVariant EventWrapper::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case ID:
                return QString( "#" );
            case MODULE:
                return QString( "Module" );
            case VALUE:
                return QString( "Value" );
            case TYPE:
                return QString( "Type" );
            default: return QString("Name not provided for this column");
            }
        }
    }
    return QVariant();
}
