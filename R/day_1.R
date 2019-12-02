#' Solve day 1 problem 1
#'
#' @param file Path to file of component masses
#'
#' @return The fuel required to launch all the components
#' @export
solve_day_1 <- function(file) {
  lines <- readLines(file)
  masses <- as.integer(lines)
  fuel_required(masses)
}

#' Solve day 1 problem 2
#'
#' @param file Path to file of component masses
#'
#' @return The fuel required to launch all the components and the fuel itself
#' @export
solve_day_1_puzzle_2 <- function(file) {
  lines <- readLines(file)
  masses <- as.integer(lines)
  fuel_and_fuel_mass_required(masses)
}
