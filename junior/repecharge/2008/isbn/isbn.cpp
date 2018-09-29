#include <iostream>
#include <cstdio>
using namespace std;

char isbn[13];
int sum =0,n=0;

int main(){
	freopen("isbn.in","r",stdin);
	freopen("isbn.out","w",stdout);

	cin >> isbn;

	for(int i=0;i<11;i++){
		if(i!=1 && i!=5){
			n = n + 1;
			sum = sum + (isbn[i]-'0')*n;
		}
	}
	
	int r = sum % 11;
	char ok='+';
	if(r==10){
		if(isbn[12]=='X'){
			cout << "Right";
		}else{
			ok = 'X';
		}
	}else{
		if((isbn[12]-'0')==r){
			cout << "Right";			
		}else{
			ok = '0' + r;
		}
	}
	
	if(ok !='+'){
		for(int i=0;i<11;i++)
			cout << isbn[i];
		cout << "-" << ok;
	}
	
	cout << endl;

	return 0;
}
