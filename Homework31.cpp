// Homework31.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

//Класс массив чисел
class Array {
private:
    int* data; //указатель на динамический массив
    size_t size; //размер массива
    size_t volume; //объем массива

    //Метод увеличения объема массива
    void resize() {
        volume *= 2; //увеличиваем объем в 2 раза
        int* newData = new int[volume];

        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i]; //копируем данные в новый массив
        }
        delete[] data;
        data = newData;
    }
public:
    //Конструктор по умолчанию
    Array() : size(0), volume(2) {
        data = new int[volume];
    }

    //Инициализирующий конструктор
    Array(const int* init_data, size_t init_size) : size(init_size), volume(init_size) {
        data = new int[volume];
        for (size_t i = 0; i < size; ++i) {
            data[i] = init_data[i];
        }
    }

    //Конструктор копирования
    Array(const Array& rest) : size(rest.size), volume(rest.volume) {
        data = new int[volume];
        for (size_t i = 0; i < size; ++i) {
            data[i] = rest.data[i]
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
