#include "test.h"

/*
    OPERATORS
*/

/*
    OPERATOR PLUS +
*/
TEST(Operator_Plus, test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m1(0, 1) = -13;
  m2(0, 0) = -22;
  m2(1, 1) = -100;

  try {
    S21Matrix res = m1 + m2;

    ASSERT_DOUBLE_EQ(res(0, 0), 0);
    ASSERT_DOUBLE_EQ(res(0, 1), -13);
    ASSERT_DOUBLE_EQ(res(1, 1), -100);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 0), -22);

    res = m2 + m1;

    ASSERT_DOUBLE_EQ(res(0, 0), 0);
    ASSERT_DOUBLE_EQ(res(0, 1), -13);
    ASSERT_DOUBLE_EQ(res(1, 1), -100);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 0), -22);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Plus, test_2) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;

  try {
    S21Matrix res = m + m;

    ASSERT_DOUBLE_EQ(res(0, 0), 44);
    ASSERT_DOUBLE_EQ(res(0, 1), -26);
    ASSERT_DOUBLE_EQ(res(1, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m(0, 0), 22);
    ASSERT_DOUBLE_EQ(m(0, 1), -13);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Plus, test_3) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;

  try {
    m = m + m;

    ASSERT_DOUBLE_EQ(m(0, 0), 44);
    ASSERT_DOUBLE_EQ(m(0, 1), -26);
    ASSERT_DOUBLE_EQ(m(1, 1), 0);
    ASSERT_DOUBLE_EQ(m(1, 0), 0);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Plus, test_4) {
  S21Matrix m1(2, 2), m2(3, 2);

  try {
    S21Matrix res = m1 + m2;
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}

/*
    OPERATOR MINUS -
*/

TEST(Operator_Minus, test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m1(0, 1) = -13;
  m2(0, 0) = -22;
  m2(1, 1) = -100;

  try {
    S21Matrix res = m1 - m2;

    ASSERT_DOUBLE_EQ(res(0, 0), 44);
    ASSERT_DOUBLE_EQ(res(0, 1), -13);
    ASSERT_DOUBLE_EQ(res(1, 1), 100);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 0), -22);

    res = m2 - m1;

    ASSERT_DOUBLE_EQ(res(0, 0), -44);
    ASSERT_DOUBLE_EQ(res(0, 1), 13);
    ASSERT_DOUBLE_EQ(res(1, 1), -100);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 0), -22);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Minus, test_2) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;

  try {
    S21Matrix res = m - m;

    ASSERT_DOUBLE_EQ(res(0, 0), 0);
    ASSERT_DOUBLE_EQ(res(0, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m(0, 0), 22);
    ASSERT_DOUBLE_EQ(m(0, 1), -13);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Minus, test_3) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;

  try {
    m = m - m;

    ASSERT_DOUBLE_EQ(m(0, 0), 0);
    ASSERT_DOUBLE_EQ(m(0, 1), 0);
    ASSERT_DOUBLE_EQ(m(1, 1), 0);
    ASSERT_DOUBLE_EQ(m(1, 0), 0);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Minus, test_4) {
  S21Matrix m1(2, 2), m2(3, 2);

  try {
    S21Matrix res = m1 - m2;
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}

/*
    OPERATOR MULT * (NUM)
*/

TEST(Operator_Mult_Num, test_1) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;

  try {
    S21Matrix res = m * 2;

    ASSERT_DOUBLE_EQ(res(0, 0), 44);
    ASSERT_DOUBLE_EQ(res(0, 1), -26);
    ASSERT_DOUBLE_EQ(res(1, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);

    ASSERT_DOUBLE_EQ(m(0, 0), 22);
    ASSERT_DOUBLE_EQ(m(0, 1), -13);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Num, test_2) {
  S21Matrix m(2, 3);

  m(0, 0) = 22;
  m(0, 1) = -13;
  m(0, 2) = 22.7;

  try {
    S21Matrix res = m * 2;

    ASSERT_DOUBLE_EQ(res(0, 0), 44);
    ASSERT_DOUBLE_EQ(res(0, 1), -26);
    ASSERT_DOUBLE_EQ(res(0, 2), 45.4);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);
    ASSERT_DOUBLE_EQ(res(1, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 2), 0);

    ASSERT_DOUBLE_EQ(m(0, 0), 22);
    ASSERT_DOUBLE_EQ(m(0, 1), -13);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Num, test_3) {
  S21Matrix m(2, 3);

  m(0, 0) = 22;
  m(0, 1) = -13;
  m(0, 2) = 22.7;

  try {
    m = m * 2;

    ASSERT_DOUBLE_EQ(m(0, 0), 44);
    ASSERT_DOUBLE_EQ(m(0, 1), -26);
    ASSERT_DOUBLE_EQ(m(0, 2), 45.4);
    ASSERT_DOUBLE_EQ(m(1, 0), 0);
    ASSERT_DOUBLE_EQ(m(1, 1), 0);
    ASSERT_DOUBLE_EQ(m(1, 2), 0);
  } catch (...) {
    FAIL();
  }
}

/*
    OPERATOR MULT * (MATRIX)
*/

TEST(Operator_Mult_Matrix, test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m1(0, 1) = -13;
  m1(1, 0) = 0.5;

  m2(0, 1) = 5.5;
  m2(1, 0) = 0.01;
  m2(1, 1) = 202;

  try {
    S21Matrix res = m1 * m2;

    ASSERT_DOUBLE_EQ(res(0, 0), -0.13);
    ASSERT_DOUBLE_EQ(res(0, 1), -2505);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);
    ASSERT_DOUBLE_EQ(res(1, 1), 2.75);

    ASSERT_EQ(res.GetCols(), 2);
    ASSERT_EQ(res.GetRows(), 2);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 1), 5.5);

    res = m2 * m1;

    ASSERT_DOUBLE_EQ(res(0, 0), 2.75);
    ASSERT_DOUBLE_EQ(res(0, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 0), 101.22);
    ASSERT_DOUBLE_EQ(res(1, 1), -0.13);

    ASSERT_EQ(res.GetCols(), 2);
    ASSERT_EQ(res.GetRows(), 2);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Matrix, test_2) {
  S21Matrix m1(2, 3), m2(3, 2);

  m1(0, 0) = 22;
  m1(0, 1) = -13;
  m1(1, 0) = 0.5;
  m1(0, 2) = 1;
  m1(1, 2) = 1;

  m2(0, 1) = 5.5;
  m2(1, 0) = 0.01;
  m2(1, 1) = 202;
  m2(2, 0) = 1;
  m2(2, 1) = 1;

  try {
    S21Matrix res = m1 * m2;

    ASSERT_DOUBLE_EQ(res(0, 0), 0.87);
    ASSERT_DOUBLE_EQ(res(0, 1), -2504);
    ASSERT_DOUBLE_EQ(res(1, 0), 1);
    ASSERT_DOUBLE_EQ(res(1, 1), 3.75);

    ASSERT_EQ(res.GetCols(), 2);
    ASSERT_EQ(res.GetRows(), 2);

    ASSERT_DOUBLE_EQ(m1(0, 0), 22);
    ASSERT_DOUBLE_EQ(m2(0, 1), 5.5);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Matrix, test_3) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;
  m(1, 0) = 0.5;
  m(1, 1) = 1;

  try {
    S21Matrix res = m * m;

    ASSERT_DOUBLE_EQ(res(0, 0), 477.5);
    ASSERT_DOUBLE_EQ(res(0, 1), -299);
    ASSERT_DOUBLE_EQ(res(1, 0), 11.5);
    ASSERT_DOUBLE_EQ(res(1, 1), -5.5);

    ASSERT_EQ(res.GetCols(), 2);
    ASSERT_EQ(res.GetRows(), 2);

    ASSERT_DOUBLE_EQ(m(0, 0), 22);
    ASSERT_DOUBLE_EQ(m(0, 1), -13);
    ASSERT_DOUBLE_EQ(m(1, 0), 0.5);
    ASSERT_DOUBLE_EQ(m(1, 1), 1);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Matrix, test_4) {
  S21Matrix m(2, 2);

  m(0, 0) = 22;
  m(0, 1) = -13;
  m(1, 0) = 0.5;
  m(1, 1) = 1;

  try {
    m = m * m;

    ASSERT_DOUBLE_EQ(m(0, 0), 477.5);
    ASSERT_DOUBLE_EQ(m(0, 1), -299);
    ASSERT_DOUBLE_EQ(m(1, 0), 11.5);
    ASSERT_DOUBLE_EQ(m(1, 1), -5.5);

    ASSERT_EQ(m.GetCols(), 2);
    ASSERT_EQ(m.GetRows(), 2);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Matrix, test_5) {
  S21Matrix m1(2, 1), m2(3, 8);

  try {
    S21Matrix res = m1 * m2;
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}

/*
    OPERATOR == EQ
*/

TEST(Operator_Eq, test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m2(0, 0) = 22;

  ASSERT_TRUE(m1 == m2);
}

TEST(Operator_Eq, test_2) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m2(0, 0) = 223;

  ASSERT_FALSE(m1 == m2);
}

TEST(Operator_Eq, test_3) {
  S21Matrix m1(2, 3), m2(2, 2);

  m1(0, 0) = 22;
  m2(0, 0) = 22;

  ASSERT_FALSE(m1 == m2);
}

TEST(Operator_Eq, test_4) {
  S21Matrix m1(2, 3);

  m1(0, 0) = 22;

  ASSERT_TRUE(m1 == m1);
}

/*
    OPERATOR = ASSIGN
*/

TEST(Operator_Assign, test_1) {
  S21Matrix m1(2, 3), m2(3, 3);

  m1(0, 0) = 22;
  m2(0, 0) = -33;

  S21Matrix& res = (m2 = m1);

  ASSERT_DOUBLE_EQ(m2(0, 0), 22);
  ASSERT_EQ(m2.GetRows(), 2);
  ASSERT_EQ(m2.GetCols(), 3);

  ASSERT_TRUE(res == m2);

  m1(0, 0) = 819;

  ASSERT_DOUBLE_EQ(m2(0, 0), 22);
}

TEST(Operator_Assign, test_2) {
  S21Matrix m1(2, 3);

  m1(1, 2) = 293;

  S21Matrix& res = (m1 = m1);

  ASSERT_TRUE(res == m1);
  ASSERT_DOUBLE_EQ(m1(1, 2), 293);
  ASSERT_EQ(m1.GetRows(), 2);
  ASSERT_EQ(m1.GetCols(), 3);
}

TEST(Operator_Assign, test_3) {
  S21Matrix m1(2, 3);

  m1(1, 2) = 293;

  S21Matrix& res = (m1 = m1.Transpose());

  ASSERT_TRUE(res == m1);
  ASSERT_DOUBLE_EQ(m1(2, 1), 293);
  ASSERT_EQ(m1.GetRows(), 3);
  ASSERT_EQ(m1.GetCols(), 2);
}

/*
    OPERATOR += PLUS-ASSIGN
*/

TEST(Operator_Plus_Assign, test_1) {
  S21Matrix m1(2, 3), m2(2, 3);

  m1(0, 0) = 2;
  m2(0, 0) = -5;
  m2(0, 1) = -10;
  try {
    S21Matrix& res = (m1 += m2);

    ASSERT_TRUE(res == m1);
    ASSERT_DOUBLE_EQ(m1(0, 0), -3);
    ASSERT_DOUBLE_EQ(m1(0, 1), -10);

    ASSERT_DOUBLE_EQ(m2(0, 0), -5);

    m1(0, 0) = 1;
    ASSERT_DOUBLE_EQ(m1(0, 0), 1);

    ASSERT_DOUBLE_EQ(m2(0, 0), -5);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Plus_Assign, test_2) {
  S21Matrix m1(2, 3), m2(2, 5);

  try {
    m1 += m2;
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Operator_Plus_Assign, test_3) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 22;

  try {
    S21Matrix& res = (m1 += m1.Transpose());

    ASSERT_TRUE(res == m1);
    ASSERT_DOUBLE_EQ(m1(0, 0), 44);
  } catch (...) {
    SUCCEED();
  }
}

/*
    OPERATOR -= MINUS-ASSIGN
*/

TEST(Operator_Minus_Assign, test_1) {
  S21Matrix m1(2, 3), m2(2, 3);

  m1(0, 0) = 2;
  m2(0, 0) = -5;
  m2(0, 1) = -10;

  try {
    S21Matrix& res = (m1 -= m2);

    ASSERT_TRUE(res == m1);
    ASSERT_DOUBLE_EQ(m1(0, 0), 7);
    ASSERT_DOUBLE_EQ(m1(0, 1), 10);

    ASSERT_DOUBLE_EQ(m2(0, 0), -5);

    m1(0, 0) = 1;
    ASSERT_DOUBLE_EQ(m1(0, 0), 1);

    ASSERT_DOUBLE_EQ(m2(0, 0), -5);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Minus_Assign, test_2) {
  S21Matrix m1(2, 3), m2(2, 5);

  try {
    m1 -= m2;
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Operator_Minus_Assign, test_3) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 22;

  try {
    S21Matrix& res = (m1 -= m1.Transpose());

    ASSERT_TRUE(res == m1);
    ASSERT_DOUBLE_EQ(m1(0, 0), 0);
  } catch (...) {
    SUCCEED();
  }
}

/*
    OPERATOR *= MULT-ASSIGN (NUM)
*/

TEST(Operator_Mult_Assign_Num, test_1) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 22;

  S21Matrix& res = (m1 *= 2);

  ASSERT_TRUE(res == m1);
  ASSERT_DOUBLE_EQ(m1(0, 0), 44);
}

/*
    OPERATOR *= MULT-ASSIGN (MATRIX)
*/

TEST(Operator_Mult_Assign_Matrix, test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 22;
  m1(0, 1) = -13;
  m1(1, 0) = 0.5;

  m2(0, 1) = 5.5;
  m2(1, 0) = 0.01;
  m2(1, 1) = 202;

  try {
    S21Matrix& res = (m1 *= m2);

    ASSERT_TRUE(res == m1);

    ASSERT_DOUBLE_EQ(res(0, 0), -0.13);
    ASSERT_DOUBLE_EQ(res(0, 1), -2505);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);
    ASSERT_DOUBLE_EQ(res(1, 1), 2.75);

    ASSERT_EQ(res.GetCols(), 2);
    ASSERT_EQ(res.GetRows(), 2);

    ASSERT_DOUBLE_EQ(m1(0, 0), -0.13);
    ASSERT_DOUBLE_EQ(m2(0, 1), 5.5);

  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Mult_Assign_Matrix, test_2) {
  S21Matrix m1(2, 3), m2(2, 2);

  try {
    m1 *= m2;
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Operator_Mult_Assign_Matrix, test_3) {
  S21Matrix m1(2, 2);

  m1(0, 0) = 22;

  try {
    S21Matrix& res = (m1 *= m1);

    ASSERT_TRUE(res == m1);
    ASSERT_DOUBLE_EQ(m1(0, 0), 484);
  } catch (...) {
    FAIL();
  }
}

/*
    OPERATOR () INDEX
*/

TEST(Operator_Index, test_1) {
  S21Matrix m(3, 3);

  try {
    m(0, 0) = 1;
    m(0, 1) = 22;
    ASSERT_DOUBLE_EQ(m(0, 0), 1);
  } catch (...) {
    FAIL();
  }
}

TEST(Operator_Index, test_2) {
  S21Matrix m(3, 3);

  try {
    m(0, -1) = 1;
    FAIL();
  } catch (...) {
    SUCCEED();
  }
}

TEST(Operator_Index, test_3) {
  S21Matrix m(3, 3);

  try {
    m(-99, 2) = 1;
    FAIL();
  } catch (...) {
    SUCCEED();
  }
}

TEST(Operator_Index, test_4) {
  S21Matrix m(3, 3);

  try {
    m(99, 2) = 1;
    FAIL();
  } catch (...) {
    SUCCEED();
  }
}

TEST(Operator_Index, test_5) {
  S21Matrix m(3, 3);

  try {
    m(2, 99) = 1;
    FAIL();
  } catch (...) {
    SUCCEED();
  }
}