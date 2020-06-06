#include <iostream>
#include "Option.h"
using namespace std;

int main() {
    Option testCall = Option(100, 22);
    cout << testCall.getStrikePrice() << endl;
    cout << testCall.getDaysToExpiry() << endl;
    // cout << "Hello world" << endl;
}
