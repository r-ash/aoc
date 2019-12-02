#include <Rcpp.h>
#include <math.h>
#include "day_1.h"
using namespace Rcpp;
using std::vector;

//' Calculate total fuel required from a set of components via their masses.
//'
//' @param masses Masses of components
//' @return The total fuel required
//' @export
// [[Rcpp::export]]
int fuel_required(std::vector<int> masses) {
  int total_fuel = 0;
  for (const auto& mass: masses) {
    total_fuel += fuel(mass);
  }
  return total_fuel;
}

int fuel(int mass) {
  if (mass == 0) {
    return 0;
  }
  int fuel = floor(mass/3) - 2;
  if (fuel < 0) {
    fuel = 0;
  }
  return fuel;
}

//' Recursively calculate the total fuel required to launch.
//'
//' This is if it takes x mass of fuel to launch then how much extra fuel
//' do we need to launch the addition x mass etc.
//'
//' @param mass The mass of the fuel to be launched
//' @return The total fuel required to launch
//' @export
// [[Rcpp::export]]
int fuel_recursive(int mass) {
  int total_fuel = 0;
  int mass_of_fuel = fuel(mass);
  if (mass_of_fuel > 0) {
    total_fuel += mass_of_fuel + fuel_recursive(mass_of_fuel);
  }
  return total_fuel;
}

//' Calculate total fuel required from a set of components via their masses.
//'
//' @param masses Masses of components
//' @return The total fuel required
//' @export
// [[Rcpp::export]]
int fuel_and_fuel_mass_required(std::vector<int> masses) {
  int total_fuel = 0;
  for (const auto& mass: masses) {
    int fuel_required = fuel(mass);
    total_fuel += fuel_required + fuel_recursive(fuel_required);
  }
  return total_fuel;
}
