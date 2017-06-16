fn are_permutations(s1 : &str, s2 : &str) -> bool {
    let s1Counts = get_ascii_counts(&s1);
    let s2Counts = get_ascii_counts(&s2);

    for i in 0..256 {
        if s1Counts[i] != s2Counts[i] {
            return false;
        }
    }

    return true;
}

fn get_ascii_counts(subject : &str) -> Vec<i32> {
    let mut counts = vec![0; 256];

    for c in subject.chars() {
        counts[c as usize] += 1;
    }

    return counts;
}

#[test]
fn t0() {
    assert!(are_permutations("Interview", "weivretnI") == true);
}

#[test]
fn t1() {
    assert!(are_permutations("road!", "!daor") == true);
}

#[test]
fn t2() {
    assert!(are_permutations("abdc", "acdb") == true);
}

#[test]
fn t3() {
    assert!(are_permutations("Speaker", "Speaker") == true);
}

#[test]
fn t4() {
    assert!(are_permutations("wood", "metal") == false);
}

#[test]
fn t5() {
    assert!(are_permutations("sword", "swo") == false);
}

#[test]
fn t6() {
    assert!(are_permutations("Wood", "wood") == false);
}