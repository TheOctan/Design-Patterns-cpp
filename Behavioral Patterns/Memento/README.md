## Особенности паттерна Memento

* Паттерны [Command] и Memento определяют объекты "волшебная палочка",
которые передаются от одного владельца к другому и используются позднее.
В [Command] такой "волшебной палочкой" является запрос;
в Memento - внутреннее состояние объекта в некоторый момент времени.
Полиморфизм важен для [Command], но не важен для Memento потому, что интерфейс Memento настолько "узкий",
что его можно передавать как значение.

* [Command] может использовать Memento для сохранения состояния,
необходимого для выполнения отмены действий.

* Memento часто используется совместно с [Iterator].
Iterator может использовать Memento для сохранения состояния итерации.

[Command]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Command
[Iterator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Iterator
