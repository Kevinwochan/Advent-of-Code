use std::fs;
use std::collections::VecDeque;


fn main() {
    struct Action {
        scalar: u32,
        direction: String,
    }

    let input = fs::read_to_string("input.txt")
        .expect("Something went wrong reading the file");

    let mut depth=0;
    let mut horizontal=0;
    for action in input {
        match action {

        }
    }
    println!("{}", depth*horizontal);
}
