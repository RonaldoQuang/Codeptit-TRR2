#include <bits/stdc++.h>
using namespace std;
int a[101][101], c[101][101], n, k;
int chuaxet[101], b[101], cnt=0, dem=0, sum=0, min1=1e9;
vector<int> v;
void kq(){
	v.push_back(k);
	for(int i=1;i<=n;i++) v.push_back(b[i]);
}
void Hamilton(int i){
	for(int j=1;j<=n;j++){
		if(a[i][j]==1&&chuaxet[j]==1){
			++dem;
			chuaxet[j]=0;
			sum+=c[i][j];
			if(dem==n&&j==k&&sum<min1){
				++cnt;
				min1=sum;
				b[dem]=j;
				v.clear();
				kq();
			}
			else{
				b[dem]=j;
				Hamilton(j);
			}
			--dem;
			sum-=c[i][j];
			chuaxet[j]=1;
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=100;i++) chuaxet[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
			if(c[i][j]<=50&&c[i][j]>0) a[i][j]=1;
			else a[i][j]=0;
		}
	}
	Hamilton(k);
	if(cnt==0) cout << "0";
	else{
		cout << min1 << endl;
		for(auto x:v) cout << x << " ";
	}
}