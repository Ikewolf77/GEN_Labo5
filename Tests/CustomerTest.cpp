//
// Created by simon on 27.05.2020.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Customer_Rental/Customer.h"
#include "Movies/Movie.h"
#include "Movies/MovieType.h"

#include <memory>


TEST(CustomerTest, statement){

    Customer customer("Olivier");
    customer.addRental( Rental( Movie("Karate Kid"), 7));
    customer.addRental( Rental( Movie( "Avengers: Endgame", std::make_shared<NewRelease>() ), 5));
    customer.addRental( Rental( Movie("Snow White", std::make_shared<Children>() ), 3 ));

    EXPECT_EQ(customer.statement(), "Rental Record for Olivier\n\t"
                                    "Karate Kid\t9.5\n\t"
                                    "Avengers: Endgame\t15\n\t"
                                    "Snow White\t1.5\n"
                                    "Amount owed is 26\n"
                                    "You earned 4 frequent renter points");
}

TEST(MovieTypeTestRegular, getAmount){

    Regular r;
    int FrequentRenterPoints = 0;

    EXPECT_EQ(r.getAmount(FrequentRenterPoints,0),2);
    EXPECT_EQ(r.getAmount(FrequentRenterPoints,1),2);
    EXPECT_EQ(r.getAmount(FrequentRenterPoints,2),2);
    EXPECT_EQ(r.getAmount(FrequentRenterPoints,3),3.5);
    EXPECT_EQ(FrequentRenterPoints,0);
}

TEST(MovieTypeTestChildren, getAmount){

    Children c;
    int FrequentRenterPoints = 0;

    EXPECT_EQ(c.getAmount(FrequentRenterPoints,0),1.5);
    EXPECT_EQ(c.getAmount(FrequentRenterPoints,2),1.5);
    EXPECT_EQ(c.getAmount(FrequentRenterPoints,4),3);
    EXPECT_EQ(c.getAmount(FrequentRenterPoints,6),6);
    EXPECT_EQ(FrequentRenterPoints,0);
}

TEST(MovieTypeTestNewRelease, getAmount){

    NewRelease n;
    int FrequentRenterPoints = 0;

    EXPECT_EQ(n.getAmount(FrequentRenterPoints,0),0);
    EXPECT_EQ(n.getAmount(FrequentRenterPoints,1),3);
    EXPECT_EQ(n.getAmount(FrequentRenterPoints,2),6);
    EXPECT_EQ(n.getAmount(FrequentRenterPoints,3),9);
    EXPECT_EQ(FrequentRenterPoints,2);
}

class NewReleaseMock : public NewRelease {
public:
    MOCK_METHOD(double, getAmount, (int &frequentRenterPoints, int daysRented));
};

TEST(Movie, getAmountNewRelease){

    Movie m("Avengers", std::make_shared<NewReleaseMock>());
    int frequentRenterPoints = 0;

    EXPECT_EQ(m.getTitle(),"Avengers");
    EXPECT_EQ(m.getAmount(frequentRenterPoints,0), 0);

}

class ChildrenMock : public Children {
public:
    MOCK_METHOD(double, getAmount, (int &frequentRenterPoints, int daysRented));
};

TEST(Movie, getAmountChildren){

    Movie m("TeleTobbies", std::make_shared<ChildrenMock>());
    int frequentRenterPoints = 0;

    EXPECT_EQ(m.getTitle(),"TeleTobbies");
    EXPECT_EQ(m.getAmount(frequentRenterPoints,0), 0);

}

class RegularMock : public Regular {
public:
    MOCK_METHOD(double, getAmount, (int &frequentRenterPoints, int daysRented));
};

TEST(Movie, getAmountRegular){

    Movie m("Generic film", std::make_shared<RegularMock>());
    int frequentRenterPoints = 0;

    EXPECT_EQ(m.getTitle(),"Generic film");
    EXPECT_EQ(m.getAmount(frequentRenterPoints,0), 0);

}

