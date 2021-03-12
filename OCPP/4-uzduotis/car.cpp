#include "car.h"

int Car::modelCounter  = 1;

bool Car::reviewCompanyName (string companyName)
{
    for (int i = 0; i < companyName.length(); ++i)
    {
        if ((!(isupper(companyName[0])) || !isalpha(companyName[i]) && companyName[i] != ' '))
        {
            throw invalid_argument ("Invalid company name.");
        }
    }
    return true;
}

bool Car::reviewVehicleBodyType (string vehicleName)
{
    for (int i = 0; i < vehicleName.length(); ++i)
    {
        if ((!(isupper(vehicleName[0])) || !isalpha(vehicleName[i]) && vehicleName[i] != ' '))
        {
            throw invalid_argument ("Invalid vehicle name.");
        }
    }
    return true;
}

bool Car::reviewManufactureYear (int manufactureYear)
{
    if (manufactureYear <= CURRENT_YEAR && manufactureYear >= FIRST_CAR_EVER)
    {
        return true;
    }
    else
    {
        throw invalid_argument ("Invalid manufacture year.");
    }
}

Car::Car ()
{
    modelID = modelCounter;
    ++modelCounter;
}

Car::Car (const string carCompanyName, const string carVechicleName, int carManufactureYear)
{
    modelID = modelCounter;
    setCompanyName (carCompanyName);
    setVehicleBodyType (carVechicleName);
    setManufactureYear (carManufactureYear);
    ++modelCounter;
}

Car::~Car ()
{

}

/*setters*/
void Car::setCompanyName (string carCompanyName)
{
    if (reviewCompanyName (carCompanyName))
    {
        companyName = carCompanyName;
    }
    else
    {
        throw invalid_argument ("Invalid company name.");
    }
}

void Car::setVehicleBodyType (string carVehicleName)
{
    if (reviewVehicleBodyType (carVehicleName))
    {
        vehicleName = carVehicleName;
    }
    else
    {
        throw invalid_argument ("Invalid vehicle name.");
    }
}

void Car::setManufactureYear (int carManufactureYear)
{
    if (reviewManufactureYear (carManufactureYear))
    {
        manufactureYear = carManufactureYear;
    }
    else
    {
        throw invalid_argument ("Invalid manufacture year.");
    }
}

void Car::setModelID ()
{
    modelID = modelCounter;
}


/*getters*/
string Car::getCompanyName () const
{
    return companyName;
}

string Car::getVehicleBodyType () const
{
    return vehicleName;
}

int Car::getManufactureYear () const
{
    return manufactureYear;
}

int Car::getModelID () const
{
    return modelID;
}

/*others*/
string Car::toString () const
{
    stringstream ss;

    ss << "Car model ID: " << modelID << endl;
    ss << "Company name of car: " << companyName << endl;
    ss << "Vehicle body type of car: " << vehicleName << endl;
    ss << "Manufacture year of car: " << manufactureYear << endl;

    return ss.str();
}

/*operators*/
bool Car::operator == (const Car& cr)
{
    if (this->getManufactureYear() == cr.getManufactureYear())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Car::operator != (const Car& cr)
{
    return !(*this == cr);
}

bool Car::operator < (const Car& cr)
{
    if (this->getManufactureYear() >= cr.getManufactureYear())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Car::operator <= (const Car& cr)
{
    if (this->getManufactureYear() > cr.getManufactureYear())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Car::operator > (const Car& cr)
{
    return !(*this <= cr);
}

bool Car::operator >= (const Car& cr)
{
    return !(*this < cr);
}

Car& Car::operator ++ ()
{
    ++manufactureYear;

    return *this;
}

Car Car::operator ++ (int)
{
    Car provisional = *this;
    ++manufactureYear;

    return provisional;
}

Car Car::operator -- ()
{
    --manufactureYear;

    return *this;
}

Car Car::operator -- (int)
{
    Car provisional = *this;
    --manufactureYear;

    return provisional;
}

/*writing*/
ostream& operator << (ostream& out, const Car& cr)
{
    out << cr.toString ();
    return out;
}

istream& operator >> (istream& in, Car& cr)
{
    Car otherCar;

    in >> otherCar.companyName;
    in >> otherCar.vehicleName;
    in >> otherCar.manufactureYear;

    cr.setCompanyName (otherCar.companyName);
    cr.setVehicleBodyType (otherCar.vehicleName);
    cr.setManufactureYear (otherCar.manufactureYear);

    return in;
}
