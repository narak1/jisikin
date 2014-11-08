#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
void get_names_and_scores_from_file(string name[], double score[][5])
{
 ifstream infile;
 int i, j;
 string infile_name;
 cout << "Enter input file name: \n";
 cin >> infile_name;
 infile.open(infile_name.c_str());
 if(!infile) {
  cout << "Cannot open file.\n";
  exit(1);
 }
 for (i=0; i<10; i++) {
  infile >> name[i];   
  for (j=0; j<5; j++)   
   infile >> score[i][j];
 }
}
void compute_grades(double score[][5], string grade[][5])
{
 int i,j;
 for(i=0; i<10; i++)
  for(j=0; j<5; j++)
  {
   if(score[i][j]>=95.0)
    grade[i][j] = "A+";
   else if(score[i][j]>=90.0)
    grade[i][j] = "A0";
   else if(score[i][j]>=85.0)
    grade[i][j] = "B+";
   else if(score[i][j]>=80.0)
    grade[i][j] = "B0";
   else if(score[i][j]>=75.0)
    grade[i][j] = "C+";
   else if(score[i][j]>=70.0)
    grade[i][j] = "C0";
   else if(score[i][j]>=65.0)
    grade[i][j] = "D+";
   else if(score[i][j]>=60.0)
    grade[i][j] = "D0";
   else
    grade[i][j] = "F";
  }
}
void compute_grade_points(double score[][5], double grade_point[][5])
{
 int i,j;
 for(i=0; i<10; i++)
  for(j=0; j<5; j++)
  {
   if(score[i][j]>=95.0)
    grade_point[i][j] = 4.5;
   else if(score[i][j]>=90.0)
    grade_point[i][j] = 4.0;
   else if(score[i][j]>=85.0)
    grade_point[i][j] = 3.5;
   else if(score[i][j]>=80.0)
    grade_point[i][j] = 3.0;
   else if(score[i][j]>=75.0)
    grade_point[i][j] = 2.5;
   else if(score[i][j]>=70.0)
    grade_point[i][j] = 2.0;
   else if(score[i][j]>=65.0)
    grade_point[i][j] = 1.5;
   else if(score[i][j]>=60.0)
    grade_point[i][j] = 1.0;
   else
    grade_point[i][j] = 0.0;
  }
}
double compute_total_grade_point(double grade_point[])
{
 int i;
 double total_grade_point;
 total_grade_point = 0;
 for(i=0; i<5; i++)
  total_grade_point = total_grade_point + grade_point[i] ;
 return total_grade_point;
}
double compute_grade_point_average(double total_grade_point, int n)
{
 double grade_point_average;
 grade_point_average = total_grade_point / n;
 return grade_point_average;
}
void print_results_in_file(string name[], double score[][5],
		string grade[][5], double grade_point[][5],
	   double compute_grade_point_average[],double compute_total_grade_point[])
{
 ofstream outfile;
 int i, j;
 string outfile_name;
 cout << "Enter output file name: \n";
 cin >> outfile_name;
 outfile.open(outfile_name.c_str());
 if(!outfile) {
  cout << "Cannot open file.\n";
  exit(1);
 }
 for (i=0; i<10; i++) {
  outfile << "이름: " << name[i] << endl; 
  outfile << "점수:";
  for (j=0; j<5; j++) 
   outfile << setw(7) << score[i][j];
  outfile << endl;
  outfile << "학점:"; 
  for (j=0; j<5; j++)      
   outfile << setw(7) << grade[i][j];
  outfile << "\n";
  outfile << "평점:"; 
  for (j=0; j<5; j++) 
   outfile << setw(7) << grade_point[i][j];
  outfile << "\n";
  outfile << "평점합계:"; 
  outfile << setw(7) << compute_total_grade_point[i];
  outfile << "\n";
  outfile << "평균평점:"; 
  outfile << setw(7) << compute_grade_point_average[i];
  outfile << "\n\n";
 }
}
int main()
{
 string name[10];
 double score[10][5];
 string grade[10][5];
 double grade_point[10][5];
 double total_grade_point[10];
 double grade_point_average[10];
 int i;

 get_names_and_scores_from_file(name, score);
 compute_grades(score, grade);
 compute_grade_points(score, grade_point);
 for( i=0 ; i<10 ; i++ ) {
  total_grade_point[i] = compute_total_grade_point(grade_point[i]);
  grade_point_average[i] = compute_grade_point_average(total_grade_point[i], 5);
 }
 print_results_in_file(name, score, grade, grade_point, grade_point_average, total_grade_point);
 
 return 0;
}
