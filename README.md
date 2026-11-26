# C Applied Algorithms & Systems Programming

A modular repository of practical C implementations demonstrating manual memory management, pointer manipulation, numerical analysis, and algorithmic problem-solving.

---

## 📋 Modules & Implementations

| File | Module | Description | Technical Highlights |
| :--- | :--- | :--- | :--- |
| **[`guess_number.c`](guess_number.c)** | **Interactive Guessing Engine** | CLI-based game engine utilizing pseudo-random generation with bounded search space and attempt control. | `rand()`, `srand()`, `time.h`, iterative control flow |
| **[`linear_equation.c`](linear_equation.c)** | **Linear Equation Solver** | Analytical solver for $ax + b = 0$ returning solution states (unique, impossible, indeterminate). | Pass-by-reference (`*x`), function interfaces, error codes |
| **[`quadratic_equation.c`](quadratic_equation.c)** | **Quadratic Equation Solver** | Robust quadratic solver evaluating real and complex roots via discriminant ($\Delta$) analysis. | `math.h`, `sqrt()`, pointers, numerical boundary checks |
| **[`dynamic_array.c`](dynamic_array.c)** | **Dynamic Array Manager** | Allocates heap memory for contiguous double arrays with explicit initialization and leak-free destruction. | `malloc()`, `free()`, heap management, pointer validation |
| **[`random_ascii.c`](random_ascii.c)** | **Random ASCII Generator** | Generates bounded character streams across the standard printable ASCII spectrum (32 to 126). | Character buffers, ASCII encoding, random distribution |
| **[`taylor_series.c`](taylor_series.c)** | **Taylor Series Sine Approximation** | High-precision numerical approximation of $\sin(x)$ using Maclaurin/Taylor expansion bounded by $10^{-6}$ epsilon. | Series expansion, numerical analysis, precision convergence |

---

## 🛠️ Build & Execution

All modules are written in standard ANSI/ISO C and compile cleanly using `gcc` on Linux / WSL:

```bash
# 1. Interactive Guessing Engine
gcc guess_number.c -o guess_number
./guess_number

# 2. Linear Equation Solver
gcc linear_equation.c -o linear_equation
./linear_equation

# 3. Quadratic Equation Solver (linked with math library)
gcc quadratic_equation.c -o quadratic_equation -lm
./quadratic_equation

# 4. Dynamic Array Manager
gcc dynamic_array.c -o dynamic_array
./dynamic_array

# 5. Random ASCII Generator
gcc random_ascii.c -o random_ascii
./random_ascii

# 6. Taylor Series Sine Approximation (linked with math library)
gcc taylor_series.c -o taylor_series -lm
./taylor_series
```

---

## 👤 Author
* **Georgios Theocharis** ([@geotheo01](https://github.com/geotheo01))
