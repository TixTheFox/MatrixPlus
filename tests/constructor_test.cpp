#include "test.h"

TEST(Constructor, NoArgConstruct) {
  S21Matrix m;

  ASSERT_EQ(m.GetRows(), 3);
  ASSERT_EQ(m.GetCols(), 3);
  ASSERT_EQ(m(0, 0), 0);
}

TEST(Constructor, NumArgConstruct_1) {
  S21Matrix m(4, 4);

  ASSERT_EQ(m.GetRows(), 4);
  ASSERT_EQ(m.GetCols(), 4);
  ASSERT_EQ(m(0, 0), 0);
  ASSERT_EQ(m(3, 3), 0);
}

TEST(Constructor, NumArgConstruct_2) {
  try {
    S21Matrix m(4, -10);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Constructor, NumArgConstruct_3) {
  try {
    S21Matrix m(-4, 10);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Constructor, NumArgConstruct_4) {
  try {
    S21Matrix m(4, 0);
    FAIL();
  } catch (const std::out_of_range& e) {
    SUCCEED();
  }
}

TEST(Constructor, NumArgConstruct_5) {
  S21Matrix m(4, 3);

  ASSERT_EQ(m.GetRows(), 4);
  ASSERT_EQ(m.GetCols(), 3);
  ASSERT_EQ(m(0, 0), 0);
  ASSERT_EQ(m(3, 2), 0);
}

TEST(Constructor, CopyConstruct_1) {
  S21Matrix m1(4, 4);
  m1(1, 1) = 12.22;
  S21Matrix m2(m1);

  ASSERT_NEAR(m1(1, 1), m2(1, 1), EPSILON);
  ASSERT_NEAR(m1(1, 1), 12.22, EPSILON);
  ASSERT_NEAR(m2(1, 1), 12.22, EPSILON);

  m2(1, 1) = -0.789;
  ASSERT_NEAR(m1(1, 1), 12.22, EPSILON);
  ASSERT_NEAR(m2(1, 1), -0.789, EPSILON);
}

TEST(Constructor, MoveContruct_1) {
  S21Matrix m_1(S21Matrix(1, 2));

  S21Matrix m(std::move(m_1));

  ASSERT_EQ(m.GetRows(), 1);
  ASSERT_EQ(m.GetCols(), 2);
  ASSERT_EQ(m(0, 1), 0);
}

/*
  MUTATORS
*/

TEST(Mutators, Test_1) {
  S21Matrix m(3, 3);

  ASSERT_EQ(m.GetRows(), 3);
  ASSERT_EQ(m.GetCols(), 3);
}

TEST(Mutators, Test_2) {
  S21Matrix m(3, 3);

  m(1, 1) = 22;

  ASSERT_THROW(m(3, 3), std::out_of_range);

  m.SetCols(4);
  m.SetRows(4);

  ASSERT_EQ(m.GetCols(), 4);
  ASSERT_EQ(m.GetRows(), 4);
  ASSERT_DOUBLE_EQ(m(1, 1), 22);
  ASSERT_NO_THROW(m(3, 3));

  m.SetCols(1);
  m.SetRows(1);

  ASSERT_EQ(m.GetCols(), 1);
  ASSERT_EQ(m.GetRows(), 1);
  ASSERT_THROW(m(1, 1), std::out_of_range);
}

TEST(Mutators, Test_3) {
  S21Matrix m(3, 3);

  ASSERT_THROW(m.SetCols(0), std::invalid_argument);
  ASSERT_THROW(m.SetCols(-29), std::invalid_argument);
  ASSERT_THROW(m.SetRows(0), std::invalid_argument);
  ASSERT_THROW(m.SetRows(-9), std::invalid_argument);
}