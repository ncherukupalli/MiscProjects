#include "pricingFunctions.h"
// #include "Option.h"
#include <math.h>
#include<algorithm>

double getFutureStockPrice(double assetPrice, double growthFactor,
    int numGrowths, int totalSteps) {
    return assetPrice * pow(growthFactor, 2 * numGrowths - totalSteps);
}

double getCallPriceBin(Option &call, double assetPrice, double intRate,
    double growthProb, double growthFactor, double timeStep) {
    return getCallPriceBinHelper(call, assetPrice, intRate, growthProb,
        growthFactor, timeStep, 0, 0);
}

double getCallPriceBinHelper(Option &call, double assetPrice, double intRate,
    double growthProb, double growthFactor, double timeStep,
    int u, int k) {
    
    // Boundary case
    double futurePrice = getFutureStockPrice(assetPrice, growthFactor, u, k);
    double excerciseProfit = std::max(0.0, futurePrice - call.getStrikePrice());
    if (k == int(call.getDaysToExpiry() / timeStep)) { return excerciseProfit; }

    // Recursive step
    double decay = exp(-1 * intRate * timeStep);
    double expectation = growthProb * (getCallPriceBinHelper(call, assetPrice,
        intRate, growthProb, growthFactor, timeStep, u + 1, k + 1)) +
        (1 - growthProb) * (getCallPriceBinHelper(call, assetPrice,
        intRate, growthProb, growthFactor, timeStep, u, k + 1));
    double adjExpectation = decay * expectation;

    return std::max(adjExpectation, std::max(0.0, futurePrice - call.getStrikePrice()));
}
