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
    
## w.微信订阅号

1. 智数精英-关注中小学程序设计及相关讨论
2. 随话录-记录小朋友们的成长时光
2. 西山征途-关注大学生成长、学习和生活

![欢迎关注“智数精英”订阅号](../../../assets/me/img/idea8.jpg)
![欢迎关注“随话录”订阅号](../../../assets/me/img/shl8.jpg)
![欢迎关注“西山征途”订阅号](../../../assets/me/img/xszt8.jpg)

----------

## b.[返回首页](../../../)
    





