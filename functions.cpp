#include <iostream>
#include <iomanip>
#include "functions.hpp"

void Read(uint32_t array[], size_t &n) {
    std::cout << "Enter the number of numbers in the array: ";
    std::cin >> n;
    if (n == 0) { return; }
    std::cout << "Enter array element: ";
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

}

bool Two_Identical_Numbers(uint32_t array[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (array[i] == array[j]) {
                return true;
            }
        } 
    }
    return false;
}

void Write(uint32_t array[], size_t n) {
    std::cout << "Array: ";
    for (size_t i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void Bubble_Sort_By_Last_Digit(uint32_t array[], size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            uint32_t last_digit_current = array[j] % 10;
            uint32_t last_digit_next = array[j + 1] % 10;
            if (last_digit_current < last_digit_next) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

int multiplication_digits(uint32_t x) {
    if (x == 0) { return 0; }
    uint32_t template_n;
    uint32_t multiplication = 1;
    while (x > 0) {
        template_n = x % 10;
        x /= 10;
        multiplication *= template_n;
    }
    return multiplication;
}

void Bubble_Sort_By_Key(uint32_t array[], size_t n) {
    if (n == 0) { return; }
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            // выделяем первые цифры
            uint32_t first_digit_current = array[j];
            while (first_digit_current >= 10) { first_digit_current /= 10; }

            uint32_t first_digit_next = array[j + 1];
            while (first_digit_next >= 10) { first_digit_next /= 10; }

            // сортировка по первой цифре
            if (first_digit_current > first_digit_next) {
                std::swap(array[j], array[j + 1]);
            } 
            else if (first_digit_current == first_digit_next) {
                // сортировка по произведению цифр
                uint32_t mult_current = multiplication_digits(array[j]);
                uint32_t mult_next = multiplication_digits(array[j + 1]);

                if (mult_current > mult_next) {
                    std::swap(array[j], array[j + 1]);
                } else if (mult_current == mult_next) {
                    // сортировка по самому числу
                    if (array[j] > array[j + 1]) {
                        std::swap(array[j], array[j + 1]);
                    }
                }
            } 
        }
    }
}

void Read_Matrix(int32_t matrix[][100], size_t &rows, size_t &cols) {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter number of cols: ";
    std::cin >> cols;

    std::cout << "Enter matrix element: " << "\n";
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void Write_Matrix(int32_t matrix[][100], size_t rows, size_t cols) {
    std::cout << "Matrix: " << "\n";
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << std::setw(6) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Sort_Matrix(int32_t matrix[][100], size_t rows, size_t cols) {
    if (cols == 0 || rows == 0) { return; }
    
    size_t min_col_index = 0;
    int32_t min_summ = 0;

    for (size_t i = 0; i < rows; ++i) {
        min_summ += matrix[i][0];
    }

    for (size_t j = 0; j < cols; ++j) {
        int32_t current_col_summ = 0;

        for(size_t i = 0; i < rows; ++i) {
            current_col_summ += matrix[i][j];
        }
        if (current_col_summ < min_summ) {
            min_summ = current_col_summ;
            min_col_index = j;
        }
    }
    for (size_t i = 0; i < rows; ++i) {
        matrix[i][min_col_index] += 3;
    }
}

bool Different_Digit(size_t x) {
    if (x == 0) { return true; }

    bool visited[10] = {false};
    while (x > 0) {
        size_t digit = x % 10;
        if (visited[digit]) { return false; }
        visited[digit] = true;
        x /= 10;
    }
    return true;
}

bool Product_Divisible_By_14(size_t x) {
    if (x == 0) { return true; }
    size_t product = 1;
    while (x > 0) {
        product *= (x % 10);
        x /= 10;
    }
    return (product % 14 == 0);
}

void Process_Array(uint32_t array[], size_t& n) {
    for (size_t i = 0; i < n; ) {
        if (Different_Digit(array[i])) {
            for (size_t j = i; j < n - 1; ++j) { array[j] = array[j + 1]; }
            n--; 
        } else { i++; }
    }

    for (size_t i = 0; i < n; i++) {
        if (Product_Divisible_By_14(array[i])) {
            for (size_t j = n; j > i + 1; --j) {
                array[j] = array[j - 1];
            }
            array[i + 1] = array[i]; 
            n++;                 
            i++;                
        }
    }
    
    std::cout << "Array: ";
    for(size_t i = 0; i < n; ++i) {
        bool already_printed = false;
        for (size_t j = 0; j < i; ++j) {
            if (array[i] == array[j]) {
                already_printed = true;
                break;
            }
        }
    if (!already_printed) { std::cout << array[i] << " "; }
    }
}

