use std::io;

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    let test_cases: u32 = input.trim().parse().unwrap();

    for test_case in 1..test_cases + 1 {
        let mut result = 0;

        println!("Case #{}: {}", test_case, result);
    }
    return Ok(());
}