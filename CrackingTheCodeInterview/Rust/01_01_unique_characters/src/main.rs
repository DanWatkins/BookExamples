fn has_unique_chars(subject : &str) -> bool {
    // space = O(n)
    // time = O(n)

    let mut frequencies = vec![0; 256];

    for c in subject.chars() {
        let index = c as usize;

        if frequencies[index] > 0 {
            return false;
        }

        frequencies[index] += 1;
    }

    return true;
}

#[test]
fn t0() {
    assert!(has_unique_chars("Vertical"))
}

#[test]
fn t1() {
    assert!(has_unique_chars("12345") == true);
}

#[test]
fn t2() {
    assert!(has_unique_chars("Google") == false);
}

#[test]
fn t3() {
    assert!(has_unique_chars("K**hv3") == false);
}