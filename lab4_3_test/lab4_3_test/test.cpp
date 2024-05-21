/**
 * @file lab4_1.cpp
 * @author Пацалюк А.В., гр. 515-і2
 * @date 20 травня 2024
 * @brief Лабораторна робота № 4
 *
 * Функції. Швидке сортування. Робота з відлагоджувачем. Завдання 3
 */

#include <stdio.h>

#include <locale.h>

#include "pch.h"

 /**
  * Обчислення факторіалу числа з використанням рекурсії
  *
  * @param n число
  * @return факторіал числа (0, якщо n < 0)
  */
int mul_numbers(int n) {
    // Якщо n менше 0, повертаємо 0, оскільки факторіал від'ємного числа не визначений
    if (n < 0) return 0;
    // Якщо n не дорівнює 0, повертаємо n, помножене на факторіал (n-1)
    if (n != 0) return n * mul_numbers(n - 1);
    else
        // Якщо n дорівнює 0, повертаємо 1, оскільки факторіал 0 дорівнює 1
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
