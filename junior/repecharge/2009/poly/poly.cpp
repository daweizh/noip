#include <iostream>
#include <cstdio>
using namespace std;

int n,a;

int main(){
	freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout);
	
	cin >> n >> a;
	
	int p = n;
	if (a==1){
		cout << "x" ;	
	}else if(a==-1){
		cout <<  "-x" ;	
	}else{
		cout <<  a << "x" ;	
	}
	if(p>1){
		cout << "^" << p;
	}
	
	for(int i=1;i<n;i++){
		p = p - 1;
		cin >> a;
		if(a!=0){
			if(a==1){
				cout << "+x" ;	
			}else if(a==-1){
				cout << "-x" ;	
			}else if(a>0){
				cout << "+" << a << "x" ;	
			}else{
				cout << a << "x" ;	
			}			
			if(p>1){
				cout << "^" << p;
			}
		}
	}
	
	cin >> a;
	if(a<0){
		cout << a;
	}
	if(a>0){
		cout << "+" << a;
	}
	
	cout << endl;

	return 0;
}
