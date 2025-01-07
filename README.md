# philosophers

**Eat, Sleep, Spaghetti, Repeat.** This project teaches you about thread management by simulating the classic "Dining Philosophers" problem, where philosophers must eat spaghetti without starving—all while sharing limited resources.

---

## Table of Contents
- [Project Overview](#project-overview)
- [Rules](#rules)
- [How to Execute](#how-to-execute)
- [Grade](#grade)

---

## Project Overview
The "Dining Philosophers" problem illustrates synchronization issues in concurrent programming. Philosophers seated at a round table share forks and must alternate between eating, thinking, and sleeping. Proper thread management ensures no philosopher dies of starvation, and resources are efficiently utilized.

### Representation of the Problem
![An illustration of the dining philosophers problem](https://github.com/t-pereira06/42_philosophers/assets/118270669/b6a00195-734b-4fcd-8de4-9b6ad762a964)

---

## Rules

- Philosophers sit at a round table with a bowl of spaghetti in the center.
- Philosophers alternate between three states:
  - **Eating:** Consumes spaghetti using two forks.
  - **Thinking:** Does not interact with forks or spaghetti.
  - **Sleeping:** Resting after eating.
- Forks are shared between philosophers. There are as many forks as philosophers.
- To eat, a philosopher must hold the fork on their left and the fork on their right.
- After eating, a philosopher returns the forks to the table and sleeps before thinking again.
- The simulation ends when:
  - A philosopher dies of starvation.
  - (Optional) All philosophers have eaten a specified number of times.

### Additional Rules
- Every philosopher must eat and avoid starvation.
- Philosophers do not communicate with each other.
- A philosopher does not know if another is about to starve.
- Philosophers should never die if managed properly.

---

## How to Execute

### Compilation
To compile the program, run:
```bash
make
```

### Execution
After compiling, execute the program with the following arguments:
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Arguments
1. **`number_of_philosophers`**: Total number of philosophers and forks.
2. **`time_to_die` (in ms)**: Time a philosopher can go without eating before dying.
3. **`time_to_eat` (in ms)**: Time it takes a philosopher to eat (requires holding two forks).
4. **`time_to_sleep` (in ms)**: Time a philosopher spends sleeping after eating.
5. **`number_of_times_each_philosopher_must_eat` (optional)**: The simulation ends when all philosophers eat this many times. If omitted, the simulation ends when a philosopher dies.

### Example
To run a simulation with 5 philosophers:
```bash
$ ./philo 5 800 200 200
```
This creates 5 philosophers who:
- Die if they don’t eat within 800 ms.
- Take 200 ms to eat.
- Sleep for 200 ms after eating.

To clean up the object files after execution, use:
```bash
make fclean
```

---

## Grade

![Grade Screenshot](https://github.com/t-pereira06/42_philosophers/assets/118270669/9c8a1d0e-9f99-4781-b2d1-3a4c1e586324)
