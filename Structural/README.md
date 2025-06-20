Structural design patterns explain how to assemble objects and classes into larger structures, while keeping these structures flexible and efficient.

**Adapter(Wrapper)**
The Adapter Design Pattern is a structural pattern used to bridge the gap between two incompatible interfaces. It acts as a wrapper that allows objects with incompatible interfaces to work together.
**Intent**
- Convert the interface of a class into another interface clients expect.
- Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces.

**Participants**
- Target (Client Interface) – the interface the client expects.
- Adaptee – the existing interface/class that needs adapting.
- Adapter – translates the Target interface into Adaptee's.

**When to Use**
- You want to use an existing class, but its interface doesn't match the one you need.
- You want to reuse a class that doesn’t implement an interface you require.

