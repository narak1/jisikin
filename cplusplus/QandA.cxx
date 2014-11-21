
#ifndef SURVEY_H_INCLUDED // Survey.h 가 중복 include 되지 않았는지 검사
#define SURVEY_H_INCLUDED // Survey.h 가 처음 include 될때 정의됨.

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
	cout << "등록할 설문 문항을 입력하시오 : ";
	do {
		getline(cin, question);
	} while( question.empty() );
}

void survey::ExampleCntInput()
{ 
	cout << "설문의 보기의 개수를 입력하시오 : "; 
	cin >> exampleCnt;
	if( this->example != NULL ) delete [] this->example;
	this->example = new string [exampleCnt];
}

void survey::ExampleInput()
{
	for( int i=0 ; i<exampleCnt ; i++ ) {
		cout << (i+1) << "번 보기의 내용을 입력하시오 : "; 
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
		cout << "보기중에 하나를 선택하시오 : ";
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
	
	cout << "등록할 질문의 수는? ";
	cin >> num;
	
	// 질문 등록
	// 
	s = new survey[num];
	for( int i=0 ; i<num ; i++ ) {
		s[i].QuestionInput();
		s[i].ExampleCntInput();
		s[i].ExampleInput();
	}
	
	// 응답 받기
	//
	for( int i=0 ; i<num ; i++ ) {
		s[i].QuestionPrint();
	}
	
	// 결과 출력
	//
	cout << endl << endl;
	cout << "설문 결과" << endl; 
	for( int i=0 ; i<num ; i++ ) {
		s[i].ResponsePrint();
	}
	
	// 메모리 삭제
	//
	delete [] s; 
}
