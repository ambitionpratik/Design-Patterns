/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class RAM {
    string type;
public:
    RAM(string t): type(std::move(t)) {}
    string Info() const { return "RAM: " + type; }
};

class Storage {
    string size;
public:
    Storage(string s): size(std::move(s)) {}
    string Info() const { return "Storage: " + size; }
};

class CPU {
    string model;
public:
    CPU(string m): model(std::move(m)) {}
    string Info() const { return "CPU: " + model; }
};

class Computer {
    unique_ptr<CPU> cpu;
    unique_ptr<RAM> ram;
    unique_ptr<Storage> storage;

public:
    void SetCpu(unique_ptr<CPU> c) { cpu = std::move(c); }
    void SetRam(unique_ptr<RAM> r) { ram = std::move(r); }
    void SetStorage(unique_ptr<Storage> s) { storage = std::move(s); }

    void show() const {
        cout << cpu->Info() << ", " << ram->Info() << ", " << storage->Info() << "\n";
    }
};

class IcomputerBuilder{
    public:
    virtual void buildCpu() = 0;
    virtual void buildRam() = 0;
    virtual void buildStorage() = 0;
    virtual std::shared_ptr<Computer> GetComputer() = 0;
};

class GamePcBuilder : public IcomputerBuilder {
    shared_ptr<Computer> computer = make_shared<Computer>();
public:
    void buildCpu() override {
        computer->SetCpu(make_unique<CPU>("Intel i9"));
    }
    void buildRam() override {
        computer->SetRam(make_unique<RAM>("32GB DDR5"));
    }
    void buildStorage() override {
        computer->SetStorage(make_unique<Storage>("1TB NVMe"));
    }
    shared_ptr<Computer> GetComputer() override {
        return computer;
    }
};

class OfficePcBuilder : public IcomputerBuilder {
    shared_ptr<Computer> computer = make_shared<Computer>();
public:
    void buildCpu() override {
        computer->SetCpu(make_unique<CPU>("Intel i5"));
    }
    void buildRam() override {
        computer->SetRam(make_unique<RAM>("12GB DDR5"));
    }
    void buildStorage() override {
        computer->SetStorage(make_unique<Storage>("2TB NVMe"));
    }
    shared_ptr<Computer> GetComputer() override {
        return computer;
    }
};


class Technician{
    public:
    void MakeComputer(IcomputerBuilder& computerBuilder)
    {
        computerBuilder.buildCpu();
        computerBuilder.buildRam();
        computerBuilder.buildStorage();
    }
};

int main()
{
    Technician technician{};
    
    GamePcBuilder gmPcBuilder{};
    
    technician.MakeComputer(gmPcBuilder);
    auto computer = gmPcBuilder.GetComputer();
    computer->show();

    return 0;
}
