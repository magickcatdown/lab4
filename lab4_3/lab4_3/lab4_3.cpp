﻿/**
* @file lab4_3.cpp
* @author Пацалюк А.В., гр. 515-і2
* @date 20 травня 2024
* @brief Лабораторна робота № 4
*
* Функції. Швидке сортування. Робота з відлагоджувачем. Завдання 3
*/

#include <stdio.h>
#include <locale.h>

/**
* Обчислення факторіалу числа з використанням рекурсії
*
* @param n число
* @return факторіал числа (0, якщо n < 0)
*/
int mul_numbers(int n);

int main()
{
    __int64 a, b, sum;

    // Встановлюємо локаль для коректного відображення української мови
    setlocale(LC_ALL, "Ukr");

    // Запитуємо користувача ввести значення a та b
    printf("Введіть значення a та b через пробіл: ");
    scanf_s("%lld %lld", &a, &b);

    // Обчислюємо суму факторіалів чисел a та b
    sum = mul_numbers(a) + mul_numbers(b);

    // Виводимо результат
    printf("mul_numbers(%lld)+mul_numbers(%lld)=%lld\n", a, b, sum);

    return 0;
}

/**
* Обчислення факторіалу числа з використанням рекурсії
*
* @param n - число, для якого обчислюється факторіал
* @return факторіал числа (0, якщо n < 0)
*/
int mul_numbers(int n)
{
    // Якщо n менше 0, повертаємо 0, оскільки факторіал від'ємного числа не визначений
    if (n < 0) return 0;
    // Якщо n не дорівнює 0, повертаємо n, помножене на факторіал (n-1)
    if (n != 0) return n * mul_numbers(n - 1); else
        // Якщо n дорівнює 0, повертаємо 1, оскільки факторіал 0 дорівнює 1
        return 1;
}
