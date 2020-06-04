//
// Created by simon on 04.06.2020.
//

#ifndef SRC_MOVIETYPE_H
#define SRC_MOVIETYPE_H


class MovieType {
public:
    virtual double getAmount(int &frequentRenterPoints, int daysRented) = 0;
    virtual ~MovieType() = default;
};

class Regular : public MovieType {
public:
    double getAmount(int &frequentRenterPoints, int daysRented) override;
};

class Children : public MovieType {
public:
    double getAmount(int &frequentRenterPoints, int daysRented) override;
};

class NewRelease : public MovieType{
public:
    double getAmount(int &frequentRenterPoints, int daysRented) override;
};

inline double Regular::getAmount(int &frequentRenterPoints, int daysRented) {
    double amount = 2;
    if (daysRented > 2 )
        amount += (daysRented - 2) * 1.5 ;
    return amount;
}

inline double Children::getAmount(int &frequentRenterPoints, int daysRented) {
    double amount = 1.5;
    if (daysRented > 3 )
        amount += (daysRented - 3 ) * 1.5;
    return amount;
}

inline double NewRelease::getAmount(int &frequentRenterPoints, int daysRented) {
    if(daysRented > 1)
        frequentRenterPoints++;
    return daysRented * 3;
}


#endif //SRC_MOVIETYPE_H
