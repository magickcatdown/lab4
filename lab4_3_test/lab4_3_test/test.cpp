/**
 * @file lab4_1.cpp
 * @author ������� �.�., ��. 515-�2
 * @date 20 ������ 2024
 * @brief ����������� ������ � 4
 *
 * �������. ������ ����������. ������ � ��������������. �������� 3
 */

#include <stdio.h>

#include <locale.h>

#include "pch.h"

 /**
  * ���������� ��������� ����� � ������������� ������
  *
  * @param n �����
  * @return �������� ����� (0, ���� n < 0)
  */
int mul_numbers(int n) {
    // ���� n ����� 0, ��������� 0, ������� �������� ��'������ ����� �� ����������
    if (n < 0) return 0;
    // ���� n �� ������� 0, ��������� n, ��������� �� �������� (n-1)
    if (n != 0) return n * mul_numbers(n - 1);
    else
        // ���� n ������� 0, ��������� 1, ������� �������� 0 ������� 1
        return 1;
}

TEST(FactorialCase, Factorial)
{
    EXPECT_EQ(479001600, mul_numbers(12));
    EXPECT_EQ(39916800, mul_numbers(11));
    EXPECT_EQ(5040, mul_numbers(7));
    EXPECT_EQ(0, mul_numbers(-12));
    EXPECT_EQ(1, mul_numbers(0));
}
