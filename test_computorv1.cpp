#include <gtest/gtest.h>
#include "computorv1.cpp"

TEST(SubjectTests, ExampleTest) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(ReduceFormTests, ProvidedExpressions) {
    // Test case 1
    string expression1 = "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0";
    vector<float> result1 = ReduceForm(expression1);
    auto solution1 = QuadraticEquation(result1);
    auto vec_result = get<shared_ptr<vector<float>>>(solution1);
    //reduce form
    ASSERT_EQ(result1.size(), 3);
    EXPECT_FLOAT_EQ(result1[0], 4.0);
    EXPECT_FLOAT_EQ(result1[1], 4.0);
    EXPECT_FLOAT_EQ(result1[2], -9.3);
    //equation solution
    EXPECT_FLOAT_EQ(vec_result->at(0), -0.475131);
    EXPECT_FLOAT_EQ(vec_result->at(1), 0.905239);

    // Test case 2
    string expression2 = "5 * X^0 + 4 * X^1 = 4 * X^0";
    vector<float> result2 = ReduceForm(expression2);
    float solution2 = LinearEquation(result2);
    //reduce form
    ASSERT_EQ(result2.size(), 2);
    EXPECT_FLOAT_EQ(result2[0], 1.0);
    EXPECT_FLOAT_EQ(result2[1], 4.0);
    //equation solution
    EXPECT_FLOAT_EQ(solution2, -0.25);

    // Test case 3
    string expression3 = "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0";
    vector<float> result3 = ReduceForm(expression3);
    ASSERT_EQ(result3.size(), 4);
    //reduce form
    EXPECT_FLOAT_EQ(result3[0], 5.0);
    EXPECT_FLOAT_EQ(result3[1], -6.0);
    EXPECT_FLOAT_EQ(result3[2], 0.0);
    EXPECT_FLOAT_EQ(result3[3], -5.6);
    //equation solution

    // Test case 4
    string expression4 = "6 * X^0 = 6 * X^0";
    vector<float> result4 = ReduceForm(expression4);
    ASSERT_EQ(result4.size(), 1);
    EXPECT_FLOAT_EQ(result4[0], 0.0);

    // Test case 5
    string expression5 = "10 * X^0 = 15 * X^0";
    vector<float> result5 = ReduceForm(expression5);
    ASSERT_EQ(result5.size(), 1);
    EXPECT_FLOAT_EQ(result5[0], -5.0);

    // Test case 6
    string expression6 = "1 * X^0 + 2 * X^1 + 5 * X^2 = 0";
    vector<float> result6 = ReduceForm(expression6);
    auto vec_result2 = get<shared_ptr<vector<string>>>(solution1);
    //reduce form
    ASSERT_EQ(result6.size(), 3);
    EXPECT_FLOAT_EQ(result6[0], 1.0);
    EXPECT_FLOAT_EQ(result6[1], 2.0);
    EXPECT_FLOAT_EQ(result6[2], 5.0);
    //equation solution
    string s1 = "-1/5 + 2i/5";
    string s2 = "-1/5 - 2i/5";
    EXPECT_EQ(vec_result2->at(0), s1);
    EXPECT_EQ(vec_result2->at(1), s2);

    // Test case 4
    string expression4 = "42 * X^0 = 42 * X^0";
    vector<float> result4 = ReduceForm(expression4);
    ASSERT_EQ(result4.size(), 1);
    EXPECT_FLOAT_EQ(result4[0], 0.0);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
