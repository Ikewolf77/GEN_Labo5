// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <memory>
#include <utility>
#include "MovieType.h"

class Movie {
public:

    Movie( std::string  title, std::shared_ptr<MovieType> priceCode = std::make_shared<Regular>());

    std::shared_ptr<MovieType> getPriceCode() const;
    void setPriceCode( std::shared_ptr<MovieType> arg );
    std::string getTitle() const;
    double getAmount(int &frequentRenterPoints, int daysRented) const;

private:
    std::string _title;
    std::shared_ptr<MovieType> _priceCode;
};

inline Movie::
Movie( std::string title, std::shared_ptr<MovieType> priceCode )
        : _title(std::move( title ))
        , _priceCode(std::move( priceCode ))
{}

inline std::shared_ptr<MovieType> Movie::getPriceCode() const {
    return _priceCode;
}

inline void Movie::setPriceCode( std::shared_ptr<MovieType> arg ) {
    _priceCode = std::move(arg);
}

inline std::string Movie::getTitle() const {
    return _title;
}

#endif // MOVIE_H