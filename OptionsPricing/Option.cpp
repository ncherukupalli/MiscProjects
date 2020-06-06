#include "Option.h"

Option::Option(double strike, double dtm): strikePrice(strike), daysToExpiry(dtm) {}

double Option::getStrikePrice() { return strikePrice; }

double Option::getDaysToExpiry() { return daysToExpiry; }

