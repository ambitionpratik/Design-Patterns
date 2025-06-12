Creational design patterns provide various object creation mechanisms, which increase flexibility and reuse of existing code.

#Singleton
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

- **Factory**
- **Abstract Factory**
- **Builder**
- **Prototype**
