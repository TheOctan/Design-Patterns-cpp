## C++ Design Patterns

Software design patterns are general reusable solutions to problems which occur
over and over again in object-oriented design enviroment. It is not a finished 
design that can be transformed into source code directly, but it is template how
to solve the problem. We can classify them by purpose into creational (abstract 
the instantiation process), structure (how classes and objects are composed to form 
larger structures) and behavioral patterns (the assignment of responsibilities between 
objects).

⚠ This repository is an extension of the [original repository].

![Patterns](list-of-patterns.png)

#### Creational Patterns ([Порождающие паттерны])
* ([Abstract Factory]) Абстрактная фабрика - создаёт семейство взаимносвязных объектов
* ([Builder]) Строитель - поэтамное создание сложного объекта
* ([Factory Method]) Фабричный метод - определяет интерфейс для создания объекта, при этом его тип определяется подклассами
* ([Object Pool]) Пул объектов - создание "затратных" объектов за счёт их многократного использования
* ([Prototype]) Прототип - создание объектов на основе прототипов
* ([Singleton]) Одиночка - создаёт единственный экземпляр некоторого класса и предоставляет к нему доступ
#### Structural Patterns ([Структурные паттерны])
* ([Adapter]) Адаптер - преобразует интерфейс существующего класса к виду, подходящему для использования
* ([Bridge]) Мост - делает абсракцию и реализацию независимыми друг от друга
* ([Composite]) Компоновщик - группирует схожие объекты в древовидные структуры
* ([Decorator]) Декоратор - динамически добавляет объекту новую функциональность
* ([Facade]) Фасад - предоставляет унифицированный интерфейс вместо набора интерфейсов некоторой системы
* ([Flyweight]) Приспособленец - использует разделение для поддержки множества мелких объектов
* ([Proxy]) Заместитель - подменяет другой объект для контроля доступа к нему
#### Behavioral Patterns ([Паттерны поведения])
* ([Chain of Responsibility]) Цепочка обязанностей - предоставляет способ передачи запроса по цепочке получателей
* ([Command]) Команда - Инкапсулирует запрос в виде объекта
* ([Interpreter]) Интерпертатор - для языка определяет его грамматику и интерпритатор, использующий эту грамматику
* ([Iterator]) Итератор - предоставляет механизм обхода элементов коллекции
* ([Mediator]) Посредник - Инкапсулирует взаимодействие между множеством объектов в объект-посредник
* ([Memento]) Хранитель - сохраняет и восстанавливает состояние объекта
* ([Observer]) Наблюдатель - при изменении объекта извещает все зависимые объекты для их обновления
* ([State]) Состояние - изменяет поведение объекта при изменении его состояния
* ([Strategy]) Стратегия - переносит алгоритмы в отдельную иерархию классов, делая их взаимозаменяемыми
* ([Template Method]) Шаблонный метод - определяет шаги алгоритма, позволяя подклассам изменить некоторые из них
* ([Visitor]) Посетитель - определяет новую операцию в классе без его изменения

### Ссылки
Шаблоны проектирования в данном репизитории основаны на:

* [Design Patterns by The "Gang of Four"]
* [Head First: Design Patterns]
* [Wikipedia]
* [Design Patterns]

[original repository]: https://github.com/JakubVojvoda/design-patterns-cpp

[Design Patterns by The "Gang of Four"]: https://en.wikipedia.org/wiki/Design_Patterns
[Head First: Design Patterns]: http://www.headfirstlabs.com/books/hfdp/ 
[Wikipedia]: https://en.wikipedia.org/wiki/Software_design_pattern
[Design Patterns]: http://cpp-reference.ru/patterns/catalog/

[Порождающие паттерны]: https://github.com/TheOctan/design-patterns-cpp/blob/master/Creational%20Patterns
[Структурные паттерны]: https://github.com/TheOctan/design-patterns-cpp/blob/master/Structural%20Patterns/
[Паттерны поведения]: https://github.com/TheOctan/design-patterns-cpp/blob/master/Behavioral%20Patterns/

[Abstract Factory]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Abstract-Factory
[Builder]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Builder
[Factory Method]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Factory-Method
[Object Pool]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Object-Pool
[Prototype]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Prototype
[Singleton]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Creational%20Patterns/Singleton
[Adapter]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Adapter
[Bridge]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Bridge
[Composite]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Composite
[Decorator]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Decorator
[Facade]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Facade
[Flyweight]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Flyweight
[Proxy]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Structural%20Patterns/Proxy
[Chain of Responsibility]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Chain-Of-Responsibility
[Command]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Command
[Interpreter]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Interpreter
[Iterator]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Iterator
[Mediator]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Mediator
[Memento]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Memento
[Observer]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Observer
[State]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/State
[Strategy]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Strategy
[Template Method]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Template-Method
[Visitor]: https://github.com/TheOctan/design-patterns-cpp/tree/master/Behavioral%20Patterns/Visitor


