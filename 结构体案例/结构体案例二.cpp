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
        cout << "ÐÕÃû£º " << heroArray[i].name << " ÄêÁä£º " << heroArray[i].age << " ÐÔ±ð£º " << heroArray[i].sex << endl;
    };
}


int main () 
{
    Hero heroArray[5] = 
    {
        {"Áõ±¸", 23, "ÄÐ"},
        {"¹ØÓð", 22, "ÄÐ"},
        {"ÕÅ·É", 20, "ÄÐ"},
        {"ÕÔÔÆ", 21, "ÄÐ"},
        {"õõ²õ", 19, "Å®"},

    };
    int len = sizeof(heroArray) / sizeof(heroArray[0]);

    cout << "ÅÅÐòÇ°£º " << endl;
    printHero(heroArray, len);

    // ÅÅÐò
    bubbleSort(heroArray, len);

    cout << "ÅÅÐòºó£º " << endl;
    printHero(heroArray, len);

    return 0;
}