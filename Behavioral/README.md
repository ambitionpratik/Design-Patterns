Behavioral design patterns are concerned with algorithms and the assignment of responsibilities between objects.

# Observer
The Observer Design Pattern is a behavioral pattern used to define a one-to-many dependency between objects. When one object (subject) changes its state, all its dependents (observers) are notified and updated automatically.

**Intent**
To establish a subscription mechanism to notify multiple objects about any events that happen to the object they’re observing.

**Real-World Analogy**
A YouTube channel is the subject. Users subscribe (observers). When a new video is uploaded (state changes), all subscribers are notified.

**Participants**

Subject (Observable) - Maintains a list of observers.
Has methods to attach, detach, and notify observers.

Observer (Subscriber) - Defines an update() interface to get notified.

ConcreteSubject - Stores the state and sends notifications on changes.

ConcreteObserver - Implements the update method to reflect subject state changes.

