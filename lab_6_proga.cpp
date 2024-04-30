#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    int num;
    while (inputFile >> num) {
        vec.push_back(num);
    }
    inputFile.close();

    // Реверс вектора
    std::reverse(vec.begin(), vec.end());

    // Находим минимальный элемент
    int minElement = *std::min_element(vec.begin(), vec.end());
    
    // Удаляем четные элементы
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }), vec.end());

    // Сортируем вектор по возрастанию
    std::sort(vec.begin(), vec.end());

    // Вставляем элемент в вектор, сохраняя сортировку
    int newElement = 100;
    vec.insert(std::upper_bound(vec.begin(), vec.end(), newElement), newElement);

    // Находим индекс заданного элемента
    int searchElement = 50;
    auto it = std::find(vec.begin(), vec.end(), searchElement);
    if (it != vec.end()) {
        int index = std::distance(vec.begin(), it);
        std::cout << "Индекс элемента " << searchElement << " : " << index << std::endl;
    } else {
        std::cout << "Элемент не найден в векторе" << std::endl;
    }

    // Удаляем повторяющиеся элементы
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    // Выводим окончательный вектор
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}