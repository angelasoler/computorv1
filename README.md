# Computor v1

A C++ program that validates and solves polynomial equations of degree less than or equal to 2 in the form of `ax^b + cx^d = ex^f + gx^h`.

## Prerequisites

Before running this project, you need to have g++ installed on your system.

## Project Structure

```
computorv1/
├── computorv1.cpp  # Implementation of the equation solver
├── computorv1.hpp  # Header file with function declarations
├── main.cpp        # Entry point of the program
├── Makefile        # Build instructions
├── test_computorv1.cpp # Unit tests using Google Test
└── README.md       # This file
```

## Building and Running

To build the project:

```bash
make
```

To run the program:

```bash
./computor "equation"
```

For example:
```bash
./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```

## Testing

To build and run the unit tests:

```bash
make run_tests
```

## Features

- Parses polynomial equations in the format `a * X^b + c * X^d = e * X^f + g * X^h`.
- Reduces the equation to a normalized form.
- Solves equations up to the second degree.
- Handles complex solutions for second degree equations.
- Provides unit tests using Google Test framework.

## Output

For a quadratic equation with positive discriminant:
```
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly positive, the two solutions are:
0.905239
-0.475131
```

For a quadratic equation with negative discriminant:
```
Reduced form: 1 * X^0 + 2 * X^1 + 5 * X^2 = 0
Polynomial degree: 2
Discriminant is strictly negative, the two complex solutions are:
-1/5 + 2i/5
-1/5 - 2i/5
```

For a linear equation:
```
Reduced form: 1 * X^0 + 4 * X^1 = 0
Polynomial degree: 1
The Solution is:
-0.25
```
