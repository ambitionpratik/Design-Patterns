/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<string>
#include<memory>

using namespace std;

class Computer{
string CPU{};
string RAM{};
string Storage{};

public:
void SetCpu(string cpu){CPU=cpu;}
void SetRam(string ram){RAM=ram;}
void SetStorage(string storage){Storage=storage;}
void show() const {
        std::cout << "cpmputer with " << CPU << ", " << RAM << ", and " << Storage << std::endl;}
};

class IcomputerBuilder{
    public:
    virtual void buildCpu() = 0;
    virtual void buildRam() = 0;
    virtual void buildStorage() = 0;
    virtual std::shared_ptr<Computer> GetComputer() = 0;
};

class GamePcBuilder : public IcomputerBuilder
{
    std::shared_ptr<Computer> computer = std::make_shared<Computer>();
    
    public:
    std::shared_ptr<Computer> GetComputer()
    {
        return computer;
    }
    virtual void buildCpu()
    {
        computer->SetCpu("HighEndCpu");
    }
    virtual void buildRam()
    {
          computer->SetRam("32Gb");
    }
    virtual void buildStorage(){
          computer->SetStorage("500Gb");
    }
};


class OfficePcBuilder : public IcomputerBuilder
{
    std::shared_ptr<Computer> computer = std::make_shared<Computer>();
    
    public:
    std::shared_ptr<Computer> GetComputer()
    {
        return computer;
    }
    virtual void buildCpu()
    {
        computer->SetCpu("LowEndCpu");
    }
    virtual void buildRam()
    {
          computer->SetRam("16Gb");
    }
    virtual void buildStorage(){
          computer->SetStorage("2Tb");
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
