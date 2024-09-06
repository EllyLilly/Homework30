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
    Array() {
        data = new int[volume];
    }

    //Инициализирующий конструктор
    Array(const int* init_data, size_t init_size) {
        this->size = init_size;
        this->volume = init_size;
        data = new int[volume];
        for (size_t i = 0; i < size; ++i) {
            data[i] = init_data[i];
        }
    }

    //Конструктор копирования
    Array(const Array& copy) {
        this->size = copy.size;
        this->volume = copy.volume;
        data = new int[volume];
        for (size_t i = 0; i < size; ++i) {
            data[i] = copy.data[i];
        }
    }

    //Деструктор
    ~Array() {
        delete[] data;
    }

    //Метод добавления элемента в конец
    void add_end(int value) {
        //проверка, нужно ли увеличивать объем массива
        if (size >= volume) {
            int new_volume = volume * 2;
            int* new_data = new int[new_volume];

            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;

            data = new_data;
            volume = new_volume;
        }
        data[size++] = value;
    }

    //Метод добавления элементов в начало
    void add_init(int value) {
        if (size >= volume) {
            int new_volume = volume * 2; //увеличиваем объем массива в два раза
            int* new_data = new int[new_volume];

            for (int i = 0; i < size; i++) {
                new_data[i + 1] = data[i]; //сдвиг элементов вправо
            }
            delete[] data;
            data = new_data;
            volume = new_volume;
        }
        else {
            //если объем массива не надо изменять, сдвигаем элементы вправо
            for (int i = size; i > 0; --i) {
                data[i] = data[i - 1];
            }
        }
        //добавляем элемент в начало
        data[0] = value;
        ++size;
    }

    //Метод удаления элемента с конца
    void remove_end() {
        if (size > 0) {
            size--;
        }
    }

    //Метод удаления элемента с начала
    void remove_init() {
        if (size > 0) {
            for (size_t i = 0; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--; //уменьшаем размер массива
        }
    }

    //Метод удаления элемента по индексу
    void remove_ind(int index) {
        if (index >= 0 && index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    //Метод сравнения двух массивов
    bool isEqual(const Array& other) {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    //Метод сортировки (пузырек)
    void sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size; ++j) {
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    //Метод поиска элемента
    int search(int value) {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1; //если индекс не найден, возвращаем -1
    }

    //Метод переворота массива
    void reverse() {
        for (size_t i = 0; i < size / 2; ++i) {
            swap(data[i], data[size - i - 1]);
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
