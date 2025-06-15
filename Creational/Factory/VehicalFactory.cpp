/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

#include <iostream>
#include <memory>
using namespace std;

class IVehicle 
{
public:
    virtual void VehicleType() = 0;
    virtual ~IVehicle() {}
};

class TwoWheeler : public IVehicle
{
public:
    void VehicleType() override { cout << "Two Wheeler" << endl; }
};

class FourWheeler : public IVehicle
{
public:
    void VehicleType() override { cout << "Four Wheeler" << endl; }
};

class VehicleFactory
{
public:
    static unique_ptr<IVehicle> CreateVehicle(int wheel)
    {
        if (wheel == 2)
            return make_unique<TwoWheeler>();
        else if (wheel == 4)
            return make_unique<FourWheeler>();
        return nullptr;
    }
};

int main()
{
    auto vehicle1 = VehicleFactory::CreateVehicle(2);
    if (vehicle1) vehicle1->VehicleType();

    auto vehicle2 = VehicleFactory::CreateVehicle(4);
    if (vehicle2) vehicle2->VehicleType();

    return 0;
}
