#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 10;
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[3] = 10;
	TVector<int> v2(v1);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[3] = 20;
	EXPECT_NE(v1[3], v2[3]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);
  EXPECT_EQ(v.GetSize(), 4);
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);
  EXPECT_EQ(v.GetStartIndex(), 2);
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-2]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[6]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[3] = 10;
	v1 = v1;
	EXPECT_EQ(v1, v1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	TVector<int> v2(v1);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[3] = 20;
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)

		v2[i] = 0;
	v1 = v2;
	EXPECT_EQ(v1.GetSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[2] = 20;
	EXPECT_EQ(true, v2 == v1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	EXPECT_EQ(true, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	v1 = v1 + 20;
	EXPECT_EQ(40, v1[2]);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	v1 = v1 - 15;
	EXPECT_EQ(5, v1[2]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(3);
	for (int i = 0; i < 3; i++)
		v1[i] = 0;
	v1[2] = 20;
	v1 = v1 * 10;
	EXPECT_EQ(200, v1[2]);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[2] = 40;
	TVector<int> v3(5);
	for (int i = 0; i < 5; i++)
		v3[i] = 0;
	v3 = v1 + v2;
	EXPECT_EQ(v3[2], 60);
	EXPECT_EQ(v3, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(7);
	for (int i = 0; i < 7; i++)
		v2[i] = 0;
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[2] = 40;
	TVector<int> v3(5);
	for (int i = 0; i < 5; i++)
		v3[i] = 0;
	v3 = v1 - v2;
	EXPECT_EQ(v3[2], -20);
	EXPECT_EQ(v3, v1 - v2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(7);
	for (int i = 0; i < 7; i++)
		v2[i] = 0;
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int res = 0;
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 2;
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = 0;
	v2[2] = 4;
	res += v1 * v2;
	EXPECT_EQ(res, 8);
	EXPECT_EQ(res, v1 * v2);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1[2] = 20;
	TVector<int> v2(7);
	for (int i = 0; i < 7; i++)
		v2[i] = 0;
	ASSERT_ANY_THROW(v1 * v2);
}

