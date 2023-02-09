## Pattern Oriented Software Design, Fall 2022
- Instructor: Prof. Y C Cheng
- Office hours: 8-10 am, Mon/Tue
- Class meeting time: Mon 5-6-7
- Class meeting place:
  - CB2-207 (in person)
  - [Microsoft Teams](https://teams.microsoft.com/l/team/19%3arx_SzFvbX9zrlkaCgj-nhRG10GaY3kcyv86eZbP5IaE1%40thread.tacv2/conversations?groupId=ddb0ff79-028c-4dbc-bba3-1a7fa6eb1b3c&tenantId=dfb5e216-2b8a-4b32-b1cb-e786a1095218) (when distance learning is in effect)
- TA: James Jhang, Paul Lai (Room 1321 S&T)
- Office hours: 10am - 12pm , Tue/Wed
- TA's homework repository: [posd2022f_TA](http://140.124.181.100/course/posd2022f_ta)

### Synopsis

This course aims to build a foundation for students to build software with design patterns and mainstream programming paradigms used in modern software development. We will also cover the SOLID principles of object-oriented design. These topics will be threaded with a long running example developed in the classroom with participation from students and with state-of-the-art engineering practices. 

Design patterns examines reusable solutions to object oriented design problems (maintainable, extendable, etc.) in software developed in object-oriented languages like C++, Java, Python, Ruby, OCaml and so on.

  - design patterns
    - individual patterns by category as they are encountered in the running example
    - application of multiple patterns
    - real-world examples

The programming paradigms affect how design patterns are implemented. Although object orientation is the the main paradigm, other paradigms that contribute to a cleaner implementation are examined in the context of design patterns implementation.

  - programming paradigms
    - procedure (ad hoc polymorphism, c, python)
    - function (math functions lisp, scheme, ...)
    - generics and templates (static polymorphism)
    - object orientation (dynamic polymorphism)
    - static typing vs dynamic typing

SOLID principles examine object-oriented design principles behind software design, patterns and beyond, to achieves _separation of concerns_.

  - source level principles
  - component level principles
  - review of their use in the running example

The main part of lectures is threaded with a long running example involving the creation,  manipulation, and storage of geometric shapes. Development of the example is done mostly (if not entirely) in class meetings; it is done iteratively and incrementally and with test-driven development, mob programming, and continuous integration. Source code is available to class participants through a repository.

  - engineering practices
    - HTSI: _understanding the problem_, _devising a plan_, _carrying out the plan_, and _looking back_
    - mob programming with strong style pair programming
      - class participants will take turn playing the roles of _driver_ and _navigator_
    - code proceeded by tests: _failing test-passing test-refactoring_ _TDD_
    - source control through git
    - program builds through builders and continuous integration

Lastly, an outside lecture from industry will give a 3-hour lecture on real-world application of design patterns. This is followed by an outlook to further deepening and broadening design knowledge and skills by touching upon architecture and design.

## Problems

**Problem 1 : sorting shapes**
A simple geometry application called _geo_ is needed to sort shapes such as triangles, circles, rectangles and others. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
geo input.txt output.txt area inc
```
sorts the shapes in file _input.txt_ in increasing order by area, and writes the result to the file _output.txt_. And
```
geo input.txt output.txt perimeter dec
```
sorts the shapes in file _input.txt_ in decreasing order by perimeter, and writes the result to the file _output.txt_.

**Problem 2: Shape manipulation**

A program for manipulating geometric shapes is needed. With the program, the user creates/deletes/modifies simple shapes such as square, circle, triangle, and convex polygons. Individual shapes will have properties such as area, perimeter, color and so on. Compound shapes can be formed from individual shapes. Area and perimeter properties are still needed on compound shapes. A compound shape can include other compound shapes. The following operations on shapes are needed.

- Add shapes to a compound shape;
- Delete shapes from a compound shape;
- Group and ungroup;
- Move shapes out of a compound shape;
- Move shapes from a compound shape to another compound shape;
- Select shapes by Boolean expression on the properties area, perimeter, color and type; and
- Load/store shapes from/into a file.

**Week1**

Problem space
- Read the problem together
- Find the main subproblems
- Organized subproblem by a tree
```
Sorting shapes
├── console IO
├── file IO
├── representation
│   ├── square 
│   ├── circle 
│   └── shape 
└── computation
    ├── area 
    ├── perimeter
    └── sorting 
        └── stl sort 
```

Solution space
- Folder structure: src, test and bin
- Builder: make and makefile

Test-driven development (TDD): use concrete examples to drive coding of functions and methods of objects
- write failing test for a function/method
  - google test
- write function to make it pass
  - including all tests so far
- clean up
  - refactoring

TDD happens at all levels: 
  - unit tests (UTDD) for functions and methods
  - collaboration of objects 
  - functional tests (acceptance TDD; ATDD)
  - end-to-end tests (ATDD)

The more you move up, the more tooling you need
  - Rails: cucumber, capybara, minitest

makefile for building executables 
-> unit test entry point for including dependencies (gtest) tests
-> unit tests in header files for tests and dependencies on source code
-> source code

support tooling
- vscode, vim, etc.
- git
- gitlab

__Test-driven learning__ of API: sort
- std::sort in STL
- template
- Comparator as a function, lambda, or functor (object with overloaded function call operator)
  - pointer to function
  - lambda (closure)
  - functor

**Week2**
OCP

Polymorphism
- base class(Shape) with virtual method(area)
- inheritance Square:Shape Circle:Shape with override
- use pointer or reference the base class

```
Shape composition and manipulation
├── console IO
├── file IO
├── representation
│   ├── square
│   ├── circle
│   ├── compound shape
│   └── shape
└── computation
    ├── area
    ├── perimeter
    ├── add
    ├── delete
    ├── move
    └── select (week 3)
        └── select by area
            └── as a member function
                └── easiest, but bloat CompoundShape
            └── as a ordinary C function
                └── provide access without breaking encapsulation
                    └── iterator pattern
```
**Week3**

- see the branch off select (week 3)

why select?
- before adding anything to a CompoundShape, you need to know _the exact location_ to add it.
- so we need to know that location
- the location can be modeled with a pointer object: iterator

Design matters when you have multiple ways of achieving the same thing.

Reading:
- Composite (163) in GoF
- Iterator(257) in GoF
- [iterators in C++ STL](https://www.cplusplus.com/reference/iterator/RandomAccessIterator/)

## Week 4

with the iterator:
- delete: delete a shape found in CompoundShape
- add: add a shape after the shape pointed to by iterator
- copy: clone the shape object

components (circle, square) and composite (compound shape)
- tree: OK (select, iterator, add, delete, copy)
- "Client" treating component objects and composite objects uniformly
    - why would we do this?

## Week 5

Refactoring `selectFirstByArea`:
- Uniformity of shapes for client function `selectFirstByArea`
  - take a shape rather than a compound shape
  - Circle/Square throws exception on createIterator vs returning a _null iterator_ (Iterator::Implementation 8)
  - polymorphic iterator (Iterator::Implementation 5)
    - smart pointer (Proxy)

The open closed principle

## Week 6

**Midterm on week 8: night 6-9 pm Wed Nov/10**

Refactoring `selectFirstByArea` (continued):
- Move from ad hoc polymorphism (overloading) to parametric polymorphism (template)
  - make constraints a function-like object
    - pointer to function
    - overload function call operator () with the class
    - template

CompoundShape
  - delete
  - add

Visitor for `selectFirstByArea`
  - motivation
  - collaboration (sequence diagram)
  - consequences (go through all points)
    - point 2: cohesion
    - point 6: breaking encapsulation
  - implementation
    - point 1: single/double dispatch

## Week 7

Visitor
  - complete SelectShapeVisitor
    - make it take a constraint

Factory Method was applied to create different iterators depending on the type of Shape

Organizing the catalog (Table 1.1)
- purpose: creational, structural, and behavioral
- scope:
  - class (mainly inheritance)
  - object (mainly composition)

Composite: object structural
Iterator: object behavioral
Factory Method: class creational
Visitor: object behavioral

Observation: There are more object X patterns than class X patterns.

The open closed principle (continued).

## Week 8

Midterm I: 6:00pm - 9:00pm Wed 11/10/2021, 12F Computer Room
open book and class repo

## Week 9

OCP:
- listing 1 `print_all_shapes` not close against adding new shapes
- listing 2 `print_all_shapes` close against adding new shape
- 100% closure is not possible: requirement change
    - hedge against common types of changes
    - Listing 3,4,5 is interesting: operator < is a template method, Precedes is a primitive method
    - `print_all_shapes` is closed, by the the point of change relocates to Shape::Precedes
    => OOD does not close it
    - listing 6 data-driven closes both when the anticipated change is the type of shape "all circle before all squares"
- design heuristics
    - no public data member
    - no global
    - RTTI (dynamic_cast and type_id) only in specific circumstances
        - listing 9 violation
        - listing 10 no violation

replace shape *[] with list<Shape *>
- clean up methods that you don't want but uses shape* []
    - begin with test
    - on to methods called from test
    - comment out one at a time compile, run.
- add list<shape *> to coexist with Shape *[] (strangler fig)
    - method by method (adding but not using should not break)
    - until list<shape *> is ready for use
- ensure only compound iterator depends on the list
    - fix tests first
    - fix iterators
- watch out for inconsistencies:
    - Square throws an exception when asked to create an iterator
- get rid of memory leak
    - tests
    - iterators

- open close: composite and visitor vs function
- visitor: distributed logic for visiting
    - more difficult to write but deal with logic for visiting individual shapes separately
- function: all logic in one place
    - easier to write (all in one place) but more involved to modify when a new Shape is added

## Week 10

### Final exam in Week 17
### Lecture from week 18 will be moved to this day:

### Guest lecture: Design Patterns in the Real World
### Kurt Hsu
### Chief Architect, VeryBuy. Co.
### Time: 2:10pm-5:00pm, Sat, Dec 11, 2021
### Place: 6th Classroom building 325

making the visitor a template?
- can we separate SelectShapeVisitor from ShapeVisitor in shape_visitor.h?
- how about something like this:
``` C++
    Shape* c2 = new Circle(1.0);
    ...
    ShapeVisitor* visitor = new SelectShapeVisitor([c2](Shape* shape) {
        return shape == c2;
    });
```
- or something like a functor (function object)

Needs [CTAD (C++17 and after)](https://en.cppreference.com/w/cpp/language/class_template_argument_deduction)

## Week 11

Builder pattern with parser and scanner
  - scanners knows how to get next tokens
  - parser knows the syntax
  - builder knows how to create and assemble shapes
  - exercise: error handling

## Week 12, 13, Week 18*
  - singleton
  - adaptor
  - template method
  - Liskov substitution principle
  - guest lecture: 12/11.

## Week 14, 15
  - dependency inversion principle
  - single responsibility principle
  - observer
  - strategy
  - decorator
  - proxy

Lab 2 12/29 18:00 - 21:00
## Week 16

***Final exam, Jan 5, 2022, in class, pen and paper test, open GoF and SOLID papers***

## Week 17

- Patterns and pattern languages
- Architecture patterns

