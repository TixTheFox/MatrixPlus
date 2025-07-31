#include "test.h"

/*
    EQ MATRIX
*/

TEST(EqMatrix, Test_1) {
  S21Matrix m1(3, 3), m2(3, 3);

  ASSERT_TRUE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Test_2) {
  S21Matrix m1(3, 3), m2(3, 3);

  m1(1, 2) = -99;

  ASSERT_FALSE(m1.EqMatrix(m2));
}

TEST(EqMatrix, Test_3) {
  S21Matrix m1(3, 3), m2(2, 3);

  ASSERT_FALSE(m1.EqMatrix(m2));
  ASSERT_FALSE(m2.EqMatrix(m1));
}

TEST(EqMatrix, Test_4) {
  S21Matrix m1(3, 3);

  ASSERT_TRUE(m1.EqMatrix(m1));
}

/*
    SUM MATRIX
*/

TEST(SumMatrix, Test_1) {
  S21Matrix m1(3, 3), m2(2, 3);

  try {
    m1.SumMatrix(m2);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(SumMatrix, Test_2) {
  S21Matrix m1(3, 3), m2(3, 3);

  m1(1, 1) = 12.09;

  m2(1, 1) = 1.0;
  m2(0, 1) = -99.72;

  try {
    m1.SumMatrix(m2);
    ASSERT_DOUBLE_EQ(m1(1, 1), 13.09);
    ASSERT_DOUBLE_EQ(m1(0, 1), -99.72);
    ASSERT_DOUBLE_EQ(m2(1, 1), 1.0);
  } catch (...) {
    FAIL();
  }
}

TEST(SumMatrix, Test_3) {
  S21Matrix m1(1, 1), m2(1, 1);

  m1(0, 0) = 22;
  m2(0, 0) = -23;
  try {
    m1.SumMatrix(m2);
    ASSERT_DOUBLE_EQ(m1(0, 0), -1);
    ASSERT_DOUBLE_EQ(m2(0, 0), -23);
  } catch (...) {
    FAIL();
  }
}

TEST(SumMatrix, Test_4) {
  S21Matrix m(3, 3);
  m(0, 0) = 10;

  try {
    m.SumMatrix(m);
    ASSERT_DOUBLE_EQ(m(0, 0), 20);
  } catch (...) {
    FAIL();
  }
}

/*
    SUB MATRIX
*/

TEST(SubMatrix, Test_1) {
  S21Matrix m1(3, 3), m2(2, 3);

  try {
    m1.SubMatrix(m2);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(SubMatrix, Test_2) {
  S21Matrix m1(3, 3), m2(3, 3);

  m1(1, 1) = 12.09;

  m2(1, 1) = 1.0;
  m2(0, 1) = -99.72;

  try {
    m1.SubMatrix(m2);
    ASSERT_DOUBLE_EQ(m1(1, 1), 11.09);
    ASSERT_DOUBLE_EQ(m1(0, 1), 99.72);
    ASSERT_DOUBLE_EQ(m2(1, 1), 1.0);
  } catch (...) {
    FAIL();
  }
}

TEST(SubMatrix, Test_3) {
  S21Matrix m1(1, 1), m2(1, 1);

  m1(0, 0) = 22;
  m2(0, 0) = -23;
  try {
    m1.SubMatrix(m2);
    ASSERT_DOUBLE_EQ(m1(0, 0), 45);
    ASSERT_DOUBLE_EQ(m2(0, 0), -23);
  } catch (...) {
    FAIL();
  }
}

TEST(SubMatrix, Test_4) {
  S21Matrix m(3, 3);
  m(0, 0) = 10;

  try {
    m.SubMatrix(m);
    ASSERT_DOUBLE_EQ(m(0, 0), 0);
  } catch (...) {
    FAIL();
  }
}

/*
    MUL NUMBER
*/

TEST(MulNumber, Test_1) {
  S21Matrix m(3, 3);

  m(1, 1) = 12;

  m.MulNumber(3);

  ASSERT_DOUBLE_EQ(m(1, 1), 36);
  ASSERT_DOUBLE_EQ(m(0, 0), 0);
}

TEST(MulNumber, Test_2) {
  S21Matrix m(1, 1);

  m(0, 0) = 12;

  m.MulNumber(3);

  ASSERT_DOUBLE_EQ(m(0, 0), 36);
}

/*
    MUL MATRIX
*/

TEST(MulMatrix, Test_1) {
  S21Matrix m1(2, 2), m2(2, 2);

  m1(0, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  try {
    m1.MulMatrix(m2);

    ASSERT_DOUBLE_EQ(m1(0, 0), 2);
    ASSERT_DOUBLE_EQ(m1(0, 1), 0);
    ASSERT_DOUBLE_EQ(m1(1, 0), 6);
    ASSERT_DOUBLE_EQ(m1(1, 1), 9);

    ASSERT_DOUBLE_EQ(m2(0, 0), 1);
    ASSERT_DOUBLE_EQ(m2(1, 1), 3);
  } catch (...) {
    FAIL();
  }
}

TEST(MulMatrix, Test_2) {
  S21Matrix m1(1, 1), m2(1, 1);

  m1(0, 0) = 2;

  m2(0, 0) = 5.5;

  try {
    m1.MulMatrix(m2);

    ASSERT_DOUBLE_EQ(m1(0, 0), 11);
    ASSERT_DOUBLE_EQ(m2(0, 0), 5.5);
  } catch (...) {
    FAIL();
  }
}

TEST(MulMatrix, Test_3) {
  S21Matrix m(2, 2);

  m(0, 0) = 2;
  m(1, 1) = 3;

  try {
    m.MulMatrix(m);

    ASSERT_DOUBLE_EQ(m(0, 0), 4);
    ASSERT_DOUBLE_EQ(m(1, 1), 9);
  } catch (...) {
    FAIL();
  }
}

TEST(MulMatrix, Test_4) {
  S21Matrix m1(1, 1), m2(2, 1);

  m1(0, 0) = 2;

  m2(0, 0) = 5.5;

  try {
    m1.MulMatrix(m2);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

/*
    TRANSPOSE
*/

TEST(Transpose, Test_1) {
  S21Matrix m(3, 3);
  m(0, 0) = 1;
  m(0, 2) = 2;

  S21Matrix res = m.Transpose();

  ASSERT_DOUBLE_EQ(res(0, 0), 1);
  ASSERT_DOUBLE_EQ(res(2, 0), 2);
  ASSERT_DOUBLE_EQ(res(0, 2), 0);
  ASSERT_EQ(res.GetRows(), 3);
  ASSERT_EQ(res.GetCols(), 3);
}

TEST(Transpose, Test_2) {
  S21Matrix m(3, 4);
  m(0, 0) = 1;
  m(0, 2) = 2;

  S21Matrix res = m.Transpose();

  ASSERT_DOUBLE_EQ(res(0, 0), 1);
  ASSERT_DOUBLE_EQ(res(2, 0), 2);
  ASSERT_DOUBLE_EQ(res(0, 2), 0);
  ASSERT_EQ(res.GetRows(), 4);
}

TEST(Transpose, Test_3) {
  S21Matrix m(2, 2);
  m(0, 0) = 1;
  m(1, 1) = 2;

  S21Matrix res = m.Transpose();

  ASSERT_TRUE(m.EqMatrix(m));
}

TEST(Transpose, Test_4) {
  S21Matrix m(1, 1);
  m(0, 0) = 1;

  S21Matrix res = m.Transpose();

  ASSERT_TRUE(m.EqMatrix(m));
}

/*
    CALC COMPLEMENTS
*/

TEST(CalcComplements, Test_1) {
  S21Matrix m(2, 2);

  m(0, 0) = 2;
  m(1, 1) = 9;

  try {
    S21Matrix res = m.CalcComplements();
    ASSERT_DOUBLE_EQ(res(0, 0), 9);
    ASSERT_DOUBLE_EQ(res(0, 1), 0);
    ASSERT_DOUBLE_EQ(res(1, 0), 0);
    ASSERT_DOUBLE_EQ(res(1, 1), 2);
  } catch (...) {
    FAIL();
  }
}

TEST(CalcComplements, Test_2) {
  S21Matrix m(3, 3);

  m(0, 0) = 2;
  m(0, 2) = 3;
  m(1, 1) = 9;
  m(2, 2) = 1;

  try {
    S21Matrix res = m.CalcComplements();
    ASSERT_DOUBLE_EQ(res(0, 0), 9);
    ASSERT_DOUBLE_EQ(res(0, 2), 0);
    ASSERT_DOUBLE_EQ(res(2, 0), -27);
    ASSERT_DOUBLE_EQ(res(1, 1), 2);
    ASSERT_DOUBLE_EQ(res(2, 2), 18);
  } catch (...) {
    FAIL();
  }
}

TEST(CalcComplements, Test_3) {
  S21Matrix m(2, 3);
  try {
    S21Matrix res = m.CalcComplements();
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}

TEST(CalcComplements, Test_4) {
  S21Matrix m(3, 3);
  try {
    S21Matrix res = m.CalcComplements();
    ASSERT_TRUE(m.EqMatrix(res));
  } catch (...) {
    FAIL();
  }
}

/*
    DETERMINANT
*/

TEST(Determinant, Test_1) {
  S21Matrix m(3, 3);

  try {
    double det = m.Determinant();
    ASSERT_DOUBLE_EQ(det, 0);
  } catch (...) {
    FAIL();
  }
}

TEST(Determinant, Test_2) {
  S21Matrix m(3, 3);

  m(0, 0) = 9;
  m(1, 1) = 9;
  m(2, 2) = 9;

  try {
    double det = m.Determinant();
    ASSERT_DOUBLE_EQ(det, 729);
  } catch (...) {
    FAIL();
  }
}

TEST(Determinant, Test_3) {
  S21Matrix m(3, 3);

  m(0, 0) = 9;
  m(1, 1) = 9;
  m(2, 2) = 9;
  m(0, 1) = 1;
  m(0, 2) = 3;

  try {
    double det = m.Determinant();
    ASSERT_DOUBLE_EQ(det, 729);
  } catch (...) {
    FAIL();
  }
}

TEST(Determinant, Test_4) {
  S21Matrix m(3, 5);

  try {
    m.Determinant();
    FAIL();
  } catch (...) {
    SUCCEED();
  }
}

TEST(Determinant, Test_5) {
  S21Matrix m(1, 1);

  m(0, 0) = 9;
  try {
    double det = m.Determinant();
    ASSERT_DOUBLE_EQ(det, 9);
  } catch (...) {
    FAIL();
  }
}

/*
    INVERSE MATRIX
*/

TEST(InverseMatrix, Test_1) {
  S21Matrix m(3, 3);

  m(0, 0) = 9;
  m(1, 1) = 9;
  m(2, 2) = 9;

  try {
    S21Matrix res = m.InverseMatrix();
    ASSERT_NEAR(res(0, 0), 1. / 9, EPSILON);
    ASSERT_NEAR(res(1, 1), 1. / 9, EPSILON);
    ASSERT_NEAR(res(2, 2), 1. / 9, EPSILON);
  } catch (...) {
    FAIL();
  }
}

TEST(InverseMatrix, Test_2) {
  S21Matrix m(3, 3);

  m(0, 0) = 9;
  m(1, 1) = 9;
  m(2, 2) = 9;
  m(0, 2) = 3;
  m(1, 0) = -9;

  try {
    S21Matrix res = m.InverseMatrix();
    ASSERT_DOUBLE_EQ(res(0, 0), 1. / 9);
    ASSERT_DOUBLE_EQ(res(1, 0), 1. / 9);
    ASSERT_DOUBLE_EQ(res(1, 1), 1. / 9);
    ASSERT_DOUBLE_EQ(res(2, 2), 1. / 9);
    ASSERT_DOUBLE_EQ(res(0, 2), -1. / 27);
    ASSERT_DOUBLE_EQ(res(1, 2), -1. / 27);
  } catch (...) {
    FAIL();
  }
}

TEST(InverseMatrix, Test_3) {
  S21Matrix m(3, 5);

  try {
    S21Matrix res = m.InverseMatrix();
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}

TEST(InverseMatrix, Test_4) {
  S21Matrix m(3, 3);

  m(2, 0) = 3;
  m(0, 2) = 288;

  try {
    S21Matrix res = m.InverseMatrix();
    FAIL();
  } catch (const std::invalid_argument& e) {
    SUCCEED();
  }
}