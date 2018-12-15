## Особенности паттерна Interpreter

* Абстрактное синтаксическое дерево интерпретатора – пример паттерна [Composite].

* Для обхода узлов дерева может применяться паттерн [Iterator].

* Терминальные символы могут разделяться c помощью [Flyweight].

* Паттерн Interpreter не рассматривает вопросы синтаксического разбора.
Когда грамматика очень сложная, должны использоваться другие методики.

[Composite]:
[Iterator]:
[Flyweight]: