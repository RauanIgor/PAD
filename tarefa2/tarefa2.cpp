#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    clock_t start, end;
    double cpu_time_used;
    int getArrayLength = 2000000;
    int nums[getArrayLength];
    int soma = 0;
    int S1 = 0;
    int S2 = 0;

    cout << getArrayLength << endl;
    start = clock();
    for (size_t i = 0; i < getArrayLength; i++)
    {

        nums[i] = i*2;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Versão 1 - Inicialização simples: " << double(cpu_time_used) << " segundos " << endl;

    start = clock();
    for (size_t i = 0; i < getArrayLength; i++)
    {
        soma += nums[i];
        
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Versão 2 - Soma simples: " << double(cpu_time_used) << " segundos " << endl;

    start = clock();
    for (size_t i = 0; i < getArrayLength; i+=2)
    {
        S1 += nums[i];
        S2 += nums[i+1];
    }
    soma = S1+S2;
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "Versão 3 - Soma dupla: " << double(cpu_time_used) << " segundos " << endl;
    return 0;
}