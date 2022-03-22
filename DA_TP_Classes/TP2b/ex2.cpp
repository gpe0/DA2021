#include "exercises.h"

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    if (n == 1) return A[i];
    int begin = i, end = j;
    int mid = (i + j + 1) / 2;
    int midS = (i + j + 1) / 2 - 1;

    int res1 = maxSubsequenceDC(A, n/2, i, midS);
    int res2 = maxSubsequenceDC(A, n/2, mid, j);
    int midSumRight = 0;
    int midSumLeft = 0;
    for (int k = (begin + end + 1) / 2; k <= end; k++) {
        int newSum = 0;
        for (int p = (begin + end + 1) / 2; p <= end; p++) {
            if (p <= k) newSum += A[p];
        }
        if (newSum > midSumRight) {
            midSumRight = newSum;
            j = k;
        }
    }
    for (int k = (begin + end + 1) / 2 - 1; k >= begin ; k--) {
        int newSum = 0;
        for (int p = (begin + end + 1) / 2 - 1; p >= begin ; p--) {
            if (p >= k) newSum += A[p];
        }
        if (newSum > midSumLeft) {
            midSumLeft = newSum;
            i = k;
        }
    }

    if (midSumRight + midSumLeft > res1 && midSumRight + midSumLeft > res2) return (midSumLeft + midSumRight);
    else {
        if (res1 > res2) {
            maxSubsequenceDC(A, n/2, i, midS);
            j = midS;
            return res1;
        }
        else {
            maxSubsequenceDC(A, n/2, mid, j);
            i = mid;
            return res2;
        }
    }

}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i=0, j=3;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    i=0, j=3;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    i=0, j=3;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    i=0, j=8;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}