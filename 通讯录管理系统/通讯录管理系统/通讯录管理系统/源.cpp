#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;

};

void addPerson(AddressBooks * ads)
{
	//判断是否超过人数
	if (ads->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		ads->personArray[ads->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入联系人性别：" << endl;
		cout << "[1] -- 男\t[0] -- 女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				ads->personArray[ads->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请重新输入！" << endl;
			}
		}

		//年龄
		int age = 0;
		cout << "请输入联系人年龄：" << endl;
		while (true)
		{
			cin >> age;
			if (age <= 150 && age >= 0)
			{
				ads->personArray[ads->m_Size].m_Age = age;
				break;
			}
			else
				cout << "请重新输入！" << endl;
		}
		//电话
		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		ads->personArray[ads->m_Size].m_Phone = phone;

		//地址
		string addr;
		cout << "请输入联系人地址：" << endl;
		cin >> addr;
		ads->personArray[ads->m_Size].m_Addr = addr;

		ads->m_Size++;

		cout << "添加成功！" << endl;

	}
	cout << "是否继续添加？" << endl;
	cout << "[y] -- 继续\t[n] -- 停止" << endl;
	char select;
	cin >> select;
	if (select == 'y')
	{
		system("cls");
		showMenu();
		addPerson(ads);
	}
	else
	{
		system("pause");
		system("cls");
	}

}

void showPerson(AddressBooks * ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前通讯录中没有人员！" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << "姓名：" << ads->personArray[i].m_Name << "\t";
			cout << "性别：" << (ads->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ads->personArray[i].m_Age << "岁" << "\t";
			cout << "电话：" << ads->personArray[i].m_Phone << "\t";
			cout << "地址：" << ads->personArray[i].m_Addr << "\t";
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(AddressBooks * ads, string name)
{
	for (int i = 0; i < ads->m_Size; i++)
	{
		if (ads->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBooks * ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前通讯录中没有人员！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "当前通讯录人员：" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl; 

		cout << "请输入删除联系人姓名：" << endl;
		string name;
		cin >> name;

		int ret = isExist(ads, name);

		if (ret == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			//要删除李四，将李四后的数据前移
			for (int i = ret; i < ads->m_Size - 1; i++)
			{
				ads->personArray[i] = ads->personArray[i + 1];
			}
			//并让m_Size -1
			ads->m_Size--;
			cout << "删除成功！" << endl;
			cout << "\n通讯录还剩下这些联系人：\n\n";
			if (ads->m_Size == 0)
			{
				cout << "当前通讯录中没有人员！" << endl;
			}
			else
			{
				for (int i = 0; i < ads->m_Size; i++)
				{
					cout << ads->personArray[i].m_Name << "\t";
				}
				cout << "\t" << endl;
			}
		}
		cout << "是否继续删除？" << endl;
		cout << "[y] -- 继续\t[n] -- 停止" << endl;
		char select;
		cin >> select;
		if (select == 'y')
		{
			system("cls");
			showMenu();
			deletePerson(ads);
		}
		else
		{
			system("pause");
			system("cls");
		}
	}
}

void findPerson(AddressBooks* ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前通讯录中没有人员！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "当前通讯录人员：" << endl;

		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;

		cout << "请输入您要查找的联系人：" << endl;
		string name;
		cin >> name;
		int ret = isExist(ads, name);
		if (ret == -1)
		{
			cout << "您要查找的联系人不存在哦！" << endl;
		}
		else
		{
			cout << "姓名：" << ads->personArray[ret].m_Name << "\t";
			cout << "性别：" << (ads->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ads->personArray[ret].m_Age << "岁" << "\t";
			cout << "电话：" << ads->personArray[ret].m_Phone << "\t";
			cout << "地址：" << ads->personArray[ret].m_Addr << "\t";
			cout << endl;
		}
		cout << "是否继续查找？" << endl;
		cout << "[y] -- 继续\t[n] -- 停止" << endl;
		char select;
		cin >> select;
		if (select == 'y')
		{
			system("cls");
			showMenu();
			findPerson(ads);
		}
		else
		{
			system("pause");
			system("cls");
		}
	}
}

void modifyPerson(AddressBooks* ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前通讯录中没有人员！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "当前通讯录人员：" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;
		cout << "请输入您要修改的联系人：" << endl;
		string name;
		cin >> name;
		int ret = isExist(ads, name);
		if (ret == -1)
		{
			cout << "您要查找的联系人不存在哦！" << endl;
		}
		else
		{
			cout << "已找到！" << endl;
			cout << "姓名：" << ads->personArray[ret].m_Name << "\t";
			cout << "性别：" << (ads->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << ads->personArray[ret].m_Age << "岁" << "\t";
			cout << "电话：" << ads->personArray[ret].m_Phone << "\t";
			cout << "地址：" << ads->personArray[ret].m_Addr << "\t";
			cout << endl;

			cout << "请输入联系人的新信息：" << endl;

			cout << "新的姓名：" << endl;

			string name;
			cin >> name;
			ads->personArray[ret].m_Name = name;

			cout << "新的性别：" << endl;

			cout << "[1] -- 男\t[0] -- 女" << endl;

			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 0)
				{
					ads->personArray[ret].m_Sex = sex;
					break;
				}
				else
				{
					cout << "请重新输入！" << endl;
				}
			}

			cout << "新的年龄：" << endl;

			int age = 0;
			while (true)
			{
				cin >> age;
				if (age <= 150 && age >= 0)
				{
					ads->personArray[ret].m_Age = age;
					break;
				}
				else
					cout << "请重新输入！" << endl;
			}

			cout << "新的电话：" << endl;

			string phone;
			cin >> phone;
			ads->personArray[ret].m_Phone = phone;

			cout << "新的地址：" << endl;

			string addr;
			cin >> addr;
			ads->personArray[ret].m_Addr = addr;

			cout << endl;
			cout << "修改成功！" << endl;
		}
		cout << "是否继续修改？" << endl;
		cout << "[y] -- 继续\t[n] -- 停止" << endl;

		char select;
		cin >> select;

		if (select == 'y')
		{
			system("cls");
			showMenu();
			modifyPerson(ads);
		}
		else
		{
			system("pause");
			system("cls");
		}
	}
}

void clearPerson(AddressBooks* ads)
{
	if (ads->m_Size == 0)
	{
		cout << "当前通讯录中没有人员！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "当前通讯录人员：" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;

		cout << "你确定要清空这些联系人吗？" << endl;
		cout << "[y] -- 确定\t[n] -- 我再想想" << endl;

		char select;
		cin >> select;

		if (select == 'y')
		{
			ads->m_Size = 0;
			cout << "通讯录成功清空！" << endl;
		}
		system("pause");
		system("cls");
	}
}

int main()
{
	AddressBooks ads;
	ads.m_Size = 0;

	int select = 0;

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&ads);
			break;
		case 2:
			showPerson(&ads);
			break;
		case 3:
			deletePerson(&ads);
			break;
		case 4:
			findPerson(&ads);
			break;
		case 5:
			modifyPerson(&ads);
			break;
		case 6:
			clearPerson(&ads);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0; 
		default:
			cout << "没有这样的操作哦！" << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}