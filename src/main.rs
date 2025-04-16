use std::env;

#[derive(Debug)]
struct Term {
    coefficient: f64,
    exponent: i32,
}

fn parse_term(term: &str) -> Result<Term, String> {
    // Remove any whitespace
    let term = term.trim();
    
    // Split by 'x^'
    let parts: Vec<&str> = term.split("x^").collect();
    if parts.len() != 2 {
        return Err(format!("Invalid term format: {}", term));
    }

    // Parse coefficient
    let coefficient = parts[0]
        .trim()
        .parse::<f64>()
        .map_err(|_| format!("Invalid coefficient: {}", parts[0]))?;

    // Parse exponent
    let exponent = parts[1]
        .trim()
        .parse::<i32>()
        .map_err(|_| format!("Invalid exponent: {}", parts[1]))?;

    Ok(Term {
        coefficient,
        exponent,
    })
}

fn validate_expression(expr: &str) -> Result<Vec<Term>, String> {
    let mut terms = Vec::new();
    let mut last_exponent = i32::MIN;

    // Split by operators (+ or -)
    let parts: Vec<&str> = expr.split(|c| c == '+' || c == '-').collect();
    
    for part in parts.iter() {
        if part.trim().is_empty() {
            continue;
        }

        let term = parse_term(part)?;
        
        // Check ascending order of exponents
        if term.exponent <= last_exponent {
            return Err(format!(
                "Exponents must be in ascending order. Found {} after {}",
                term.exponent, last_exponent
            ));
        }
        
        last_exponent = term.exponent;
        terms.push(term);
    }

    Ok(terms)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() != 2 {
        println!("Usage: {} \"expression\"", args[0]);
        println!("Example: {} \"2x^1 + 3x^2\"", args[0]);
        return;
    }

    match validate_expression(&args[1]) {
        Ok(terms) => {
            println!("Valid expression! Parsed terms:");
            for term in terms {
                println!("Coefficient: {}, Exponent: {}", term.coefficient, term.exponent);
            }
        }
        Err(e) => {
            println!("Invalid expression: {}", e);
        }
    }
}
