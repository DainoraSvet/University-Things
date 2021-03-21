#include "car.h"

using namespace std;

int main()
{
    try
    {
        /*first example*/
        Car firstCar;

        firstCar.setCompanyName ("BMW");
        firstCar.setVehicleBodyType ("Coupe");
        firstCar.setManufactureYear (2015);
        cout << firstCar << endl;

        /*second example*/
        Car secondCar;
        cout << "Write car Company name, Vehicle Body Type, Manufacture year: " << endl;
        cin >> secondCar;
        cout << secondCar << endl;

        cout << endl << "Operators: " << endl;
        cout << (firstCar < secondCar) << endl;
        cout << (firstCar > secondCar) << endl;
        cout << (firstCar == secondCar) << endl;
        cout << (firstCar != secondCar) << endl;
        cout << (firstCar <= secondCar) << endl;
        cout << (firstCar >= secondCar) << endl;


        ++secondCar;
        cout << endl << secondCar << endl;

        --firstCar;
        cout << endl << firstCar << endl;
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
