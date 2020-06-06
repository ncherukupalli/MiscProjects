#ifndef OPTION_H
#define OPTION_H

class Option {
private:
    double strikePrice;
    double daysToExpiry;
public:
    Option(double strike, double dtm);
    double getStrikePrice();
    double getDaysToExpiry();
};

#endif