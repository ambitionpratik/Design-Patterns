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
The Builder Design Pattern is a creational design pattern that separates the construction of a complex object from its representation so that the same construction process can create different representations.

**When to Use Builder Pattern:**
- When the creation of an object involves many steps or configurations.
- When you want to construct different representations of the same type of object.
- When constructors with many parameters become hard to manage (especially optional ones).

**Participants in the Builder Pattern:**
- Product: The complex object under construction.
- Builder: Abstract interface to define steps for building the product.
- ConcreteBuilder: Implements the builder interface and provides specific parts of the product.
- Director: Controls the building process using a builder.
- Client: Uses the director and builder to create the product.

**Advantages of Builder Pattern:**
- Better control over the construction process.
- Supports different representations of an object.
- Avoids telescoping constructor anti-pattern.
- Encapsulates the building logic in separate builder classes.


# Prototype
The Prototype Design Pattern is a creational pattern that allows you to create new objects by copying an existing object, known as the prototype, instead of creating from scratch using constructors.

**Intent:**
- Create new objects by copying existing ones, instead of instantiating new objects directly. It helps improve performance when object creation is expensive.

**Use Cases:**
- When object creation is costly (e.g., database operations, network fetch).
- When you want to keep object creation logic hidden.
- When you want to create clones of objects at runtime.

**Structure:**
- Prototype (interface): Declares a clone() method.
- ConcretePrototype: Implements the clone() method.
- Factory: Holds constructed objects
- Client: Clones objects using the prototype interface.

**Advantages of Prototype Pattern:**
- Avoids costly object creation.
- Cloning can be faster than creating a new object via constructor.
- Reduces subclassing and factory logic.
- Easy to add or remove new prototypes at runtime.

**Caveats:**
- Deep copy vs shallow copy complexity.
- Object graph with circular references may require careful handling.
- Requires careful implementation of clone() to avoid slicing and memory issues.
