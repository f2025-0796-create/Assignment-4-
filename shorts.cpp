#include <iostream>
#include <vector>
#include <algorithm> // for count, max_element, min_element
#include <limits>

void reverseVector(std::vector<int> &v) {
    // Reverse elements in place using two-pointer swap
    size_t i = 0, j = (v.empty() ? 0 : v.size() - 1);
    while (i < j) {
        std::swap(v[i], v[j]);
        ++i;
        --j;
    }
}

int main() {
    // 1) Initialize and Print
    std::vector<int> init = {10, 20, 30, 40, 50};

    std::cout << "Initial vector contents (traditional for loop):\n";
    for (size_t i = 0; i < init.size(); ++i) {
        std::cout << init[i] << (i + 1 < init.size() ? ", " : "\n");
    }

    std::cout << "Initial vector contents (range-based for loop):\n";
    for (int value : init) {
        std::cout << value << " ";
    }
    std::cout << "\n\n";

    // 2) User input: read N integers into vector
    std::cout << "Enter number of integers to read (N): ";
    int N;
    if (!(std::cin >> N) || N < 0) {
        std::cerr << "Invalid N. Exiting.\n";
        return 1;
    }

    std::vector<int> data;
    data.reserve(static_cast<size_t>(N));
    std::cout << "Enter " << N << " integer(s), separated by spaces or newlines:\n";
    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        data.push_back(x);
    }

    if (data.empty()) {
        std::cout << "No elements were entered. Exiting.\n";
        return 0;
    }

    std::cout << "You entered:\n";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << (i + 1 < data.size() ? " " : "\n");
    }

    // 3) Find Maximum and Minimum
    auto minIt = std::min_element(data.begin(), data.end());
    auto maxIt = std::max_element(data.begin(), data.end());
    if (minIt != data.end() && maxIt != data.end()) {
        std::cout << "Minimum element: " << *minIt << "\n";
        std::cout << "Maximum element: " << *maxIt << "\n";
    }

    // 4) Reverse the Elements (in place)
    reverseVector(data);
    std::cout << "Vector after reversing:\n";
    for (int v : data) std::cout << v << " ";
    std::cout << "\n";

    // 5) Count Occurrences
    std::cout << "Enter a target number to count occurrences: ";
    int target;
    if (!(std::cin >> target)) {
        std::cerr << "Invalid input for target. Exiting.\n";
        return 1;
    }

    int count = static_cast<int>(std::count(data.begin(), data.end(), target));
    std::cout << "The number " << target << " appears " << count
              << (count == 1 ? " time" : " times") << " in the vector.\n";

    return 0;
}
