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
        int modelId;
        static int modelCounter;

    public:
        Car ();
        Car (const string carCompanyName, const string carVehicleName, int carManufactureYear);
        ~Car ();

        /*setters*/
        void setCompanyName (string carCompanyName);
        void setVehicleBodyType (string carVechicleName);
        void setManufactureYear (int carManufactureYear);
        void setModelId ();

        /*getters*/
        string getCompanyName () const;
        string getVehicleBodyType () const;
        int getManufactureYear () const;
        int getModelId () const;

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
        Car operator -- ();
        Car operator -- (int);

        /*writing*/
        friend ostream& operator << (ostream& out, const Car& car);
        friend istream& operator >> (istream& in, Car& car);

    private:
        bool reviewCompanyName (string companyName);
        bool reviewVehicleBodyType (string vehicleName);
        bool reviewManufactureYear (int manufactureYear);

};


#endif // CAR_H
