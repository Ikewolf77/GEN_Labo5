//
// Created by simon on 04.06.2020.
//

#include "Rental.h"
#include <sstream>

using namespace std;

string Rental::getFigures(double &totalAmount, int &frequentRenterPoints) const {

    ostringstream result;
    double thisAmount = _movie.getAmount(frequentRenterPoints, _daysRented);

    // show figures for this rental
    result << "\t" << _movie.getTitle() << "\t" << thisAmount << "\n";
    totalAmount += thisAmount;

    return result.str();
}
