/*1.Se desea eliminar todos los números duplicados de una
lista o vector (array). Por ejemplo, si el array
toma los valores 4 7 11 4 9 5 11 7 3  5
ha de cambiarse a 4 7 11 9 5 3.
A.Escribir una función que elimine los elementos duplicados de un array.
B.Escribir una función que elimine los elementos duplicados de un vector
ordenado. ¿Cuál es la eficiencia de esta función?
2. Se desea realizar un programa que realice las siguientes tareas:
a) Generar, aleatoriamente, una lista de MAX números enteros en
el rango de 0 a 20.000.
b) Ordenar en modo creciente
c) Buscar si existe el número x (leído del teclado)
en la lista. La búsqueda debe serBinaria*/
#include <iostream>
#define MAX 999
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void copyArray(int originArray[], int destinyArray[], int size);
void deleteDupes(int array[], int n);
void shellSort(int list[], int n);
void generateRandomNumbers(int list[]);
void bubbleSort(int list[], int n);
void insertionSort(int list[], int n);
void exchangeSort(int list[], int n);
int binarySearchNumber(int key, int list[], int size);
void printMenu();
void printArray(int array[], int size);
void printFunctionSelected();

int main()
{
    int dupedNumbers[10] = {4, 7, 11, 4, 9, 5, 11, 7, 3, 5};
    int numberList[MAX], exchangeList[MAX], bubbleList[MAX], insertionList[MAX], shellList[MAX];
    int deleteNumbersCopy[10], orderedCopy[10];

    int choice, choice2, searchedNumber, results;
    unsigned t0, t1;
    t0 = clock();
    while (choice != 4)
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            copyArray(dupedNumbers, deleteNumbersCopy, 10);
            deleteDupes(deleteNumbersCopy, 10);
            break;
        case 2:
            copyArray(dupedNumbers, orderedCopy, 10);
            shellSort(orderedCopy, 10);
            deleteDupes(orderedCopy, 10);
            break;
        case 3:

            generateRandomNumbers(numberList);
            while (choice2 != 6)
            {
                printFunctionSelected();
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    copyArray(numberList, exchangeList, MAX);
                    exchangeSort(exchangeList, MAX);
                    printArray(exchangeList, MAX);
                    exchangeSort(exchangeList, MAX);
                    break;
                case 2:
                    copyArray(numberList, bubbleList, MAX);
                    bubbleSort(bubbleList, MAX);
                    printArray(bubbleList, MAX);
                    bubbleSort(bubbleList, MAX);
                    break;
                case 3:
                    copyArray(numberList, insertionList, MAX);
                    insertionSort(insertionList, MAX);
                    printArray(insertionList, MAX);
                    insertionSort(insertionList, MAX);
                    break;
                case 4:
                    copyArray(numberList, shellList, MAX);
                    shellSort(shellList, MAX);
                    printArray(shellList, MAX);
                    shellSort(shellList, MAX);
                    break;
                case 5:
                    printArray(numberList, MAX);
                    break;
                case 6:
                    cout << "Ingresa el numero a buscar" << endl;
                    cin >> searchedNumber;
                    shellSort(shellList, MAX);
                    results = binarySearchNumber(searchedNumber, shellList, MAX);
                    if (results == -1)
                    {
                        cout << "No se encontro el elemento en la lista" << endl;
                        break;
                    }
                    cout << "El numero se encuentra en la lista, en el indice: " << results << endl;

                    break;
                case 7:
                    cout << "Saliendo del programa." << endl;
                    break;
                default:
                    cout << "Ingrese una opcion valida." << endl;
                    break;
                }
            }

            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            break;
        }
    }
    t1 = clock();
    double time = (double(t0 - t1) / CLOCKS_PER_SEC);
    cout << "El tiempo transcurrido es de " << time << endl;
    return 0;
}

void copyArray(int originArray[], int destinyArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destinyArray[i] = originArray[i];
    }
}
void deleteDupes(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                array[j] = 0;
            }
        }
    }
}
void shellSort(int list[], int n)
{
    auto inicio = chrono::high_resolution_clock::now();
    int intervalo, i, j, k;
    intervalo = n / 2;
    while (intervalo > 0)
    {
        for (i = intervalo; i < n; i++)
        {
            j = i - intervalo;
            while (j >= 0)
            {
                k = j + intervalo;
                if (list[j] <= list[k])
                    j = -1;
                else
                {
                    double temp;
                    temp = list[j];
                    list[j] = list[k];
                    list[k] = temp;
                    j -= intervalo;
                }
            }
        }
        intervalo = intervalo / 2;
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> tiempo_promedio = fin - inicio;
    cout << "Tiempo promedio de ejecución: " << tiempo_promedio.count() << " nanosegundos" << endl;
}

void generateRandomNumbers(int list[])
{
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < MAX; i++)
    {
        int randomNumber = rand() % 20001;
        list[i] = randomNumber;
    }
}
void bubbleSort(int list[], int n)
{

    auto inicio = chrono::high_resolution_clock::now();
    int interruptor = 1;
    int pasada, j;
    for (pasada = 0; pasada < n - 1 && interruptor; pasada++)
    {
        interruptor = 0;
        for (j = 0; j < n - pasada - 1; j++)
            if (list[j] > list[j + 1])
            {
                long aux;
                interruptor = 1;
                aux = list[j];
                list[j] = list[j + 1];
                list[j + 1] = aux;
            }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> tiempo_promedio = fin - inicio;
    cout << "Tiempo promedio de ejecución: " << tiempo_promedio.count() << " nanosegundos" << endl;
}
void insertionSort(int list[], int n)
{
    auto inicio = chrono::high_resolution_clock::now();
    int i, j;
    int aux;
    for (i = 1; i < n; i++)
    {
        j = i;
        aux = list[i];
        while (j > 0 && aux < list[j - 1])
        {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = aux;
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> tiempo_promedio = fin - inicio;
    cout << "Tiempo promedio de ejecución: " << tiempo_promedio.count() << " nanosegundos" << endl;
}
void exchangeSort(int list[], int n)
{
    auto inicio = chrono::high_resolution_clock::now();
    int i, j;
    for (i = 0; i <= n - 2; i++)

        for (j = i + 1; j <= n - 1; j++)
            if (list[i] > list[j])
            {
                int aux;
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> tiempo_promedio = fin - inicio;
    cout << "Tiempo promedio de ejecución: " << tiempo_promedio.count() << " nanosegundos" << endl;
}
void printMenu()
{
    cout << "Menu examen 1er corte II Semestre" << endl;
    cout << "Seleccione una opcion: " << endl;
    cout << "1. Eliminar numeros duplicados en un arreglo desordenado." << endl;
    cout << "2. Eliminar numeros duplicados en un arreglo ordenado." << endl;
    cout << "3. Ordenamiento de una lista de numeros aleatorios." << endl;
    cout << "4. Salir del programa" << endl;
}
void printFunctionSelected()
{
    cout << "Con que metodo desea ordenar los numeros?" << endl;
    cout << "1. Ordenar lista de numeros aleatorios por intercambio." << endl;
    cout << "2. Ordenar lista de numeros aleatorios por metodo burbuja." << endl;
    cout << "3. Ordenar lista de numeros aleatorios por insercion." << endl;
    cout << "4. Ordenar lista de numeros aleatorios por metodo shell." << endl;
    cout << "5. Mostrar lista de numeros aleatorios sin ordenar. " << endl;
    cout << "6. Realizar busqueda binaria." << endl;
    cout << "7. Salir del menu." << endl;
}
void printArray(int array[], int size)
{

    cout << "Mostrando el arreglo: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int binarySearchNumber(int key, int list[], int size)
{
    auto inicio = chrono::high_resolution_clock::now();
    int central, bajo, alto;
    int valorCentral;
    bajo = 0;
    alto = size - 1;
    while (bajo <= alto)
    {
        central = (bajo + alto) / 2;
        valorCentral = list[central];
        if (key == valorCentral)
            return central;
        else if (key < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> tiempo_promedio = fin - inicio;
    cout << "Tiempo promedio de ejecución: " << tiempo_promedio.count() << " nanosegundos" << endl;
    return -1;
}
