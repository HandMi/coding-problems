pub fn part_one(input: &Vec<String>) {
    let input_length = input.len() / 2;
    let string_length = input[0].len();

    let (gamma, epsilon) = input
        .iter()
        .fold(vec![0; string_length], |counts, bits| {
            counts
                .iter()
                .zip(bits.chars())
                .map(|(count, bit)| match bit {
                    '1' => *count + 1,
                    _ => *count,
                })
                .collect()
        })
        .iter()
        .rev()
        .enumerate()
        .fold((0, 0), |(g, e), (i, count)| {
            if count < &input_length {
                (g + (1 << i), e)
            } else {
                (g, e + (1 << i))
            }
        });

    println!("{}", gamma * epsilon)
}
