pub fn part_two(input: &Vec<(i32, i32)>) {
    let (length, depth, aim) = input.iter().fold((0, 0, 0), |(x, y, aim), (a, b)| {
        (x + a, y - a * aim, aim + b)
    });
    println!("{}", length * depth)
}
