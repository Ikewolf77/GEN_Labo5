//
// Created by simon on 04.06.2020.
//

#include "Rental.h"
#include <sstream>

using namespace std;

string Rental::getRentalFigures(double &totalAmount, int &frequentRenterPoints) const {

    ostringstream result;
    double thisAmount = 0;
    Rental each = *this;

    // determine amounts for each line
    switch ( each.getMovie().getPriceCode() ) {
        case Movie::REGULAR:
            thisAmount += 2;
            if ( each.getDaysRented() > 2 )
                thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += each.getDaysRented() * 3;
            break;
        case Movie::CHILDRENS:
            thisAmount += 1.5;
            if ( each.getDaysRented() > 3 )
                thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
            break;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;

    return result.str();
}
