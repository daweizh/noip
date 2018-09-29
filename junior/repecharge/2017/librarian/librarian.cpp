#include <stdio.h>
#include <iostream>
using namespace std;

int n;              //图书馆里书的数量
int q;              //读者的数量
int book[1005];     //n本书的图书编号
int reqlen[1005];   //q个需求码的长度，与需求码的下标对应
int reqcode[1005];  //q个读者的需求码

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin >> n >> q;
	for(int i=0;i<n;i++)
		cin >> book[i];
	for(int i=0;i<q;i++){
		cin >> reqlen[i] >> reqcode[i] ;
	}
	
	for(int i=0;i<q;i++){
		int min = 100000000;

		int m = 1;
		for(int j=0;j<reqlen[i];j++){
			m = m * 10;
		}
		
		//cout << "len=" << reqlen[i] <<"\t m=" << m << endl;
		
		for(int j=0;j<n;j++){
			if(book[j]%m==reqcode[i]){
				if(book[j]<min)
					min = book[j];
			}
		}

		if(min<100000000)       //min被改变了，说明所要的图书编码找到了
		    cout << min << endl;
		else                    //min没有变化，说明没有找到任何图书
		    cout << -1 << endl;
	}
	
	return 0;

}
