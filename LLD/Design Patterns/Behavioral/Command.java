// Command Pattern: Encapsulate a request as an object, thereby letting you parameterize clients with queues, requests, and operations.
// Use the Command pattern when:
// 1. You want to parameterize objects with operations.
// 2. You want to specify, queue, and execute requests at different times.
// 3. You want to support undoable operations.
// 4. You want to support logging changes so that they can be reapplied in case of a system crash.
// 5. You want to structure a system around high-level operations built on primitive operations.
// Example: A remote control that can turn on and off different devices.

// Command interface
interface Command {
    void execute();
    void undo();
}

// ConcreteCommand for turning on a light
class LightOnCommand implements Command {
    private Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.on();
    }

    @Override
    public void undo() {
        light.off();
    }
}

// ConcreteCommand for turning off a light
class LightOffCommand implements Command {
    private Light light;

    public LightOffCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.off();
    }

    @Override
    public void undo() {
        light.on();
    }
}

// Receiver class
class Light {
    public void on() {
        System.out.println("The light is on");
    }

    public void off() {
        System.out.println("The light is off");
    }
}

// Invoker class
class RemoteControl {
    private Command command;

    public void setCommand(Command command) {
        this.command = command;
    }

    public void pressButton() {
        command.execute();
    }

    public void pressUndo() {
        command.undo();
    }
}

// Client
class CommandPatternExample {
    public static void main(String[] args) {
        Light livingRoomLight = new Light();

        Command lightOn = new LightOnCommand(livingRoomLight);
        Command lightOff = new LightOffCommand(livingRoomLight);

        RemoteControl remote = new RemoteControl();

        // Turn the light on
        remote.setCommand(lightOn);
        remote.pressButton();

        // Turn the light off
        remote.setCommand(lightOff);
        remote.pressButton();

        // Undo the last operation (turn the light back on)
        remote.pressUndo();
    }
}