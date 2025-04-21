use std::env;

// #[derive(Debug)]
// struct Term {
//     coefficient: f64,
//     exponent: u8,
// }

// fn reduce_form(expr: &str) -> Result<Vec<Term>, String> {
fn reduce_form(expr: &str) {
    // let mut terms = Vec::new();
    let parts: Vec<&str> = expr.split(|c| c == '=').collect();

    // if parts.len() != 2 {
    //     return Err(format!(
    //         "Expression must contain exactly one '='"
    //     ));
    // }
    for part in parts.iter() {
        let parts2: Vec<&str> = part.replace(" ", "");
    }
    println!("{:?}", parts);

    // let mut eq: Vec<&str> = parts[0].split("*x^").collect();
    // parts[1] = &parts[1].replace(" ", "")
    // eq.extend(parts[1].split(' '));
    

    // Ok(terms)
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() != 2 {
        println!("Usage: {} \"expression\"", args[0]);
        println!("Example: {} \"2 * x^1 + 3 * x^2\"", args[0]);
        return;
    }

    // let terms: Vec<Term> = reduce_form(&args[1]).unwrap();
    reduce_form(&args[1]);
    // polinomial_degree(terms).unwrap();
    // solution(terms).unwrap();
}
