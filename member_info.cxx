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
	PN phone; //��ȭ��ȣ �Է� ����ü PN�� �ڷ������� ���� ���� phone
	int AN; //Account Number
	int password; //4�ڸ� ��й�ȣ
};		//Merit(Membership information) = struct MI, PM = Pointer of MI

MI* reg() // ȸ�� ���
{
	MI* PMV; //PMV = Pointer of MV
	//Merit MV; //MV = Membership information Variable
	PMV = new MI;
	
	cout << "ȸ �� �� ��" << endl;
	// Information Setting
	cout << "=================" << endl; 
	cout << "�� �� : "; cin >> PMV->name;
	cout << "�� �� : "; cin >> PMV->age;
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
