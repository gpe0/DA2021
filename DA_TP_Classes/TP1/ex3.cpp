// By: Gonçalo Leão

#include "exercises.h"
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

bool isEmpty(unsigned int a[], unsigned int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) return false;
    }
    return true;
}

int cmbf(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    if (T == 0) return 0;
    if (isEmpty(Stock, n)) return INT_MAX / 2;
    int res = INT_MAX / 2;
    unsigned int tempU[n];
    unsigned int before[n];
    int bIndex;

    for (int i = 0; i < n; i++) {
        tempU[i] = usedCoins[i];
        before[i] = usedCoins[i];
    }

    for (int i = 0; i < n; i++) {
        if (C[i] > T || Stock[i] <= 0) continue;
        Stock[i]--;
        tempU[i]++;
        int temp = cmbf(C, Stock, n, T - C[i], tempU);

        if (temp + 1 < res) {
            for (int i = 0; i < n; i++) {
                usedCoins[i] = tempU[i];
                tempU[i] = before[i];
            }
            res = temp + 1;
        } else {
            Stock[i]++;
            tempU[i]--;
        }
    }
    return res;
}


bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    if (cmbf(C, Stock, n, T, usedCoins) != INT_MAX / 2) return true;
    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4] = {0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    for (int i = 0; i < 4; i++) usedCoins[i] = 0;

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3] = {0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    for (int i = 0; i < 3; i++) usedCoins[i] = 0;
    Stock[0] = 2;
    Stock[1] = 2;
    Stock[2] = 1;

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4] = {0};

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);

    for (int i = 0; i < 4; i++) usedCoins[i] = 0;

    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}