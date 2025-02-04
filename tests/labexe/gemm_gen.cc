/*
 * Arch 2024 fall course code.
 * - This is a C++ code generating matrices for GEMM.
 * - This code is generated by Github Copilot.
 * - This program will generate two matrices with random values and
 * write them to the given file as C-style arrays.
 */

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Usage: " << argv[0] << " <file_name> <n> <m> <k>\n";
        return 1;
    }

    std::ofstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file " << argv[1] << "\n";
        return 1;
    }

    int n = std::atoi(argv[2]);
    int m = std::atoi(argv[3]);
    int k = std::atoi(argv[4]);
    file << "#define N " << n << "\n";
    file << "#define M " << m << "\n";
    file << "#define K " << k << "\n";

    // Generate matrices with random values, ranging from 0 to 1e4
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1e6);
    // Write the matrices to the file as C-style arrays
    file << "double A[N][K] = {\n";
    for (int i = 0; i < n; i++) {
        file << "  {";
        for (int j = 0; j < k; j++) {
            file << dis(gen);
            if (j != k - 1) file << ", ";
        }
        file << "}";
        if (i != n - 1) file << ",";
        file << "\n";
    }
    file << "};\n";

    file << "double B[M][K] = {\n";
    for (int i = 0; i < m; i++) {
        file << "  {";
        for (int j = 0; j < k; j++) {
            file << dis(gen);
            if (j != m - 1) file << ", ";
        }
        file << "}";
        if (i != k - 1) file << ",";
        file << "\n";
    }
    file << "};\n";

    file << "double C[N][M] = {0};\n";
    file.close();

    return 0;
}
