Creational design patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

# Singleton
The Singleton Design Pattern ensures that only one instance of a class is created and provides a global point of access to that instance.

**Key Characteristics of Singleton:**
- Only one instance of the class is allowed.
- Global access to that instance.
- Useful for shared resources: logging, configuration manager, thread pool, etc.

**How to Implement a Singleton in C++**
- Private constructor: Prevent external instantiation.
- Static pointer/reference to instance.
- Public static method to access the instance.

**Drawbacks of Singleton:**
- Global state can make testing harder.
- Can hide dependencies.
- May lead to tight coupling.

# Factory
The Factory Design Pattern is a creational pattern that abstracts the process of object creation. Instead of instantiating objects directly using new, you delegate this responsibility to a factory class or method.

**When to Use the Factory Pattern**
- When the exact type of object is determined at runtime.
- When you want to decouple object creation from usage.
- When the object creation process is complex or repetitive.
- When a class can't anticipate which subclass to instantiate.

**Components of Factory Pattern**
- Product Interface (Abstract Class or Base Class)
- Concrete Products (Derived Classes)
- Factory (Creates and returns the correct product)
- Client (Uses the factory to create products)

**Disadvantages**
- May introduce extra classes and complexity
- Switching logic (if-else or switch) can grow large — consider Factory Registry or Abstract Factory in that case

# Abstract Factory
The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

**Components of Abstract Factory**
- AbstractFactory	- Declares creation methods for product families
- ConcreteFactory	- Implements creation methods for specific product variants
- AbstractProduct	- Interface for a type of product
- ConcreteProduct	- A Specific implementation of a product
- Client - Uses the factory to create products without knowing their concrete types

**Real-World Analogy**
A GUI toolkit supports different operating systems. Each OS has its own versions of buttons and scrollbars.
The abstract factory ensures you create compatible sets (e.g., WinButton + WinScrollbar or MacButton + MacScrollbar).


# Builder
# Prototype
