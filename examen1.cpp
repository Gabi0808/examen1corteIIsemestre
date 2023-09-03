/*1.Se desea eliminar todos los números duplicados de una
lista o vector (array). Por ejemplo, si el array
toma los valores 4 7 11 4 9 5 11 7 3  5
ha de cambiarse a 4 7 11 9 5 3.
A.Escribir una función que elimine los elementos duplicados de un array.
B.Escribir una función que elimine los elementos duplicados de un vector
ordenado. ¿Cuál es la eficiencia de esta función?
2. Se desea realizar un programa que realice las siguientes tareas:
a) Generar, aleatoriamente, una lista de 999 números enteros en
el rango de 0 a 20.000.
b) Ordenar en modo creciente
c) Buscar si existe el número x (leído del teclado)
en la lista. La búsqueda debe serBinaria*/
#include <iostream>
#define MAX 10
#include <cstdlib>
#include <ctime>

using namespace std;

void copyArray(int originArray[], int destinyArray[]);
void deleteDupes(int array[]);
void shellSort(int list[], int n);
void generateRandomNumbers();
void bubbleSort(int list[], int n);
void insertionSort(int list[], int n);
void exchangeSort(int list[], int n);
void binarySearchNumber(char number, int list[]);
void printMenu();

int main()
{
    int dupedNumbers[10] = {4, 7, 11, 4, 9, 5, 11, 7, 3, 5};
    int deleteNumbersCopy[10], orderedCopy[10];

    int choice;

    while (true)
    {
        printMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            copyArray(dupedNumbers, deleteNumbersCopy);
            deleteDupes(deleteNumbersCopy);
            break;
        case 2:
            generateRandomNumbers();
            break;
        case 3:
            copyArray(dupedNumbers, orderedCopy);
            shellSort(orderedCopy);
            deleteDupes(orderedCopy);
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            break;
        }
    }

    return 0;
}

int funciones()
{
    int dupedNumbers[10] = {4, 7, 11, 4, 9, 5, 11, 7, 3, 5};
    int deleteNumbersCopy[10], orderedCopy[10];
    copyArray(dupedNumbers, deleteNumbersCopy);
    deleteDupes(deleteNumbersCopy);
    copyArray(dupedNumbers, orderedCopy);
    shellSort(orderedCopy, 10);
    deleteDupes(orderedCopy);

    int shellSortCopy[999], bubbleSortCopy[999], insertionSortCopy[999], exchangeSortCopy[999];

    return 0;
}

void copyArray(int originArray[], int destinyArray[])
{
    for (int i = 0; i < 10; i++)
    {
        destinyArray[i] = originArray[i];
    }
}

void deleteDupes(int array[])
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
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


    int intervalo, i, j, k;
    intervalo = 10 / 2;
    while (intervalo > 0)
    {
        for (i = intervalo; i < n; i++)
        {
            j = i - intervalo;
            while (j >= 0)
            {
                k = j + intervalo;
                if (list[j] <= list[k])
                    j = -1; /* así termina el bucle, par ordenado */
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
}

void generateRandomNumbers()
{
void generateRandomNumbers()
{

    int numberList[999];
    srand(static_cast<unsigned>(time(nullptr)));
    int numberList[999];
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 999; i++)
    {
        int randomNumber = rand() % 20001;
        numberList[i] = randomNumber;
    }
}

void bubbleSort(int list[], int n)
{
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
}
void insertionSort(int list[], int n)
{
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
}
void exchangeSort(int list[], int n)
{


}