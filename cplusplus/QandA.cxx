
#ifndef SURVEY_H_INCLUDED // Survey.h �� �ߺ� include ���� �ʾҴ��� �˻�
#define SURVEY_H_INCLUDED // Survey.h �� ó�� include �ɶ� ���ǵ�.

#include <iostream>
#include <iomanip>
using namespace std;

class survey
{
	string question;
	int exampleCnt;
	string* example;
	int response;
public:
	survey() : exampleCnt(0), example(NULL), response(0) { ; };
	void QuestionInput();
	void ExampleCntInput();
	void ExampleInput();
	void QuestionPrint();
	void ResponsePrint();
};

#endif

//=========== Class CPP ===========

void survey::QuestionInput()
{ 
	cout << "����� ���� ������ �Է��Ͻÿ� : ";
	do {
		getline(cin, question);
	} while( question.empty() );
}

void survey::ExampleCntInput()
{ 
	cout << "������ ������ ������ �Է��Ͻÿ� : "; 
	cin >> exampleCnt;
	if( this->example != NULL ) delete [] this->example;
	this->example = new string [exampleCnt];
}

void survey::ExampleInput()
{
	for( int i=0 ; i<exampleCnt ; i++ ) {
		cout << (i+1) << "�� ������ ������ �Է��Ͻÿ� : "; 
		do {
			getline(cin, example[i]);
		} while( example[i].empty() );
	}
}

void survey::QuestionPrint()
{
	if( exampleCnt == 0 || example[0].empty() )
		return;

	cout << question << endl;
	for( int i=0 ; i<exampleCnt ; i++ ) {
		cout << setw(4) << (i+1) << ". " << example[i] << endl; 
	}
	cout << endl;
	do {
		cout << "�����߿� �ϳ��� �����Ͻÿ� : ";
		cin >> response;
	} while( (response <= 0) || (response > exampleCnt) );
}

void survey::ResponsePrint()
{
	if( exampleCnt == 0 || example[0].empty() || response == 0 )
		return;

	cout << question << endl;
	cout << setw(4) << response << ". " << example[response-1] << endl;	
}

//============= Main CPP =============

int main()
{
	survey *s;
	int num;
	
	cout << "����� ������ ����? ";
	cin >> num;
	
	// ���� ���
	// 
	s = new survey[num];
	for( int i=0 ; i<num ; i++ ) {
		s[i].QuestionInput();
		s[i].ExampleCntInput();
		s[i].ExampleInput();
	}
	
	// ���� �ޱ�
	//
	for( int i=0 ; i<num ; i++ ) {
		s[i].QuestionPrint();
	}
	
	// ��� ���
	//
	cout << endl << endl;
	cout << "���� ���" << endl; 
	for( int i=0 ; i<num ; i++ ) {
		s[i].ResponsePrint();
	}
	
	// �޸� ����
	//
	delete [] s; 
}
