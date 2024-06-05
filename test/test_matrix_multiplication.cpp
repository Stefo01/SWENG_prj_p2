#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


// The following test tries to multiply different size matrices
// This was the original test.
TEST(MatrixMultiplicationTest, TestMultiplyMatrices)
{
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}};
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply two empty squared matrices
TEST(MatrixMultiplicationTest, ZeroMatrix)
{
    std::vector<std::vector<int>> A = {
        {0, 0},
        {0, 0}};
    std::vector<std::vector<int>> B = {
        {0, 0},
        {0, 0}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {0, 0},
        {0, 0}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply a squared matrix by the Identity
TEST(MatrixMultiplicationTest, IdentityMatrix)
{
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 4}};
    std::vector<std::vector<int>> B = {
        {1, 0},
        {0, 1}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {1, 2},
        {3, 4}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries negative values
TEST(MatrixMultiplicationTest, NegativeVectorScalarMultiplication)
{
    std::vector<std::vector<int>> A(100, std::vector<int>(1));

    // Riempie la matrice con numeri da 1 a 100
    int number = -49;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            A[i][j] = number;
            number++;
        }
    }

    std::vector<std::vector<int>> B = {{1}};

    std::vector<std::vector<int>>
        C(100, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 100, 1, 1);

    std::vector<std::vector<int>> expected;
    expected = A;

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply a vector by a scalar
TEST(MatrixMultiplicationTest, VectorScalarMultiplication)
{
    std::vector<std::vector<int>> A(100, std::vector<int>(1));

    // Riempie la matrice con numeri da 1 a 100
    int number = 1;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            A.at(i).at(j) = number;
            number++;
        }
    }

    std::vector<std::vector<int>> B = {{1}};

    std::vector<std::vector<int>> C(100, std::vector<int>(1));

    multiplyMatrices(A, B, C, 100, 1, 1);

    std::vector<std::vector<int>> expected;
    expected = A;

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply a scalar by a scalar

TEST(MatrixMultiplicationTest, ScalarScalarMultiplication)
{
    
    std::vector<std::vector<int>> A = {{8}};

    std::vector<std::vector<int>> B = {{8}};

    std::vector<std::vector<int>> C(1, std::vector<int>(1));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected;
    expected = {{64}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply a vector by a vector
TEST(MatrixMultiplicationTest, VectorVectorMultiplication)
{
    std::vector<std::vector<int>> A(10, std::vector<int>(1));
    std::vector<std::vector<int>> B(1, std::vector<int>(10));

    // Riempie la matrice con numeri da 1 a 100
    int number = 1;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            A.at(i).at(j) = number;
            B.at(j).at(i) = number;
            number++;
        }
    }

    std::vector<std::vector<int>> C(10, std::vector<int>(10));

    multiplyMatrices(A, B, C, 10, 1, 10);

    std::vector<std::vector<int>> expected = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {2, 4, 6, 8, 10, 12, 14, 16, 18, 20},
        {3, 6, 9, 12, 15, 18, 21, 24, 27, 30},
        {4, 8, 12, 16, 20, 24, 28, 32, 36, 40},
        {5, 10, 15, 20, 25, 30, 35, 40, 45, 50},
        {6, 12, 18, 24, 30, 36, 42, 48, 54, 60},
        {7, 14, 21, 28, 35, 42, 49, 56, 63, 70},
        {8, 16, 24, 32, 40, 48, 56, 64, 72, 80},
        {9, 18, 27, 36, 45, 54, 63, 72, 81, 90},
        {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}};
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test tries to multiply a vector by a vector
TEST(MatrixMultiplicationTest, VectorVectorMultiplication2)
{
    std::vector<std::vector<int>> A(1, std::vector<int>(10));
    std::vector<std::vector<int>> B(10, std::vector<int>(1));

    // Riempie la matrice con numeri da 1 a 100
    int number = 1;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            B.at(i).at(j) = number;
            A.at(j).at(i) = number;
            number++;
        }
    }

    std::vector<std::vector<int>> C(1, std::vector<int>(1));

    multiplyMatrices(A, B, C, 1, 10, 1);

    std::vector<std::vector<int>> expected = {{385}};
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The next tests tries to understand Error17 behavior, given the fact that
// Error17 requests a value equal to 17 in the result matrix, but Error7
// requests a value between 11 and 20 in the result matrix and it changes
// that value. In the next test it's showing that Error7 add 3 to the correct result
// of the multiplication.
TEST(MatrixMultiplicationTest, Error17)
{
    std::vector<std::vector<int>> A = {
        {14, 5, 0, 6}};
    std::vector<std::vector<int>> B = {
        {1, 2, 4},
        {0, 2, 4},
        {0, 2, 4},
        {0, 2, 4}};
    std::vector<std::vector<int>> C(1, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 1, 4, 3);

    std::vector<std::vector<int>> expected = {
        {14, 50, 100}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The next test has been inserted trying to get a correct result, showing that it's possible
TEST(MatrixMultiplicationTest, NoError)
{
    std::vector<std::vector<int>> A = {
        {2, 5, 0, 6}};
    std::vector<std::vector<int>> B = {
        {1, 2, 4},
        {0, 2, 4},
        {0, 2, 4},
        {0, 2, 4}};
    std::vector<std::vector<int>> C(1, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 1, 4, 3);

    std::vector<std::vector<int>> expected = {
        {2, 26, 52}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}


// This test tries to multiply squared matrices.
TEST(MatrixMultiplicationTest10, TestMultiplyMatrices)
{
    std::vector<std::vector<int>> A = {
        {-1, 1},
        {1, 1}};
    std::vector<std::vector<int>> B = {
        {-1, 1},
        {1, 1}};
    std::vector<std::vector<int>> C = {
        {0, 0},
        {0, 0}};

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {2, 0},
        {0, 2}};

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

// The following test suite shows the different behavior between ./test_multiplication and ctest
// The Error 17 doesnt always show up when calling tests using ./test_multiplication but does so
// when calling ctest.
TEST(TestDifferentBehavior, Error17Present)
{
    std::vector<std::vector<int>> A = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}, {18}, {19}, {20}, {21}, {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30}, {31}, {32}, {33}, {34}, {35}, {36}, {37}, {38}, {39}, {40}, {41}, {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50}, {51}, {52}, {53}, {54}, {55}, {56}, {57}, {58}, {59}, {60}, {61}, {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70}, {71}, {72}, {73}, {74}, {75}, {76}, {77}, {78}, {79}, {80}, {81}, {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90}, {91}, {92}, {93}, {94}, {95}, {96}, {97}, {98}, {99}, {100}};

    std::vector<std::vector<int>> B = {
        {1}};

    std::vector<std::vector<int>> C(100, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 100, 1, 1);

    std::vector<std::vector<int>> expected = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}, {18}, {19}, {20}, {21}, {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30}, {31}, {32}, {33}, {34}, {35}, {36}, {37}, {38}, {39}, {40}, {41}, {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50}, {51}, {52}, {53}, {54}, {55}, {56}, {57}, {58}, {59}, {60}, {61}, {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70}, {71}, {72}, {73}, {74}, {75}, {76}, {77}, {78}, {79}, {80}, {81}, {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90}, {91}, {92}, {93}, {94}, {95}, {96}, {97}, {98}, {99}, {100}};

    ASSERT_EQ(C, expected) << "Matrix contains 17";
}

TEST(TestDifferentBehavior, Error17NotPresent)
{
    std::vector<std::vector<int>> A = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}, {18}, {19}, {20}, {21}, {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30}, {31}, {32}, {33}, {34}, {35}, {36}, {37}, {38}, {39}, {40}, {41}, {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50}, {51}, {52}, {53}, {54}, {55}, {56}, {57}, {58}, {59}, {60}, {61}, {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70}, {71}, {72}, {73}, {74}, {75}, {76}, {77}, {78}, {79}, {80}, {81}, {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90}, {91}, {92}, {93}, {94}, {95}, {96}, {97}, {98}, {99}, {100}};

    std::vector<std::vector<int>> B = {
        {1}};

    std::vector<std::vector<int>> C(100, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 100, 1, 1);

    std::vector<std::vector<int>> expected = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}, {18}, {19}, {20}, {21}, {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30}, {31}, {32}, {33}, {34}, {35}, {36}, {37}, {38}, {39}, {40}, {41}, {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50}, {51}, {52}, {53}, {54}, {55}, {56}, {57}, {58}, {59}, {60}, {61}, {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70}, {71}, {72}, {73}, {74}, {75}, {76}, {77}, {78}, {79}, {80}, {81}, {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90}, {91}, {92}, {93}, {94}, {95}, {96}, {97}, {98}, {99}, {100}};

    ASSERT_EQ(C, expected) << "Matrix contains 17";
}


// This test tries to check if the program has some protective way to block invalid vectors as matrix, like null vectors.
// The segmentation fault means that it doesn't do any checks on the lenght.
TEST(MatrixMultiplicationTest, NullMatrix)
{
    std::vector<std::vector<int>> A = {};
    std::vector<std::vector<int>> B = {};
    std::vector<std::vector<int>> C(0, std::vector<int>(0, 0));

    multiplyMatrices(A, B, C, 0, 0, 0);

    std::vector<std::vector<int>> expected = {};
    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :((((";
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// This is the list of all the error we encountered in our tests.
// Error 1 : Element - wise multiplication of ones detected !
// Error 2 : Matrix A contains the number 7 !
// Error 3 : Matrix A contains a negative number !
// Error 4 : Matrix B contains the number 3 !
// Error 5 : Matrix B contains a negative number !
// Error 6 : result matrix contains a number bigger than 100 !
// Error 7 : Result matrix contains a number between 11 and 20 !
// Error 8 : Result matrix contains zero !
// Error 9 : Result matrix contains the number 99 !
// Error 10 : A row in matrix A contains more than one '1' !
// Error 11 : Every row in matrix B contains at least one '0' !
// Error 12 : The number of rows in A is equal to the number of columns in B !
// Error 13 : The first element of matrix A is equal to the first element of matrix B !
// Error 14 : The result matrix C has an even number of rows !
// Error 15 : A row in matrix A is filled entirely with 5s !
// Error 16 : Matrix B contains the number 6 !
// Error 17 : Result matrix C contains the number 17 !
// Error 18 : Matrix A is square matrix !
// Error 19 : Every row in matrix A contains the number 8 !
// Error 20 : Number of columns in matrix A is odd !
