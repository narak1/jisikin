#include <iostream>
#include <iomanip>
using namespace std;

const int student_number = 6 , HW_number = 5;

void getData(int grade[][HW_number], const int student_number, const int HW_number);

void calculate_st_avg(const int grade[][HW_number], double student_avg[]);

void calculate_HW_avg(const int grade[][HW_number], double HW_avg[]);

void display(const int grade[][HW_number], const double student_avg[], const double HW_avg[]);



int main()
{
  int grade[student_number][HW_number];
  double student_avg[student_number];
  double HW_avg[HW_number];

  //filling the array grade here
  getData(grade, student_number,HW_number);

  calculate_st_avg(grade, student_avg);
  calculate_HW_avg(grade, HW_avg);
  display(grade, student_avg, HW_avg);

  return 0;
}

void getData(int grade[][HW_number], const int student_number, const int HW_number)
{

  int index1, index2;
  for(index1 = 0; index1 < student_number; index1++)
  {
    for(int index2 = 0; index2 < HW_number; index2++)
    {
      cin >> grade[index1][index2];
    }
  }
}

void calculate_st_avg(const int grade[][HW_number], double student_avg[])
{
  for (int st_num = 1; st_num <= student_number; st_num++)
  {
    double sum = 0;
    for (int HW_num = 1; HW_num <= HW_number; HW_num++)
    {
      sum = sum + grade[st_num - 1][HW_num - 1];
    }

    student_avg[st_num - 1] = sum / HW_number;
  }

}
void calculate_HW_avg(const int grade[][HW_number], double HW_avg[])
{
  for (int HW_num = 1; HW_num <= HW_number; HW_num++)
  {
    double sum = 0;
    for ( int st_num= 1; st_num <= student_number; st_num++)
    {
      sum = sum + grade[st_num - 1][HW_num - 1];
    }

    HW_avg[HW_num - 1] = sum / student_number;

  }

}
void display (const int grade[][HW_number], const double student_avg[], const double HW_avg[])
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  cout << setw(10) << "Student" << setw(5) << "Avg" << setw(15) << "Homework" << endl;

  for (int st_num = 1; st_num <= student_number; st_num++)
  {
    cout << setw(10) << st_num << setw(5) << student_avg[st_num - 1] << " ";
    for (int HW_num = 1; HW_num <= HW_number; HW_num++)
      {
        cout << setw(5) << grade[st_num - 1][HW_num - 1];
      }
    cout << endl;
  }
  cout << "Homework averages = ";
  for (int HW_num = 1; HW_num <= HW_number; HW_num++)
  {
    cout << setw(5) << HW_avg[HW_num - 1];
  }
  cout << endl;

}


