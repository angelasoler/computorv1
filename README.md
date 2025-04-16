# Computor v1

A Rust program that validates and parses polynomial expressions in the form of `ax^b + cx^d`.al expressions in the form of `ax^b + cx^d`.

## Prerequisites

Before running this project, you need to have Rust and Cargo installed on your system. You can install them by following these steps:

1. Install Rustup (Rust installer and version manager):
```bash
sudo apt install rustup
```

2. Set up the stable Rust toolchain:
```bash
rustup default stable
```

## Project Structure

```
computor/
├── src/
│   └── main.rs      # The main source file
├── Cargo.toml       # Project configuration and dependencies
└── README.md        # This file
```

## Building and Running

To build and run the project:

```bash
cargo run -- "expression" -- "expression"
```

For example:
```bash```bash
cargo run -- "2x^1 + 3x^2"un -- "2x^1 + 3x^2"
```

To only build the project without running:To only build the project without running:

```bash```bash
cargo builduild
```

To check if the code compiles without producing an executable:To check if the code compiles without producing an executable:

```bash```bash
cargo check
```

## Features

- Parses polynomial terms in the format `ax^b`.
- Validates that the terms are in ascending order of exponents.
- Outputs the parsed terms if the expression is valid.

## Output

When run with a valid expression, the program will output:
```
Valid expression! Parsed terms:
Coefficient: 2, Exponent: 1
Coefficient: 3, Exponent: 2
```

If the expression is invalid, it will output an error message:
```
Invalid expression: <error message>
```

## Usage Example

Run the program with a polynomial expression as an argument:
```bash
cargo run -- "2x^1 + 3x^2"
