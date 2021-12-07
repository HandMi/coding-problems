pub fn part_one(input: &Vec<i32>) {
    let triple_sum: Vec<i32> = input.windows(3).map(|slice| slice.iter().sum()).collect();
    println!(
        "{}",
        triple_sum
            .iter()
            .zip(triple_sum.iter().skip(1))
            .filter(|(x, y)| y > x)
            .count()
    )
}
