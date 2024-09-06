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
        size = 0;
        volume = 10;
        data = new int[volume];
    }

    //Инициализирующий конструктор
    Array(const int* init_data, size_t init_size) {
        this->size = init_size;
        this->volume = init_size * 2;
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
            resize();
        }
        data[size++] = value;
    }

    //Метод добавления элементов в начало
    void add_init(int value) {
        if (size >= volume) {
            resize();
        }
            for (int i = size; i << size > 0; --i) {
                data[i] = data[i - 1]; //сдвиг элементов вправо
            }
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

    //Метод удаления элемента из произвольного места
    void remove_ind(int index) {
        if (index >= size) {
            cout << "Index is out of range.\n";
            return;
        }
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
        }

    //Метод сравнения двух массивов
    bool isEqual(const Array& other) {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    //Метод сортировки пузырьком
    void sort() {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
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
        return -1;
    }

    //Метод переворота массива
    void reverse() {
        for (size_t i = 0; i < size / 2; ++i) {
            swap(data[i], data[size - i - 1]);
        }
    }

    //Метод вывода
    void print() {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    //Метод получения текущего размера массива
    size_t get_size() {
        return size;
    }

    

};

int main()
{
    Array arr;

    arr.add_end(10);
    arr.add_end(20);
    arr.add_end(30);
    arr.print();

    arr.add_init(5);
    arr.print();

    arr.remove_end();
    arr.print();
    arr.remove_init();
    arr.print();

    arr.remove_ind(0);
    arr.print();

    arr.add_end(15);
    arr.add_end(25);
    arr.sort();
    arr.print();

    arr.reverse();
    arr.print();

    int index = arr.search(20);
    cout << "Index of 20: " << index << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
