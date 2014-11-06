#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void get_names_and_scores_from_file (string name[], double score[][5]);
void compute_grades (double score[][5],string grade[][5]);
void compute_grade_points (double score[][5], double grade_point[][5]);
void print_results_in_file(string name[], double score[][5], string grade[][5], double grade_point[][5]);

int main()
{
   double score[10][5];
   double grade_point[10][5];
   string name[10];
   string grade[10][5];
   get_names_and_scores_from_file(name, score);
   compute_grades(score, grade);
   compute_grade_points(score, grade_point);
   print_results_in_file(name, score, grade, grade_point);
}
void get_names_and_scores_from_file(string name[],double score[][5])
{
 ifstream infile;

 int i,j;
 string infile_name;

 cout << "enter input file name: ";
  cin >> infile_name;

 infile.open(infile_name.c_str());
 if(!infile){

  cout << "cannot open file.\n";
   exit(1);
}

 for (i=0; i<10; i++){
  infile >> name[i];

  for (j=0; j<5; j++)
   infile >> score[i][j];
 }
}
void compute_grades (double score[][5],string grade[][5])
{
for(int i=0; i < 10; i++)
{
for(int j=0; j < 5; j++)
if(score[i][j]>=95.0)
grade[i][j]="A+";
else if(score[i][j] >=90.0)
grade[i][j]="A";
else if(score[i][j] >=85.0)
grade[i][j]="B+";
else if(score[i][j] >=80.0)
grade[i][j]="B";
else if(score[i][j] >=75.0)
grade[i][j]="C+";
else if(score[i][j] >=70.0)
grade[i][j]="C";
else if(score[i][j] >=65.0)
grade[i][j]="D+";
else if(score[i][j] >=60.0)
grade[i][j]="D";
else
grade[i][j]="F";
}
}
void compute_grade_points (double score[][5], double grade_point[][5])
{
for(int i=0; i < 10; i++)
{
for(int j=0; j < 5; j++)
if(score[i][j]>=95.0)
grade_point[i][j] = 4.5;
else if(score[i][j] >=90.0)
grade_point[i][j] = 4.0;
else if(score[i][j] >=85.0)
grade_point[i][j] = 3.5;
else if(score[i][j] >=80.0)
grade_point[i][j] = 3.0;
else if(score[i][j] >=75.0)
grade_point[i][j] = 2.5;
else if(score[i][j] >=70.0)
grade_point[i][j] = 2.0;
else if(score[i][j] >=65.0)
grade_point[i][j] = 1.5;
else if(score[i][j] >=60.0)
grade_point[i][j] = 1.0;
else
grade_point[i][j] = 0;
}
}
void print_results_in_file(string name[], double score[][5], string grade[][5], double grade_point[][5])
{
   ofstream outfile;
   int i, j;
   string outfile_name;

   cout << "enter output file name: ";
   cin >> outfile_name;
   outfile.open(outfile_name.c_str());

   if(!outfile)
   {
      cout << "cannot open file: \n";
      exit(1);
   }
   for (i=0; i<10; i++)
   {
      outfile << "이름:  " << name[i] << "\t\n점수:  ";
      for (j=0; j<5; j++)
         outfile <<  score[i][j] << "\t";
      outfile << "\n학점:  ";
      for (j=0; j<5; j++)
         outfile << grade[i][j] << "\t";
      outfile << "\n평점:  ";
      for (j=0; j<5; j++)
         outfile << grade_point[i][j] << "\t";
      outfile << endl;
   }
}

