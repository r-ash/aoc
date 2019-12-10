#include <Rcpp.h>
#include <math.h>
#include <iostream>
#include <stdexcept>
#include "day_1.h"
using namespace Rcpp;
using std::vector;
using std::cout;


//' Run intcode
//'
//' @param programme The intcode programme
//' @return The decoded intcode
//' @export
// [[Rcpp::export]]
std::vector<int> intcode(std::vector<int> programme) {
  for (int i = 0; i < programme.size(); i += 4) {
    if (programme[i] == 99) {
      return(programme);
    } else if (programme[i] == 1) {
      programme[programme[i + 3]] = programme[programme[i + 1]] + programme[programme[i + 2]];
    } else if (programme[i] == 2) {
      programme[programme[i + 3]] = programme[programme[i + 1]] * programme[programme[i + 2]];
    } else {
      throw std::invalid_argument("intcode not recognised. Each block should start with 1, 2 or 99.");
    }
  }
  throw std::invalid_argument("intcode issue - got to end without encountering 99.");
}

//' Problem asks us to run so arbitrary updates before decoding
//'
//' @param programme The intcode programme
//' @return The updated intcode
//' @export
// [[Rcpp::export]]
std::vector<int> update_programme(std::vector<int> programme) {
  programme[1] = 12;
  programme[2] = 2;
  return(programme);
}


//' Set noun and verb and run to get the output
//'
//' @param programme The number to get factors for
//' @export
// [[Rcpp::export]]
std::vector<int> set_input_and_run(std::vector<int> programme, int noun, int verb) {
  programme[1] = noun;
  programme[2] = verb;
  return(intcode(programme));
}

//' Set noun and verb and run to get the output
//'
//' @param programme The number to get factors for
//' @export
// [[Rcpp::export]]
std::vector<int> get_19690720_input(std::vector<int> programme) {
  // This just uses some big brute force loop - there is probably a smarter
  // way to do this.
  for (int noun = 12; noun < 100; noun += 1) {
    for (int verb = 2; verb < 100; verb += 1) {
      std::vector<int> result = set_input_and_run(programme, noun, verb);
      std::cout << "first val of output is " << result[0] << "\n";
      if (result[0] == 19690720) {
        std::vector<int> output(2);
        output[0] = noun;
        output[1] = verb;
        return(output);
      }
    }
  }
  throw std::invalid_argument("couldn't find input in these ranges");
}
