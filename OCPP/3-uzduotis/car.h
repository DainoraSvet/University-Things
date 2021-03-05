#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

#define CURRENT_YEAR 2021
#define FIRST_CAR_EVER 1886

namespace car
{
    class Car
        {
        private:
            string companyName;
            string vehicleName;
            int manufactureYear;
            int modelID;
            static int modelCounter;

            bool reviewCompanyName (string companyName);
            bool reviewVehicleBodyType (string vehicleName);
            bool reviewManufactureYear (int manufactureYear);

        public:
            Car ();
            Car (string carCompanyName, string carVehicleName, int carManufactureYear);
            ~Car ();

            /*setters*/
            void setCompanyName (string carCompanyName);
            void setVehicleBodyType (string carVechicleName);
            void setManufactureYear (int carManufactureYear);

            /*getters*/
            string getCompanyName ();
            string getVehicleBodyType ();
            int getManufactureYear ();

            /*others*/
            string toString ();

        };
}


#endif // CAR_H
