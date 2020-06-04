//
// Created by simon on 04.06.2020.
//

#include "Rental.h"
#include <sstream>

using namespace std;

string Rental::getFigures(double &totalAmount, int &frequentRenterPoints) const {

    ostringstream result;
    double thisAmount = getMovie().getMovieAmount(frequentRenterPoints,getDaysRented());

    // show figures for this rental
    result << "\t" << getMovie().getTitle() << "\t" << thisAmount << "\n";
    totalAmount += thisAmount;

    return result.str();
}
