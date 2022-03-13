// By: Gonçalo Leão

#include <iostream>
#include "exercises.h"
#include <algorithm>

bool Activity::operator==(const Activity &a2) const {
    return start == a2.start && finish == a2.finish;
}

bool Activity::operator<(const Activity &a2) const {
    return finish < a2.finish;
}

std::vector<Activity> earliestFinishScheduling(std::vector<Activity> A) {

    std::vector<Activity> res;

    std::sort(A.begin(), A.end());

    res.push_back(A.front());

    A.erase(A.begin());

    while (!A.empty()) {
        bool temp = true;
        for (int i = 0; i < A.size(); i++) {
            if (A[i].start >= res.back().finish) {
                res.push_back(A[i]);
                A.erase(A.begin() + i);
                temp = false;
                break;
            }
        }
        if (temp) break;

    }

    return res;
}

/// TESTS ///
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TP1_Ex6, activityScheduling) {
    std::vector<Activity> A = {{10,20}, {30, 35}, {5, 15}, {10, 40}, {40, 50}};
    std::vector<Activity> V = earliestFinishScheduling(A);
    EXPECT_EQ(V.size(), 3 );
    ASSERT_THAT(earliestFinishScheduling(A),  ::testing::ElementsAre(Activity(5, 15), Activity(30, 35), Activity(40, 50)));
}