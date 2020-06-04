//
// Created by simon on 04.06.2020.
//

#include "Rental.h"
#include <sstream>

using namespace std;

string Rental::getFigures(double &totalAmount, int &frequentRenterPoints) const {

    ostringstream result;
    double thisAmount = 0;

    // determine amounts for each line
    switch ( getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            thisAmount += 2;
            if ( getDaysRented() > 2 )
                thisAmount += ( getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if ( getDaysRented() > 3 )
                thisAmount += ( getDaysRented() - 3 ) * 1.5;
            break;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;

    return result.str();
}
