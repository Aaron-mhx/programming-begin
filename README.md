＃ 编程基础
## NOLP竞赛的仓库
## 一起学习吧
## 埃氏筛
#### 埃氏筛的核心思想是：假设所有的数都是质数，找到一个质数，就把他所有的倍数都当成合数
那么，我们就需要一个指示数组，来记录数是合数还是质数。因为只有两种状态，所以我们要使用**bool**类型的数组，数组的下标就是要找的那个数，而真值就代表质数，假值则代表合数。我们先把这个数组完成。
`bool zs[1000000];//指示数组：是否为质数`
接下来我们需要把他们都假设为是质数，尽管他不是char类型的数组，也可以使用memset，不过别忘了加上`include<cstring>`头文件~~其实也可以用万能头文件`#include<bits/stdc++.h>`但有时使用它会出错~~。再把这句补上。
`memset(zs,1,sizeof(zs));//赋值为“是质数”（真为质数，假为合数） `
但是，有些数学好的童鞋已经看出来了：0、都被算成了质数！！！，我们把这句给添上。
`zs[0] = zs[1] = 0;`
#####接下来到了重头戏~~其实也不难~~
我们先找到一个能不断找到质数的办法：**for循环！！！**我们的for循环要从2开始（毕竟2是最小的质数），再到我们查找的范围结束（我们假定范围是0~n）但并不是所有的都是质数，所以我们再加上一个if语句，是质数（`sz[i] == 1`)时再找他的倍数，还要用到for循环，从2开始（从0或1开始是毫无意义的，还费时间）那什么时候结束呢？A.j<=n  B.i\*j <= n，答案是B，因为我们找的是i的倍数，也就是i\*j，我们的范围是小于n的，所以i乘j一定小于或等于n。循环体作用就是把i的倍数设为合数，所以这一大段代码赶紧补上吧！
```c
for(int i = 2; i <= n; i++){
		if(zs[i]){//是质数才执行
			for(int j = 2; i*j <= n; j++){//质数的倍数都是合数 
				zs[i*j] = 0;
			}
		}
		
	}
```
### 接下来到了我们最喜欢的完整代码
这段代码我做成了函数的形式，并且完成了输入n，输出0~n范围内质数的个数
#### 再说一点，非常重要，**请勿抄袭！！！**
```c
#include<bits/stdc++.h>//万能头文件
using namespace std;
bool zs[101010];//指示数组：是否为质数
int ass(int n){//埃氏筛 拼音
	int sum = 0;//质数数量 
	memset(zs,1,sizeof(zs));//赋值为“是质数”（真为质数，假为合数） 
	zs[0] = zs[1] = 0;
	for(int i = 2; i <= n; i++){
		if(zs[i]){
			sum ++;
			for(int j = 2; i*j <= n; j++){//质数的倍数都是合数 
				zs[i*j] = 0;
			}
		}
		
	}
	return sum;
}

//******************************* 
int main(){
	//freopen("1.in","w",stdin);定义输入文件，这个语句执行一次后，一定要注释掉，不然你会疯的
	//freopen("1.in","r",stdin);读取输入文件
	//freopen("1.out","w",stdout);这些比赛时才用得着，了解一下吧
	//**********文件**************
	
	int n;
	cin >> n;
	cout << ass(n);
	
	return 0;
} 
```
# 
#
## 示范题目：哥德巴赫猜想升级版
#### 我们先读读题目


题目背景
1742年6月7日哥德巴赫写信给当时的大数学家欧拉，正式提出了以下的猜想：任何一个大于9的奇数都可以表示成3个质数之和。质数是指除了1和本身之外没有其他约数的数，如2和11都是质数，而6不是质数，因为6除了约数1和6之外还有约数2和3。需要特别说明的是1不是质数。

这就是哥德巴赫猜想。欧拉在回信中说，他相信这个猜想是正确的，但他不能证明。

从此，这道数学难题引起了几乎所有数学家的注意。哥德巴赫猜想由此成为数学皇冠上一颗可望不可及的“明珠”。

题目描述
现在请你编一个程序验证哥德巴赫猜想。

先给出一个奇数n，要求输出3个质数，这3个质数之和等于输入的奇数。

输入格式
**仅有一行，包含一个正奇数n，其中9<n<20000**

输出格式
**仅有一行，输出3个质数，这3个质数之和等于输入的奇数。相邻两个质数之间用一个空格隔开，最后一个质数后面没有空格。如果表示方法不唯一，请输出第一个质数最小的方案，如果第一个质数最小的方案不唯一，请输出第一个质数最小的同时，第二个质数最小的方案。**

输入输出样例
输入 \#1 
2009
输出 \#1 
3 3 2003
读完题后我们的第一反应是三层嵌套for循环，找到数后判断是否符合题意，但是这未免太麻烦了，如果数据过大就会有超时的风险。有没有更方便的办法？**肯定有！！！**，在进入正题之前，我们要先了解一件事，那就是所有的质数中，只有一个是偶质数，那就是2，所以只有两种情况：
**1.两个二加上一个奇数**
**2.三个奇数相加**
这样我们就可以先把第一情况给写完。
```c
if(n-4 /*是质数*/){ 
		cout << "2" << " " << "2" << " " << n-4;
		return 0;//这里任务已完成，可以退出程序
	}
```
那如何判断一个数是不是质数呢，用for循环一个一个试？还是用其他质数筛法吧，今天我们尝试使用埃氏筛，埃氏筛的详解请Ctrl+单击访问 https://aaron-mhx.github.io/post/ai-shi-shai/，在这儿，我们先加上函数版的埃氏筛：
```c
    bool zs[20100];//指示数组：是否为质数
void ass(){//埃氏筛:埃氏筛详解：https://aaron-mhx.github.io/post/ai-shi-shai/
	memset(zs,1,sizeof(zs));//赋值为“是质数”（真为质数，假为合数） 
	zs[0] = zs[1] = 0;
	for(int i = 2; i <= n; i++){
		if(zs[i]){
			sum ++;
			for(int j = 2; i*j <= n; j++){//质数的倍数都是合数 
				zs[i*j] = 0;
			}
		}
		
	}
	return;
}
```
使用埃氏筛的好处有很多：1.只用执行一次，数据调用时只需要访问数组zs就可以了 2.时间复杂度低，仅为O(nloglogn)。所以刚才的代码就可以改成：
```c
    ass(); //调用函数
	if(zs[n-4]){//因为2是唯一的偶质数，单独看。 
		cout << "2" << " " << "2" << " " << n-4;
		return 0;//这里任务已完成，可以退出程序
	}
```
#### 接下来到了重头戏：第二种情况三个奇质数相加
因为我们已经将偶数排除在外，所以for循环可以从3开始，每次加2，找到第一个数后，zs数组又派上用场了。我们要判断找到的数，是否为质数，是质数才进行下一层循环，下一层循环也是同理。但是找到了前两个数后，第三个数（n-i-j）不也找到了吗，只需要再判断第三个数是不是质数就行了。这是第二种情况的代码：
```c
    for(int i = 3; i < n; i+=2){//优化：除2之外没有其他偶质数
		if(zs[i]){//是质数才执行 
			for(int j =3; j < n-i; j+=2){
				if(zs[j] && zs[n-i-j]){
					cout << i << " " << j << " " << n-i-j;
					return 0;
				}
			} 
		} 
	}
```
#### 接下来，又到了喜闻乐见的完整代码了，还是强调**禁止抄袭**
```c
#include<bits/stdc++.h>//万能头文件 
using namespace std;
bool zs[20100];//指示数组：是否为质数
int ass(int n){//埃氏筛:埃氏筛详解：https://aaron-mhx.github.io/post/ai-shi-shai/
	int sum = 0;//质数数量 
	memset(zs,1,sizeof(zs));//赋值为“是质数”（真为质数，假为合数） 
	zs[0] = zs[1] = 0;
	for(int i = 2; i <= n; i++){
		if(zs[i]){
			sum ++;
			for(int j = 2; i*j <= n; j++){//质数的倍数都是合数 
				zs[i*j] = 0;
			}
		}
		
	}
	return sum;
}

//******************************* 
int main(){
	//freopen("1.in","w",stdin);定义输入文件，这个语句执行一次后，一定要注释掉，不然你会疯的
	//freopen("1.in","r",stdin);读取输入文件
	//freopen("1.out","w",stdout);这些比赛时才用得着，了解一下吧
	//**********文件**************
	
	int n;//这就是我们要分解的那个数 
	cin >> n;
	ass(20010); 
	if(zs[n-4]){//因为2是唯一的偶质数，单独看。 
		cout << "2" << " " << "2" << " " << n-4;
		return 0;//这里任务已完成，可以退出程序
	}
	for(int i = 3; i < n; i+=2){//优化：除2之外没有其他偶质数
		if(zs[i]){//是质数才执行 
			for(int j =3; j < n-i; j+=2){
				if(zs[j] && zs[n-i-j]){
					cout << i << " " << j << " " << n-i-j;
					return 0;
				}
			} 
		} 
	}
	
	return 0;//养成良好的习惯 
} 
```
