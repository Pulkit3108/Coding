// Movie Ticket Booking System
// Features:
// 1. Users can view available movies, browse theaters and screens, select shows, book seats, and make payments.
// 2. The system supports concurrent seat bookings with thread safety.
// 3. Payment processing is simulated for simplicity.

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// Movie class
class Movie {
    private final String title;
    private final String genre;
    private final int duration; // in minutes

    public Movie(String title, String genre, int duration) {
        this.title = title;
        this.genre = genre;
        this.duration = duration;
    }

    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public int getDuration() {
        return duration;
    }
}

// Theater class
class Theater {
    private final String name;
    private final List<Screen> screens;

    public Theater(String name) {
        this.name = name;
        this.screens = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public List<Screen> getScreens() {
        return screens;
    }

    public void addScreen(Screen screen) {
        screens.add(screen);
    }
}

// Screen class
class Screen {
    private final int screenNumber;
    private final List<Show> shows;

    public Screen(int screenNumber) {
        this.screenNumber = screenNumber;
        this.shows = new ArrayList<>();
    }

    public int getScreenNumber() {
        return screenNumber;
    }

    public List<Show> getShows() {
        return shows;
    }

    public void addShow(Show show) {
        shows.add(show);
    }
}

// Show class
class Show {
    private final Movie movie;
    private final String showTime;
    private final List<Seat> seats;

    public Show(Movie movie, String showTime, int totalSeats) {
        this.movie = movie;
        this.showTime = showTime;
        this.seats = new ArrayList<>();
        for (int i = 1; i <= totalSeats; i++) {
            seats.add(new Seat(i));
        }
    }

    public Movie getMovie() {
        return movie;
    }

    public String getShowTime() {
        return showTime;
    }

    public List<Seat> getSeats() {
        return seats;
    }
}

// Seat class
class Seat {
    private final int seatNumber;
    private boolean isBooked;
    private final Lock lock;

    public Seat(int seatNumber) {
        this.seatNumber = seatNumber;
        this.isBooked = false;
        this.lock = new ReentrantLock();
    }

    public int getSeatNumber() {
        return seatNumber;
    }

    public boolean isBooked() {
        return isBooked;
    }

    public boolean bookSeat() {
        lock.lock();
        try {
            if (!isBooked) {
                isBooked = true;
                return true;
            }
            return false;
        } finally {
            lock.unlock();
        }
    }
}

// Booking class
class Booking {
    private final Show show;
    private final List<Seat> bookedSeats;

    public Booking(Show show) {
        this.show = show;
        this.bookedSeats = new ArrayList<>();
    }

    public Show getShow() {
        return show;
    }

    public List<Seat> getBookedSeats() {
        return bookedSeats;
    }

    public boolean bookSeats(List<Integer> seatNumbers) {
        for (int seatNumber : seatNumbers) {
            Seat seat = show.getSeats().get(seatNumber - 1);
            if (!seat.bookSeat()) {
                return false; // Booking failed, seat already booked
            }
            bookedSeats.add(seat);
        }
        return true; // Booking successful
    }
}

// Payment class
class Payment {
    public static boolean processPayment(double amount) {
        System.out.println("Processing payment of $" + amount);
        return true; // Simulate successful payment
    }
}

// Client
class MovieTicketBookingSystem {
    public static void main(String[] args) {
        // Create movies
        Movie inception = new Movie("Inception", "Sci-Fi", 148);
        Movie darkKnight = new Movie("The Dark Knight", "Action", 152);

        // Create theaters
        Theater amcTheater = new Theater("AMC");
        Theater regalTheater = new Theater("Regal");

        // Create screens
        Screen screen1 = new Screen(1);
        Screen screen2 = new Screen(2);

        // Add screens to theaters
        amcTheater.addScreen(screen1);
        regalTheater.addScreen(screen2);

        // Create shows
        Show show1 = new Show(inception, "10:00 AM", 100);
        Show show2 = new Show(darkKnight, "1:00 PM", 100);

        // Add shows to screens
        screen1.addShow(show1);
        screen2.addShow(show2);

        // Book seats
        Booking booking1 = new Booking(show1);
        List<Integer> seatsToBook = List.of(1, 2, 3);
        if (booking1.bookSeats(seatsToBook)) {
            System.out.println("Seats booked successfully for " + show1.getMovie().getTitle() + " at " + show1.getShowTime());
            Payment.processPayment(seatsToBook.size() * 10.0); // Assume $10 per seat
        } else {
            System.out.println("Failed to book seats for " + show1.getMovie().getTitle() + " at " + show1.getShowTime());
        }
    }
}