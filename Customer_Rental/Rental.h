// Rental.h
#ifndef RENTAL_H
#define RENTAL_H
#include "Movies/Movie.h"
#include <string>

class Rental {
public:
    Rental( const Movie& movie, int daysRented );

    int getDaysRented() const;
    const Movie& getMovie() const;

    std::string getFigures(double &totalAmount, int &frequentRenterPoints) const;

private:
    Movie _movie;
    int _daysRented;

    double getMovieAmount(int &frequentRenterPoints, double thisAmount) const;
};

inline Rental::
Rental( const Movie& movie, int daysRented )
        : _movie( movie )
        , _daysRented( daysRented ) {}

inline int Rental::
getDaysRented() const { return _daysRented; }

inline const Movie& Rental::
getMovie() const { return _movie; }

#endif // RENTAL_H