#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long n;

bool isPrime(long num){
	if(num==2 || num==3)
		return 1;

	if(num%6!=1 && num%6!=5)
		return 0;
		
	long tmp = sqrt(num);
	for(int i=5;i<=tmp;i+=6)
		if(num%i==0 || num%(i+2)==0)
			return 0;
	return 1;
}

int main(){
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);

	cin >> n;

	if(isPrime(n)){
		cout << n << endl;
	}else{
		long t = sqrt(n);
		for(int i=2;i<=t;i++){
			if(isPrime(i) && n%i==0){
				cout << n/i << endl;
				break;
			}
		}
	}

	return 0;
}
