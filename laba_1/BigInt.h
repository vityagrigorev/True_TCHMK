#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

#define mymin(x,y) (x) < (y) ? (x) : (y)

#define mymax(x,y) (x)> (y) ? (x) : (y)

class BigInt
{
private:
	char *digits;
	int size;           
	int capacity;      
	int sign;            

public:
	/** Создание большого числа из n с емкостью cap**/
	BigInt(int n, int cap);

	BigInt(int n);


	BigInt();

	BigInt(const char s[]);

	BigInt(const BigInt &n);

	const BigInt &operator=(const BigInt &n);

	~BigInt();

	void normalize();

	static int sig(int n);

	BigInt operator-();
	BigInt operator+ (BigInt n);
	BigInt operator- (BigInt n);
	BigInt operator* (int n);
	BigInt operator* (BigInt n);
	BigInt operator/ (int n);
	BigInt operator/ (BigInt n);
	void   operator/=(int n);
	void   operator/=(BigInt n);
	BigInt operator% (BigInt n);
	BigInt divide(BigInt n);        

	bool operator<(BigInt n);
	bool operator>(BigInt n);
	bool operator==(BigInt n);
	bool operator<=(BigInt n);
	bool operator>=(BigInt n);
	bool operator<(int n);
	bool operator>(int n);
	bool operator==(int n);
	bool operator<=(int n);
	bool operator>=(int n);
	int compare(BigInt n);

	operator string();

	string toString();

	bool getFrom_txt(const char* filename);
	bool saveTo_txt(const char* filename);

private:
	void grow();

	friend istream &operator>>(istream &in, BigInt &n);
	friend ostream &operator<<(ostream &out, BigInt n);
};