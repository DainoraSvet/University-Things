#include "car.h"

int car::Car::modelCounter  = 1;

bool car::Car::reviewCompanyName (string companyName)
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

bool car::Car::reviewVehicleBodyType (string vehicleName)
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

bool car::Car::reviewManufactureYear (int manufactureYear)
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

car::Car::Car ()
{
    modelID = modelCounter;
    ++modelCounter;
}

car::Car::Car (string carCompanyName, string carVechicleName, int carManufactureYear)
{
    modelID = modelCounter;
    setCompanyName (carCompanyName);
    setVehicleBodyType (carVechicleName);
    setManufactureYear (carManufactureYear);
    ++modelCounter;
}

car::Car::~Car ()
{

}

/*setters*/
void car::Car::setCompanyName (string carCompanyName)
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

void car::Car::setVehicleBodyType (string carVehicleName)
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

void car::Car::setManufactureYear (int carManufactureYear)
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


/*getters*/
string car::Car::getCompanyName ()
{
    return companyName;
}

string car::Car::getVehicleBodyType ()
{
    return vehicleName;
}

int car::Car::getManufactureYear ()
{
    return manufactureYear;
}

/*others*/
string car::Car::toString ()
{
    stringstream ss;

    ss << "Car model ID: " << modelID << endl;
    ss << "Company name of car: " << companyName << endl;
    ss << "Vehicle body type of car: " << vehicleName << endl;
    ss << "Manufacture year of car: " << manufactureYear << endl;

    return ss.str();
}
