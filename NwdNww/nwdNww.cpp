#include "nwdNww.hpp"
#include <cmath>

int NWW(int lhs,int rhs){
    if(NWD(lhs, rhs) == 0) {
        return {};
    }

    return abs((lhs * rhs) / NWD(lhs, rhs));
}
int NWD(int lhs, int rhs){
    int rest{};

    while(rhs != 0) {
        rest = lhs % rhs;
        lhs = rhs;
        rhs = rest;
    }

    return abs(lhs);
}