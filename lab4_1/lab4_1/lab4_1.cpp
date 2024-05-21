/**
* @file lab4_1.cpp
* @author Пацалюк А.В., гр. 515-і2
* @date 20 травня 2024
* @brief Лабораторна робота № 4
*
* Функції. Швидке сортування. Робота з відлагоджувачем. Завдання 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define N 10  // Розмір масиву

int a[N];  // Масив, який буде відсортовано

/**
* Швидке сортування
*
* @param a[] - масив
* @param low - нижній маркер
* @param high - верхній маркер
* @return void
*/
void quicksort(int a[], int low, int high);

/**
* Розділення масиву
*
* @param a[] - масив
* @param low - нижній маркер
* @param high - верхній маркер
* @return індекс розділення
*/
int split(int a[], int low, int high);

/**
* Заповнення масиву вручну
*
* @param void
* @return void
*/
void mas_scanf();

/**
* Заповнення масиву випадковими числами в діапазоні [-100;100]
*
* @param void
* @return void
*/
void mas_rand();

/**
* Функція меню
*
* @param void
* @return void
*/
void mas_menu();

/**
* Вивід відсортованого масиву
*
* @param void
* @return void
*/
void print_result();

int main()
{
    // Встановлюємо локаль для коректного відображення української мови
    setlocale(LC_ALL, "Ukr");

    // Викликаємо меню для заповнення масиву
    mas_menu();

    // Виконуємо швидке сортування масиву
    quicksort(a, 0, N - 1);

    // Виводимо результат сортування
    print_result();

    return 0;
}

void quicksort(int a[], int low, int high)
{
    int middle;
    if (low >= high) return; // Базовий випадок для рекурсії
    middle = split(a, low, high); // Розділяємо масив
    quicksort(a, low, middle - 1); // Рекурсивно сортуємо ліву частину
    quicksort(a, middle + 1, high); // Рекурсивно сортуємо праву частину
}

int split(int a[], int low, int high)
{
    int part_element = a[low]; // Обираємо опорний елемент
    for (;;) {
        while (low < high && part_element >= a[high])
            high--; // Знаходимо елемент, менший за опорний з правого боку
        if (low >= high) break;
        a[low++] = a[high]; // Переміщуємо елемент

        while (low < high && a[low] >= part_element)
            low++; // Знаходимо елемент, більший за опорний з лівого боку
        if (low >= high) break;
        a[high--] = a[low]; // Переміщуємо елемент
    }
    a[high] = part_element; // Встановлюємо опорний елемент на його місце
    return high;
}

void mas_scanf()
{
    printf("Введіть %d чисел для сортування: ", N);
    for (int i = 0; i < N; i++)
        scanf_s("%d", &a[i]); // Вводимо елементи масиву
}

void mas_rand()
{
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел
    printf("Сгенерований масив: ");
    for (int i = 0; i < N; i++) {
        a[i] = -100 + rand() % (201); // Генеруємо випадкові числа
        printf("%d ", a[i]);
    }
    printf("\n");
}

void mas_menu()
{
    int num = 3;
    while (num > 2) {
        printf("Оберіть, як заповнювати масив.\n");
        printf("1. Вручну \n");
        printf("2. За допомогою rand()\n");
        scanf_s("%d", &num); // Вводимо вибір користувача
        switch (num) {
        case 1:
            mas_scanf(); // Заповнення вручну
            break;
        case 2:
            mas_rand(); // Заповнення випадковими числами
            break;
        default:
            printf("Введіть коректне значення!\n"); // Обробка некоректного вибору
        }
    }
}

void print_result()
{
    printf("Відсортовані числа: ");
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]); // Виводимо елементи масиву
    printf("\n");
}
