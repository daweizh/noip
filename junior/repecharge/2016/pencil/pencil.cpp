#include <iostream>
#include <cstdio>
using namespace std;

int n,package,price;
int minimum,m;

int main(){
	freopen("pencil.in","r",stdin);
	freopen("pencil.out","w",stdout);
	
	cin >> n;
	minimum = n * 10000;
	
	for(int i=0;i<3;i++){
		cin >> package >> price;
		
		if(n%package==0){
			m = n/package * price;
		}else{
			m = (n/package + 1) * price;
		}
		
		if(m < minimum){
			minimum = m;
		}
	}

	cout << minimum << endl;
	
	return 0;
}
