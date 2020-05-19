## Особенности паттерна Interpreter

* Абстрактное синтаксическое дерево интерпретатора – пример паттерна [Composite].

* Для обхода узлов дерева может применяться паттерн [Iterator].

* Терминальные символы могут разделяться c помощью [Flyweight].

* Паттерн Interpreter не рассматривает вопросы синтаксического разбора.
Когда грамматика очень сложная, должны использоваться другие методики.

[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Iterator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Iterator
[Flyweight]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Flyweight
