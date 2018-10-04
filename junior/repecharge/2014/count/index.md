# 20.1 count

- 张大为 QQ:1243605845 @大连
- 辽宁师范大学计算机与信息技术学院
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/) 

## step1

用测试数据count1.ans的数据作为输出，编写主程序框架。

~~~
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);

    cout << 14 << endl;

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


## step2

复制count1.in作为输入测试数据count.in。

~~~cpp
4
1 2 3 4
~~~

## step3

设计输入数据变量及其对应的数据类型。
设计数据读取及其运算结构。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int n,flag[10005],num[10005],d;

int main(){
    freopen("count.in","r",stdin);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d;
        flag[d]=1;
        num[i]=d;
    }

    cout << 2 << endl;
    
    return 0;
}
~~~

观察数据读取情况。

![观察输入数据](var.png)

## step4

增加中间变量，组织算法逻辑，按`Ctrl+F5`观察计算结果。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int n,flag[10005],num[10005],d;
int count=0;

int main(){
    freopen("count.in","r",stdin);

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
~~~

![观察计算结果](out.png)

## step5

增加输出重定向，完成程序，按`F7`编译通过。
按`Ctrl+F5`执行，将计算机结果count.out与count1.ans比较，看是否正确。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int n,flag[10005],num[10005],d;
int count=0;

int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);

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
~~~

count.out

~~~cpp
2
~~~

## step6

编写对拍程序，检测通过测试点情况。

~~~sh
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo count$i
    cp -f count$i.in count.in
    ./count
    if diff count$i.ans count.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
~~~

## step7

执行对拍程序，查看结果，Ac为通过的测试用例。

~~~sh
$ cd ~/noip/2014/count/
$ sh ./count.sh
~~~

执行结果如下：

~~~sh
count1
Ac
count2
Ac
count3
Ac
count4
Ac
count5
Ac
count6
Ac
count7
Ac
count8
Ac
count9
Ac
count10
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
