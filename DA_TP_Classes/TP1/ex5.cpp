// By: Gonçalo Leão

#include "exercises.h"

unsigned int sumArray(unsigned int a[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

#include <iostream>

bool isCanonical(unsigned int C[], unsigned int n) {

    unsigned int S[n];
    unsigned int used[n];

    for (int i = 0; i < n; i++) {
        S[i] = INT_MAX;
    }

    for (int i = C[2] + 2; i < C[n - 2] + C[n - 1]; i++) {
        changeMakingBF(C, S, n, i, used);
        for (int i = 0; i < n; i++) std::cout << used[i] << std::endl;
    }

    return false;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex5, canonicalTrue) {
    unsigned int C[] = {1,2,5};
    EXPECT_EQ(isCanonical(C,3), true);

    unsigned int C2[] = {1,2,5,10};
    EXPECT_EQ(isCanonical(C2,4), true);
}

TEST(TP1_Ex5, canonicalFalse) {
    unsigned int C[] = {1,4,5};
    EXPECT_EQ(isCanonical(C,3), true);
}