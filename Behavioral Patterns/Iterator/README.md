## Особенности паттерна Iterator

* Iterator может применяться для обхода сложных структур, создаваемых [Composite].

* Для создания экземпляра подкласса Iterator полиморфные итераторы используют [Factory Method].

* Часто [Memento] и Iterator используются совместно.
Iterator может использовать [Memento] для сохранения состояния итерации и содержит его внутри себя.

[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Factory Method]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Factory-Method
[Memento]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Memento
