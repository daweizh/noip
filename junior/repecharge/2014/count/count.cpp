#include <iostream>
#include <cstdio>
using namespace std;

int n,flag[10005],num[10005],d,count=0;

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);

	for(int i=0;i<10005;i++){
		flag[i]=0;
	}
	
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> d;
		flag[d]=1;
		num[i]=d;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int sum = num[i]+num[j];
			if(sum <=10000 && flag[sum]>0){
				count = count + 1;
				flag[sum]=0;
			}
		}
	}
	
	cout << count << endl;
	
	return 0;
}
