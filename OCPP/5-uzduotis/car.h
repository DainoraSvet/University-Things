#ifndef CAR_H
#define CAR_H
#include "Review.h"

#include <iostream>
#include <sstream>

using namespace std;

#define INVALID_NAME "Invalid name."
#define INVALID_YEAR "Invalid year."


namespace MyCar
{
    class Car
    {
        private:
            class InnerCar;
            InnerCar* carPtr;
            friend class InnerCar;

        public:
            Car ();
            Car (const string& carCompanyName, const string& carVehicleName, int carManufactureYear);
            ~Car ();

            /*setters*/
            void setCompanyName (const string& carCompanyName);
            void setVehicleName (const string& carVechicleName);
            void setManufactureYear (int carManufactureYear);
            void setCarId ();

            /*getters*/
            string getCompanyName () const;
            string getVehicleName () const;
            int getManufactureYear () const;
            int getCarId () const;

            /*others*/
            string toString () const;

            /*operators*/
            bool operator == (const Car& car);
            bool operator != (const Car& car);
            bool operator < (const Car& car);
            bool operator <= (const Car& car);
            bool operator > (const Car& car);
            bool operator >= (const Car& car);

            Car& operator ++ ();
            Car operator ++ (int);
            Car& operator -- ();
            Car operator -- (int);

            /*writing*/
            friend ostream& operator << (ostream& out, const Car& car);
            friend istream& operator >> (istream& in, Car& car);

        private:


    };
}



#endif // CAR_H
