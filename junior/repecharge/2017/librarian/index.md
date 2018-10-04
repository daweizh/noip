# 23.2 librarian

- 张大为 QQ:1243605845 @大连
- 辽宁师范大学计算机与信息技术学院
- [https://daweizh.github.io/noip/](https://daweizh.github.io/noip/) 

## step1

以librarian1.ans作为输出内容，建立最小可提交程序框架。

~~~
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);

    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;

    fclose(stdout);
    fclose(stdin);

    return 0;
}
~~~

## step2

编写对拍程序，通过测试点1。

~~~
#!/bin/bash
i=1
while [ $i -le 10 ]
do
    echo librarian$i
    cp -f librarian$i.in librarian.in
    ./librarian
    if diff librarian$i.ans librarian.out ; then
        echo Ac
    fi
    i=$(($i+1))
done
~~~

执行对拍程序，观测测试结果。

~~~
$ cd ~/noip/2017/librarian/
$ sh ./librarian.sh 
librarian1
Ac
~~~

只有librarian1测试数据通过，可得10分。

## step3

综合分析试题描述对数据建模，找到基本的输入输出数据存储方式，并确定它们的数据类型。

~~~
int n,q,book[1005],reqlen[1005],reqcode[1005];
~~~

其中n图书馆里书的数量，q是读者的数量，对于 100%的数据， 1 ≤ n，q ≤ 1,000，
book[1005]是n本书的图书编号，
reqlen[1005]是q个需求码的长度与需求码的下标对应，
reqcode[1005]是q个读者的需求码，
所有的图书编码和需求码均不超过 10,000,000。
所以上述变量定义为**int**符合要求。

由于需要读入n本图书和q个读者的数据，所以采用**循环读入数组**的数据读取策略。

~~~
#include <stdio.h>
#include <iostream>
using namespace std;

int n,q,book[1005],reqlen[1005],reqcode[1005];

int main(){
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);

    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> book[i];
    for(int i=0;i<q;i++){
        cin >> reqlen[i] >> reqcode[i] ;
    }

    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << -1 << endl;
    cout << 9392912 << endl;
    cout << -1 << endl;

    fclose(stdout);
    fclose(stdin);
    
    return 0;
}
~~~

## step4

根据题意，求**每位读者（q位）**需要的书，并判断该书是否存在。

~~~
for(int i=0;i<q;i++){
    int min = 100000000;    //设定一个最大的，不存在的图书编码
    
    //查找图书的方法，并把找到的图书编码存入min
    
}
~~~

根据每位读者需求码查找图书的过程，就是把图书编码的后几位按照需求码的长度截取下来进行比对的过程。
要想截取图书编码的后几位，需要根据需求码的长度计算**模数**的大小。变量m用来保存模数。

~~~
int m = 1;
for(int j=0;j<reqlen[i];j++){
    m = m * 10;
}
~~~

接下来对当前读者**i**就可以用他的需求码比对截取后的图书码了，
如果发现新找到的图书码比前面找到的图书码小，用新的图书码替换旧的图书码。

~~~
for(int j=0;j<n;j++){
    if(book[j]%m==reqcode[i]){
        if(book[j]<min)
            min = book[j];
    }
}
~~~

根据【输出格式】和【输入输出样例】确定输出策略——对每位读者判断是否找到了他所需要的那本书。

~~~
if(min<100000000)       //min被改变了，说明所要的图书编码找到了
    cout << min << endl;
else                    //min没有变化，说明没有找到任何图书
    cout << -1 << endl;
~~~

完整的程序代码为如下，按**F7**键编译，按**Ctrl+F5**键执行，观察执行结果的正确性。

~~~
#include <stdio.h>
#include <iostream>
using namespace std;

int n,q,book[1005],reqlen[1005],reqcode[1005];

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

    fclose(stdout);
    fclose(stdin);
    
    return 0;
}
~~~

## step5

再次执行对拍程序，确认全部**Ac**通过测试数据。

~~~
$ cd ~/noip/junior-rep-23-2017-C++/librarian/
$ sh ./librarian.sh
librarian1
Ac
librarian2
Ac
librarian3
Ac
librarian4
Ac
librarian5
Ac
librarian6
Ac
librarian7
Ac
librarian8
Ac
librarian9
Ac
librarian10
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
