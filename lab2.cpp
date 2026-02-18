#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;

// УПРАЖНЕНИЕ 2: Ссылки и Указатели. 
void changeValues(int& a, int* b, int newVal1, int newVal2) {
    a = newVal1;
    *b = newVal2;
}

void task2() {
    int x, y, new1, new2;

    cout << "\n Упражнение 2: Ссылка + Указатель \n";
    cout << "Введите начальное значение для 1-й переменной (ссылка): ";
    cin >> x;
    cout << "Введите начальное значение для 2-й переменной (указатель): ";
    cin >> y;

    cout << "\nДО изменений: x = " << x << ", y = " << y << endl;

    cout << "\nНа что изменить?\n";
    cout << "Новое значение для 1-й переменной: ";
    cin >> new1;
    cout << "Новое значение для 2-й переменной: ";
    cin >> new2;

    changeValues(x, &y, new1, new2);

    cout << "\nПосле изменений: x = " << x << ", y = " << y << endl;
    cout << "x изменён через Ссылку, y изменён через Указатель\n";
}

// УПРАЖНЕНИЕ 3.1 - Массивы 
void task3_1() {
    const int razmer = 10;
    int massiv[razmer];
    for (int i = 0; i < razmer; i++) massiv[i] = i * i;
    cout << "\n3.1 (Статич., индекс): ";
    for (int i = 0; i < razmer; i++) cout << massiv[i] << " ";
    cout << endl;
}

void task3_2() {
    const int razmer = 10;
    int massiv[razmer];
    for (int i = 0; i < razmer; i++) *(massiv + i) = i * i;
    cout << "\n3.2 (Статич., указатель): ";
    for (int i = 0; i < razmer; i++) cout << *(massiv + i) << " ";
    cout << endl;
}

void task3_3() {
    const int razmer = 10;
    int* massiv = new int[razmer];
    for (int i = 0; i < razmer; i++) massiv[i] = i * i;
    cout << "\n3.3 (Динам., индекс): ";
    for (int i = 0; i < razmer; i++) cout << massiv[i] << " ";
    cout << endl;
    delete[] massiv;
}

void task3_4() {
    const int razmer = 10;
    int* massiv = new int[razmer];
    for (int i = 0; i < razmer; i++) *(massiv + i) = i * i;
    cout << "\n3.4 (Динам., указатель): ";
    for (int i = 0; i < razmer; i++) cout << *(massiv + i) << " ";
    cout << endl;
    delete[] massiv;
}

// УПРАЖНЕНИЕ 3.2 - Слияние массивов 
void task3_merge() {
    const int razmerMassiva1 = 5, razmerMassiva2 = 6;

    int* massiv1 = new int[razmerMassiva1] {1, 3, 5, 7, 9};
    int* massiv2 = new int[razmerMassiva2] {2, 4, 6, 8, 10, 12};
    int* massivResult = new int[razmerMassiva1 + razmerMassiva2];

    int indeks1 = 0, indeks2 = 0, indeksResult = 0;

    // Слияние: косвенная адресация для чтения, индексная для записи
    while (indeks1 < razmerMassiva1 && indeks2 < razmerMassiva2) {
        if (*(massiv1 + indeks1) <= *(massiv2 + indeks2)) {
            massivResult[indeksResult] = *(massiv1 + indeks1); indeks1++;
        }
        else {
            massivResult[indeksResult] = *(massiv2 + indeks2); indeks2++;
        }
        indeksResult++;
    }
    while (indeks1 < razmerMassiva1) { massivResult[indeksResult] = *(massiv1 + indeks1); indeks1++; indeksResult++; }
    while (indeks2 < razmerMassiva2) { massivResult[indeksResult] = *(massiv2 + indeks2); indeks2++; indeksResult++; }

    cout << "\nСлитый массив: ";
    for (int indeksVyvoda = 0; indeksVyvoda < razmerMassiva1 + razmerMassiva2; indeksVyvoda++) cout << massivResult[indeksVyvoda] << " ";
    cout << endl;

    delete[] massiv1; delete[] massiv2; delete[] massivResult;
}

// УПРАЖНЕНИЕ 4: Двусвязный список 
struct Spisok {
    int data;
    Spisok* next;
    Spisok* prev;
};

void task4() {
    Spisok* head = nullptr;
    Spisok* tail = nullptr;

    for (int i = 1; i <= 10; i++) {
        Spisok* newElement = new Spisok;
        newElement->data = i;
        newElement->next = nullptr;
        newElement->prev = tail;
        if (tail)
            tail->next = newElement;
        else
            head = newElement;
        tail = newElement;
    }

    cout << "\nДвусвязный список: ";
    Spisok* p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    while (head) {
        Spisok* temp = head;
        head = head->next;
        delete temp;
    }
}

// ГЛАВНАЯ ПРОГРАММА 
int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    do {
        cout << "\n Лабораторная N-8 \n";
        cout << "1) Упр 2: ссылка + указатель (Ввод Данных)\n";
        cout << "2) Упр 3.1 статический индекс\n";
        cout << "3) Упр 3.1 статический указатель\n";
        cout << "4) Упр 3.1 динамический индекс\n";
        cout << "5) Упр 3.1 динамический указатель\n";
        cout << "6) Упр 3.2 слияние массивов\n";
        cout << "7) Упр 4: двусвязный список\n";
        cout << "0) Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: task2(); break;
        case 2: task3_1(); break;
        case 3: task3_2(); break;
        case 4: task3_3(); break;
        case 5: task3_4(); break;
        case 6: task3_merge(); break;
        case 7: task4(); break;
        case 0: cout << "Выход.\n"; break;
        default: cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}