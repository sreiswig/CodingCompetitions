use std::io;

fn minTransform (s: &str, f: &str) -> i32 {
    let mut total = 0;
    for c in s.chars() {
        if !f.find(c).is_some() {
            let mut min = 27;
            for c2 in f.chars() {
                let mut distance = (c as i32 - c2 as i32).abs();
                if distance > 13 {
                    distance = 26 - distance;
                }
                if distance < min {
                    min = distance;
                }
            }
            total += min;
        }
    }
    return total;
}

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    let test_cases: u32 = input.trim().parse().unwrap();

    for test_case in 1..test_cases + 1 {
        let mut result = 0;
        let mut s = String::new();
        let mut f = String::new();
        io::stdin().read_line(&mut s)?;
        io::stdin().read_line(&mut f)?;
        // remove delimiter
        s.pop();
        f.pop();
        result = minTransform(&s, &f);
        println!("Case #{}: {}", test_case, result);
    }
    return Ok(());
}