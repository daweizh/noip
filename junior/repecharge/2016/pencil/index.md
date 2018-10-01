# 22.1 pencil

- 张大为
- 辽宁师范大学计算机与信息技术学院@大连
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/)  QQ:1243605845

## step1

用测试数据pencil1.ans的数据作为输出，编写主程序框架。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    cout << 15024 << endl;
    
    return 0;
}
~~~

## step2

复制pencil1.in作为输入测试数据pencil.in。

~~~cpp
4632
579 7249
579 1878
579 5603
~~~

## step3

设计输入数据变量及其对应的数据类型。
设计数据读取及其运算结构。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int n,package,price;

int main(){
    freopen("pencil.in","r",stdin);
    
    cin >> n;
    
    for(int i=0;i<3;i++){
        cin >> package >> price;
    }

    cout << 15024 << endl;
    
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

int n,package,price;
int minimum,m;

int main(){
    freopen("pencil.in","r",stdin);
    
    cin >> n;
    minimum = n * 10000;
    
    for(int i=0;i<3;i++){
        cin >> package >> price;
        
        if(n%package==0){
            m = n/package * price;
        }else{
            m = (n/package + 1) * price;
        }
        
        if(m < minimum){
            minimum = m;
        }
    }

    cout << minimum << endl;
    
    return 0;
}
~~~

![观察计算结果](out.png)

## step5

增加输出重定向，完成程序，按`F7`编译通过。
按`Ctrl+F5`执行，将计算机结果pencil.out与pencil1.ans比较，看是否正确。

~~~cpp
#include <iostream>
#include <cstdio>
using namespace std;

int n,package,price;
int minimum,m;

int main(){
    freopen("pencil.in","r",stdin);
    freopen("pencil.out","w",stdout);
    
    cin >> n;
    minimum = n * 10000;
    
    for(int i=0;i<3;i++){
        cin >> package >> price;
        
        if(n%package==0){
            m = n/package * price;
        }else{
            m = (n/package + 1) * price;
        }
        
        if(m < minimum){
            minimum = m;
        }
    }

    cout << minimum << endl;
    
    return 0;
}
~~~

pencil.out

~~~cpp
15024
~~~

## step6

编写对拍程序，检测通过测试点情况。

~~~sh
#!/bin/bash
i=1
while [ $i -le 20 ]
do
    echo pencil$i
    cp -f pencil$i.in pencil.in
    ./pencil
    if diff pencil$i.ans pencil.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
~~~

## step7

执行对拍程序，查看结果，Ac为通过的测试用例。

~~~sh
$ cd ~/noip/2016/pencil/
$ sh ./pencil.sh
~~~

执行结果如下：

~~~sh
pencil1
Ac
pencil2
Ac
pencil3
Ac
pencil4
Ac
pencil5
Ac
pencil6
Ac
pencil7
Ac
pencil8
Ac
pencil9
Ac
pencil10
Ac
pencil11
Ac
pencil12
Ac
pencil13
Ac
pencil14
Ac
pencil15
Ac
pencil16
Ac
pencil17
Ac
pencil18
Ac
pencil19
Ac
pencil20
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
