## Особенности паттерна Facade

* Facade определяет новый интерфейс, в то время как [Adapter] использует уже имеющийся.
Помните, [Adapter] делает работающими вместе два существующих интерфейса, не создавая новых.

* Если [Flyweight] показывает, как сделать множество небольших объектов,
то Facade показывает, как сделать один объект, представляющий целую подсистему.

* [Mediator] похож на Facade тем, что абстрагирует функциональность существующих классов.
Однако Mediator централизует функциональность между объектами-коллегами, не присущую ни одному из них.
Коллеги обмениваются информацией друг с другом через [Mediator].
С другой стороны, Facade определяет простой интерфейс к подсистеме,
не добавляет новой функциональности и не известен классам подсистемы.

* [Abstract Factory] может применяться как альтернатива Facade для сокрытия платформенно-зависимых классов.

* Объекты "фасадов" часто являются [Singleton], потому что требуется только один объект Facade.

> [Adapter] и Facade в являются "обертками", однако эти "обертки" разных типов.
Цель Facade – создание более простого интерфейса, цель [Adapter] – адаптация существующего интерфейса.
Facade обычно "обертывает" несколько объектов, [Adapter] "обертывает" один объект.

[Adapter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Flyweight]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Flyweight
[Mediator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Mediator
[Abstract Factory]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Abstract-Factory
[Singleton]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Singleton
