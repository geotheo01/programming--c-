# C Programming Practice & Lab Exercises

A curated collection of foundational C programming exercises focusing on core algorithms, functions, pointers, and dynamic memory management.

---

## 📋 Programs Overview

| File | Program | Description | Key Concepts |
| :--- | :--- | :--- | :--- |
| **[`guess_number.c`](guess_number.c)** | **Guess the Number Game** | Interactive CLI game where the player has 7 attempts to guess a random number between 1 and 100. | `rand()`, `srand()`, `time.h`, loops |
| **[`linear_equation.c`](linear_equation.c)** | **Linear Equation Solver** | Solves $ax + b = 0$. Determines if the equation has a unique root, is impossible, or indeterminate. | Functions, pointers (`*x`), status codes |
| **[`quadratic_equation.c`](quadratic_equation.c)** | **Quadratic Equation Solver** | Solves $ax^2 + bx + c = 0$ using the discriminant ($\Delta$). Handles real roots, double roots, and complex cases. | `math.h`, `sqrt()`, pointers, mathematical logic |
| **[`dynamic_array.c`](dynamic_array.c)** | **Dynamic Array Allocation** | Allocates a dynamic array of $N$ doubles on the heap, initializes all positions with value $L$, and frees memory safely. | `malloc()`, `free()`, heap allocation, memory safety |
| **[`random_ascii.c`](random_ascii.c)** | **Random ASCII Characters** | Fills an array of size $N$ with random printable ASCII characters (range 32 to 126). | Arrays, ASCII values, character handling, `rand()` |
| **[`taylor_series.c`](taylor_series.c)** | **Taylor Series Sine Approximation** | Approximates $\sin(x)$ using Taylor/Maclaurin series expansion up to a precision of $10^{-6}$. | Series expansion, numerical approximation, `math.h` |

---

## 🛠️ How to Compile & Run

All programs can be compiled using `gcc` in Linux / WSL (remember to add `-lm` when using `<math.h>`):

```bash
# 1. Guess the Number Game
gcc guess_number.c -o guess_number
./guess_number

# 2. Linear Equation Solver
gcc linear_equation.c -o linear_equation
./linear_equation

# 3. Quadratic Equation Solver (requires -lm)
gcc quadratic_equation.c -o quadratic_equation -lm
./quadratic_equation

# 4. Dynamic Array Allocation
gcc dynamic_array.c -o dynamic_array
./dynamic_array

# 5. Random ASCII Characters
gcc random_ascii.c -o random_ascii
./random_ascii

# 6. Taylor Series Sine Approximation (requires -lm)
gcc taylor_series.c -o taylor_series -lm
./taylor_series
```

---

## 👤 Author
* **Georgios Theocharis** ([@geotheo01](https://github.com/geotheo01))
