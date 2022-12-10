use std::fs;
use std::str;

/*
 A for Rock, B for Paper, and C for Scissors.
 X for Rock, Y for Paper, and Z for Scissors.
the score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors)

 */
fn get_outcome_score(your_move:&str, opponnent_move:&str)-> u32 {
    match your_move {
        "X" => {
           match opponnent_move {
            "C" => return 6,
            "A" => return 3,
            _ => return 0
           } 
        }
        "Y" => {
           match opponnent_move {
            "A" => return 6,
            "B" => return 3,
            _ => return 0
           } 
        }
        "Z" => {
           match opponnent_move {
            "B" => return 6,
            "C" => return 3,
            _ => return 0
           } 
        }
        _ => return 0
    };
}

fn get_shape_score(your_move:&str)->u32 {
    match your_move {
        "X" => return 1,
        "Y" => return 2,
        "Z" => return 3,
        _ => return 0
    } 
}
fn get_score(your_move:&str, opponent_move:&str) -> u32{
    return get_outcome_score(your_move, opponent_move) + get_shape_score(your_move);
}

// X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win
fn get_your_move(your_outcome:&str, opponent_move:&str) -> &'static str{
    match your_outcome {
        "Z" => { // win
           match opponent_move {
            "A" => return "Y",
            "B" => return "Z",
            _ => return "X"
           } 
        }
        "Y" => { // draw
           match opponent_move {
            "A" => return "X",
            "B" => return "Y",
            _ => return "Z"
           } 
        }
        "X" => { // lose
           match opponent_move {
            "A" => return "Z",
            "B" => return "X",
            _ => return "Y"
           } 
        }
        _ => return "K"
    };
}

fn main() {
    // read file into a string    
    let input: String = fs::read_to_string("input.txt")
        .expect("Something went wrong reading the file");

    let mut total_score: u32 = 0;

    input.lines().for_each(|line| {
        let moves: Vec<&str> = line.split(" ").collect();
        let opponent_move = moves.get(0).unwrap();
        let your_outcome = moves.get(1).unwrap();
        let your_move = get_your_move(your_outcome, opponent_move);
        println!("The move is {:?} against {:?} for the outcome {:?}", your_move, opponent_move, your_outcome);
        //println!("move is {:?} {:?} for score: {:?}", your_move, opponent_move, score);
        total_score += get_score(your_move, opponent_move);

    });
    println!("The total score sum is {:?}", total_score);
}
