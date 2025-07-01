// Concrete command
class ICommand {
public:
    virtual ~ICommand() {}
    virtual void Execute() = 0;
};

// Command implementation
class LightOnCommand : public ICommand {
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void Execute() override {
        light->On();
    }
};

class LightOffCommand : public ICommand {
    Light* light;
public:
    LightOffCommand(Light* l) : light(l) {}
    void Execute() override {
        light->Off();
    }
};

// Command receiver
class Light {
public:
    void On() { std::cout << "Light is ON\n"; }
    void Off() { std::cout << "Light is OFF\n"; }
};

// Command Invoker (Have the command and execute it)
class RemoteControl {
    ICommand* command;
public:
    void SetCommand(ICommand* cmd) {
        command = cmd;
    }
    void PressButton() {
        if (command) command->Execute();
    }
};

int main() {
    Light livingRoomLight;

    LightOnCommand onCmd(&livingRoomLight);
    LightOffCommand offCmd(&livingRoomLight);

    RemoteControl remote;

    remote.SetCommand(&onCmd);
    remote.PressButton(); // Output: Light is ON

    remote.SetCommand(&offCmd);
    remote.PressButton(); // Output: Light is OFF

    return 0;
}


