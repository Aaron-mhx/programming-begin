#include<bits/stdc++.h>
using namespace std;
bool zs[1000000];//ָʾ���飺�Ƿ�Ϊ����
void ass(int n){//����ɸ ����⣺https://aaron-mhx.github.io/post/ai-shi-shai/ 
	memset(zs,1,sizeof(zs));//��ֵΪ��������������Ϊ��������Ϊ������ 
	zs[0] = zs[1] = 0;
	for(int i = 2; i <= n; i++){
		if(zs[i]){
			for(int j = 2; i*j <= n; j++){//�����ı������Ǻ��� 
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
	//**********�ļ�**************
	int n/*���ʴ���*/,m/*���ֵ*/,l[1000]/*��Χ(С)*/,r[1000]/*��Χ(��)*/,sum/*����*/;
	cin >> n >> m;
	ass(m);     
	for(int i = 0; i < n; i++){//n��ѯ��
		cin >> l[i] >> r[i];
	}
	for(int i = 0; i < n; i++){//n��ѯ��
		sum = 0;//���������� 
		if(l[i] < 1 || l[i] > m || r[i] < 1 || r[i] > m){//��Щ������������� 
			cout << "Crossing the line" << endl;
			continue;
		}else{//���l~r֮������������
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
