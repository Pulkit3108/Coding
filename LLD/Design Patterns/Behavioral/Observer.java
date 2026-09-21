// Observer Pattern: Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
// Use the Observer pattern when:
// 1. An abstraction has two aspects, one dependent on the other. Encapsulating these aspects in separate objects lets you vary and reuse them independently.
// 2. A change to one object requires changing others, and you don't know how many objects need to be changed.
// 3. An object should be able to notify other objects without making assumptions about who these objects are. In other words, you don't want these objects tightly coupled.
// 4. An object should be able to notify other objects without knowing who these objects are. The Observer pattern lets any object that implements the subscriber interface subscribe for updates.
// 5. You have an object that needs to be updated by multiple other objects, but you don't want these objects tightly coupled to the object that needs updating.
// Example: A weather station that notifies weather data to multiple displays such as mobile, web, and desktop applications.

import java.util.ArrayList;
import java.util.List;

// Observer interface
interface Observer {
    void update(float temperature, float humidity, float pressure);
}

// ConcreteObserver1
class MobileDisplay implements Observer {
    @Override
    public void update(float temperature, float humidity, float pressure) {
        System.out.println("Mobile Display - Temperature: " + temperature + ", Humidity: " + humidity + ", Pressure: " + pressure);
    }
}

// ConcreteObserver2
class WebDisplay implements Observer {
    @Override
    public void update(float temperature, float humidity, float pressure) {
        System.out.println("Web Display - Temperature: " + temperature + ", Humidity: " + humidity + ", Pressure: " + pressure);
    }
}

// Subject interface
interface Subject {
    void registerObserver(Observer o);
    void removeObserver(Observer o);
    void notifyObservers();
}

// ConcreteSubject
class WeatherStation implements Subject {
    private List<Observer> observers;
    private float temperature;
    private float humidity;
    private float pressure;

    public WeatherStation() {
        observers = new ArrayList<>();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(temperature, humidity, pressure);
        }
    }

    public void setMeasurements(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        notifyObservers();
    }
}

// Client
class ObserverPatternExample {
    public static void main(String[] args) {
        WeatherStation weatherStation = new WeatherStation();

        Observer mobileDisplay = new MobileDisplay();
        Observer webDisplay = new WebDisplay();

        weatherStation.registerObserver(mobileDisplay);
        weatherStation.registerObserver(webDisplay);

        weatherStation.setMeasurements(25.5f, 65.0f, 1013.1f);
        weatherStation.setMeasurements(27.0f, 70.0f, 1012.5f);
    }
}