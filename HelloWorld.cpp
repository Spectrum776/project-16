// HelloWorld.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
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
#include <iostream>
#include <limits>  // For numeric_limits

// Function to find the index of the minimum element in an array
int findMinIndex(const double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the sum of array elements between the first and second negative elements
double sumBetweenNegatives(const double arr[], int size) {
    bool firstNegativeFound = false;
    double sum = 0.0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            if (firstNegativeFound) {
                // Second negative element found, stop the loop
                break;
            }
            firstNegativeFound = true;
        }

        if (firstNegativeFound) {
            sum += arr[i];
        }
    }

    return sum;
}

// Function to transform the array based on the modulus criterion
void transformArray(double arr[], int size) {
    int lowModulusIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (std::abs(arr[i]) <= 1.0) {
            // Swap element with the first position where modulus <= 1
            std::swap(arr[i], arr[lowModulusIndex]);
            ++lowModulusIndex;
        }
    }
}

int main() {
    const int maxSize = 100;  // Adjust the size according to your needs
    double arr[maxSize];
    int size;

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    if (size <= 0 || size > maxSize) {
        std::cerr << "Invalid array size\n";
        return 1;
    }

    // Input array elements
    std::cout << "Enter the array elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Task 1: Find the number of the minimum element in the array
    int minIndex = findMinIndex(arr, size);
    std::cout << "Task 1: Number of the minimum element: " << minIndex + 1 << "\n";

    // Task 2: Calculate the sum of array elements between the first and second negative elements
    double sumBetweenNegativesResult = sumBetweenNegatives(arr, size);
    std::cout << "Task 2: Sum between the first and second negative elements: " << sumBetweenNegativesResult << "\n";

    // Task 3: Transform the array based on the modulus criterion
    transformArray(arr, size);

    // Output the transformed array
    std::cout << "Task 3: Transformed Array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
