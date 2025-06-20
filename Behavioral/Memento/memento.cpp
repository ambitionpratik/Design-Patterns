#include <iostream>
#include <string>
#include <stack>

// Memento class (stores state)
class Memento {
    std::string state;

public:
    Memento(const std::string& s) : state(s) {}
    std::string getState() const { return state; }
};

// Originator class (creates and restores Mementos)
class TextEditor {
    std::string text;

public:
    void type(const std::string& newText) {
        text += newText;
    }

    std::string getText() const {
        return text;
    }

    void showText() const {
        std::cout << "Current Text: " << text << std::endl;
    }

    Memento save() const {
        return Memento(text); // Save current state
    }

    void restore(const Memento& memento) {
        text = memento.getState(); // Restore state
    }
};

// Caretaker class (manages mementos)
class History {
    std::stack<Memento> backups;

public:
    void backup(const Memento& m) {
        backups.push(m);
    }

    Memento undo() {
        if (backups.empty()) {
            throw std::runtime_error("No backups!");
        }
        Memento m = backups.top();
        backups.pop();
        return m;
    }

    bool hasHistory() const {
        return !backups.empty();
    }
};

// Client code
int main() {
    TextEditor editor;
    History history;

    editor.type("Hello ");
    history.backup(editor.save());

    editor.type("World!");
    history.backup(editor.save());

    editor.showText();

    std::cout << "\nUndoing...\n";
    if (history.hasHistory()) editor.restore(history.undo());

    editor.showText();

    std::cout << "\nUndoing again...\n";
    if (history.hasHistory()) editor.restore(history.undo());

    editor.showText();

    return 0;
}
