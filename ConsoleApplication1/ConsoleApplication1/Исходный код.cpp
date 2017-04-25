//#include "stdafx.h"
#include <string.h> 
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
using std::istream;
using std::ostream;
//#include "mj.h"
//class mj();



class mj //����� ���������
{
private:
	int *x;//����� ���������
	int nm;//������ ���������
	int nom;
public:
	mj() //����������� ��� ����������
	{
		nm = 1;
	x = new int[nm+2];
		for (int i = 1; i <= nm; i++)
			x[i] = i;
	}


	mj(int nom) //����������� � ����� ����������
	{
		nm = nom;
		x = new int[nm+2];
		for (int i = 1; i <= nm; i++)
		{
			x[i] = 0;
		}

	}

	//~mj() //����������
	//{
	//	delete []x;
	//}

	void vvod()//���� ���������
	{
		for (int i = 1; i <= nm; i++)
		{
			cin >> x[i]; 
		}
	}

	int razmer() //������ ���������
	{
		return nm;
	}

	void massiv()// �������� ���������
	{

		for (int i = 1; i <= nm; i++)
			cout << x[i] << "	";
		cout << endl;
	}

	void rendom()//��������� ���������� ���������
	{
		srand(time(0));
	for (int i = 1; i <= nm; i++)
	{
	x[i] = rand()%100-50;
	}
	}
	
	mj operator+(mj mass)//����������� ���������
	{
		int *y,z;
		int maxnm = (nm > mass.nm ? nm : mass.nm);      // x - ������� �����(mass1) mass.x-��������(mass2) prmass-���������(mass3)
		y = new int[nm*2];
		int j = maxnm;
		for (int i = 1; i <= j; i++)
		{
			y[i] = x[i];
		}
		for (int i = 1; i <= nm; i++)
		{
			z = 1;
			for (int k = 1; k <= nm; k++)
			{
				if (mass.x[i]==y[k]){ z = 0; break; }
			}
			if (z == 0);
			else { j++; y[j] = mass.x[i]; }
		}
		mj prmass(j);
		for (int i = 1; i <= j; i++)
		{
			prmass.x[i] = y[i];
		}
		return prmass;
	}

	mj operator-(mj mass)//�������� ��������
	{
		int *y, z;
		int maxnm = (nm > mass.nm ? nm : mass.nm);      // x - ������� �����(mass1) mass.x-��������(mass2) prmass-���������(mass3)
		y = new int[nm];
		int j = maxnm;
		for (int i = 1; i <= j; i++)
		{
			y[i] = x[i];
		}
		for (int i = 1; i <= j; i++)
		{
			
			for (int k = 1; k <= nm; k++)
			{
				if (y[i] == mass.x[k]) { for (int d = i; d <= j - 1; d++)y[d] = y[d + 1]; j = j - 1; }
				
			}
		}
		mj prmass(j);
		for (int i = 1; i <= j; i++)
		{
			prmass.x[i] = y[i];
		}
		return prmass;
	}
	
		mj operator/(mj mass)//����������� ��������
		{
			int *y;
			int maxnm = (nm > mass.nm ? nm : mass.nm);
			y = new int[maxnm];
			int j = 0;
			for (int i = 1; i <= maxnm; i++)
			{
				for (int k = 1;k<=maxnm;k++)
				{if (x[i] == mass.x[k]) { j++; y[j] = x[i]; }}   
			}
			mj prmass(j);
			for (int i = 1; i <= j; i++)
				prmass.x[i] = y[i];

			return prmass;
		}


	void dobavlen(int db)//���������� �������� � ����� ���������
	{
		x[nm+1]=db;
		nm++;
		
	}
	void del(int el)//�������� �������� �� ������
	{
		for (int i = el; i <= nm - 1; i++)
		{
			x[i] = x[i + 1];
		}
		nm = nm-1 ;
	}
};



void main()
{
	setlocale(LC_CTYPE, "rus");
	int r = 0, op, nom;
	char gen;
	cout << "������� ���������� ��������� ��������:	"; cin >> r;
	mj mass1(r);
	mj mass2(r);
	while (true)
	{
		cout << "������������ ���������? (Y/N) "; cin >> gen;
		if (gen == 'y' || gen == 'Y' || gen == 'N' || gen == 'n') break;
	}
	if (gen == 'y' || gen == 'Y')
	{ 
		mass1.rendom(); cout << "���������...\n"; system("pause"); mass2.rendom();
		cout << "������ ���������	"; mass1.massiv();
		cout << "������ ���������	"; mass2.massiv();
	}
	else
	{
		cout << "������� ������ ���������	"; mass1.vvod();
		cout << "������� ������ ���������	"; mass2.vvod();
	}
	while (true)
	{
		cout << "������� ����� ��������:\n1)���������� �������� \n2)�������� ��������\n3)����������� ��������\n4)�������� �������� \n5)����������� ��������	\n"; 
		cin >> op;
		if (op == 1 || op == 2 || op == 3 || op == 4||op==5) break;
		else cout << "�� ������ �����" << endl;
	}
	while (true)
	{
		if (op == 1 || op == 2) {
			cout << "������� ����� ��������� ��� ��������: "; cin >> nom;
			if (nom == 1 || nom == 2) break; else cout << "������! ��������� �����������.\n";
		}
		else break;
	}
	
	//mj mass3(2*r);
	int el=0;
	switch (op)
	{
	case (1) : {cout << "������� ����� "; cin >> el; cout << "� ���������\n"; if (nom == 1){ mass1.dobavlen(el); mass1.massiv(); }
			   else { mass2.dobavlen(el); mass2.massiv(); } break; }
	case (2) : {cout << "������� ����� ��������: "; cin >> el; cout << "��� ��������\n"; if (nom == 1){ mass1.del(el); mass1.massiv(); }
			   else { mass2.del(el); mass2.massiv(); } break; }
	case (3) : {mj mass3(r); mass3 = mass1 + mass2; cout << "����������� ��������\n"; mass3.massiv(); break; };
	case (4) : {mj mass3(r); mass3 = mass1 - mass2; cout << "�������� ��������\n"; mass3.massiv(); break; }
	case (5) : {mj mass3(r); mass3 = mass1 / mass2; cout << "����������� ��������\n"; mass3.massiv(); break; }
			;
		break;
	}
	//mass1.massiv();
		cout << "				\n�������� ���������� ����������\n";
	system("pause");
	return;
}



