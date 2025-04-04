#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
using namespace chrono;

double calcularPi(size_t iteracoes) {
    double pi = 0.0;
    for (size_t k = 0; k < iteracoes; ++k) {
        pi += pow(-1, k) / (2.0 * k + 1);
    }
    return 4.0 * pi;
}

int main() {
    ofstream file("dados_pi.csv");
    file << "Iteracoes,Aproximado,Erro,Tempo(ms)" << endl;
    vector<size_t> steps = {10, 100, 1000, 10000, 100000, 1000000};
    for (size_t iter : steps) {
        auto start = high_resolution_clock::now();
        double pi_aprox = calcularPi(iter);
        auto end = high_resolution_clock::now();
        double tempo_ms = duration_cast<microseconds>(end - start).count() / 1000.0;

        double erro = abs(M_PI - pi_aprox);

        cout << fixed << setprecision(10);
        cout << "Iterações: " << iter
             << " | π ~ " << pi_aprox
             << " | Erro: " << erro
             << " | Tempo: " << tempo_ms << " ms" << endl;

        file << iter << "," << pi_aprox << "," << erro << "," << tempo_ms << endl;
    }

    file.close();
    cout << "Resultados salvos em dados_pi.csv" << endl;
    return 0;
}
