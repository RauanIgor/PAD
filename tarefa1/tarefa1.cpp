#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace chrono;

vector<double> matrixVectorRowMajor(const vector<vector<double>>& matrix, const vector<double>& vec) {
    size_t n = matrix.size();
    vector<double> result(n, 0.0);
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

vector<double> matrixVectorColumnMajor(const vector<vector<double>>& matrix, const vector<double>& vec) {
    size_t n = matrix.size();
    vector<double> result(n, 0.0);
    
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < n; ++i) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

void benchmark(size_t size, ofstream& file) {
    vector<vector<double>> matrix(size, vector<double>(size));
    vector<double> vec(size);
    
    for (size_t i = 0; i < size; ++i) {
        vec[i] = rand() % 100;
        for (size_t j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    auto start = high_resolution_clock::now();
    matrixVectorRowMajor(matrix, vec);
    auto end = high_resolution_clock::now();
    auto rowMajorTime = duration_cast<microseconds>(end - start).count();
    
    start = high_resolution_clock::now();
    matrixVectorColumnMajor(matrix, vec);
    end = high_resolution_clock::now();
    auto columnMajorTime = duration_cast<microseconds>(end - start).count();
    
    cout << "Tamanho: " << size << "x" << size << " | Row-Major: " << rowMajorTime << " us | Column-Major: " << columnMajorTime << " us" << endl;
    
    file << size << "," << rowMajorTime << "," << columnMajorTime << endl;
}

int main() {
    srand(time(nullptr));
    
    ofstream file("dados.csv");
    file << "Tamanho,RowMajor,ColumnMajor" << endl;
    
    vector<size_t> sizes = {100, 200, 500, 1000, 1500, 2000};
    for (size_t size : sizes) {
        benchmark(size, file);
    }
    
    file.close();
    
    cout << "Resultados salvos em dados.csv" << endl;
    
    return 0;
}
