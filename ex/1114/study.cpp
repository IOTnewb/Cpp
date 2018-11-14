#include <iostream>
using namespace std;
/*
- �������� ����̴�. ( �� �� )
- �����, ������ ������ �� �ֵ��� Ŭ���� �������ϼ���. ( ĸ �� ȭ )
- ����� ������ �� �ִ� Ŭ������ �������ϼ���. ( �� �� �� )
- ������ �λ���� ���α׷� �ۼ�
- �̹� �� �����ؾ� �� �޿����� ( virtual )
*/

/* ��Ⱦ� */
class Employee
{
private:
	char name[100];
public:
	Employee(const char *name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
	//�޿� ��ȯ�ϴ� �����Լ�
	virtual int GetSalary() const
	{
		return 0;
	}

	virtual void ShowEmployee() const
	{
		
	}
};

class PernamentWorker : public Employee
{
private:
	int salary;
public:
	PernamentWorker(const char *name, int salary)
		: Employee(name), salary(salary)
	{}
	int GetSalary() const
	{
		return salary;
	}
	
	void ShowEmployee() const
	{
		ShowYourName();
		cout << "salary : " << GetSalary() << endl;
	}
};

class EmployeeHandler
{
private:
	/* �� �� �� */
	Employee *emplist[50];		// �� ��
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	//����߰�����Լ�
	void AddEmployee(Employee *emp) // �� ��
	{
		emplist[empNum++] = emp;
	}
	//��ü����޿����� ����Լ�
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			emplist[i]->ShowEmployee();
		}
	
	}
	//�̹��������ѱ޿� ����Լ�
	void ShowMonthTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetSalary();
		}
		cout << "TOTAL SALARY : " << sum << endl;
	}
	//�Ҹ���
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete emplist[i];
		}
		
	}
};
/* ��� �� */

/*
class Staff // ���
{
private:
	char name[20];
	int Salary;
public:
	Staff(const char* staff_name, int SalaryNum)
	{
		strcpy(name, staff_name);
		Salary = SalaryNum;
	}

	int getSalary()
	{
		return Salary;
	}

	void Incentive(int money)
	{
		Salary += money;
	}
	
	void Paycut(int money)
	{
		Salary -= money;
	}

	void MyCarrier()
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << Salary << endl;
	}
};

class Full_time_job : public Staff // ������
{
private:
	int year;
public:

};

class StaffManage
{
private:
	Staff *Stafflist[100];		// ��� �ο�
	int incentive;					// ���� �λ�
	int paycut;						// ���� ����
	int count=0;					// �����ڿ��� �ذ��߾����
public:
	StaffManage(int up, int down)
		: incentive(up),
		  paycut(down)
	{}
	void Register_Staff(const char* name, int money)
	{
		Stafflist[count] = new Staff(name, money);
		count++;
	}
	void IncreaseSalary(int No)
	{
		Stafflist[No]->Incentive(incentive);
	}
	
	void DecreaseSalary(int No)
	{
		Stafflist[No]->Paycut(paycut);
	}

	void MonthTotalSalary()
	{
		int All = 0;

		for (int i = 0; i < count; i++)
		{
			All += Stafflist[i]->getSalary();
		}
		cout << "Month Total Salary : " << All << endl;
	}
};
*/


class Gun
{
private:
	int bullet;
public:
	Gun(int bulletNum)
		: bullet(bulletNum)
	{}
	void shoot()
	{
		cout << "BAAAAAAAAAAM" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun *pistol;
public:
	Police(int bulletNum, int handcuffsNum)
		: handcuffs(handcuffsNum)
	{
		if (bulletNum > 0)
			pistol = new Gun(bulletNum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "Snap.." << endl;
		handcuffs--;
	}
	void shooot()
	{
		if (pistol == NULL)
			cout << "Tik" << endl;
		else
			pistol->shoot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

/*
class Gun
{
private:
	int bullet;
public:
	Gun(int bulletNum)
		: bullet(bulletNum)
	{}
	void shoot()
	{
		cout << "BAAAAAAAAAAM" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bulletNum, int handcuffsNum)
		: Gun(bulletNum), handcuffs(handcuffsNum)
	{}
	void PutHandcuff()
	{
		cout << "Snap.." << endl;
		handcuffs--;
	}
};
*/

/*
class Person
{
protected:
int age;
char name[50];
public:
Person(int myAge, const char *myName)
: age(myAge)
{
//		this->age = myAge;
strcpy(name, myName);
}

void WhatYourName() const
{
cout << "My Name is " << name << endl;
}
void HowOldAreYou() const
{
cout << "I'm " << age << " Years old" << endl;
}
};

class Student : public Person // ( �л��� : ����̴�.)
{
private:
char major[50];
public:
Student(int myAge, const char *myName, const char *myMajor)
: Person(myAge, myName)
{
strcpy(major, myMajor);
}

void WhoAreYou() const
{
WhatYourName();
HowOldAreYou();
cout << "My Major is " << major << endl;
}
};
*/


int main(void)
{	
	EmployeeHandler handler;
	
	handler.AddEmployee(
	new PernamentWorker(
	"ghdrlfehd",200));
	handler.AddEmployee(
	new PernamentWorker(
	"rlarlarla",300));
	handler.AddEmployee(
	new PernamentWorker(
	"qkrqkrqkr",500));
	
	handler.ShowAllSalaryInfo();

	handler.ShowMonthTotalSalary();

	/*
	StaffManage HRmanager(20, 20);
	HRmanager.Register_Staff("dnjswn", 200);
	HRmanager.Register_Staff("qhdwn", 200);

	HRmanager.DecreaseSalary(20);
	HRmanager.DecreaseSalary(20);


	HRmanager.MonthTotalSalary();

	*/
	/* ���� ���� 
	Police policeMan(5, 3);
	policeMan.shooot();
	policeMan.PutHandcuff();

	/* ���� ���� 
	Police trafficPolice(0, 3);
	trafficPolice.shooot();
	trafficPolice.PutHandcuff();

	/* has a 
	Police policeman(5, 3);
	policeman.shoot();
	policeman.PutHandcuff();
	*/

	/*
	�� ��
	- ����
	Ŭ���� �� ���踦 ü�������� ���� �� �����ϱ� ���ؼ� ���
	(���뼺�� ���̱� ���ؼ�)
	- ���谡 �������� ����
	- is A, has A
	- is A
	(ex - �л��� ����̴�.)
	(Student is a person.)
	(ex - ��Ʈ���� ��ǻ���̴�.)
	(Notebook is a computer.)
	- has A
	(ex - ������ ���� ������.)
	(Police has a gun.)
	/*is A
	Student stu1(22, "KIM", "Computer Eng.");
	stu1.WhoAreYou();

	Student stu2(20, "PARK", "Electronic Eng.");
	stu2.WhoAreYou();
	stu2.HowOldAreYou();
	stu2.WhatYourName();
	*/
	return 0;
}