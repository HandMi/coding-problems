pub fn part_one(input: &Vec<(i32, i32)>) {
    let (length, depth) = input.iter().fold((0, 0), |(a, b), (c, d)| (a + c, b + d));
    println!("{}", length * depth)
}
