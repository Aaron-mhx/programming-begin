#include<bits/stdc++.h>
using namespace std;
bool zs[1000000];//指示数组：是否为质数
void ass(int n){//埃氏筛 ：详解：https://aaron-mhx.github.io/post/ai-shi-shai/ 
	memset(zs,1,sizeof(zs));//赋值为“是质数”（真为质数，假为合数） 
	zs[0] = zs[1] = 0;
	for(int i = 2; i <= n; i++){
		if(zs[i]){
			for(int j = 2; i*j <= n; j++){//质数的倍数都是合数 
				zs[i*j] = 0;
			}
		}
		
	}
	return;
}

int main(){
	//freopen("1.in","w",stdin);
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//**********文件**************
	int n/*访问次数*/,m/*最大值*/,l[1000]/*范围(小)*/,r[1000]/*范围(大)*/,sum/*数量*/;
	cin >> n >> m;
	ass(m);     
	for(int i = 0; i < n; i++){//n次询问
		cin >> l[i] >> r[i];
	}
	for(int i = 0; i < n; i++){//n次询问
		sum = 0;//别忘了清零 
		if(l[i] < 1 || l[i] > m || r[i] < 1 || r[i] > m){//这些情况不符合条件 
			cout << "Crossing the line" << endl;
			continue;
		}else{//输出l~r之间质数个数。
			for(int j = l[i]; j <= r[i]; j++){
				if(zs[j]){
					sum++;
				}
			}
			cout << sum << endl; 
		} 
	} 

	return 0;
} 
