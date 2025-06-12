#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

using namespace std;

// Prototype Interface
class Shape {
public:
    virtual ~Shape() = default;
    virtual shared_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

// ConcretePrototype 1
class Circle : public Shape {
public:
    Circle(float r = 0.0f) : radius(r) {}

    shared_ptr<Shape> clone() const override {
        return make_shared<Circle>(*this);  // Copy constructor
    }

    void draw() const override {
        cout << "Drawing Circle with radius: " << radius << "\n";
    }

    void setRadius(float r) { radius = r; }

private:
    float radius;
};

// ConcretePrototype 2
class Rectangle : public Shape {
public:
    Rectangle(float w = 0.0f, float h = 0.0f) : width(w), height(h) {}

    shared_ptr<Shape> clone() const override {
        return make_shared<Rectangle>(*this);
    }

    void draw() const override {
        cout << "Drawing Rectangle [w: " << width << ", h: " << height << "]\n";
    }

    void setDimensions(float w, float h) {
        width = w;
        height = h;
    }

private:
    float width;
    float height;
};

// Prototype Factory
class ShapePrototypeFactory {
public:
    void registerShape(const string& key, shared_ptr<Shape> prototype) {
        prototypes[key] = prototype;
    }

    shared_ptr<Shape> createShape(const string& key) {
        if (prototypes.find(key) != prototypes.end()) {
            return prototypes[key]->clone();
        }
        return nullptr;
    }

private:
    unordered_map<string, shared_ptr<Shape>> prototypes;
};

// Client code
int main() {
    ShapePrototypeFactory factory;

    // Registering prototypes
    factory.registerShape("circle", make_shared<Circle>(10.5f));
    factory.registerShape("rectangle", make_shared<Rectangle>(5.0f, 8.0f));

    // Creating clones
    auto shape1 = factory.createShape("circle");
    auto shape2 = factory.createShape("rectangle");

    shape1->draw();  // Drawing Circle with radius: 10.5
    shape2->draw();  // Drawing Rectangle [w: 5.0, h: 8.0]

    return 0;
}
