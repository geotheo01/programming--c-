# C Programming | Algorithms & Numerical Methods

A collection of standalone C programs covering algorithms, numerical methods, pointer manipulation, and dynamic memory management.

---

## 📋 Program Overview

| File | Program | Description | Technical Highlights |
| :--- | :--- | :--- | :--- |
| **[`guess_number.c`](guess_number.c)** | **Number Guessing Game** | CLI game where the player has 7 attempts to guess a random number between 1 and 100. | `rand()`, `srand()`, `time.h`, `for` loop |
| **[`linear_equation.c`](linear_equation.c)** | **Linear Equation Solver** | Solves $ax + b = 0$ and reports whether the solution is unique, impossible, or indeterminate. | Functions, pointers (`*x`), status return codes |
| **[`quadratic_equation.c`](quadratic_equation.c)** | **Quadratic Equation Solver** | Solves $ax^2 + bx + c = 0$ using the discriminant ($\Delta$) to find real, double, or complex roots. | `math.h`, `sqrt()`, pointers, discriminant calculation |
| **[`dynamic_array.c`](dynamic_array.c)** | **Dynamic Array Allocation** | Dynamically allocates an array of $N$ doubles, initializes each element with value $L$, and frees the memory. | `malloc()`, `free()`, heap allocation, pointer checks |
| **[`random_ascii.c`](random_ascii.c)** | **Random ASCII Generator** | Fills a character array of size $N$ with random printable ASCII characters (values 32 to 126). | Arrays, ASCII values, character handling, `rand()` |
| **[`taylor_series.c`](taylor_series.c)** | **Taylor Series Sine Approximation** | Approximates $\sin(x)$ using a Taylor series expansion until the term is smaller than $10^{-6}$. | Taylor series, `math.h`, numerical loops |

---

## 🛠️ How to Compile & Run

All programs can be compiled using `gcc` on Linux / WSL:

```bash
# 1. Number Guessing Game
gcc guess_number.c -o guess_number
./guess_number

# 2. Linear Equation Solver
gcc linear_equation.c -o linear_equation
./linear_equation

# 3. Quadratic Equation Solver (requires -lm for math library)
gcc quadratic_equation.c -o quadratic_equation -lm
./quadratic_equation

# 4. Dynamic Array Allocation
gcc dynamic_array.c -o dynamic_array
./dynamic_array

# 5. Random ASCII Generator
gcc random_ascii.c -o random_ascii
./random_ascii

# 6. Taylor Series Sine Approximation (requires -lm for math library)
gcc taylor_series.c -o taylor_series -lm
./taylor_series
```

---

## 👤 Author
* **Georgios Theocharis** ([@geotheo01](https://github.com/geotheo01))
