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
    unsigned int used1[n];
    unsigned int used2[n];

    for (int i = 0; i < n; i++) {
        S[i] = 5;
        used1[i] = 0;
        used2[i] = 0;
    }

    for (int i = C[2] + 2; i < C[n - 2] + C[n - 1]; i++) {
        for (int j = 0; j < n; j++) {
            used1[j] = 0;
            S[j] = 5;
        }
        changeMakingBF(C, S, n, i, used1);

        for (int j = 0; j < n; j++) {
            S[j] = 5;
        }

        changeMakingGreedy(C, S, n, i, used2);

        for (int j = 0; j < n; j++) {
            if (used1[j] != used2[j]) {
                return false;
            }
        }
    }


    return true;
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
    EXPECT_EQ(isCanonical(C,3), false);
}