//
// Created by simon on 04.06.2020.
//

#include "Rental.h"
#include <sstream>

using namespace std;

string Rental::getFigures(double &totalAmount, int &frequentRenterPoints) const {

    ostringstream result;
    double thisAmount = getMovieAmount(frequentRenterPoints);

    // show figures for this rental
    result << "\t" << getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;

    return result.str();
}

double Rental::getMovieAmount(int &frequentRenterPoints) const {// determine amounts for each line

    double amount = 0;

    switch ( getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            amount += 2;
            if (getDaysRented() > 2 )
                amount += (getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            amount += getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if (getDaysRented() > 3 )
                amount += (getDaysRented() - 3 ) * 1.5;
            break;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ((getMovie().getPriceCode() == Movie::NEW_RELEASE )
        && getDaysRented() > 1 ) frequentRenterPoints++;

    return amount;
}
