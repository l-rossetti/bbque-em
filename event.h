    #ifndef BBQUE_EVENT_H_
    #define BBQUE_EVENT_H_

    #include <cstdint>
    #include <string>
    #include <ctime>
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

    #include <boost/serialization/access.hpp>

    namespace bbque
    {
    class Event
    {

    public:

        /**
             * @brief Constructor with no params
             */
        inline Event(){}

        /**
                 * @brief Constructor
                 * @param module The module which has triggered the event
                 * @param type of event
                 * @param value associated to the event
                 */
        Event(std::string const & module, std::string const & type, const int & value);
        /**
                 * @brief Destructor
                 */
        ~Event();

        /**
             * @brief Get the module which has triggered the event
             */
        inline std::string GetModule() const{
            return this->module;
        }

        /**
             * @brief Get the type of event
             */
        inline std::string GetType() const{
            return this->type;
        }

        /**
             * @brief Get the timestamp
             */
        inline std::time_t GetTimestamp() const{
            return this->timestamp;
        }

        /**
             * @brief Get the value associated to the event
             */
        inline int GetValue() const{
            return this->value;
        }

        /**
             * @brief Set the timestamp
             */
        inline void SetTimestamp(std::time_t timestamp) {
            this->timestamp = timestamp;
        }

        /**
             * @brief Set the value
             */
        inline void setValue(int v){
            this->value = v;
        }

        /**
             * @brief Set the type
             */
        inline void setType(std::string t){
            this->type = t;
        }

        /**
             * @brief Set the module
             */
        inline void setModule(std::string m){
            this->module = m;
        }

    private:

        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            if (version == 0 || version != 0)
            {
                ar & timestamp;
                ar & module;
                ar & type;
                ar & value;
            }
        }

        std::time_t timestamp;

        std::string module;

        std::string type;

        int value;
    };
    } //namespace bbque
    #endif // BBQUE_EVENT_H
