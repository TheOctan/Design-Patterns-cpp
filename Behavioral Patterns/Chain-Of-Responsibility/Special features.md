## Особенности паттерна Chain Of Responsibility

* Паттерны Chain of Responsibility, [Command], [Mediator] и [Observer] показывают,
как можно разделить отправителей и получателей с учетом их особенностей.
Chain of Responsibility передает запрос отправителя по цепочке потенциальных получателей.

* Chain of Responsibility может использовать [Command] для представления запросов в виде объектов.

* Chain of Responsibility часто применяется вместе с паттерном [Composite].
Родитель компонента может выступать в качестве его преемника.

[Command]:
[Mediator]:
[Observer]:
[Composite]: