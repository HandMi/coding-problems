mod solve;
use std::env;
use std::fs;
use std::io::BufRead;
use std::io::BufReader;

fn main() {
    let args: Vec<String> = env::args().collect();
    let file_path = &args[1];

    println!("Path to txt: {}.", file_path);

    let file = fs::File::open(file_path).expect("file wasn't found.");
    let reader = BufReader::new(file);
    // let input = fs::read_to_string(filename).expect("Error while reading file");
    // println!("With text:\n{}", input);

    let numbers: Vec<i32> = reader
        .lines()
        .map(|line| line.unwrap().parse::<i32>().unwrap())
        .collect();
    solve::part_one(&numbers);
}
