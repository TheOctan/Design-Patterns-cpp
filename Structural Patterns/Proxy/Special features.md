## Ћсобенности паттерна Proxy

* [Adapter] предоставляет своему объекту другой интерфейс.
Proxy предоставляет тот же интерфейс.
[Decorator] предоставляет расширенный интерфейс.

* [Decorator] и Proxy имеют разные цели, но схожие структуры.
Оба вводят дополнительный уровень косвенности:
их реализации хранят ссылку на объект, на который они отправляют запросы.

[Adapter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Decorator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Decorator
