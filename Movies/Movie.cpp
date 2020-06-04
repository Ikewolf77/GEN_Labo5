#include "Movie.h"

const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

double Movie::getAmount(int &frequentRenterPoints, int daysRented) const { // determine amounts for each line

    double amount = 0;

    switch ( getPriceCode() ) {
        case Movie::REGULAR:
            amount += 2;
            if (daysRented > 2 )
                amount += (daysRented - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            amount += daysRented * 3;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if (daysRented > 3 )
                amount += (daysRented - 3 ) * 1.5;
            break;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ((getPriceCode() == Movie::NEW_RELEASE ) && daysRented > 1 )
        frequentRenterPoints++;

    return amount;
}
 