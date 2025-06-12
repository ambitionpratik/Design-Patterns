// Button interface
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

// Checkbox interface
class Checkbox {
public:
    virtual void toggle() = 0;
    virtual ~Checkbox() = default;
};

// Concrete classes

// Windows variants
class WindowsButton : public Button {
public:
    void paint() override {
        std::cout << "Rendering Windows Button\n";
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void toggle() override {
        std::cout << "Toggling Windows Checkbox\n";
    }
};

// Mac variants
class MacButton : public Button {
public:
    void paint() override {
        std::cout << "Rendering Mac Button\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void toggle() override {
        std::cout << "Toggling Mac Checkbox\n";
    }
};

//Abstract Factory

class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Factories
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WindowsButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<WindowsCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<MacCheckbox>();
    }
};

void renderUI(std::unique_ptr<GUIFactory> factory) {
    auto button = factory->createButton();
    auto checkbox = factory->createCheckbox();

    button->paint();
    checkbox->toggle();
}

int main() {
    // Dynamically select platform
    std::unique_ptr<GUIFactory> factory;

    std::string os = "Windows";  // Could come from config/env

    if (os == "Windows") {
        factory = std::make_unique<WindowsFactory>();
    } else {
        factory = std::make_unique<MacFactory>();
    }

    renderUI(std::move(factory));

    return 0;
}
