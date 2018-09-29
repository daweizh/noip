#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,d,k,dist[500005],value[500005];
long long coins[500005],inf;
int head,tail,deque[500005];  

bool check(int g){
	coins[0] = 0;
	deque[0] = 0;
	head = tail = 0;
	int pointer = 1;
	
	for(int i=1;i<=n;i++){
		while(pointer<=n && dist[pointer]<=min(dist[i]-1,dist[i]-d+g)){
			while(head<=tail && coins[deque[tail]] <=coins[pointer])  tail--;
			deque[++tail] = pointer++;
		}

		while(head<=tail && dist[deque[head]]<dist[i]-d-g) 	head++;
			
		if(head<=tail && deque[head] <=dist[i]-d+g) 
			coins[i] = coins[deque[head]] + value[i];
		else
			coins[i] = -inf;
		
		if (coins[i]>k) return 1;
	}
	return 0;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	
	inf = 1000000000;
	inf = inf * inf;
    
    long long sum = 0;
    cin >> n >> d >> k;
    for (int i=1;i<=n;i++){
        cin >> dist[i] >> value[i];
        if(value[i]>0) sum = sum + value[i];
    }
    
    if(sum < k){
        cout << -1 << endl;
        return 0;
    }
    
    int lg=0,rg=1000000000;
    while(lg<rg){
        int midg = (lg+rg)>>1;
        if(check(midg)) {
            rg = midg;
        }else{
            lg = midg + 1;
        }
    }
    
    cout << rg << endl;
    
    return 0;
}
