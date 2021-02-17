#include <iostream>
#include <string>
using namespace std;

struct KNIGA {
    string name; //Название книги
    string author; //Автор книги
    int year; //Год публикации
    int pages; //Кол-во страниц
};

//Функция вывода элементов структуры
void out(struct KNIGA book[], int N, int i = 1) {
    while (i < N) {
        cout << "\nНазвание книги: " << book[i].name << "\nАвтор книги: " << book[i].author << "\nГод издания: " << book[i].year << "\nКол-во страниц: " << book[i].pages << endl;
        i++;
    }
};

int main()
{
    system("chcp 1251");
    KNIGA book[100]; //Создаём структуру KNIGA на 100 элементов
    KNIGA kniga[100]; //Создаём дополнительную структуру на 100 элементов
    string answer;
    int i = 1, N, j = 1, n = 1;

    //Ввод элементов в структуру с проверкой правильности введенных данных
    cout << "\nХотите ввести элементы вручную? (Да/Нет)\n";
    cin >> answer;
    if (answer != "Нет") {
        while (answer != "Нет") {
            cout << "\nВведите название книги: ";
            getline(cin, book[i].name);
            cout << "Введите фамилию автора книги: ";
            cin >> book[i].author;
            cout << "Введите год издания книги: ";
            do {
                cin >> book[i].year;
                if ((book[i].year > 2021) || (book[i].year < 1)) {
                    cout << "Введён некорректный год! \nВедите год издания книги: ";
                }
            } while ((book[i].year > 2021) || (book[i].year < 1));
            cout << "Введите кол-во страниц: ";
            do {
                cin >> book[i].pages;
                if (book[i].pages < 5) {
                    cout << "Введено некорректное кол - во страниц! \nВедите кол-во страниц: ";
                }
            } while (book[i].pages < 5);
            i++;
            cout << "\nПродолжить заполнение? (Да/Нет)\n";
            cin >> answer;
            cin.get(); //Удаление последнего введенного символа в потоке
        };
    }
    else {
        book[1] = { "Горе от ума", "Грибоедов", 1825, 98 };
        book[2] = { "Евгений Онегин", "Пушкин", 1825, 400 };
        book[3] = { "Герой нашего времени", "Лермонтов", 1840, 423 };
        book[4] = { "Мертвые души", "Гоголь", 2011, 352 };
        book[5] = { "Приключения Шерлока Холмса", "Дойль", 1892, 307 };
        book[6] = { "Мастер и Маргарита", "Булгаков", 1966, 504 };
        i = 7;
    }

    // Вывод элементов структуры после заполнения при помощи функции
    N = i;
    out(book, N);

    //Удаление первых 3-ёх элементов структуры
    for (i = 4; i < N; i++) {
        kniga[j].name = book[i].name;
        kniga[j].author = book[i].author;
        kniga[j].year = book[i].year;
        kniga[j].pages = book[i].pages;
        j++;
    }

    //Поиск по названию книги
    N = j;
    cout << "\nУкажите название книги перед которой вы хотите вставить новый элемент.\n";
    cin.get();
    getline(cin, answer);
    while ((answer != kniga[n].name) && (n < N)) {
        n++;
    }
    if (n >= N) {
        cout << "\nВведенная вами книга в структуре отсутствует либо удалена.\n";
    }
    else {
        //Сдвиг структуры вправо от искомой
        for (i = N; i >= n; i--) {
            kniga[i].name = kniga[i - 1].name;
            kniga[i].author = kniga[i - 1].author;
            kniga[i].year = kniga[i - 1].year;
            kniga[i].pages = kniga[i - 1].pages;
        }
    }
    cout << "\nВведите название новой книги: ";
    getline(cin, kniga[n].name);
    cout << "Введите фамилию автора книги: ";
    cin >> kniga[n].author;
    cout << "Введите год издания книги: ";
    do {
        cin >> kniga[n].year;
        if ((kniga[n].year > 2021) || (kniga[n].year < 1)) {
            cout << "Введён некорректный год! \nВведите правильный год издания книги: ";
        }
    } while ((kniga[n].year > 2021) || (kniga[n].year < 1));
    cout << "Введите кол-во страниц: ";
    do {
        cin >> kniga[n].pages;
        if (kniga[n].pages < 5) {
            cout << "Введено некорректное кол - во страниц! \nВведите правильное кол - во страниц: ";
        }
    } while (kniga[n].pages < 5);

    //Вывод результата работы программы
    cout << "\nКонечная версия структуры: \n";
    out(kniga, N + 1);
    cout << endl;

    system("pause");
    return 0;
}