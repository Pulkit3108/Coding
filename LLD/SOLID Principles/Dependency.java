// Dependency Inversion Principle (DIP):
// --------------------------------------
// High-level modules should not depend on low-level modules. Both should depend on abstractions.
// Abstractions should not depend on details; details should depend on abstractions.
//
// In practice, this means:
// 1. Rather than having classes create their own concrete dependencies, provide (inject) these dependencies
//    from the outside—typically via constructor injection or parameter injection.
// 2. This inversion decouples business logic (high-level modules) from implementation details (low-level modules),
//    making your code more flexible, testable, and maintainable.
//
// Benefits include:
// - **Flexibility:** Change behavior at runtime by swapping implementations without rewriting classes.
// - **Reusability:** Promote composition over inheritance by relying on abstractions rather than concrete types.
// - **Testability:** Isolate units by injecting mocks or stubs, avoiding hidden dependencies and unpredictable behavior.
//
// Example:
// Instead of having a Cat class instantiate its own SpeakingBehavior (e.g., CatSpeakingBehavior),
// inject an ISpeakingBehavior via the constructor. This allows the Cat class to operate
// independently of any specific speaking behavior and makes it easy to substitute different behaviors,
// whether for new requirements or unit testing.


// High-level module
class NotificationService {
    private MessageSender messageSender;

    public NotificationService(MessageSender messageSender) {
        this.messageSender = messageSender;
    }

    public void sendNotification(String message) {
        messageSender.sendMessage(message);
    }
}

// Abstraction
interface MessageSender {
    void sendMessage(String message);
}

// Low-level module 1
class EmailSender implements MessageSender {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending email with message: " + message);
    }
}

// Low-level module 2
class SMSSender implements MessageSender {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending SMS with message: " + message);
    }
}

// Client
class DependencyInversionPrincipleExample {
    public static void main(String[] args) {
        MessageSender emailSender = new EmailSender();
        NotificationService emailNotification = new NotificationService(emailSender);
        emailNotification.sendNotification("Hello via Email!");

        MessageSender smsSender = new SMSSender();
        NotificationService smsNotification = new NotificationService(smsSender);
        smsNotification.sendNotification("Hello via SMS!");
    }
}