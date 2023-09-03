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

using namespace std;

void copyArray(int originArray[], int destinyArray[]);
void deleteDupes(int array[]);
void shellSort(int array[]);
void generateRandomNumbers();
void sortNumbersList(int list[]);
void binarySearchNumber(char number, int list[]);

int main()
{
    int dupedNumbers[10] = {4, 7, 11, 4, 9, 5, 11, 7, 3, 5};
    int deleteNumbersCopy[10], orderedCopy[10];
    copyArray(dupedNumbers, deleteNumbersCopy);
    deleteDupes(deleteNumbersCopy);
    copyArray(dupedNumbers, orderedCopy);
    shellSort(orderedCopy);
    deleteDupes(orderedCopy);

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

void shellSort(int array[])
{
 
    int intervalo, i, j, k;
    intervalo = 10 / 2;
    while (intervalo > 0)
    {
        for (i = intervalo; i < 10; i++)
        {
            j = i - intervalo;
            while (j >= 0)
            {
                k = j + intervalo;
                if (array[j] <= array[k])
                    j = -1; /* así termina el bucle, par ordenado */
                else
                {
                    double temp;
                    temp = array[j];
                    array[j] = array[k];
                    array[k] = temp;
                    j -= intervalo;
                }
            }
        }
        intervalo = intervalo / 2;
    }
}
