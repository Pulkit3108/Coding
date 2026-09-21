// Memento Pattern: This pattern is used to restore the state of an object to a previous state.
// Use the Memento Pattern when:
// 1. You want to save and restore the state of an object.
// 2. You want to provide a way to rollback changes.
// 3. You want to preserve encapsulation boundaries.
// 4. You want to avoid exposing the internal state of an object directly.
// Example: A text editor that allows you to undo and redo changes.

import java.util.Stack;

// Originator
class Originator {
    private String state;

    public void setState(String state) {
        this.state = state;
        System.out.println("State set to: " + state);
    }

    public String getState() {
        return state;
    }

    public Memento saveStateToMemento() {
        return new Memento(state);
    }

    public void getStateFromMemento(Memento memento) {
        state = memento.getState();
    }

    // Memento
    public static class Memento {
        private final String state;

        public Memento(String state) {
            this.state = state;
        }

        private String getState() {
            return state;
        }
    }
}

// Caretaker
class Caretaker {
    private Stack<Originator.Memento> mementoStack = new Stack<>();

    public void addMemento(Originator.Memento memento) {
        mementoStack.push(memento);
    }

    public Originator.Memento getMemento() {
        return mementoStack.pop();
    }
}

// Client
class MementoPatternExample {
    public static void main(String[] args) {
        Originator originator = new Originator();
        Caretaker caretaker = new Caretaker();

        originator.setState("State #1");
        caretaker.addMemento(originator.saveStateToMemento());

        originator.setState("State #2");
        caretaker.addMemento(originator.saveStateToMemento());

        originator.setState("State #3");
        System.out.println("Current State: " + originator.getState());

        originator.getStateFromMemento(caretaker.getMemento());
        System.out.println("Restored to State: " + originator.getState());

        originator.getStateFromMemento(caretaker.getMemento());
        System.out.println("Restored to State: " + originator.getState());
    }
}