#include <iostream>
using namespace std;

struct PN
{
	int num[5];
	PN() { num[0]=num[1]=num[2]=num[3]=num[4]=0; };
};

struct MI //MI = Membership Information
{
	char name[10];
	int age;
	PN phone; //전화번호 입력 구조체 PN을 자료형으로 갖는 변수 phone
	int AN; //Account Number
	int password; //4자리 비밀번호
};		//Merit(Membership information) = struct MI, PM = Pointer of MI

MI* reg() // 회원 등록
{
	MI* PMV; //PMV = Pointer of MV
	//Merit MV; //MV = Membership information Variable
	PMV = new MI;
	
	cout << "회 원 등 록" << endl;
	// Information Setting
	cout << "=================" << endl; 
	cout << "이 름 : "; cin >> PMV->name;
	cout << "나 이 : "; cin >> PMV->age;
	//....
	
	return PMV; 
}

main()
{
	MI **mem_list;
	int max_mem = 100;
	int num_mem = 0;
	
	mem_list = new MI* [max_mem]();
	for( int i=0 ; i<max_mem ; i++ )
	{
		mem_list[i] = reg();
	}
}
