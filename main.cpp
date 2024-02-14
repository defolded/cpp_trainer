#include <iostream>
#include <fstream>

int main() {

    std::ofstream testFile("test.txt");

    for (int b = 1; b <= 10; ++b) {
        testFile << b << '\n';
    }

    testFile.close();

    return 0;
}
