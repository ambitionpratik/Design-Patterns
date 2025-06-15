#include <iostream>
#include <memory>
#include <string>
using namespace std;

// === Abstract Product ===
class IVehicle {
public:
    virtual void VehicleType() = 0;
    virtual ~IVehicle() {}
};

// === Concrete Products ===
class HeroTwoWheeler : public IVehicle {
public:
    void VehicleType() override { cout << "Hero Two Wheeler" << endl; }
};

class HeroFourWheeler : public IVehicle {
public:
    void VehicleType() override { cout << "Hero Four Wheeler" << endl; }
};

class HondaTwoWheeler : public IVehicle {
public:
    void VehicleType() override { cout << "Honda Two Wheeler" << endl; }
};

class HondaFourWheeler : public IVehicle {
public:
    void VehicleType() override { cout << "Honda Four Wheeler" << endl; }
};

// === Abstract Factory Interface ===
class IVehicleFactory {
public:
    virtual unique_ptr<IVehicle> CreateTwoWheeler() = 0;
    virtual unique_ptr<IVehicle> CreateFourWheeler() = 0;
    virtual ~IVehicleFactory() {}
};

// === Concrete Factories ===
class HeroFactory : public IVehicleFactory {
public:
    unique_ptr<IVehicle> CreateTwoWheeler() override {
        return make_unique<HeroTwoWheeler>();
    }

    unique_ptr<IVehicle> CreateFourWheeler() override {
        return make_unique<HeroFourWheeler>();
    }
};

class HondaFactory : public IVehicleFactory {
public:
    unique_ptr<IVehicle> CreateTwoWheeler() override {
        return make_unique<HondaTwoWheeler>();
    }

    unique_ptr<IVehicle> CreateFourWheeler() override {
        return make_unique<HondaFourWheeler>();
    }
};

// === Factory Provider (Abstract Factory Manager) ===
class IVehicleFactoryProvider {
public:
    static unique_ptr<IVehicleFactory> GetFactory(const string& brand) {
        if (brand == "hero") {
            return make_unique<HeroFactory>();
        } else if (brand == "honda") {
            return make_unique<HondaFactory>();
        }
        return nullptr;
    }
};

// === Client Code ===
int main() {
    auto factory = IVehicleFactoryProvider::GetFactory("hero");
    if (factory) {
        auto v1 = factory->CreateTwoWheeler();
        v1->VehicleType();
        auto v2 = factory->CreateFourWheeler();
        v2->VehicleType();
    }

    factory = IVehicleFactoryProvider::GetFactory("honda");
    if (factory) {
        auto v3 = factory->CreateTwoWheeler();
        v3->VehicleType();
        auto v4 = factory->CreateFourWheeler();
        v4->VehicleType();
    }

    return 0;
}
