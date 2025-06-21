#include <bits/stdc++.h>
using namespace std;
int a[101][101], n, k;
int chuaxet[101], b[101], cnt=0, dem=0;
vector<int> v;
void kq(){
	v.push_back(k);
	for(int i=1;i<=n;i++){
		v.push_back(b[i]);
	}
}
void Hamilton(int i){
	for(int j=1;j<=n;j++){
		if(a[i][j]==1&&chuaxet[j]==1){
			++dem;
			chuaxet[j]=0;
			if(dem==n&&j==k){
				++cnt;
				b[dem]=j;
				kq();
			}
			else{
				b[dem]=j;
				Hamilton(j);
			}
			--dem;
			chuaxet[j]=1;
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=100;i++) chuaxet[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	Hamilton(k);
	cout << cnt << endl;
	for(int i=0;i<v.size();i++){
		if(i%(n+1)==n) cout << v[i] << endl;
		else cout << v[i] << " ";
	}
}