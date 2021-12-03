use std::fs;
use std::collections::VecDeque;

fn main() {
    let input = fs::read_to_string("input")
        .expect("Something went wrong reading the file");

    let nums:Vec<i32> = input.split("\n")
        .map(|line| line.trim())
        .map(|line| line.parse().unwrap())
        .collect();

    let mut count=-1;
    let mut prev=0;
    let mut window = VecDeque::<i32>::new();
    for num in nums {
        window.push_back(num);
        println!("{}", window.len());
        if window.len() < 3 {
            continue;
        }
        let sum:i32 = window.iter().sum();
        if sum > prev {
            count += 1;
            println!("{} {}", sum, prev);
        }
        prev = sum;
        window.pop_front();
    }
    println!("{}", count);
}
