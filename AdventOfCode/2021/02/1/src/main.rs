mod solve;
use itertools::Itertools;
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

    let numbers: Vec<_> = reader
        .lines()
        .map(|line| {
            line.unwrap()
                .split_whitespace()
                .collect_tuple()
                .map(|(dir, num)| (dir, num.parse::<i32>().unwrap()))
                .map(|(d, x)| match (d, x) {
                    ("forward", x) => (x, 0),
                    ("down", x) => (0, x),
                    ("up", x) => (0, -x),
                    _ => unreachable!(),
                })
        })
        .flatten()
        .collect();
    solve::part_one(&numbers);
}
