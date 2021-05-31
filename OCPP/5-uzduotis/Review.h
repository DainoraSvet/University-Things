#ifndef REVIEW_H
#define REVIEW_H
#include "car.h"

#include <string>
#include <sstream>

using namespace std;

#define LOGIC_ERROR "Not initialized object is found."
#define UNINTIALIZED "Unintialized object is found."

#define CURRENT_YEAR 2021
#define FIRST_CAR_EVER 1886

#define INVALID_NAME "Invalid name."
#define INVALID_YEAR "Invalid year."

class Review
{
    public:
        static bool reviewCompanyName (const string& companyName);
        static bool reviewVehicleName (const string& vehicleName);
        static bool reviewManufactureYear (int manufactureYear);
        static void reviewPointer (string file, int line, void *carPtr);

        Review();
        virtual ~Review();

};

#endif // REVIEW_H
