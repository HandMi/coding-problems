fn binary_string_to_decimal(input: &String) -> u32 {
    return input.chars().rev().enumerate().fold(
        0,
        |sum, (i, x)| {
            if x == '1' {
                sum + (1 << i)
            } else {
                sum
            }
        },
    );
}

fn get_rating(input: &Vec<String>, low: char, high: char) -> u32 {
    let string_length = input[0].len();
    let mut filtered_input = (*input).clone();
    for i in 0..string_length {
        let one_count = filtered_input
            .iter()
            .filter(|s| s.as_bytes()[i] as char == '1')
            .count();
        let zero_count = filtered_input.len() - one_count;
        filtered_input = filtered_input
            .into_iter()
            .filter(|s| {
                if one_count >= zero_count {
                    s.as_bytes()[i] as char == high
                } else {
                    s.as_bytes()[i] as char == low
                }
            })
            .collect();
        if filtered_input.len() == 1 {
            return binary_string_to_decimal(&filtered_input[0]);
        }
    }
    return 0;
}

pub fn part_two(input: &Vec<String>) {
    let o2_rating = get_rating(input, '1', '0');
    let co2_rating = get_rating(input, '0', '1');
    println!("{}", co2_rating * o2_rating)
}
