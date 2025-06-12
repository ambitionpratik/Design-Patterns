#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Product
class House {
public:
    void setBasement(const string& basement) { this->basement = basement; }
    void setStructure(const string& structure) { this->structure = structure; }
    void setRoof(const string& roof) { this->roof = roof; }
    void setInterior(const string& interior) { this->interior = interior; }

    void show() const {
        cout << "House with:\n";
        cout << "Basement: " << basement << "\n";
        cout << "Structure: " << structure << "\n";
        cout << "Roof: " << roof << "\n";
        cout << "Interior: " << interior << "\n";
    }

private:
    string basement;
    string structure;
    string roof;
    string interior;
};

// Builder Interface
class HouseBuilder {
public:
    virtual ~HouseBuilder() = default;
    virtual void buildBasement() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual void buildInterior() = 0;
    virtual shared_ptr<House> getHouse() = 0;
};

// Concrete Builder 1
class IglooHouseBuilder : public HouseBuilder {
public:
    IglooHouseBuilder() { house = make_shared<House>(); }

    void buildBasement() override {
        house->setBasement("Ice Bars");
    }
    void buildStructure() override {
        house->setStructure("Ice Blocks");
    }
    void buildRoof() override {
        house->setRoof("Ice Dome");
    }
    void buildInterior() override {
        house->setInterior("Ice Carvings");
    }
    shared_ptr<House> getHouse() override {
        return house;
    }

private:
    shared_ptr<House> house;
};

// Concrete Builder 2
class WoodenHouseBuilder : public HouseBuilder {
public:
    WoodenHouseBuilder() { house = make_shared<House>(); }

    void buildBasement() override {
        house->setBasement("Concrete Slab");
    }
    void buildStructure() override {
        house->setStructure("Wooden Walls");
    }
    void buildRoof() override {
        house->setRoof("Wood Shingles");
    }
    void buildInterior() override {
        house->setInterior("Wooden Decor");
    }
    shared_ptr<House> getHouse() override {
        return house;
    }

private:
    shared_ptr<House> house;
};

// Director
class Director {
public:
    void setBuilder(shared_ptr<HouseBuilder> builder) {
        this->builder = builder;
    }

    void constructHouse() {
        builder->buildBasement();
        builder->buildStructure();
        builder->buildRoof();
        builder->buildInterior();
    }

private:
    shared_ptr<HouseBuilder> builder;
};

// Client Code
int main() {
    Director director;

    auto iglooBuilder = make_shared<IglooHouseBuilder>();
    director.setBuilder(iglooBuilder);
    director.constructHouse();
    iglooBuilder->getHouse()->show();

    cout << "-----------------------------\n";

    auto woodenBuilder = make_shared<WoodenHouseBuilder>();
    director.setBuilder(woodenBuilder);
    director.constructHouse();
    woodenBuilder->getHouse()->show();

    return 0;
}
