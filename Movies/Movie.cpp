#include "Movie.h"

double Movie::getAmount(int &frequentRenterPoints, int daysRented) const { // determine amounts for each line

    // add frequent renter points
    frequentRenterPoints++;

    return getPriceCode()->getAmount(frequentRenterPoints,daysRented);
}
