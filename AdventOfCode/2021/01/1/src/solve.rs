pub fn part_one(input: &Vec<i32>) {
    println!(
        "{}",
        input
            .iter()
            .zip(input.iter().skip(1))
            .filter(|(x, y)| y > x)
            .count()
    )
}
