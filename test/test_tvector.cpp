#include "tmatrix.h"

#include <gtest.h>


TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> vector(50));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> vector(-15));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> vector(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> vector(9);
	EXPECT_EQ(vector, TDynamicVector<int>(vector));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> vector(3);
  ASSERT_NO_THROW(TDynamicVector<int> v1(vector));
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> vector1(6), vector2(vector1);

	vector2[4] = 3;

	EXPECT_NE(&vector1[0], &vector2[0]);
	EXPECT_NE(vector1, vector2);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> vector(5);

  EXPECT_EQ(5, vector.size());
}


TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> vector(2);

	ASSERT_ANY_THROW(vector[-5] = 2);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> vector(13);

	ASSERT_NO_THROW(vector = vector);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> vector(13);

	ASSERT_ANY_THROW(vector[14] = 13);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> vector1(2), vector2(2);

	vector2[0] = 3;
	vector2[1] = 1;

	vector1 = vector2;

	EXPECT_EQ(vector1[0], vector2[0]);
	EXPECT_EQ(vector1[1], vector2[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> vector1(7), vector2(13), vector3(16);

	vector1 = vector2;
	vector3 = vector2;

	EXPECT_EQ(13, vector1.size());
	EXPECT_EQ(13, vector3.size());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> vector1(4), vector2(13);

	vector2[4] = 6;
	vector2[9] = 1;
	vector2[10] = 2;

	vector1 = vector2;

	EXPECT_TRUE(vector1 == vector2);
	EXPECT_FALSE(vector1 != vector2);

	vector2[0] = 4;

	EXPECT_TRUE(vector1 != vector2);
	EXPECT_FALSE(vector1 == vector2);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> vector1(4), vector2(13);

	vector2[0] = 3;
	vector2[7] = 8;
	vector2[12] = 1;

	vector1 = vector2;

	EXPECT_EQ(vector1[0], vector2[0]);
	EXPECT_EQ(vector1[7], vector2[7]);
	EXPECT_EQ(vector1[12], vector2[12]);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> vector(4);

	vector[0] = 13;

	EXPECT_TRUE(vector == vector);
	EXPECT_FALSE(vector != vector);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> vector1(14), vector2(13);

	EXPECT_FALSE(vector1 == vector2);
	EXPECT_TRUE(vector1 != vector2);
}

TEST(TDynamicVector, can_addition_scalar_to_vector)
{
	TDynamicVector<int> vector1(2);

	vector1[0] = 1;
	vector1[1] = 0;
	vector1 = vector1 + 2;
	EXPECT_EQ(3, vector1[0]);
	EXPECT_EQ(2, vector1[1]);
}

TEST(TDynamicVector, can_multiplication_scalar_by_vector)
{
	TDynamicVector<int> vector(3);

	vector[0] = 1;
	vector[1] = 2;
	vector[2] = 3;
	vector = vector * 5;

	EXPECT_EQ(5, vector[0]);
	EXPECT_EQ(10, vector[1]);
	EXPECT_EQ(15, vector[2]);
}

TEST(TDynamicVector, can_addition_vectors_with_equal_size)
{
	TDynamicVector<int> vector1(2), vector2(2), expVector(2);

	vector1[0] = 1;
	vector2[1] = 3;

	expVector[0] = 1;
	expVector[1] = 3;

	EXPECT_EQ(expVector, vector1 + vector2);

	vector1 =vector1+ vector2;

	EXPECT_EQ(expVector, vector1);
}

TEST(TDynamicVector, can_subtraction_scalar_from_vector)
{
	TDynamicVector<int> vector1(2);
	vector1[0] = 5;
	vector1[1] = 3;
	vector1 = vector1 - 1;
	EXPECT_EQ(4, vector1[0]);
	EXPECT_EQ(2, vector1[1]);
}

TEST(TDynamicVector, cant_addition_vectors_with_not_equal_size)
{
	TDynamicVector<int> vector1(2), vector2(3);
	ASSERT_ANY_THROW(vector1 + vector2);
}

TEST(TDynamicVector, can_subtraction_vectors_with_equal_size)
{
	TDynamicVector<int> vector1(2), vector2(2), expVector(2);

	vector1[0] = 4;
	vector2[0] = 3;
	vector2[1] = 7;

	expVector[0] = 1;
	expVector[1] = -7;

	EXPECT_EQ(expVector, vector1 - vector2);

	vector1 =vector1-vector2;

	EXPECT_EQ(expVector, vector1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> vector1(2), vector2(2);

	vector1[0] = 1;
	vector1[1] = 4;
	vector2[0] = 7;
	vector2[1] = 3;

	EXPECT_EQ(19, vector1 * vector2);
}

TEST(TDynamicVector, cant_subtraction_vectors_with_not_equal_size)
{
	TDynamicVector<int> vector1(12), vector2(13);

	ASSERT_ANY_THROW(vector1 - vector2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> vector1(12), vector2(13);

	ASSERT_ANY_THROW(vector1 * vector2);
}

