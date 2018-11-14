#include <iostream>
using namespace std;
/*
- 정규직은 사원이다. ( 상 속 )
- 사원명, 월급을 관리할 수 있도록 클래스 디자인하세요. ( 캡 슐 화 )
- 사원을 관리할 수 있는 클래스를 디자인하세요. ( 다 형 성 )
- 간단한 인사관리 프로그램 작성
- 이번 달 지불해야 할 급여총합 ( virtual )
*/

/* 답안쓰 */
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
	//급여 반환하는 가상함수
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
	/* 다 형 성 */
	Employee *emplist[50];		// 중 요
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	//사원추가기능함수
	void AddEmployee(Employee *emp) // 중 요
	{
		emplist[empNum++] = emp;
	}
	//전체사원급여정보 출력함수
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
		{
			emplist[i]->ShowEmployee();
		}
	
	}
	//이번달지급총급여 출력함수
	void ShowMonthTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
		{
			sum += emplist[i]->GetSalary();
		}
		cout << "TOTAL SALARY : " << sum << endl;
	}
	//소멸자
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete emplist[i];
		}
		
	}
};
/* 답안 끝 */

/*
class Staff // 사원
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
		cout << "이름 : " << name << endl;
		cout << "월급 : " << Salary << endl;
	}
};

class Full_time_job : public Staff // 정규직
{
private:
	int year;
public:

};

class StaffManage
{
private:
	Staff *Stafflist[100];		// 사원 인원
	int incentive;					// 월급 인상
	int paycut;						// 월급 감축
	int count=0;					// 생성자에서 해결했어야지
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

class Student : public Person // ( 학생은 : 사람이다.)
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
	/* ㄹㅇ 경찰 
	Police policeMan(5, 3);
	policeMan.shooot();
	policeMan.PutHandcuff();

	/* 교통 경찰 
	Police trafficPolice(0, 3);
	trafficPolice.shooot();
	trafficPolice.PutHandcuff();

	/* has a 
	Police policeman(5, 3);
	policeman.shoot();
	policeman.PutHandcuff();
	*/

	/*
	상 속
	- 목적
	클래스 간 관계를 체계적으로 유지 및 관리하기 위해서 사용
	(재사용성을 높이기 위해서)
	- 관계가 논리적으로 성립
	- is A, has A
	- is A
	(ex - 학생은 사람이다.)
	(Student is a person.)
	(ex - 노트북은 컴퓨터이다.)
	(Notebook is a computer.)
	- has A
	(ex - 경찰은 총을 가진다.)
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