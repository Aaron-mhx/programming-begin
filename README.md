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

