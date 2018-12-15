## Особенности паттерна Observer

* Паттерны [Chain of Responsibility], [Command], [Mediator] и Observer показывают,
как можно разделить отправителей и получателей запросов с учетом своих особенностей.
[Chain of Responsibility] передает запрос отправителя по цепочке потенциальных получателей.
[Command] определяет связь - "оправитель-получатель" с помощью подкласса.
В [Mediator] отправитель и получатель ссылаются друг на друга косвенно, через объект-посредник.
В паттерне Observer связь между отправителем и получателем получается слабой,
при этом число получателей может конфигурироваться во время выполнения.

* [Mediator] и Observer являются конкурирующими паттернами.
Если Observer распределяет взаимодействие c помощью объектов "наблюдатель" и "субъект",
то [Mediator] использует объект-посредник для инкапсуляции взаимодействия между другими объектами.
Мы обнаружили, что легче сделать повторно используемыми Наблюдателей и Субъектов, чем Посредников.

* [Mediator] может использовать Observer для динамической регистрации коллег и их взаимодействия с посредником.

[Chain of Responsibility]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Chain-Of-Responsibility
[Command]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Command
[Mediator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Mediator
