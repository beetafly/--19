// ЛР-19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

// Шаблонна функція для знаходження мінімального елемента у двовимірному масиві
template <typename T>
T findMinElement(const std::vector<std::vector<T>>& matrix) {
    T minElement = matrix[0][0];
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            if (elem < minElement) {
                minElement = elem;
            }
        }
    }
    return minElement;
}

// Шаблонна функція для сортування елементів головної діагоналі
template <typename T>
void sortMainDiagonal(std::vector<std::vector<T>>& matrix) {
    int n = std::min(matrix.size(), matrix[0].size());
    std::vector<T> diagonal;
    for (int i = 0; i < n; ++i) {
        diagonal.push_back(matrix[i][i]);
    }
    std::sort(diagonal.begin(), diagonal.end());
    for (int i = 0; i < n; ++i) {
        matrix[i][i] = diagonal[i];
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {3, 2, 1},
        {9, 8, 7},
        {6, 5, 4}
    };

    // Знаходження мінімального елемента
    int minElement = findMinElement(matrix);
    std::cout << "Мінімальний елемент: " << minElement << std::endl;

    // Сортування елементів головної діагоналі
    sortMainDiagonal(matrix);

    // Виведення відсортованої матриці
    std::cout << "Матриця після сортування головної діагоналі:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
