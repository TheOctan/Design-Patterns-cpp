## Структурные паттерны

Структурные паттерны рассматривают вопросы о компоновке системы на основе классов и объектов.
При этом могут использоваться следующие механизмы:
> Наследование, когда базовый класс определяет интерфейс, а подклассы - реализацию. Структуры на основе наследования получаются статичными.
>
> Композиция, когда структуры строятся путём объединения объектов некоторых классов. Композиция позволяет получать структуры, которые можно изменять во время выполнения.

* Паттерн [Adapter] представляет собой программную обёртку над уже существующими классами и предназначен для преобразования их интерфейсов к виду,
пригодному для последующего испольщования в новом программном проетке.

* Паттерн [Bridge] отделяет абстракцию от реализации так, что то и другое можно изменять независимо.

* Паттерн [Composite] группирует схожие объекты в древовидные структуры. Рассматривает единообразно простые и сложные объекты.

* Паттерн [Decorator] используется для расширения функциональности объектов.
Являясь гибкой альтернативой порождению классов, паттре Decorator динамически добавляет объекту новые обязанности.

* Паттерн [Facade] предоставляет высокоуровневый унифицированный интерфейс к набору интерфейсов некоторой подсистемы, что облегчает её испольщование.

* Паттерн [Flyweight] использует разделение для эффективной поддержики множества объектов.

* Паттерн [Proxy] замещает другой объект для контроля доступа к нему.

### References

[Структурные паттерны]

[Структурные паттерны]: http://cpp-reference.ru/patterns/structural-patterns/

[Adapter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Bridge]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Bridge
[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Decorator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Decorator
[Facade]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Facade
[Flyweight]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Flyweight
[Proxy]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Proxy
