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

#ifndef BBQUE_EVENT_WRAPPER_H_
#define BBQUE_EVENT_WRAPPER_H_

#include <QAbstractTableModel>
#include "event.h"


#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>

namespace bbque {

/**
    This class is the Model for the model-view pattern
*/
class EventWrapper : public QAbstractTableModel
{
    Q_OBJECT
public:

    /**
        * @brief Constructor
        * @param parent The container QObject
        */
    EventWrapper(QObject *parent = 0) {
        std::cout << "Creating event_wrapper" << std::endl;
    }
    /**
        * @brief Constructor
        * @param events The list of events
        * @param parent The container QObject
        */
    EventWrapper(std::vector<Event> & events, QObject *parent = 0);

    /**
        * @brief Destructor
        */
    ~EventWrapper();

    /**
        * @brief Get the list of events
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

    /**
        * @brief Add an event to the list of events
        */
    inline void AddEvent(Event event) {
        this->events.insert(this->events.begin(), event);
    }

    enum { ID=0, MODULE, TYPE, VALUE,/*TIMESTAMP,*/ MAX_COLS };

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        if (version == 0 || version != 0)
        {
            ar & events;
        }
    }

    std::vector<Event> events;
};

} // namespace bbque

#endif // BBQUE_EVENT_WRAPPER_H_
