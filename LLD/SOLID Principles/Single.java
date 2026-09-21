// Single Responsibility Principle: A class should have only one reason to change.
// Use the Single Responsibility Principle when:
// 1. You want to ensure that a class has only one responsibility.
// 2. You want to make your code more maintainable and understandable.
// 3. You want to reduce the impact of changes in your code.


// Class responsible for handling user data
class User {
    private String name;
    private String email;

    public User(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}

// Class responsible for user validation
class UserValidator {
    public boolean validate(User user) {
        return user.getEmail().contains("@");
    }
}

// Class responsible for user persistence
class UserRepository {
    public void save(User user) {
        // Code to save user to a database
        System.out.println("User " + user.getName() + " saved to the database.");
    }
}

// Client
class SingleResponsibilityPrincipleExample {
    public static void main(String[] args) {
        User user = new User("John Doe", "john.doe@example.com");
        UserValidator validator = new UserValidator();
        UserRepository repository = new UserRepository();

        if (validator.validate(user)) {
            repository.save(user);
        } else {
            System.out.println("User " + user.getName() + " is not valid.");
        }
    }
}