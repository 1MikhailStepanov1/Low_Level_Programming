# Низкоуровневое программирование
## Лабораторная работа №2
## Степанов Михаил Анреевич P33312

### Вариант №3
### Язык запросов - GraphQL

#### Сборка

```shell
make
```

### Цели

Использовать средство синтаксического анализа по выбору, реализовать модуль для разбора некоторого достаточного подмножества языка запросов по выбору в соответствии с вариантом формы данных. Должна быть обеспечена возможность описания команд создания, выборки, модификации и удаления элементов данных.

### Задачи
* Выбор и изучение средства синтаксического анализа.
* Изучить синтаксис языка запросов и записать спецификацию для средства синтаксического анализа.
* Реализовать модуль, использующий средство синтаксического анализа для разбора языка запросов
* Реализовать тестовую программу для демонстрации работоспособности созданного модуля, принимающую на стандартный ввод текст запроса и выводящую на стандартный вывод результирующее дерево разбора или сообщение об ошибке
* Результаты тестирования представить в виде отчёта.

### Условия

* На равенство и неравенство для чисел, строк и булевских значений
* На строгие и нестрогие сравнения для чисел
* Существование подстроки
* Логическую комбинацию произвольного количества условий и булевских значений
* В качестве любого аргумента условий могут выступать литеральные значения (константы) или ссылки на значения, ассоциированные с элементами данных (поля, атрибуты, свойства)

### Описание работы

Программа реализована в виде модуля, который запрашивает у пользователя строку и обертку над Ast деревом для возвращения результата.
Код возврата представлен значением int. Если возвращен не 0, то программа отработала с ошибкой.

Пример использования:

```console
Person(select: true, node_name: "John"){
    id,
    props.cyl
};

Query: Select
class_type: Person
  SelectionSet:
    Arguments:
      Argument: node_name
      Argument_value: "John"
  ResultSet:
    StringConstant: id
    StringConstant: props.cyl
```

### Аспекты реализации

#### Структура модуля:

* `lexer.l` - файл лексера (flex)
* `perser.y` - файл парсера (bison)
* `ast.h`, `ast.cpp` - реализация узлов дерева запроса

#### Типы узлов
```c++
enum node_type {
    QUERY_NODE,
    SELECTION_SET_NODE,
    RESULT_SET_NODE,
    ARGUMENT_WRAPPER_NODE,
    ARGUMENT_NODE,
    OBJECT_WRAPPER_NODE,
    OBJECT_NODE,
    FIELDS_WRAPPER_NODE,
    FIELD_NODE,
    RELATION_WRAPPER_NODE,
    RELATION_NODE,
    SUB_OPERATION_WRAPPER,
    SUB_OPERATION,
    FILTER_NODE,
    LOGICAL_OP_NODE,
    CONSTANT_NODE
};
```
#### Типы данных
```c++
enum data_type {
    INT,
    FLOAT,
    STRING,
    BOOL
};
```

#### Типы операторов сравнения
```c++
enum filter_operation{
    GT,
    GE,
    LT,
    LE,
    NE,
    LIKE
};
```

#### Типы логических операторов
```c++
enum logical_operation{
    OR,
    AND
};
```

#### Типы операций модификации
```c++
enum sub_operation {
    SET,
    ADD,
    SUB
};
```

### Пример запросов

* Базовая выборка
```shell
Person(select: true, node_name: "John"){
    id,
    props.cyl
};
Query: Select
class_type: Person
  SelectionSet:
    Arguments:
      Argument: node_name
      Argument_value: "John"
  ResultSet:
    StringConstant: id
    StringConstant: props.cyl
```

* Выборка с несколькими условиями
```shell
Person(select: true, node_name: "John", props.privet: 123){
    id,
    props.cyl
};
Query: Select
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: node_name
        Argument_value: "John"
      Argument: props.privet
        Argument_value: 123
  ResultSet: 
    StringConstant: id
    StringConstant: props.cyl
```

* Выборка с оператором сравнения на условие
```shell
Person(select: true, node_name: "John", props.privet: filter{ op: gt, val: 123}){
    id,
    props.cyl,
    relations.muratu
};
Query: Select
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: node_name
        Argument_value: "John"
      Argument: props.privet
        Argument_value: 123
        Filter: GT
  ResultSet: 
    StringConstant: id
    StringConstant: props.cyl
    StringConstant: relations.muratu
```

* Выборка с логическим оператором
```shell
Person(select: true, node_name: "John", or{id:5, props.privet: 123}){
    id,
    props.cyl
};
Query: Select
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: node_name
        Argument_value: "John"
      Logical_op: OR
        Arguments: 
          Argument: id
            Argument_value: 5
          Argument: props.privet
            Argument_value: 123
  ResultSet: 
    StringConstant: id
    StringConstant: props.cyl
```

* Выборка с комбинацией аргументов
```shell
Person(select: true, node_name: "John", or{ and{ id:5, relations.kiwi: "Ogurec"}, props.cyl: 10}, props.privet: 123){
    id,
    props.cyl
};
Query: Select
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: node_name
        Argument_value: "John"
      Logical_op: OR
        Arguments: 
          Logical_op: AND
            Arguments: 
              Argument: id
                Argument_value: 5
              Argument: relations.kiwi
                Argument_value: "Ogurec"
          Argument: props.cyl
            Argument_value: 10
      Argument: props.privet
        Argument_value: 123
  ResultSet: 
    StringConstant: id
    StringConstant: props.cyl
```

* Вставка элемента
```shell
Person(insert: {
    {
        node_name: Volkswagen,
        props{
            id: 5,
            cyl: 124.5
        }
    }
}){
    id
};
Query: Insert
class_type: Person
  SelectionSet: 
    Objects: 
      Object: 
        Name: Volkswagen
        Fields: 
          Field: id
            Value: 5
          Field: cyl
            Value: 124.500000
  ResultSet: 
    StringConstant: id
```

* Удаление элемента
```shell
Person(delete: true,
    node_name: "John"){
    id,
    node_name
};
Query: Delete
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: node_name
        Argument_value: "John"
  ResultSet: 
    StringConstant: id
    StringConstant: node_name
```

* Обновление элемента
```shell
Person(update:[["set", node_name, "Jack"],["set", props.cyl, "123"]], id: 1){
    id,
    node_class,
    node_name
};
Query: Update
class_type: Person
  SelectionSet: 
    Arguments: 
      Argument: id
        Argument_value: 1
    SubOperations: 
      Sub_Operation: Person
        Name: node_name
        Value: "Jack"
      Sub_Operation: "Jack"
        Name: props.cyl
        Value: "123"
  ResultSet: 
    StringConstant: id
    StringConstant: node_class
    StringConstant: node_name
```

### Вывод
В процессе выполнения лабораторной работы было разработано абстрактное синтаксическое дерево запросов к базе данных из лабораторной работы №1.
Разработан модуль считывания и распознавания запросов при помощи технологий Flex и Bison.