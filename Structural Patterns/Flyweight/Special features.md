## Особенности паттерна Flyweight

* Если Flyweight показывает, как сделать множество небольших объектов,
то [Facade] показывает, как представить целую подсистему одним объектом.

* Flyweight часто используется совместно с [Composite] для реализации иерархической
структуры в виде графа с разделяемыми листовыми вершинами.

* Терминальные символы абстрактного синтаксического дерева [Interpreter] могут разделяться при помощи Flyweight.

* Flyweight объясняет, когда и как могут разделяться объекты [State].

[Facade]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Facade
[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Interpreter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Interpreter
[State]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/State
