fn compress_repeated_characters(subject : &str) -> String {
    if subject.len() == 0 {
        return "".to_owned();
    }

    let mut buffer = String::new();
    buffer.reserve(subject.len() * 2 + 1);

    let mut count = 1;
    let mut last_char = subject.chars().nth(0);

    for i in 1..subject.len() {
        let current_char = subject.chars().nth(i);

        if last_char == current_char {
            count += 1;
        }
        else {
            buffer.push(last_char.unwrap());
            buffer.push_str(&count.to_string());

            last_char = current_char;
            count = 1;
        }
    }

    buffer.push(last_char.unwrap());
    buffer.push_str(&count.to_string());

    return buffer;
}

fn uncompress_repeated_character(subject : &str) -> &str {
    // TODO this one is bonus points

    return "";
}

#[test]
fn t0() {
    assert_eq!(compress_repeated_characters("aabcccccaaa"), "a2b1c5a3");
}

#[test]
fn t1() {
    assert_eq!(compress_repeated_characters("#Coding"), "#1C1o1d1i1n1g1");
}

#[test]
fn t2() {
    assert_eq!(compress_repeated_characters("ooooo"), "o5");
}

#[test]
fn t3() {
    assert_eq!(compress_repeated_characters(""), "");
}

#[test]
fn t4() {
    assert_eq!(compress_repeated_characters("a5b7"), "a151b171");
}