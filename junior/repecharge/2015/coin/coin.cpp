#include <iostream>
#include <cstdio>
using namespace std;

int d,i,m=0;

int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	
	cin >> d;
	for(i=1;i<d;i++){
		m = m + i*i;
		d = d - i;
	}
	m = m + i * d;
	
	cout << m << endl;
	
	return 0;
}
