#include <iostream>
#include <cstdio>
using namespace std;

long l,r,c;

int main(){
	freopen("two.in","r",stdin);
	freopen("two.out","w",stdout);
	
	cin >> l >> r;
	
	for(int i=l;i<=r;i++){
		long t = i;
		while(t>0){
			long m = t % 10;
			if(m==2){
				c = c + 1;
			}
			t = t / 10;
		}
	}

	cout << c << endl;
	
	return 0;
}
