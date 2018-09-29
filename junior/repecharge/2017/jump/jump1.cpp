#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,d,k,dist[500005],value[500005];
long long coins[500005];
int lpos,rpos;

bool check(int g){
    lpos = d-g; //跳的最短距离 
    rpos = d+g; //跳的最长距离 
    if(lpos<=0) lpos = 1;
    memset(coins,-127,sizeof(coins));  //设为很小的负数
    coins[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=i-1; j>=0; j--){
            if(dist[i]-dist[j]<lpos) continue;
            if(dist[i]-dist[j]>rpos) break;
            coins[i]=max(coins[i],coins[j]+value[i]);
            if(coins[i]>=k) return 1;
        }
    }
    return 0;
}

int main(){
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    
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
