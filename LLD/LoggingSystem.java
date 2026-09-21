// Low-Level Design: Logging System 📝

// A Logging System is designed to efficiently capture, filter, and output application events with varying levels of severity. 
// The system supports multiple log levels, formatting options, destinations, and filtering capabilities while maintaining a clean separation of concerns. 
// It is extensible, allowing for new log handlers, formatters, and destinations to be easily integrated.

// Features:
// • Multiple log levels (DEBUG, INFO, WARNING, ERROR, FATAL)
// • Logs with attributes like timestamp, level, message, and context data
// • Routing logs to different destinations based on level and content
// • Level-based filtering to control which logs are processed
// • Formatting options for different output destinations
// • Support for multiple output destinations (console, file, network, etc.)
// • Context enrichment to add additional information to log entries
// • Chain of Responsibility for log processing
// • Singleton Logger for centralized logging

import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.concurrent.ConcurrentHashMap;

// ----- Log Level Enum -----
enum LogLevel {
    DEBUG(1), INFO(2), WARNING(3), ERROR(4), FATAL(5);

    private final int severity;

    LogLevel(int severity) {
        this.severity = severity;
    }

    public int getSeverity() {
        return severity;
    }

    public boolean isGreaterOrEqual(LogLevel other) {
        return this.severity >= other.severity;
    }
}

// ----- Log Message Class -----
class LogMessage {
    private final LogLevel level;
    private final String message;
    private final long timestamp;

    public LogMessage(LogLevel level, String message) {
        this.level = level;
        this.message = message;
        this.timestamp = System.currentTimeMillis();
    }

    public LogLevel getLevel() {
        return level;
    }

    public String getMessage() {
        return message;
    }

    public long getTimestamp() {
        return timestamp;
    }

    @Override
    public String toString() {
        return String.format("[%s] %s - %s", level, new Date(timestamp), message);
    }
}

// ----- Log Formatter Interface & Implementations -----
interface LogFormatter {
    String format(LogMessage logMessage);
}

class SimpleLogFormatter implements LogFormatter {
    @Override
    public String format(LogMessage logMessage) {
        return String.format("[%s] %s: %s", new Date(logMessage.getTimestamp()), logMessage.getLevel(), logMessage.getMessage());
    }
}

class JsonLogFormatter implements LogFormatter {
    @Override
    public String format(LogMessage logMessage) {
        return String.format("{\n  \"timestamp\": \"%s\",\n  \"level\": \"%s\",\n  \"message\": \"%s\"\n}",
                new Date(logMessage.getTimestamp()), logMessage.getLevel(), logMessage.getMessage());
    }
}

// ----- Log Appender Interface & Implementations -----
interface LogAppender {
    void append(LogMessage logMessage);
}

class ConsoleAppender implements LogAppender {
    private final LogFormatter formatter;

    public ConsoleAppender(LogFormatter formatter) {
        this.formatter = formatter;
    }

    @Override
    public void append(LogMessage logMessage) {
        System.out.println(formatter.format(logMessage));
    }
}

class FileAppender implements LogAppender {
    private final String filePath;
    private final LogFormatter formatter;

    public FileAppender(String filePath, LogFormatter formatter) {
        this.filePath = filePath;
        this.formatter = formatter;
    }

    @Override
    public void append(LogMessage logMessage) {
        try (FileWriter writer = new FileWriter(filePath, true)) {
            writer.write(formatter.format(logMessage) + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

// ----- Abstract Log Handler (Chain of Responsibility) -----
abstract class LogHandler {
    private final LogLevel handlerLevel;
    private final LogAppender appender;
    private LogHandler nextHandler;

    public LogHandler(LogLevel handlerLevel, LogAppender appender) {
        this.handlerLevel = handlerLevel;
        this.appender = appender;
    }

    public void setNextHandler(LogHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public void handle(LogMessage logMessage) {
        if (logMessage.getLevel().isGreaterOrEqual(handlerLevel)) {
            appender.append(logMessage);
        }
        if (nextHandler != null) {
            nextHandler.handle(logMessage);
        }
    }
}

// ----- Logger Configuration -----
class LoggerConfig {
    private LogLevel logLevel;
    private LogAppender logAppender;

    public LoggerConfig(LogLevel logLevel, LogAppender logAppender) {
        this.logLevel = logLevel;
        this.logAppender = logAppender;
    }

    public LogLevel getLogLevel() {
        return logLevel;
    }

    public void setLogLevel(LogLevel logLevel) {
        this.logLevel = logLevel;
    }

    public LogAppender getLogAppender() {
        return logAppender;
    }

    public void setLogAppender(LogAppender logAppender) {
        this.logAppender = logAppender;
    }
}

// ----- Singleton Logger -----
class Logger {
    private static final ConcurrentHashMap<String, Logger> instances = new ConcurrentHashMap<>();
    private LoggerConfig config;

    private Logger(LogLevel logLevel, LogAppender logAppender) {
        this.config = new LoggerConfig(logLevel, logAppender);
    }

    public static Logger getInstance(LogLevel logLevel, LogAppender logAppender) {
        String key = logLevel.name() + "_" + logAppender.getClass().getName();
        return instances.computeIfAbsent(key, k -> new Logger(logLevel, logAppender));
    }

    public synchronized void setConfig(LoggerConfig config) {
        this.config = config;
    }

    public void log(LogLevel level, String message) {
        if (level.isGreaterOrEqual(config.getLogLevel())) {
            LogMessage logMessage = new LogMessage(level, message);
            config.getLogAppender().append(logMessage);
        }
    }

    public void debug(String message) {
        log(LogLevel.DEBUG, message);
    }

    public void info(String message) {
        log(LogLevel.INFO, message);
    }

    public void warning(String message) {
        log(LogLevel.WARNING, message);
    }

    public void error(String message) {
        log(LogLevel.ERROR, message);
    }

    public void fatal(String message) {
        log(LogLevel.FATAL, message);
    }
}

// ----- Client Code to Demonstrate the Logging System -----
class LoggingSystemDemo {
    public static void main(String[] args) {
        LogFormatter jsonFormatter = new JsonLogFormatter();
        LogAppender consoleAppender = new ConsoleAppender(jsonFormatter);
        LogAppender fileAppender = new FileAppender("app_logs.txt", jsonFormatter);

        Logger logger = Logger.getInstance(LogLevel.DEBUG, fileAppender);
        logger.info("Informational message.");
        logger.debug("Debugging message.");
        logger.error("Error message.");
    }
}
