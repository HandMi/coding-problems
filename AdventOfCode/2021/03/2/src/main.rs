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

    let numbers: Vec<_> = reader.lines().flatten().collect();
    solve::part_two(&numbers);
}
