# C Programming Practice & Lab Exercises

A collection of foundational C programming exercises focusing on algorithms, functions, pointers, and dynamic memory management.

---

## 📋 Programs Overview

| File | Program | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **[`pro1.c`](pro1.c)** | **Guess the Number Game** | Interactive CLI game where the player has 7 attempts to guess a random number between 1 and 100. | `rand()`, `srand()`, `time.h`, loops |
| **[`pro2.c`](pro2.c)** | **Linear Equation Solver** | Solves $ax + b = 0$. Determines if the equation has a unique root, is impossible, or indeterminate. | Functions, pointers (`*x`), status codes |
| **[`pro3.c`](pro3.c)** | **Quadratic Equation Solver** | Solves $ax^2 + bx + c = 0$ using the discriminant ($\Delta$). Handles real roots, double roots, and complex cases. | `math.h`, `sqrt()`, pointers, mathematical logic |
| **[`pro4.c`](pro4.c)** | **Dynamic Array Allocation** | Allocates a dynamic array of $N$ doubles on the heap, initializes all positions with value $L$, and frees memory safely. | `malloc()`, `free()`, heap allocation, memory safety |
| **[`pro5.c`](pro5.c)** | **Random ASCII Characters** | Fills an array of size $N$ with random printable ASCII characters (range 32 to 126). | Arrays, ASCII values, character handling, `rand()` |
| **[`taylor_series.c`](taylor_series.c)** | **Taylor Series Sine Approximation** | Approximates $\sin(x)$ using Taylor/Maclaurin series expansion up to a precision of $10^{-6}$. | Series expansion, numerical approximation, `math.h` |

---

## 🛠️ How to Compile & Run

All programs can be compiled using `gcc` in Linux / WSL (remember to add `-lm` when using `<math.h>`):

```bash
# 1. Guess the Number Game
gcc pro1.c -o pro1
./pro1

# 2. Linear Equation Solver
gcc pro2.c -o pro2
./pro2

# 3. Quadratic Equation Solver (requires -lm)
gcc pro3.c -o pro3 -lm
./pro3

# 4. Dynamic Array Allocation
gcc pro4.c -o pro4
./pro4

# 5. Random ASCII Characters
gcc pro5.c -o pro5
./pro5

# 6. Taylor Series Sine Approximation (requires -lm)
gcc taylor_series.c -o taylor_series -lm
./taylor_series
```

---

## 👤 Author
* **Georgios Theocharis** ([@geotheo01](https://github.com/geotheo01))
