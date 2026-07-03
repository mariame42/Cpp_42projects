# C++ Modules — 42 School

A progressive C++ curriculum: each module builds on the last, moving from syntax and memory to OOP, templates, and the STL.

---

## Big Picture

42’s C++ track does not teach “random exercises.” It walks you through the **core language step by step**:

| Phase | Modules | What you learn |
|-------|---------|----------------|
| **Basics** | CPP00 | Namespaces, classes, I/O streams, `static` / `const` |
| **Memory** | CPP01 | Stack vs heap, pointers, references, file I/O |
| **Classes** | CPP02 | Orthodox Canonical Form, operator overloading |
| **Inheritance** | CPP03 | Base/derived classes, virtual inheritance |
| **Polymorphism** | CPP04 | Virtual functions, abstract classes, interfaces |
| **Exceptions** | CPP05 | `try` / `catch`, custom exceptions, abstract forms |
| **Casts** | CPP06 | `static_cast`, `reinterpret_cast`, `dynamic_cast` |
| **Templates** | CPP07 | Function and class templates |
| **STL** | CPP08 | Containers, iterators, algorithms |
| **Applied STL** | CPP09 | Real parsers and algorithms with STL tools |

Each exercise is small on purpose. Together they form a complete picture of modern C++ fundamentals.

---

## Repository Layout

```
Cpp_42projects/
├── CPP00 … CPP09/    # Main project folders (one per module)
├── intra/            # Evaluation copies (CPP00 … CPP09)
└── learn/            # Personal notes and practice
```

---

## CPP00 — C++ Basics

**Goal:** Leave C behind. Use C++ streams, classes, and encapsulation.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Megaphone | CLI + strings | Uppercase command-line arguments with `iostream` |
| **ex01** PhoneBook | OOP app | `Contact` + `PhoneBook` — add, search, and store contacts |
| **ex02** Account | Static members | `Account` class with static counters; deposits and withdrawals |

---

## CPP01 — Memory Management

**Goal:** Own memory safely. Understand pointers, references, and allocation.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Braiiii/new Zombie | Heap vs stack | `new` / `delete` with `Zombie` on heap vs stack |
| **ex01** Moar brainz! | Array allocation | `new[]` / `delete[]` — zombie horde |
| **ex02** HI THIS IS BRAIN | Pointers & references | Address (`&`) vs value (`*`) |
| **ex03** Unnecessary violence | References in classes | `HumanA` (ref), `HumanB` (ptr), `Weapon` |
| **ex04** Sed is for losers | File I/O | Find and replace text in a file |
| **ex05** Harl 2.0 | Pointer-to-member | Call `Harl::complain` via member-function pointers |
| **ex06** Harl filter | Switch dispatch | Filter Harl’s complaints by log level |

---

## CPP02 — Orthodox Canonical Form

**Goal:** Write proper C++ classes with copy semantics and overloaded operators.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** My First Class | OCCF basics | Constructor, copy, assignment, destructor on `Fixed` |
| **ex01** Towards a more useful form | Fixed-point math | Int/float conversion, `operator<<` |
| **ex02** Now we're talking | Operator overloading | `+ - * /`, comparisons, `++`/`--`, `min`/`max` |
| **ex03** At least this beats coffee break | Geometry | `Point` + `bsp()` — point inside a triangle |

---

## CPP03 — Inheritance

**Goal:** Reuse code through class hierarchies.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** A new hope | Base class | `ClapTrap` — HP, energy, attack, repair |
| **ex01** Serena, my love | Single inheritance | `ScavTrap` extends `ClapTrap`, `guardGate()` |
| **ex02** Repetitive work | Another derived class | `FragTrap` extends `ClapTrap`, `highFivesGuys()` |
| **ex03** Now it's weird! | Diamond problem | `DiamondTrap` — virtual inheritance, `whoAmI()` |

---

## CPP04 — Polymorphism

**Goal:** Runtime behavior through virtual functions and abstract interfaces.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Polymorphism | Virtual functions | `Animal`/`Dog`/`Cat` vs broken `WrongAnimal`/`WrongCat` |
| **ex01** I don't want to set the world on fire | Deep copy | `Brain` inside `Dog`/`Cat`; array of polymorphic animals |
| **ex02** Abstract class | Pure virtual | `Animal` becomes abstract — only `Dog`/`Cat` instantiable |
| **ex03** Interface & recap | Interfaces | `AMateria`, `Ice`/`Cure`, `ICharacter`, `MateriaSource` |

---

## CPP05 — Exceptions

**Goal:** Handle errors cleanly with exceptions instead of return codes.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Mommy, when I grow up | Custom exceptions | `Bureaucrat` grades, `GradeTooHigh` / `GradeTooLow` |
| **ex01** Form up, maggots! | Form signing | `Form` + `Bureaucrat::signForm` with grade checks |
| **ex02** A sign of things to come | Abstract forms | `AForm`, shrubbery / robotomy / pardon forms, `execute()` |
| **ex03** Bureaucrat internship | Factory pattern | `Intern::makeForm` creates forms by name |

---

## CPP06 — C++ Casts

**Goal:** Convert types safely using C++ cast operators.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Conversion of scalar types | `static_cast` logic | `ScalarConverter` — char/int/float/double from a literal |
| **ex01** Serialization | `reinterpret_cast` | Serialize/deserialize a pointer to `uintptr_t` |
| **ex02** Identify real type | `dynamic_cast` | Generate random `A`/`B`/`C`, identify via pointer and reference |

---

## CPP07 — Templates

**Goal:** Write generic code that works with any type.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Whatever | Function templates | `swap`, `min`, `max` for any comparable type |
| **ex01** Iter | Function template | `iter` — apply a function to each array element |
| **ex02** Array | Class template | `Array<T>` — bounds-checked dynamic array |

---

## CPP08 — STL Containers

**Goal:** Use the Standard Template Library instead of reinventing data structures.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Easy find | STL + templates | `easyfind` — search any container, throw if missing |
| **ex01** Span | Container wrapper | `Span` — store N ints, find shortest/longest span |
| **ex02** Mutated abomination | Iterator adaptation | `MutantStack` — `std::stack` exposed with iterators |

---

## CPP09 — STL in Practice

**Goal:** Solve real problems with containers and algorithms.

| Exercise | Topic | What it teaches |
|----------|-------|-----------------|
| **ex00** Bitcoin Exchange | `map` + file parsing | `BitcoinExchange` — lookup BTC rates from CSV by date |
| **ex01** RPN | Stack algorithm | Evaluate reverse Polish notation expressions |
| **ex02** PmergeMe | Merge-insertion sort | Ford–Johnson sort on `vector` and `deque`, with timing |

---

## Resources

### CPP00 — C++ Basics
- [cpp containers list](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/) — 
- [vector vs deque](https://youtu.be/Ct8ykaKrKOA?si=BZ4lkajPJcV-Wlza/) — 
- [Reverse Polish Notation](https://medium.com/@interviewbuddies/reverse-polish-notation-b88524252960) — 
- [merge-insert sort](https://www.linkedin.com/posts/nerraou_ford-johnson-merge-insertion-sort-activity-7076577075712675840-AJ1l/) — 

---
## How to Build & Run

Every exercise uses a **Makefile**. The workflow is the same everywhere:

```bash
cd CPP<module>/ex<exercise>    # e.g. cd CPP05/ex00
make                            # compile
./<binary>                      # run
make fclean && make             # full rebuild
make clean                      # remove object files
make fclean                     # remove objects + binary
```

### Examples

```bash
# CPP00 — uppercase CLI args
cd CPP00/ex00 && make && ./megaphone "hello world"

# CPP01 — file find/replace
cd CPP01/ex04 && make && ./fileReplacer file.txt s1 s2

# CPP06 — scalar conversion
cd CPP06/ex00 && make && ./ScalarConverter 42

# CPP09 — RPN calculator
cd CPP09/ex01 && make && ./RPN "3 4 2 * 1 + 5 *"
```

Some programs are **interactive** (PhoneBook, ClapTrap, Bureaucrat) — just run the binary and follow the prompts.

Programs that need **arguments** will print usage or an error if you run them without the right input.

---

## Compiler

All projects compile with **C++98**:

```
c++ -Wall -Wextra -Werror -std=c++98
```
