use std::fs;
use std::cmp;

fn main() {
    // read file into a string    
    let input: String = fs::read_to_string("input.txt")
        .expect("Something went wrong reading the file");

    let mut max: Vec<u32> = vec![0, 0, 0];

    let mut elf: Vec<u32> = Vec::new();
    // Each line is a calorie count
    input.lines().for_each(|line| {
        // Empty lines denote a different elf
        if line.is_empty() {
           // sum the calories
           let sum: u32 = elf.iter().sum();
           // find the max
           max[0] = cmp::max(sum, max[0]);
           max.sort();
           elf.clear();
        } else {
            elf.push(line.parse().unwrap());
        }
    });
    let sum:u32 = max.iter().sum();
    println!("The calorie count of the top 3 elves is: {:?}", sum);
}
