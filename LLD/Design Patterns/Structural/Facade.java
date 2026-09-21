// Facade Pattern: Provides a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.
// Use the Facade pattern when:
// 1. You want to provide a simple interface to a complex subsystem.
// 2. There are many dependencies between clients and the implementation classes of an abstraction.
// 3. You want to layer your subsystems to minimize communication and dependencies between them.
// Example: A home theater system with various components like DVD player, projector, and sound system. The Facade provides a simple interface to control all these components.


// Subsystem class 1
class DVDPlayer {
    public void on() {
        System.out.println("DVD Player is on");
    }

    public void play(String movie) {
        System.out.println("Playing movie: " + movie);
    }

    public void off() {
        System.out.println("DVD Player is off");
    }
}

// Subsystem class 2
class Projector {
    public void on() {
        System.out.println("Projector is on");
    }

    public void off() {
        System.out.println("Projector is off");
    }

    public void wideScreenMode() {
        System.out.println("Projector in widescreen mode");
    }
}

// Subsystem class 3
class SoundSystem {
    public void on() {
        System.out.println("Sound System is on");
    }

    public void setVolume(int level) {
        System.out.println("Setting volume to " + level);
    }

    public void off() {
        System.out.println("Sound System is off");
    }
}

// Facade class
class HomeTheaterFacade {
    private DVDPlayer dvdPlayer;
    private Projector projector;
    private SoundSystem soundSystem;

    public HomeTheaterFacade(DVDPlayer dvdPlayer, Projector projector, SoundSystem soundSystem) {
        this.dvdPlayer = dvdPlayer;
        this.projector = projector;
        this.soundSystem = soundSystem;
    }

    public void watchMovie(String movie) {
        System.out.println("Get ready to watch a movie...");
        dvdPlayer.on();
        dvdPlayer.play(movie);
        projector.on();
        projector.wideScreenMode();
        soundSystem.on();
        soundSystem.setVolume(5);
    }

    public void endMovie() {
        System.out.println("Shutting movie theater down...");
        dvdPlayer.off();
        projector.off();
        soundSystem.off();
    }
}

// Client
class FacadePatternExample {
    public static void main(String[] args) {
        DVDPlayer dvdPlayer = new DVDPlayer();
        Projector projector = new Projector();
        SoundSystem soundSystem = new SoundSystem();

        HomeTheaterFacade homeTheater = new HomeTheaterFacade(dvdPlayer, projector, soundSystem);

        homeTheater.watchMovie("Inception");
        homeTheater.endMovie();
    }
}
