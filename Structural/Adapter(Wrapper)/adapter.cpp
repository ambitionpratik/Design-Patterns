#include <iostream>
#include <memory>

/// Target interface (what client expects)
class Printer {
public:
    virtual void print() const = 0;
    virtual ~Printer() = default;
};

/// Adaptee class (incompatible interface)
class OldPrinter {
public:
    void printText() const {
        std::cout << "Printing using OldPrinter\n";
    }
};

/// Adapter class (wraps OldPrinter)
class PrinterAdapter : public Printer {
private:
    std::shared_ptr<OldPrinter> oldPrinter;

public:
    PrinterAdapter(std::shared_ptr<OldPrinter> printer)
        : oldPrinter(std::move(printer)) {}

    void print() const override {
        oldPrinter->printText(); // Translate to expected interface
    }
};

/// Client code
void clientCode(const Printer& printer) {
    printer.print();
}

int main() {
    std::shared_ptr<OldPrinter> old = std::make_shared<OldPrinter>();
    PrinterAdapter adapter(old);

    clientCode(adapter);  // Works even though OldPrinter is incompatible!
    return 0;
}
