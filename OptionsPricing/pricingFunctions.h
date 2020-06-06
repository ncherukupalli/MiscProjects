#ifndef OPTIONSPRICING_PRICINGFUNCTIONS_H
#define OPTIONSPRICING_PRICINGFUNCTIONS_H

#include "Option.h"

double getFutureStockPrice(double assetPrice, double growthFactor,
    int numGrowths, int totalSteps);

double getCallPriceBin(Option &call, double assetPrice, double intRate,
    double growthProb, double growthFactor, double timeStep);

double getCallPriceBinHelper(Option &call, double assetPrice, double intRate,
    double growthProb, double growthFactor, double timeStep,
    int u, int k);

#endif // OPTIONSPRICING_PRICINGFUNCTIONS_H

