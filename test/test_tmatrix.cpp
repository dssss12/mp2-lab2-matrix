#include "tmatrix.h"

#include <gtest.h>


TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> matrix(10));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> matrix(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> matrix(-10));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> matrix(10);

  ASSERT_NO_THROW(TDynamicMatrix<int> matrix1(matrix));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> matrix1(13);

	matrix1[5][5] = 4;

	TDynamicMatrix<int> matrix2(matrix1);

	EXPECT_EQ(matrix1, matrix2);
}


TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> matrix(13);

	EXPECT_EQ(13, matrix.size());
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> matrix1(6), matrix2(matrix1);

	matrix2[4][1] = 3;

	EXPECT_NE(&matrix1[0], &matrix2[0]);
	EXPECT_NE(matrix1, matrix2);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> matrix(13);

	matrix[1][3] = 5;

	EXPECT_EQ(5, matrix[1][3]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> matrix(13);

	ASSERT_ANY_THROW(matrix[13][3]);
	ASSERT_ANY_THROW(matrix[3][13]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> matrix(13);

	ASSERT_ANY_THROW(matrix[-1][3]);
	ASSERT_ANY_THROW(matrix[3][-1]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> matrix(13);

	ASSERT_NO_THROW(matrix = matrix);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> matrix1(12), matrix2(13), matrix3(14);

	matrix1 = matrix2;
	matrix3 = matrix2;

	EXPECT_EQ(13, matrix1.size());
	EXPECT_EQ(13, matrix3.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> matrix1(13), matrix2(13);

	matrix2[1][4] = 7;
	matrix2[6][9] = 3;

	matrix1 = matrix2;

	EXPECT_EQ(matrix1, matrix2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> matrix1(6), matrix2(4);

	matrix1[5][2] = 1;
	matrix2[1][3] = 5;
	matrix2[2][3] = 7;

	matrix1 = matrix2;

	EXPECT_EQ(matrix1, matrix2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> matrix1(4), matrix2(4);

	matrix1[1][3] = 6;
	matrix1[2][1] = 1;

	matrix2 = matrix1;

	EXPECT_TRUE(matrix1 == matrix2);
	EXPECT_FALSE(matrix1 != matrix2);

	matrix2[3][0] = 9;

	EXPECT_TRUE(matrix1 != matrix2);
	EXPECT_FALSE(matrix1 == matrix2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> matrix(13);

	matrix[0][12] = 5;

	EXPECT_TRUE(matrix == matrix);
	EXPECT_FALSE(matrix != matrix);
}

TEST(TDynamicMatrix, can_addition_matrices_with_equal_size)
{
	TDynamicMatrix<int> matrix1(3), matrix2(3), expMatrix(3);

	matrix1[0][1] = 4;
	matrix1[2][2] = 6;

	matrix2[1][2] = 1;
	matrix2[2][2] = 2;

	expMatrix[0][1] = 4;
	expMatrix[1][2] = 1;
	expMatrix[2][2] = 8;

	EXPECT_EQ(expMatrix, matrix1 + matrix2);
}

TEST(TDynamicMatrix, cant_addition_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> matrix1(12), matrix2(13);

	ASSERT_ANY_THROW(matrix1 + matrix2);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> matrix1(12), matrix2(13);

	EXPECT_FALSE(matrix1 == matrix2);
	EXPECT_TRUE(matrix1 != matrix2);
}

TEST(TDynamicMatrix, can_subtraction_matrices_with_equal_size)
{
	TDynamicMatrix<int> matrix1(3), matrix2(3), expMatrix(3);

	matrix1[0][0] = 2;
	matrix1[1][2] = 8;

	matrix2[1][2] = 3;
	matrix2[2][0] = -5;

	expMatrix[0][0] = 2;
	expMatrix[1][2] = 5;
	expMatrix[2][0] = 5;

	EXPECT_EQ(expMatrix, matrix1 - matrix2);
}

TEST(TDynamicMatrix, cant_subtraction_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> matrix1(12), matrix2(13);

	ASSERT_ANY_THROW(matrix1 - matrix2);
}

