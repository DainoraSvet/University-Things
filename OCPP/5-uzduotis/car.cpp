#include "car.h"

#include <iostream>
#include <string>
#include <sstream>

namespace MyCar
{
        class Car::InnerCar
        {
            string companyName;
            string vehicleName;
            int manufactureYear;
            int carId;
            static int carCounter;
            static int id;

            static bool reviewCompanyName (const string& companyName);
            static bool reviewVehicleName (const string& vehicleName);
            static bool reviewManufactureYear (int manufactureYear);

            friend class Car;
        };


    int Car::InnerCar::carCounter  = 0;
    int Car::InnerCar::id  = 0;

    Car::Car ()
    {
        carPtr = NULL;
        ++carPtr->carCounter;
    }

    Car::Car (const string& carCompanyName, const string& carVechicleName, int carManufactureYear)
    {
        carPtr = new InnerCar ();

        ++carPtr->carCounter;

        setCarId ();
        setCompanyName (carCompanyName);
        setVehicleName (carVechicleName);
        setManufactureYear (carManufactureYear);
    }

    Car::~Car ()
    {
        delete carPtr;
    }

    /*setters*/
    void Car::setCompanyName (const string& carCompanyName)
    {
        if (carPtr == NULL)
        {
           carPtr = new InnerCar;
           carPtr->carCounter = 0;
           carPtr->carId = ++carPtr->id;
        }

        if (Review::reviewVehicleName (carCompanyName))
        {
            carPtr->companyName = carCompanyName;
        }
        else
        {
            throw invalid_argument (INVALID_NAME);
        }
    }

    void Car::setVehicleName (const string& carVehicleName)
    {
        if (carPtr == NULL)
        {
           carPtr = new InnerCar;
           carPtr->carCounter = 0;
           carPtr->carId = ++carPtr->id;
        }
        if (Review::reviewVehicleName (carVehicleName))
        {
            carPtr->vehicleName = carVehicleName;
        }
        else
        {
            throw invalid_argument (INVALID_NAME);
        }
    }

    void Car::setManufactureYear (int carManufactureYear)
    {
        if (carPtr == NULL)
        {
           carPtr = new InnerCar;
           carPtr->carCounter = 0;
           carPtr->carId = ++carPtr->id;
        }
        if (Review::reviewManufactureYear (carManufactureYear))
        {
            carPtr->manufactureYear = carManufactureYear;
        }
        else
        {
            throw invalid_argument (INVALID_YEAR);
        }
    }

    void Car::setCarId ()
    {
        if (carPtr == NULL)
        {
           carPtr = new InnerCar;
           carPtr->carCounter = 0;
           carPtr->carId = ++carPtr->id;
        }
        carPtr->carId = carPtr->carCounter;
    }


    /*getters*/
    string Car::getCompanyName () const
    {
        if (carPtr == NULL)
        {
           throw logic_error (LOGIC_ERROR);
        }

        return carPtr->companyName;
    }

    string Car::getVehicleName () const
    {
        if (carPtr == NULL)
        {
           throw logic_error (LOGIC_ERROR);
        }

        return carPtr->vehicleName;
    }

    int Car::getManufactureYear () const
    {
        if (carPtr == NULL)
        {
           throw logic_error (LOGIC_ERROR);
        }

        return carPtr->manufactureYear;
    }

    int Car::getCarId () const
    {
        if (carPtr == NULL)
        {
           throw logic_error (LOGIC_ERROR);
        }

        return carPtr->carId;
    }

    /*others*/
    string Car::toString () const
    {
        if (carPtr == NULL)
        {
           throw logic_error (LOGIC_ERROR);
        }

        stringstream ss;

        ss << getCarId () << " " << getCompanyName () << " " << getVehicleName () << " " << getManufactureYear () << endl;

        return ss.str();
    }

    /*operators*/
    bool Car::operator == (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        if (this->getManufactureYear() == car.getManufactureYear())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Car::operator != (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        return !(*this == car);
    }

    bool Car::operator < (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        if (this->getManufactureYear() >= car.getManufactureYear())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool Car::operator <= (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        if (this->getManufactureYear() > car.getManufactureYear())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool Car::operator > (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        return !(*this <= car);
    }

    bool Car::operator >= (const Car& car)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        return !(*this < car);
    }

    Car& Car::operator ++ ()
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        int manufactureYear = this->getManufactureYear ();
        this->setManufactureYear (++manufactureYear);

        return *this;
    }

    Car Car::operator ++ (int)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        Car provisional = *this;
        int manufactureYear = this->getManufactureYear ();
        this->setManufactureYear (++manufactureYear);

        return provisional;
    }

    Car& Car::operator -- ()
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        int manufactureYear = this->getManufactureYear ();
        this->setManufactureYear (--manufactureYear);

        return *this;
    }

    Car Car::operator -- (int)
    {
        Review::reviewPointer (__FILE__, __LINE__, this->carPtr);

        Car provisional = *this;
        int manufactureYear = this->getManufactureYear ();
        this->setManufactureYear (--manufactureYear);

        return provisional;
    }

    /*writing*/
    ostream& operator << (ostream& out, const Car& car)
    {
        out << car.toString ();
        return out;
    }

    istream& operator >> (istream& in, Car& car)
    {
        Car otherCar;

        string companyName, vehicleName;
        int manufactureYear;

        car.setCompanyName (companyName);
        car.setVehicleName (vehicleName);
        car.setManufactureYear (manufactureYear);

        car = otherCar;

        return in;
    }

}
