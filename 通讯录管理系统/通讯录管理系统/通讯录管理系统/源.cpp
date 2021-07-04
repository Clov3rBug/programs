#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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
	//�ж��Ƿ񳬹�����
	if (ads->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "��������ϵ��������" << endl;
		cin >> name;
		ads->personArray[ads->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "��������ϵ���Ա�" << endl;
		cout << "[1] -- ��\t[0] -- Ů" << endl;
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
				cout << "���������룡" << endl;
			}
		}

		//����
		int age = 0;
		cout << "��������ϵ�����䣺" << endl;
		while (true)
		{
			cin >> age;
			if (age <= 150 && age >= 0)
			{
				ads->personArray[ads->m_Size].m_Age = age;
				break;
			}
			else
				cout << "���������룡" << endl;
		}
		//�绰
		string phone;
		cout << "��������ϵ�˵绰��" << endl;
		cin >> phone;
		ads->personArray[ads->m_Size].m_Phone = phone;

		//��ַ
		string addr;
		cout << "��������ϵ�˵�ַ��" << endl;
		cin >> addr;
		ads->personArray[ads->m_Size].m_Addr = addr;

		ads->m_Size++;

		cout << "��ӳɹ���" << endl;

	}
	cout << "�Ƿ������ӣ�" << endl;
	cout << "[y] -- ����\t[n] -- ֹͣ" << endl;
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
		cout << "��ǰͨѶ¼��û����Ա��" << endl;
	}
	else
	{
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << "������" << ads->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (ads->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ads->personArray[i].m_Age << "��" << "\t";
			cout << "�绰��" << ads->personArray[i].m_Phone << "\t";
			cout << "��ַ��" << ads->personArray[i].m_Addr << "\t";
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
		cout << "��ǰͨѶ¼��û����Ա��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ǰͨѶ¼��Ա��" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl; 

		cout << "������ɾ����ϵ��������" << endl;
		string name;
		cin >> name;

		int ret = isExist(ads, name);

		if (ret == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			//Ҫɾ�����ģ������ĺ������ǰ��
			for (int i = ret; i < ads->m_Size - 1; i++)
			{
				ads->personArray[i] = ads->personArray[i + 1];
			}
			//����m_Size -1
			ads->m_Size--;
			cout << "ɾ���ɹ���" << endl;
			cout << "\nͨѶ¼��ʣ����Щ��ϵ�ˣ�\n\n";
			if (ads->m_Size == 0)
			{
				cout << "��ǰͨѶ¼��û����Ա��" << endl;
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
		cout << "�Ƿ����ɾ����" << endl;
		cout << "[y] -- ����\t[n] -- ֹͣ" << endl;
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
		cout << "��ǰͨѶ¼��û����Ա��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ǰͨѶ¼��Ա��" << endl;

		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;

		cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
		string name;
		cin >> name;
		int ret = isExist(ads, name);
		if (ret == -1)
		{
			cout << "��Ҫ���ҵ���ϵ�˲�����Ŷ��" << endl;
		}
		else
		{
			cout << "������" << ads->personArray[ret].m_Name << "\t";
			cout << "�Ա�" << (ads->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ads->personArray[ret].m_Age << "��" << "\t";
			cout << "�绰��" << ads->personArray[ret].m_Phone << "\t";
			cout << "��ַ��" << ads->personArray[ret].m_Addr << "\t";
			cout << endl;
		}
		cout << "�Ƿ�������ң�" << endl;
		cout << "[y] -- ����\t[n] -- ֹͣ" << endl;
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
		cout << "��ǰͨѶ¼��û����Ա��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ǰͨѶ¼��Ա��" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;
		cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
		string name;
		cin >> name;
		int ret = isExist(ads, name);
		if (ret == -1)
		{
			cout << "��Ҫ���ҵ���ϵ�˲�����Ŷ��" << endl;
		}
		else
		{
			cout << "���ҵ���" << endl;
			cout << "������" << ads->personArray[ret].m_Name << "\t";
			cout << "�Ա�" << (ads->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << ads->personArray[ret].m_Age << "��" << "\t";
			cout << "�绰��" << ads->personArray[ret].m_Phone << "\t";
			cout << "��ַ��" << ads->personArray[ret].m_Addr << "\t";
			cout << endl;

			cout << "��������ϵ�˵�����Ϣ��" << endl;

			cout << "�µ�������" << endl;

			string name;
			cin >> name;
			ads->personArray[ret].m_Name = name;

			cout << "�µ��Ա�" << endl;

			cout << "[1] -- ��\t[0] -- Ů" << endl;

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
					cout << "���������룡" << endl;
				}
			}

			cout << "�µ����䣺" << endl;

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
					cout << "���������룡" << endl;
			}

			cout << "�µĵ绰��" << endl;

			string phone;
			cin >> phone;
			ads->personArray[ret].m_Phone = phone;

			cout << "�µĵ�ַ��" << endl;

			string addr;
			cin >> addr;
			ads->personArray[ret].m_Addr = addr;

			cout << endl;
			cout << "�޸ĳɹ���" << endl;
		}
		cout << "�Ƿ�����޸ģ�" << endl;
		cout << "[y] -- ����\t[n] -- ֹͣ" << endl;

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
		cout << "��ǰͨѶ¼��û����Ա��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ǰͨѶ¼��Ա��" << endl;
		for (int i = 0; i < ads->m_Size; i++)
		{
			cout << ads->personArray[i].m_Name << "\t";
		}
		cout << endl;

		cout << "��ȷ��Ҫ�����Щ��ϵ����" << endl;
		cout << "[y] -- ȷ��\t[n] -- ��������" << endl;

		char select;
		cin >> select;

		if (select == 'y')
		{
			ads->m_Size = 0;
			cout << "ͨѶ¼�ɹ���գ�" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0; 
		default:
			cout << "û�������Ĳ���Ŷ��" << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}