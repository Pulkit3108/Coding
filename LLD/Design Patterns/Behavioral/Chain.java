// Chain of Responsibility Design Pattern: Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.
// Use the Chain of Responsibility pattern when:
// 1. More than one object may handle a request, and the handler isn't known a priori. The handler should be ascertained automatically.
// 2. You want to issue a request to one of several objects without specifying the receiver explicitly.
// 3. The set of objects that can handle a request should be specified dynamically.
// 4. You don't want to specify a receiver explicitly in your code.
// 5. The request isn't handled by any handler.
// Example: A help desk system where a request is sent to a chain of handlers such as a general support team, a technical support team, and a billing team.

// Handler interface
abstract class Handler {
    protected Handler nextHandler;

    public void setNextHandler(Handler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public abstract void handleRequest(String request);
}

// ConcreteHandler1
class GeneralSupportHandler extends Handler {
    @Override
    public void handleRequest(String request) {
        if (request.equals("general")) {
            System.out.println("GeneralSupportHandler handling request: " + request);
        } else if (nextHandler != null) {
            nextHandler.handleRequest(request);
        }
    }
}

// ConcreteHandler2
class TechnicalSupportHandler extends Handler {
    @Override
    public void handleRequest(String request) {
        if (request.equals("technical")) {
            System.out.println("TechnicalSupportHandler handling request: " + request);
        } else if (nextHandler != null) {
            nextHandler.handleRequest(request);
        }
    }
}

// ConcreteHandler3
class BillingSupportHandler extends Handler {
    @Override
    public void handleRequest(String request) {
        if (request.equals("billing")) {
            System.out.println("BillingSupportHandler handling request: " + request);
        } else if (nextHandler != null) {
            nextHandler.handleRequest(request);
        }
    }
}

// Client
class ChainOfResponsibilityExample {
    public static void main(String[] args) {
        Handler generalSupport = new GeneralSupportHandler();
        Handler technicalSupport = new TechnicalSupportHandler();
        Handler billingSupport = new BillingSupportHandler();

        generalSupport.setNextHandler(technicalSupport);
        technicalSupport.setNextHandler(billingSupport);

        // Making requests
        generalSupport.handleRequest("general");
        generalSupport.handleRequest("technical");
        generalSupport.handleRequest("billing");
        generalSupport.handleRequest("unknown");
    }
}