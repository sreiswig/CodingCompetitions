use std::io;

fn numStrokes(painting: &str) -> u32 {
    let mut strokes = 0;
    let mut prevRed = false;
    let mut prevBlue = false;
    let mut prevYellow = false;

    for c in painting.chars() {
        match c {
            'R' => {
                if prevBlue {
                    strokes += 1;
                }
                if prevYellow {
                    strokes += 1;
                }
                prevRed = true;
                prevBlue = false;
                prevYellow = false;
            }
            'Y' => {
                if prevRed {
                    strokes += 1;
                }
                if prevBlue {
                    strokes += 1;
                }
                prevRed = false;
                prevBlue = false;
                prevYellow = true;
            }
            'B' => {
                if prevRed {
                    strokes += 1;
                }
                if prevYellow {
                    strokes += 1;
                }
                prevRed = false;
                prevBlue = true;
                prevYellow = false;
            }
            'O' => {
                if prevBlue {
                    strokes += 1;
                }
                prevRed = true;
                prevBlue = false;
                prevYellow = true;
            }
            'P' => {
                if prevYellow {
                    strokes += 1;
                }
                prevRed = true;
                prevBlue = true;
                prevYellow = false;
            }
            'G' => {
                if prevRed {
                    strokes += 1;
                }
                prevRed = false;
                prevBlue = true;
                prevYellow = true;
            }
            'A' => {
                prevRed = true;
                prevBlue = true;
                prevYellow = true;
            }
            _ => {
                if prevRed {
                    strokes += 1;
                }
                if prevBlue {
                    strokes += 1;
                }
                if prevYellow {
                    strokes += 1;
                }
                prevRed = false;
                prevBlue = false;
                prevYellow = false;
            }
        }
    }
    if prevRed {
        strokes += 1;
    }
    if prevBlue {
        strokes += 1;
    }
    if prevYellow {
        strokes += 1;
    }
    return strokes;
}

fn main() -> io::Result<()> {
    let mut input = String::new();
    io::stdin().read_line(&mut input)?;
    let test_cases: u32 = input.trim().parse().unwrap();

    for test_case in 1..test_cases + 1 {
        let mut result = 0;
        let mut paintingLength: u32;
        input.clear();
        io::stdin().read_line(&mut input)?;
        paintingLength = input.trim().parse().unwrap();
        let mut painting = String::new();
        io::stdin().read_line(&mut painting)?;
        painting.pop();
        let result = numStrokes(&painting);
        println!("Case #{}: {}", test_case, result);
    }
    return Ok(());
}