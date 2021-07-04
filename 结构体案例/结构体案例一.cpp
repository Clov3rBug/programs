#include<iostream>
using namespace std;
#include<string>
#include<ctime>



struct Student
{
    string sName;
    int score;
};

struct Teacher
{
    string tName;
    Student sArray [5];
};

void allocateSpace (Teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++ )
    {
        tArray[i].tName = "teacher_";
        tArray[i].tName += nameSeed[i];
        int random = rand() % 61 + 40;
        for (int j = 0; j < 5; j++) 
        {
            tArray[i].sArray[j].sName = "student_";
            tArray[i].sArray[j].sName += nameSeed[j];
            tArray[i].sArray[j].score = random;
        }
    }
}

void printInfo(Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++ )
    {
        cout << "老师的名字： " << tArray[i].tName << endl;

        for (int j = 0; j < 5; j++ )
        {
            cout << "\t学生的名字： " << tArray[i].sArray[j].sName << "  学生的成绩： " << tArray[i].sArray[j].score << endl;
        }

        cout << endl;
    }
}

int main() 
{
    // 随机数种子
    srand((unsigned int )time(NULL));
    Teacher tArray[3];

    int len = sizeof (tArray) / sizeof (tArray[0]);
    allocateSpace(tArray, len);

    printInfo(tArray, len);
    return 0; 
}