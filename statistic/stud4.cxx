#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void get_names_and_scores_from_file (string name[], double score[][5]);
void compute_grades (double score[][5],string grade[][5]);
void compute_grade_points (double score[][5], double grade_point[][5]);
void print_results_in_file(string name[], double score[][5], string grade[][5], double grade_point[][5]);

const double score_level[] = { 95, 90, 85, 80, 75, 70, 65, 60, 0 };
const char* grade_name[] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };
const double grade_point[] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };

const int LEVEL = sizeof(score_level) / sizeof(double);

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
	for(int i=0; i < 10; i++) {
	    for(int j=0; j < 5; j++) {
	    	for( int k=0 ; k<LEVEL ; k++ ) {
	    		if( score[i][j] >= score_level[k] ) {
	    			grade[i][j] = grade_name[k];
	    			break;
	    		}
	    	}
	    }
	}
}

void compute_grade_points (double score[][5], double grade_point[][5])
{
	for(int i=0; i < 10; i++) {
	    for(int j=0; j < 5; j++) {
	    	for( int k=0 ; k<LEVEL ; k++ ) {
	    		if( score[i][j] >= score_level[k] ) {
	    			grade_point[i][j] = ::grade_point[k];
	    			break;
	    		}
	    	}
	    }
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

