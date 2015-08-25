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

#ifndef MODEL_H_
#define MODEL_H_

#include <QAbstractTableModel>
#include "event.h"
#include "event_wrapper.h"
#include "event_manager.h"

namespace bbque {

/**
    This class is the Model for the model-view pattern
*/
class Model : public QAbstractTableModel
{
    Q_OBJECT
public:

    /**
        * @brief Constructor
        * @param parent The EventManagercontainer QObject
        */
    Model(QObject *parent = 0);

    /**
        * @brief Destructor
        */
    ~Model();

    /**
        * @brief Get the list
        */
    inline std::vector<Event> GetEvents() {
        return this->events;
    }

    /**
        * @brief Set the list of events
        */
    inline void SetEvents(std::vector<Event> events) {
        this->events = events;
    }

    enum { ID=0, MODULE, TYPE, VALUE,/*TIMESTAMP,*/ MAX_COLS };

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    std::vector<Event> events;
};

} // namespace bbque

#endif // BBQUE_EVENT_WRAPPER1_H_
