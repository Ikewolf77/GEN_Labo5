#include "Movie.h"

double Movie::getAmount(int &frequentRenterPoints, int daysRented) const { // determine amounts for each line

    /*
    switch ( getPriceCode() ) {
        case Movie::REGULAR:
            amount += 2;
            if (daysRented > 2 )
                amount += (daysRented - 2 ) * 1.5 ;
            break;
        case Movie::NEW_RELEASE:
            amount += daysRented * 3;
            if(daysRented > 1)
                frequentRenterPoints++;
            break;
        case Movie::CHILDRENS:
            amount += 1.5;
            if (daysRented > 3 )
                amount += (daysRented - 3 ) * 1.5;
            break;
    }*/

    // add frequent renter points
    frequentRenterPoints++;

    return getPriceCode()->getAmount(frequentRenterPoints,daysRented);
}
