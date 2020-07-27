#include "fibonacci.hpp"

int fibonacci_iterative(int sequence) {
    if (sequence < 0) {
        return 0;
    }

    if ((sequence == 0) || (sequence == 1)) {
        return sequence;
    }

    int fibBeforePrevious = {};
    int fibPrevious = 1;
    int result = {};

    for (int i = 2; i <= sequence; i++) {
        result = fibPrevious + fibBeforePrevious;
        fibBeforePrevious = fibPrevious;
        fibPrevious = result;
    }

    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence < 0) {
        return 0;
    }
    return (sequence == 0) || (sequence == 1) ? sequence
                                              : fibonacci_recursive(sequence - 2) + fibonacci_recursive(sequence - 1);
}