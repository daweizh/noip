#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long n,m=10;

int main(){
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	
	cin >> n;
	
	if(n==0)
		cout << 0;
	
	if(n<0)
		cout << "-" ;

	int flag = 1;
	n = abs(n);
	while(n!=0){
		int t = n % 10;
		n = n / 10;
		if(flag && t==0){
			continue;
		}else{
			flag = 0;
		}
		cout << t;
	}
	cout << endl;

	return 0;
}
