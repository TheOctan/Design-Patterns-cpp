## Паттерны поведения

Паттерны поведения рассматривают вопросы о связях между объектами и распределнием обязанностей между ними.
Для этого могут использоваться механизмы, основанные как на наследовании, так и на композиции.

* Паттерн [Chain of Responsibility] позволяет обработать запрос нескольким объектам-получателям.
Получатели связваются в цепочку, и запрос передаётся по цепочке, пока не будет обработан каким-то объектом.
Паттерн Chain of Responsibility позволяет также избежать жёсткой зависимости между отправителем запроса и его полуателями.

* Паттерн [Command] преобразует запрос на выполнение действия в отдельный объект-команду.
Это придаёт системе гибкость: позволяет осуществлять динамическую замену команд, использовать сложные составные команды, осуществлять отмену операций.

* Паттерн [Iterator] предоставляет механизм обхода элементов составных обхъектов (коллекций) не расскрывая их внутренного представления.

* Паттерн [Interpreter] предназначен для решения повторяющихся задач, которые можно описать некоторым языком.
Для этого паттерн Interpreter описывает решаемую задачу в виде преложений этого языка, а затем интерпритирует их.

* Паттерн [Mediator] инкапсулирует взаимодействие совокупности объектов в отдельный объект-посредник.
Уменьшает степень связаности взаимодействующих объектов - им не нужно хранить ссылки друг на друга.

* Паттерн [Memento] получает и сохраняет за пределами объекта его внутренние состояния так, чтобы позже можно было восстановить объект в таком же состоянии.

* Паттерн [Observer] определяет зависимость "один ко многим" между объектами так,
что при изменении состояния одного объекта все зависящие от него объекты уведомляются и обновяются автоматически.

* Паттерн [State] позволяет объекту изменить свой поведение в зависимости от внутреннего состояния.
Создаётся впечатление, что объект изменил свой класс. Паттерн State является объектно-ориентированной реализацией конечного автомата.

* Если поведение системы настраивается согласно одному из некоторых множества алгоритму,
то применение паттерна [Strategy], переносит семйство алгоритмав в отдельную иерархию классов,
что позволяет заменять один алгоритм другим в ходе выполнения программы. Кроме того, такую систему проше расширять и поддерживать.

* Паттерн [Template Method] определяет основу алгоритма и позволяет подклассам изменить некоторые шаги этого алгоритма без изменения его общей структуры.

* Паттерн [Visitor] определяет операцию, выполняемую на каждом элементе из некоторой структуры без изменения классов этих объектов.

### References

[Паттерны поведения]

[Паттерны поведения]: http://cpp-reference.ru/patterns/behavioral-patterns/

[Chain of Responsibility]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Chain-Of-Responsibility
[Command]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Command
[Interpreter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Interpreter
[Iterator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Iterator
[Mediator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Mediator
[Memento]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Memento
[Observer]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Observer
[State]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/State
[Strategy]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Strategy
[Template Method]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Template-Method
[Visitor]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Visitor
