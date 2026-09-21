// Mediator Pattern: Define an object that encapsulates how a set of objects interact. Mediator promotes loose coupling by keeping objects from referring to each other explicitly, and it lets you vary their interaction independently.
// Use the Mediator pattern when:
// 1. A set of objects communicate in well-defined but complex ways. The resulting interdependencies are unstructured and difficult to understand.
// 2. Reusing an object is difficult because it refers to and communicates with many other objects.
// 3. A behavior that's distributed between several classes should be customizable without a lot of subclassing.
// 4. A set of related classes behave as a single unit.
// 5. An interaction between many objects should be encapsulated in a separate object.
// Example: A chat room where multiple users can send messages to each other. The chat room acts as a mediator between the users.

import java.util.ArrayList;
import java.util.List;

// Mediator interface
interface ChatMediator {
    void sendMessage(String message, User user);
    void addUser(User user);
}

// ConcreteMediator
class ChatRoom implements ChatMediator {
    private List<User> users;

    public ChatRoom() {
        this.users = new ArrayList<>();
    }

    @Override
    public void addUser(User user) {
        this.users.add(user);
    }

    @Override
    public void sendMessage(String message, User user) {
        for (User u : this.users) {
            // Message should not be received by the user sending it
            if (u != user) {
                u.receive(message);
            }
        }
    }
}

// Colleague
abstract class User {
    protected ChatMediator mediator;
    protected String name;

    public User(ChatMediator mediator, String name) {
        this.mediator = mediator;
        this.name = name;
    }

    public abstract void send(String message);
    public abstract void receive(String message);
}

// ConcreteColleague1
class UserImpl extends User {
    public UserImpl(ChatMediator mediator, String name) {
        super(mediator, name);
    }

    @Override
    public void send(String message) {
        System.out.println(this.name + " sends: " + message);
        mediator.sendMessage(message, this);
    }

    @Override
    public void receive(String message) {
        System.out.println(this.name + " receives: " + message);
    }
}

// Client
class MediatorPatternExample {
    public static void main(String[] args) {
        ChatMediator chatMediator = new ChatRoom();

        User user1 = new UserImpl(chatMediator, "Alice");
        User user2 = new UserImpl(chatMediator, "Bob");
        User user3 = new UserImpl(chatMediator, "Charlie");
        User user4 = new UserImpl(chatMediator, "David");

        chatMediator.addUser(user1);
        chatMediator.addUser(user2);
        chatMediator.addUser(user3);
        chatMediator.addUser(user4);

        user1.send("Hello, everyone!");
    }
}