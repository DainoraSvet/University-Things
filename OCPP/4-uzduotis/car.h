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

#define NOT_FOUND_NUM 0
#define NOT_FOUND_SYM "-"


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
        Car (const string carCompanyName, const string carVehicleName, int carManufactureYear);
        ~Car ();

        /*setters*/
        void setCompanyName (string carCompanyName);
        void setVehicleBodyType (string carVechicleName);
        void setManufactureYear (int carManufactureYear);
        void setModelID ();

        /*getters*/
        string getCompanyName () const;
        string getVehicleBodyType () const;
        int getManufactureYear () const;
        int getModelID () const;

        /*others*/
        string toString () const;

        /*operators*/
        bool operator == (const Car& cr);
        bool operator != (const Car& cr);
        bool operator < (const Car& cr);
        bool operator <= (const Car& cr);
        bool operator > (const Car& cr);
        bool operator >= (const Car& cr);

        Car& operator ++ ();
        Car operator ++ (int);
        Car operator -- ();
        Car operator -- (int);

        /*writing*/
        friend ostream& operator << (ostream& out, const Car& cr);
        friend istream& operator >> (istream& in, Car& cr);

};


#endif // CAR_H
