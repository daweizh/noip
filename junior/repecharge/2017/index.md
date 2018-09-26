# 23. 2017年普及组复赛C++题解

- 张大为
- 辽宁师范大学计算机与信息技术学院@大连
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/)  QQ:1243605845

## 23.1 score



## 23.2 librarian


## 23.4 jump

~~~
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n,d,dist[500005],k,value[500005];
int head,tail,deque[500005];  //define double-end queue 
long long score[500005],inf;

bool check(int g){
    score[0] = 0;
    deque[0] = 0;
    head = tail = 0;
    int pointer = 1;
    
    for(int i=1;i<=n;i++){
        //for each can jump to distance[i]
        while(pointer<=n && dist[pointer]<=min(dist[i]-1,dist[i]-d+g)){
            while(head<=tail && score[deque[tail]] <=score[pointer])  tail--;
            deque[++tail] = pointer++;
        }

        while(head<=tail && dist[deque[head]]<dist[i]-d-g)  head++;
            
        if(head<=tail && deque[head] <=dist[i]-d+g) 
            score[i] = score[deque[head]] + value[i];
        else
            score[i] = -inf;
        
        if (score[i]>k) return 1;
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
        if(check(midg)) 
            rg = midg;
        else
            lg = midg + 1;
    }
    
    cout << lg << endl;
    
    return 0;
}

~~~






    
## w. 微信订阅号

1. 智数精英-关注中小学程序设计及相关讨论
2. 随话录-记录小朋友们的成长时光
2. 西山征途-关注大学生成长、学习和生活

![欢迎关注“智数精英”订阅号](../../../assets/me/img/idea8.jpg)
![欢迎关注“随话录”订阅号](../../../assets/me/img/shl8.jpg)
![欢迎关注“西山征途”订阅号](../../../assets/me/img/xszt8.jpg)

----------

## b. [返回首页](../../../)
    





