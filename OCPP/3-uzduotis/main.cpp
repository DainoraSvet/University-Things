#include "car.h"

using namespace std;
using namespace car;

int main()
{
    try
    {
        /*first example*/
        Car firstCar;

        firstCar.setCompanyName ("BMW");
        firstCar.setVehicleBodyType ("Coupe");
        firstCar.setManufactureYear (2015);
        cout << firstCar.toString() << endl;

        try
        {
            /*second example*/
            Car *secondCar = new Car[2];

            secondCar[0].setCompanyName ("TOYOTA");
            secondCar[0].setVehicleBodyType ("Sedan");
            secondCar[0].setManufactureYear (2019);
            cout << secondCar[0].toString() << endl;

            secondCar[1].setCompanyName ("suBaru");/*throw exception*/
            secondCar[1].setVehicleBodyType ("Hatchback");
            secondCar[1].setManufactureYear (1999);
            cout << secondCar[1].toString() << endl;

            delete[] secondCar;
        }
        catch (invalid_argument& e)
        {
            cout << e.what() << endl << endl;
        }

        /*third example*/
        Car forthCar ("KIA", "Jeep", 2000);

        cout << forthCar.toString() << endl;

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
