# 23. 2017年普及组复赛C++题解

- 张大为
- 辽宁师范大学计算机与信息技术学院@大连
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/)  QQ:1243605845

## 23.1 score

1. 建立程序框架，熟悉编译执行过程，并把样例输出作为测试信息输出。
    ~~~
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int main(){
        cout << "90" << endl;
        return 0;
    }
    ~~~
2. 综合分析【问题描述】、【输入格式】、【输入输入样例】和【数据说明】对数据建模。
    ~~~
    int a, b, c;
    ~~~
3. 根据【输入格式】和【输入输出样例】确定数据的读入策略为**一次性读入**。
    ~~~
    cin >> a >> b >> c;
    ~~~
4. 根据【问题描述】和【输入输出样例说明】，确定数据加工方法（算法）。
    ~~~
    a*.2 + b*.3 + c*.5
    ~~~
    注意：20%=0.2；30%=0.3；50%=0.5。
5. 根据【输出格式】和【输入输出样例】确定输出策略。
    ~~~
    cout << a*.2 + b*.3 + c*.5 << endl;
    ~~~
6. 完整的程序代码为
    ~~~
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int main(){
        int a, b, c;
        
        cin >> a >> b >> c;
        cout << a*.2 + b*.3 + c*.5 << endl;
        
        return 0;
    }
    ~~~
7. 在终端窗口手动测试成功后，在程序开始处增加输入/输出文件语句并重新编译通过。
    ~~~
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    ~~~
8. 准备提交代码的最终版本。
    ~~~
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
    
        int a, b, c;
        
        cin >> a >> b >> c;
        cout << a*.2 + b*.3 + c*.5 << endl;
        
        return 0;
    }
    ~~~
9. 编写对拍脚本如下：
    ~~~
	#!/bin/bash
	i=1
	while [ $i -le 10 ]
	do
	    echo score$i
	    cp -f score$i.in score.in
	    ./score
	    if diff score$i.ans score.out ; then
	        echo Ac
	    fi
	    i=$(($i+1))
	done
    ~~~
10. 执行对拍程序，查看结果,Ac为通过的测试用例。
    ~~~
    $ cd ~/noip/junior-rep-23-2017-C++/score/
    $ sh ./score.sh
    ~~~


## 23.2 librarian

int 可以装下10位整数

~~~
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    cout << -1 << endl;
    
    return 0;

}
~~~


#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    
    int n,q;
    int book[1005],reqlen[1005],reqcode[1005];
    
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
        if(min<100000000)
            cout << min << endl;
        else
            cout << -1 << endl;
    }
    
    return 0;

}


## 23.3 chess

~~~
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int m,n;
int chess[105][105],cost[105][105];
int step[4][2]={ {0,-1},{0,1},{-1,0},{1,0} };

void walk(int sx,int sy,int coin,int magic){
        if (coin < cost[sx][sy])
            cost[sx][sy] = coin;
        else
            return ;
            
        for(int i=0;i<4;i++){
            int tx = sx + step[i][0];
            int ty = sy + step[i][1];
            if(tx<=m && ty<=m && tx >=1 && ty >=1){
                if(chess[tx][ty]>0){
                    if(chess[sx][sy]==chess[tx][ty]){
                        walk(tx,ty,coin,0);
                    }else{
                        walk(tx,ty,coin+1,0);
                    }
                }else if(magic==0){
                    chess[tx][ty] = chess[sx][sy];
                    walk(tx,ty,coin+2,1);
                    chess[tx][ty] = 0;
                }
            }
        }

        return;
}


int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    
    memset(cost,0x7f,sizeof(cost));
    
    int x, y, c;
    cin >> m >> n;
    
    for(int i=1;i<=n;i++){
        cin >> x >> y >> c;
        chess[x][y]=c+1;
    }

    walk(1,1,0,0);
    
    if(cost[m][m]==cost[0][0])
        cout << -1 << endl;
    else
        cout << cost[m][m] << endl;
    
    return 0;
}
~~~



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






    
## w.微信订阅号

1. 智数精英-关注中小学程序设计及相关讨论
2. 随话录-记录小朋友们的成长时光
2. 西山征途-关注大学生成长、学习和生活

![欢迎关注“智数精英”订阅号](../../../assets/me/img/idea8.jpg)
![欢迎关注“随话录”订阅号](../../../assets/me/img/shl8.jpg)
![欢迎关注“西山征途”订阅号](../../../assets/me/img/xszt8.jpg)

----------

## b.[返回首页](../../../)
    





