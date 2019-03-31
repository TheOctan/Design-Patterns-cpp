## C++ Design Patterns

Software design patterns are general reusable solutions to problems which occur
over and over again in object-oriented design enviroment. It is not a finished 
design that can be transformed into source code directly, but it is template how
to solve the problem. We can classify them by purpose into creational (abstract 
the instantiation process), structure (how classes and objects are composed to form 
larger structures) and behavioral patterns (the assignment of responsibilities between 
objects).

![01-HelloWorld](list-of-patterns.png)

#### Creational Patterns ([Порождающие паттерны])
* [Abstract Factory], families of product objects
> Абстрактная фабрика - создаёт семейство взаимносвязных объектов
* [Builder], how a composite object gets created
> Строитель - поэтамное создание сложного объекта
* [Factory Method], subclass of object that is instantiated
> Фабричный метод - определяет интерфейс для создания объекта, при этом его тип определяется подклассами
* [Object Pool], storage of expensive resources
> Пул объектов - создание "затратных" объектов за счёт их многократного использования
* [Prototype], class of object that is instantiated
> Прототип - создание объектов на основе прототипов
* [Singleton], the sole instance of a class 
> Одиночка - создаёт единственный экземпляр некоторого класса и предоставляет к нему доступ
#### Structural Patterns ([Структурные паттерны])
* [Adapter], interface to an object
> Адаптер - преобразует интерфейс существующего класса к виду, подходящему для использования
* [Bridge], implementation of an object 
> Мост - делает абсракцию и реализацию независимыми друг от друга
* [Composite], structure and composition of an object
> Компоновщик - группирует схожие объекты в древовидные структуры
* [Decorator], responsibilities of an object without subclassing
> Декоратор - динамически добавляет объекту новую функциональность
* [Facade], interface to a subsystem
> Фасад - предоставляет унифицированный интерфейс вместо набора интерфейсов некоторой системы
* [Flyweight], storage costs of objects
> Приспособленец - использует разделение для поддержки множества мелких объектов
* [Proxy], how an object is accessed (its location)
> Заместитель - подменяет другой объект для контроля доступа к нему
#### Behavioral Patterns ([Паттерны поведения])
* [Chain of Responsibility], object that can fulfill a request
> Цепочка обязанностей - предоставляет способ передачи запроса по цепочке получателей
* [Command], when and how a request is fulfilled
> Команда - Инкапсулирует запрос в виде объекта
* [Interpreter], grammar and interpretation of a language
> Интерпертатор - для языка определяет его грамматику и интерпритатор, использующий эту грамматику
* [Iterator], how an aggregate's elements are accessed
> Итератор - предоставляет механизм обхода элементов коллекции
* [Mediator], how and which objects interact with each other
> Посредник - Инкапсулирует взаимодействие между множеством объектов в объект-посредник
* [Memento], what private information is stored outside an object, and when
> Хранитель - сохраняет и восстанавливает состояние объекта
* [Observer], how the dependent objects stay up to date
> Наблюдатель - при изменении объекта извещает все зависимые объекты для их обновления
* [State], states of an object
> Состояние - изменяет поведение объекта при изменении его состояния
* [Strategy], an algorithm
> Стратегия - переносит алгоритмы в отдельную иерархию классов, делая их взаимозаменяемыми
* [Template Method], steps of an algorithm
> Шаблонный метод - определяет шаги алгоритма, позволяя подклассам изменить некоторые из них
* [Visitor], operations that can be applied to objects without changing their classes
> Посетитель - определяет новую операцию в классе без его изменения

### References
Design patterns in this repository are based on

* [Design Patterns by The "Gang of Four"]
* [Head First: Design Patterns]
* [Wikipedia]
* [Design Patterns]

[Design Patterns by The "Gang of Four"]: https://en.wikipedia.org/wiki/Design_Patterns
[Head First: Design Patterns]: http://www.headfirstlabs.com/books/hfdp/ 
[Wikipedia]: https://en.wikipedia.org/wiki/Software_design_pattern
[Design Patterns]: http://cpp-reference.ru/patterns/catalog/

[Порождающие паттерны]: https://github.com/AlvinGames/design-patterns-cpp/blob/master/Creational%20Patterns/Creational%20Patterns.md
[Структурные паттерны]: https://github.com/AlvinGames/design-patterns-cpp/blob/master/Structural%20Patterns/Structural%20Patterns.md
[Паттерны поведения]: https://github.com/AlvinGames/design-patterns-cpp/blob/master/Behavioral%20Patterns/Behavioral%20Patterns.md

[Abstract Factory]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Abstract-Factory
[Builder]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Builder
[Factory Method]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Factory-Method
[Object Pool]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Object-Pool
[Prototype]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Prototype
[Singleton]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Creational%20Patterns/Singleton
[Adapter]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Bridge]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Bridge
[Composite]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Decorator]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Decorator
[Facade]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Facade
[Flyweight]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Flyweight
[Proxy]: https://github.com/AlvinGames/design-patterns-cpp/tree/master/Structural%20Patterns/Proxy
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


