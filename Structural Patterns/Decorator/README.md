## Особенности паттерна Decorator

* [Adapter] придает своему объекту новый интерфейс, [Proxy] предоставляет тот же интерфейс,
а Decorator обеспечивает расширенный интерфейс.

* [Adapter] изменяет интерфейс объекта. Decorator расширяет ответственность объекта.
Decorator, таким образом, более прозрачен для клиента.
Как следствие, Decorator поддерживает рекурсивную композицию,
что невозможно с чистыми адаптерами.

* Decorator можно рассматривать как вырожденный случай [Composite] с единственным компонентом.
Однако Decorator добавляет новые обязанности и не предназначен для агрегирования объектов.

* Decorator позволяет добавлять новые функции к объектам без наследования.
[Composite] фокусирует внимание на представлении, а не декорировании.
Эти характеристики являются различными, но взаимодополняющими,
поэтому [Composite] и Decorator часто используются вместе.

* Decorator и [Proxy] имеют разное назначение, но схожие структуры.
Их реализации хранят ссылку на объект, которому они отправляют запросы.

* Decorator позволяет изменить внешний облик объекта,
[Strategy] – его внутреннее содержание.

[Adapter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Proxy]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Proxy
[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Strategy]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Behavioral%20Patterns/Strategy
