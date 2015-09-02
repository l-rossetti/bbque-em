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

#include "model.h"

using namespace bbque;

Model::Model(QObject *parent) {
    std::cout << "Creating model" << std::endl;
    bbque::EventManager em = bbque::EventManager::GetInstance();
    bbque::Event event("init1","type1",666);
    em.InitializeArchive(event);
    bbque::EventWrapper ew;
    em.Push(Event("prova2","prova",12));
    ew = em.Deserialize();
    em.Serialize(ew);
    //sleep(11);
    em.Push(Event("prova3","prova3",11));
    ew = em.Deserialize();
    em.Serialize(ew);
    SetEvents(ew.GetEvents());
}

Model::~Model()
{

}

int Model::rowCount(const QModelIndex & /*parent*/) const
{
    return events.size();
}

int Model::columnCount(const QModelIndex & /*parent*/) const
{
    return MAX_COLS;
}

QVariant Model::data(const QModelIndex &index, int role) const
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
        case TIMESTAMP:{
            std::time_t timestamp = events[index.row()].GetTimestamp();

            //return QString::fromStdString(std::asctime(std::localtime(&timestamp)));

            const int n = snprintf(NULL, 0, "%lu", timestamp);
            assert(n > 0);
            char buf[n+1];
            int c = snprintf(buf, n+1, "%lu", timestamp);
            assert(buf[n] == '\0');
            assert(c == n);

            return QString::fromStdString(buf);
        }
            break;
        case TYPE:
            return QString::fromStdString(events[index.row()].GetType());
            break;
        case VALUE:
            return events.at(index.row()).GetValue();
            break;
        default:
            return QVariant();
            break;
        }
    }
    else
        return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
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
            case TIMESTAMP:
                return QString( "Timestamp" );
            case TYPE:
                return QString( "Type" );
            case VALUE:
                return QString( "Value" );
            default: return QString("Name not provided for this column");
            }
        }
    }
    return QVariant();
}
