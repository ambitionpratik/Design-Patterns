#pragma once
#include <iostream>
using namespace std;

// Interface for the product
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// Concrete classes
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square\n";
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Triangle\n";
    }
};


// Factory implementation
class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(const string& shapeType) {
        if (shapeType == "circle") {
            return make_unique<Circle>();
        } else if (shapeType == "square") {
            return make_unique<Square>();
        } else if (shapeType == "triangle") {
            return make_unique<Triangle>();
        } else {
            return nullptr;
        }
    }
};


int main() {
    auto shape1 = ShapeFactory::createShape("circle");
    auto shape2 = ShapeFactory::createShape("square");
    auto shape3 = ShapeFactory::createShape("triangle");

    if (shape1) shape1->draw();
    if (shape2) shape2->draw();
    if (shape3) shape3->draw();

    return 0;
}
