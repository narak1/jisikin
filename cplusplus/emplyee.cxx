//#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{
 string Name,EmployeeNo;
public:
 Employee(void) { ; };
 Employee(string, string);
 string getName() const { return Name; } //��ȣ�ȿ����°����ٲ������Ѵ�
 string getNo() { return EmployeeNo; }
 string setName(string name) { Name = name; return Name; }
 string setNo(string no) { EmployeeNo = no; return EmployeeNo; }
 int computeSalary() {}
 
 ~Employee(void);
};

/*
������,������,������, computeSalary() ������
*/
class FulltimeEmployee :
 public Employee
{
 int salary;
public:
 FulltimeEmployee(void);
 int setSalary(int s){
  salary = s;
 }
 int getSalary(){
  return salary;
 }
 int computeSalary();
 ~FulltimeEmployee(void);
};
int FulltimeEmployee::computeSalary(){
 return 0;
}

class parttimeEmployee :
 public Employee
{
 int timeSalary; //�ð����ӱ�
 int timeWork; //���ѽð�
public:
 parttimeEmployee(void) { ; };
 int getSalary(){
  return timeSalary;
 }
 int getWork(){
  return timeWork;
 }
 int setSalary(int s){
  timeSalary = s;
  return timeSalary;
 }
 int setWork(int w){
  timeWork = w;
  return timeWork;
 }
 int computeSalary();
 ~parttimeEmployee(void);
};
int parttimeEmployee::computeSalary(){
 int sal = timeSalary * timeWork;
 return sal;
}


//#include "Employee.h"
//#include "parttimeEmployee.h"
//#include "FulltimeEmployee.h"
int main(void)
{
 //Employee *em = new Employee();
 parttimeEmployee *part = new parttimeEmployee();
 return 0;
}

