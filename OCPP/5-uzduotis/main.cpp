#include "car.h"
#include "Check.h"

using namespace std;
using namespace MyCar;

int main()
{
    try
    {
        /*first example*/
        Car firstCar ("BMW", "Coupe", 2015);
        Car secondCar ("Tesla", "Sedan", 2021);
        Car thirdCar ("Mazda", "Universal", 2009);
        Car forthCar;

        cout << firstCar << endl;
        cout << secondCar << endl;
        cout << thirdCar << endl;

        cout << "First car company name: " << firstCar.getCompanyName () << endl;
        cout << "Second car vehicle name: " << firstCar.getVehicleName () << endl;
        cout << "Third car manufacture year: " << firstCar.getManufactureYear () << endl;

        forthCar.setCompanyName ("Toyota");
        forthCar.setVehicleName ("Sedan");
        forthCar.setManufactureYear (2003);

        cout << endl << forthCar << endl;

    }
    catch (invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "Any exception." << endl;
    }

    return 0;
}
