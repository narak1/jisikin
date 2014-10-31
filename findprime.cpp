/* m ���� n ������ �Ҽ��� ���ؼ� ����ϰ� ���� ���ϴ� ���α׷� */

#include <iostream>
#include <string>

const int EXIT = -999;
const int MAX_INT = 10000;
const int TRUE = 1;
const int FALSE = 0;

using namespace std;

//�Ҽ� ���ϱ� Ŭ����
class findPrime
{
private:
	int *prime;			// ������ ���� �迭
	int prime_num;		// ������ ��
public:
	void setPrime(int m, int n);	// �׻� m <= n �� �ǰ� �ϴ���.. ���ο��� ó���ϴ���..
	bool isPrime(int n);
	int* getPrime(int &n);			// �μ��� ������ ���� �����ϰ�, ���ϰ��� ������ �迭�� ����
	findPrime() { prime=NULL; prime_num=0; }
	~findPrime() { if( prime != NULL ) delete [] prime; }
};

//����� Ŭ����
class ioHandler
{
public:
	int getInteger(string message, int lower, int upper); //������ Ű����κ��� �޾Ƶ���
	void putPrime(int prime[], int n); //�Ҽ��� ���
	void putString(string message) { cout << message << endl; }
	int putSumResult(string message, int n); //�Ҽ����� �� ���
};

bool findPrime::isPrime(int n)
{
	if( n < 2 )				// 1�� ������ �ƴ�. �ڿ����� ������� ��.
		return false;
	if( n == 2 )			// 2�� ����
		return true;
	if( n % 2 == 0 )		// 2 �ƴ� ¦���� ������ �ƴ�
		return false;

	for( int i=3 ; i*i<=n ; i+=2 ) {	// Ȧ���� �˻�
		if( n % i == 0 )
			return false;
	}
	return true;
}

void findPrime::setPrime(int m, int n)
{
	// m <= n �� �ǰ� �����.
	if (m > n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}

	int idx = 0;	// prime_num
	for( int i=m ; i<=n ; i++ ) {
		if( isPrime(i) ) {
			if( idx % 1024 == 0 ) {		// memory re-alloc
				int *tmp = new int [idx+1024];
				for( int k=0 ; k<idx ; k++ ) {
					tmp[k] = this->prime[k];
				}
				delete [] this->prime;
				this->prime = tmp;
			}
			this->prime[idx] = i;
			++idx;
		}
	}
	this->prime_num = idx;
}

int* findPrime::getPrime(int &n)
{
	n = this->prime_num;
	return this->prime;
}

//�Ҽ����� ���ϴ� �Լ�
int sumofPrimes(int prime[], int num)
{
	int sum = 0;

	for (int i=0 ; i<num ; i++)
	{ sum += prime[i]; }

	return sum;
}

int ioHandler::getInteger(string message, int lower, int upper)
{
	int value;
	while(1)
	{
		cout << message;
		cin >> value;
		cout << endl;

		if (value == EXIT)
			break;
		else if (value < lower || value > upper) {
			putString("������ ������ϴ�. 2 �̻� 10000 ���Ϸ� �Է��ϼ���.");
		}
		else
			break;
	}
	return value;
}

void ioHandler::putPrime (int prime[], int n)
{
	for( int i=0 ; i<n ; i++ ) {
		cout << prime[i] << "  ";
		if( i % 10 == 9 )
			cout << endl;
	}
	cout << endl;
}

int ioHandler::putSumResult(string message, int n)
{
	cout << message << n << endl;
	return 0;
}

int main() 
{
	ioHandler ioh;
	findPrime fp;

	ioh.putString("* ���� ���� �Ҽ��� �Ҽ��� ���� ���ϱ� ���α׷� *");

	while(1) 
	{
		int m = ioh.getInteger("2 �̻��� ���� ������ �Է��ϼ��� (EXIT = -999) -> ", 2, MAX_INT);
		if( m == EXIT )
			break;
			
		int n = ioh.getInteger("2 �̻��� ���� ������ �ϳ� �� �Է��ϼ��� (EXIT = -999) -> ", 2, MAX_INT);
		if (n == EXIT)
			break;
		else if (m == n)
			ioh.putString("���� ���� �Է����� ������!") ;
		else 
		{
			int num = 0;
			int *prime = NULL;

			fp.setPrime(m, n);
			prime = fp.getPrime(num);
			ioh.putPrime(prime, num);
			ioh.putSumResult("�Ҽ����� �� : ", sumofPrimes(prime, num));
		}
	}
}

