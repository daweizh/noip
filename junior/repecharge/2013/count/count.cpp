#include <iostream>
#include <cstdio>
using namespace std;

long c[10],n,x,m=10;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	
	for (int i=0;i<10;i++)
		c[i] = 0;
		
	cin >> n >> x;
		
	for(int i=1;i<=n;i++){
		int r = i;
		while(r>0){
			c[r%10]++;
			r = r/10;
		}
	}

	cout << c[x] << endl;	

	return 0;
}
