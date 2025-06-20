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

# Memento(Snapshot)
The Memento Design Pattern is a behavioral pattern that allows you to capture and restore an object's internal state without violating encapsulation.

**Real-world Analogy**
Think of undo in a text editor. Every time you make a change, the app saves the current state. When you press undo, the app restores a previous state — that’s the Memento pattern in action.

**Participants**
Originator – The object whose state needs to be saved/restored.
Memento – A value object that stores the state of the Originator.
Caretaker – Manages and keeps track of Mementos (but doesn’t modify or examine them).

