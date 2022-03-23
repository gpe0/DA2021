#include "exercises.h"

int minCoins(unsigned int C[], unsigned int n, unsigned int T, unsigned long mem[]) {

    if (T == 0) {
        mem[0] = 0;
        return 0;
    }

    if (mem[T] != 0) return mem[T];
    int best = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (C[i] <= T) {
            if (mem[T - C[i]] == INT_MAX) best = INT_MAX;
            else if (mem[T - C[i]] < best) best = mem[T - C[i]] + 1;
        }
    }
    mem[T] = best;
    return best;
}

int lastCoin(unsigned int C[], unsigned int n, unsigned int T, unsigned long mem1[], long mem2[]) {
    if (T == 0) {
        mem2[0] = -1;
        return -1;
    }

    if (mem2[T] != 0) return mem2[T];
    int best = INT_MAX;
    int ind;

    for (int i = 0; i < n; i++) {
        if (C[i] <= T) {
            if (mem1[T - C[i]] == INT_MAX) best = INT_MAX;
            else if (mem1[T - C[i]] < best) {
                best = mem1[T - C[i]] + 1;
                ind = i;
            }
        }
    }
    mem2[T] = ind;
    return ind;
}

bool changeMakingUnlimitedDP(unsigned int C[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    static unsigned long mem1[100];
    static long mem2[100];
    for (int i = 0; i < n; i++) usedCoins[i] = 0;
    for (int i = 0; i < 100; i++) mem1[i] = 0;
    for (int i = 0; i < 100; i++) mem2[i] = 0;
    for (int i = 0; i <= T; i++) minCoins(C, n, i, mem1);
    if (minCoins(C, n, T,mem1) == INT_MAX) return false;

    for (int i = 0; i <= T; i++) {
        lastCoin(C, n, i, mem1, mem2);
    }

    int temp = lastCoin(C, n, T, mem1, mem2);
    while (temp != -1) {
        usedCoins[temp]++;
        T -= C[temp];
        temp = lastCoin(C, n, T, mem1, mem2);
    }
    return true;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, hasChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 1);
    EXPECT_EQ(usedCoins[3], 3);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,10,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);
}

TEST(TP4_Ex2, hasChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,7,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 2);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);
}

TEST(TP4_Ex2, hasNoChange) {
    unsigned int C[] = {5,10};
    unsigned int n = 2;
    unsigned int usedCoins[2];

    EXPECT_EQ(changeMakingUnlimitedDP(C,n,1,usedCoins), false);
}