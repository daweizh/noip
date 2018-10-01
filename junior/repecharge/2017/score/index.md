# 23.1 score

- 张大为 
- 辽宁师范大学计算机与信息技术学院
- @大连 QQ:1243605845
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/)  

## step1

以score1.ans作为输出内容，建立最小可提交程序框架。

~~~cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);

    cout << 40 << endl;

    return 0;
}
~~~

## step2

编写对拍程序，通过测试点1。

~~~sh
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

执行对拍程序，观测测试结果。

~~~sh
$ cd ~/noip/2017/score/
$ sh ./score.sh 
score1
Ac
~~~

只有score1测试数据通过，可得10分。

## step3

综合分析试题描述对数据建模，找到基本的输入输出数据存储方式，并确定它们的数据类型。
由于需要计算成绩的只有牛牛，确定数据的读入策略为**一次性读入**。

~~~cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int a,b,c;

int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    
    cin >> a >> b >> c;
    
    cout << 40 << endl;

    return 0;
}
~~~

## step4

根据试题中给出的计算总成绩的方法，确定数据加工方法（算法）。

1. 直接输出计算结果
    ~~~cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
        
        cin >> a >> b >> c;
        cout << a*.2 + b*.3 + c*.5 << endl;
            
        return 0;
    }
    ~~~
2. 全整型计算
    ~~~cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c,score;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
        
        cin >> a >> b >> c;
        score = (a*2 + b * 3 + c *5) / 10;
        
        cout << score << endl;
            
        return 0;
    }
    ~~~
3. 输出浮点计算结果
    ~~~cpp
    #include <stdio.h>
    #include <iostream>
    using namespace std;
    
    int a,b,c;
    double score;
    
    int main(){
        freopen("score.in","r",stdin);
        freopen("score.out","w",stdout);
    
        cin >> a >> b >> c;
        score = a*.2 + b*.3 + c*.5;
        cout << score << endl;
    
        return 0;
    }
    ~~~

## step5

再次执行对拍程序，确认全部**Ac**通过测试数据。

~~~sh
$ cd ~/noip/junior-rep-23-2017-C++/score/
$ sh ./score.sh
score1
Ac
score2
Ac
score3
Ac
score4
Ac
score5
Ac
score6
Ac
score7
Ac
score8
Ac
score9
Ac
score10
Ac
~~~

## w. 微信订阅号

1. 智数精英-关注中小学程序设计及相关讨论
2. 随话录-记录小朋友们的成长时光
2. 西山征途-关注大学生成长、学习和生活

![欢迎关注“智数精英”订阅号](../../../../assets/me/img/idea8.jpg)
![欢迎关注“随话录”订阅号](../../../../assets/me/img/shl8.jpg)
![欢迎关注“西山征途”订阅号](../../../../assets/me/img/xszt8.jpg)

----------

## b. [返回](../../)
    
## h. [首页](../../../../)
