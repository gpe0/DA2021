// By: Gonçalo Leão

#include "exercises.h"


int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = 0;

    for (int p1 = 0; p1 < n; p1++) {
        for (int p2 = p1 + 1; p2 < n; p2++) {
            int t1 = p1, t2 = p2, temp = 0;
            while (t2 != t1) {
                temp += A[t2];
                t2--;
            }
            temp += A[t1];
            if (temp > maxSum) {
                maxSum = temp;
                i = p1;
                j = p2;
            }
        }
    }

    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}