#include <iostream>
#include <string>
using namespace std;

struct KNIGA {
    string name; //�������� �����
    string author; //����� �����
    int year; //��� ����������
    int pages; //���-�� �������
};

//������� ������ ��������� ���������
void out(struct KNIGA book[], int N, int i = 1) {
    while (i < N) {
        cout << "\n�������� �����: " << book[i].name << "\n����� �����: " << book[i].author << "\n��� �������: " << book[i].year << "\n���-�� �������: " << book[i].pages << endl;
        i++;
    }
};

int main()
{
    system("chcp 1251");
    KNIGA book[100]; //������ ��������� KNIGA �� 100 ���������
    KNIGA kniga[100]; //������ �������������� ��������� �� 100 ���������
    string answer;
    int i = 1, N, j = 1, n = 1;

    //���� ��������� � ��������� � ��������� ������������ ��������� ������
    cout << "\n������ ������ �������� �������? (��/���)\n";
    cin >> answer;
    if (answer != "���") {
        while (answer != "���") {
            cout << "\n������� �������� �����: ";
            getline(cin, book[i].name);
            cout << "������� ������� ������ �����: ";
            cin >> book[i].author;
            cout << "������� ��� ������� �����: ";
            do {
                cin >> book[i].year;
                if ((book[i].year > 2021) || (book[i].year < 1)) {
                    cout << "����� ������������ ���! \n������ ��� ������� �����: ";
                }
            } while ((book[i].year > 2021) || (book[i].year < 1));
            cout << "������� ���-�� �������: ";
            do {
                cin >> book[i].pages;
                if (book[i].pages < 5) {
                    cout << "������� ������������ ��� - �� �������! \n������ ���-�� �������: ";
                }
            } while (book[i].pages < 5);
            i++;
            cout << "\n���������� ����������? (��/���)\n";
            cin >> answer;
            cin.get(); //�������� ���������� ���������� ������� � ������
        };
    }
    else {
        book[1] = { "���� �� ���", "���������", 1825, 98 };
        book[2] = { "������� ������", "������", 1825, 400 };
        book[3] = { "����� ������ �������", "���������", 1840, 423 };
        book[4] = { "������� ����", "������", 2011, 352 };
        book[5] = { "����������� ������� ������", "�����", 1892, 307 };
        book[6] = { "������ � ���������", "��������", 1966, 504 };
        i = 7;
    }

    // ����� ��������� ��������� ����� ���������� ��� ������ �������
    N = i;
    out(book, N);

    //�������� ������ 3-�� ��������� ���������
    for (i = 4; i < N; i++) {
        kniga[j].name = book[i].name;
        kniga[j].author = book[i].author;
        kniga[j].year = book[i].year;
        kniga[j].pages = book[i].pages;
        j++;
    }

    //����� �� �������� �����
    N = j;
    cout << "\n������� �������� ����� ����� ������� �� ������ �������� ����� �������.\n";
    cin.get();
    getline(cin, answer);
    while ((answer != kniga[n].name) && (n < N)) {
        n++;
    }
    if (n >= N) {
        cout << "\n��������� ���� ����� � ��������� ����������� ���� �������.\n";
    }
    else {
        //����� ��������� ������ �� �������
        for (i = N; i >= n; i--) {
            kniga[i].name = kniga[i - 1].name;
            kniga[i].author = kniga[i - 1].author;
            kniga[i].year = kniga[i - 1].year;
            kniga[i].pages = kniga[i - 1].pages;
        }
    }
    cout << "\n������� �������� ����� �����: ";
    getline(cin, kniga[n].name);
    cout << "������� ������� ������ �����: ";
    cin >> kniga[n].author;
    cout << "������� ��� ������� �����: ";
    do {
        cin >> kniga[n].year;
        if ((kniga[n].year > 2021) || (kniga[n].year < 1)) {
            cout << "����� ������������ ���! \n������� ���������� ��� ������� �����: ";
        }
    } while ((kniga[n].year > 2021) || (kniga[n].year < 1));
    cout << "������� ���-�� �������: ";
    do {
        cin >> kniga[n].pages;
        if (kniga[n].pages < 5) {
            cout << "������� ������������ ��� - �� �������! \n������� ���������� ��� - �� �������: ";
        }
    } while (kniga[n].pages < 5);

    //����� ���������� ������ ���������
    cout << "\n�������� ������ ���������: \n";
    out(kniga, N + 1);
    cout << endl;

    system("pause");
    return 0;
}