<h1>Виртуални функции. Ключови думи override и final. Полиморфизъм. Чисто виртуални функции. Абстрактни класове.</h1>

### Задача 1
Да се продължи задачата от <i>Week 09</i> като направите клас `Square` да наследява класовете `Rectangle` и `Rhombus`. Помислете до какъв проблем би довело това и как може да се справите с него.

Да се направи клас `Figure`, който има три виртуални метода - `Print`, `GetArea` и `GetPerimeter`.
`GetArea` да бъде чисто виртуална функция.
Класовете `Circle`, `Triangle` и `Quadrilateral` да наследяват класа `Figure`.
Да се допише реализацията на клас `Triangle`, който да има собствени реализации на трите виртуални метода и да се имплементира класът `Circle`, описващ окръжност.

Да се направи виртуален копиращ конструктор за класовете на йерархията.

Да се направи клас `FigureCollection`, имплементиращ динамичен саморазширяващ се масив от указатели към обекти от клас `Figure` и да се демонстрира работата с него.

### Схема на йерархията:
<br>![](https://github.com/xKrashx/Object_Oriented_Programming/blob/main/Practicum/Week%2010/img/Diagram.png?raw=true)

---

### Задача 2 <b>(за домашно)</b>
 Да се имплементира клас `Player`, описващ играч. Нека той има за член-данни:
- `име` – динамично заделен символен низ с максимална дължина <b>50</b>;
- `точки` – цяло число;
- `позиция` – точка в двумерна координатната система.

Реализирайте клас `Mage`, описващ магьосник и наследяващ клас `Player`. Нека той има за член-данна `сила` – динамично заделен символен низ с максимална дължина <b>25</b>.

Погрижете се за коректното управление на паметта на двата класа чрез реализиране на голяма четворка. Помислете дали има специфика при реализацията ѝ за класа `Mage`. Напишете функции за достъп до член-данните.
