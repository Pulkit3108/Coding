# Low-Level Design Examples

Standalone Java examples for common system-design exercises, concurrency, SOLID principles, and design patterns.

## Explore

| Area | Contents |
| --- | --- |
| Root directory | System-design examples such as ATM, parking lot, elevator, rental, logging, cache, and games |
| [Concurrency](Concurrency/) | Cache, movie booking, and publish-subscribe examples |
| [SOLID Principles](SOLID%20Principles/) | Single responsibility, open-closed, Liskov substitution, interface segregation, and dependency inversion examples |
| [Design Patterns](Design%20Patterns/) | Creational, structural, and behavioral pattern examples |

## Running An Example

These examples intentionally have no package declarations and reuse simple class names across files. Compile one source file at a time, then run the class that contains its `main` method.

```bash
javac Cache.java
java Main
```

The example above applies to `Cache.java`; other files use different entry-point class names. Generated `.class` files are ignored by the repository.
