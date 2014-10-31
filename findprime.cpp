/* m 부터 n 사이의 소수를 구해서 출력하고 합을 구하는 프로그램 */

#include <iostream>
#include <string>

const int EXIT = -999;
const int MAX_INT = 10000;
const int TRUE = 1;
const int FALSE = 0;

using namespace std;

//소수 구하기 클래스
class findPrime
{
private:
	int *prime;			// 씨수를 담을 배열
	int prime_num;		// 씨수의 수
public:
	void setPrime(int m, int n);	// 항상 m <= n 이 되게 하던지.. 내부에서 처리하던지..
	bool isPrime(int n);
	int* getPrime(int &n);			// 인수는 씨수의 수를 리턴하고, 리턴값을 씨수의 배열을 리턴
	findPrime() { prime=NULL; prime_num=0; }
	~findPrime() { if( prime != NULL ) delete [] prime; }
};

//입출력 클래스
class ioHandler
{
public:
	int getInteger(string message, int lower, int upper); //정수를 키보드로부터 받아들임
	void putPrime(int prime[], int n); //소수를 출력
	void putString(string message) { cout << message << endl; }
	int putSumResult(string message, int n); //소수들의 합 출력
};

bool findPrime::isPrime(int n)
{
	if( n < 2 )				// 1은 씨수가 아님. 자연수만 대상으로 함.
		return false;
	if( n == 2 )			// 2는 씨수
		return true;
	if( n % 2 == 0 )		// 2 아닌 짝수는 씨수가 아님
		return false;

	for( int i=3 ; i*i<=n ; i+=2 ) {	// 홀수만 검사
		if( n % i == 0 )
			return false;
	}
	return true;
}

void findPrime::setPrime(int m, int n)
{
	// m <= n 이 되게 만든다.
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

//소수들을 합하는 함수
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
			putString("범위를 벗어났습니다. 2 이상 10000 이하로 입력하세요.");
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

	ioh.putString("* 범위 내의 소수와 소수의 총합 구하기 프로그램 *");

	while(1) 
	{
		int m = ioh.getInteger("2 이상의 양의 정수를 입력하세요 (EXIT = -999) -> ", 2, MAX_INT);
		if( m == EXIT )
			break;
			
		int n = ioh.getInteger("2 이상의 양의 정수를 하나 더 입력하세요 (EXIT = -999) -> ", 2, MAX_INT);
		if (n == EXIT)
			break;
		else if (m == n)
			ioh.putString("같은 수를 입력하지 마세요!") ;
		else 
		{
			int num = 0;
			int *prime = NULL;

			fp.setPrime(m, n);
			prime = fp.getPrime(num);
			ioh.putPrime(prime, num);
			ioh.putSumResult("소수들의 합 : ", sumofPrimes(prime, num));
		}
	}
}

