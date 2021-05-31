#include "Review.h"

Review::Review ()
{
    //ctor
}

Review::~Review ()
{
    //dtor
}

bool Review::reviewCompanyName (const string& companyName)
{
    for (int i = 0; i < companyName.length(); ++i)
    {
        if ((!(isupper(companyName[0])) || !isalpha(companyName[i]) && companyName[i] != ' '))
        {
            return false;
        }
    }
    return true;
}

bool Review::reviewVehicleName (const string& vehicleName)
{
    for (int i = 0; i < vehicleName.length(); ++i)
    {
        if ((!(isupper(vehicleName[0])) || !isalpha(vehicleName[i]) && vehicleName[i] != ' '))
        {
            return false;
        }
    }
    return true;
}

bool Review::reviewManufactureYear (int manufactureYear)
{
    if (manufactureYear <= CURRENT_YEAR && manufactureYear >= FIRST_CAR_EVER)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Review::reviewPointer (string file, int line, void *carPtr)
{
    if (carPtr == NULL)
    {
        stringstream ss;

        ss << UNINTIALIZED << " In " << file << " in " << line << " line." << endl;

        throw logic_error (ss.str());
    }
}
