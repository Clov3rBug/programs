#include<iostream>
using namespace std;
#include<string>

struct Hero
{
    string name;
    int age;
    string sex;

};

void bubbleSort(Hero heroArray[], int len)
{
    for (int i = 0; i < len - 1; i++ )
    {
        for (int j = 0; j < len - i - 1; j ++ )
        {
            if (heroArray[j].age > heroArray[j + 1].age) 
            {
                Hero temp = heroArray[j];
                heroArray[j] = heroArray[j + 1];
                heroArray[j + 1] = temp;
            }
        }
    }
}

void printHero(Hero heroArray[], int len)
{
    for (int i = 0; i < len; i++ ) 
    {
        cout << "������ " << heroArray[i].name << " ���䣺 " << heroArray[i].age << " �Ա� " << heroArray[i].sex << endl;
    };
}


int main () 
{
    Hero heroArray[5] = 
    {
        {"����", 23, "��"},
        {"����", 22, "��"},
        {"�ŷ�", 20, "��"},
        {"����", 21, "��"},
        {"����", 19, "Ů"},

    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);

    cout << "����ǰ�� " << endl;
    printHero(heroArray, len);

    // ����
    bubbleSort(heroArray, len);

    cout << "����� " << endl;
    printHero(heroArray, len);

    return 0;
}