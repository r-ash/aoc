library("aoc")

input <- read.csv(system.file("extdata", "day_2.txt", package = "aoc"), header = FALSE, stringsAsFactors = FALSE)
input <- as.integer(input)
intcode(update_programme(input))

output <- get_19690720_input(input)
noun <- output[1]
verb <- output[2]
answer <- 100 * noun + verb
