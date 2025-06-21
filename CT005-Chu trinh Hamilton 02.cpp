//Input
//4 4 1
//1 2
//2 3
//3 4
//4 1
//Output
//1
//1 2 3 4 1
#include <bits/stdc++.h>
using namespace std;
int a[101][101], n, m, k;
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
	cin >> n >> m >> k;
	for(int i=1;i<=100;i++) chuaxet[i]=1;
	while(m--){
		int x, y; cin >> x >> y;
		a[x][y]=1;
		a[y][x]=1;
	}
	Hamilton(k);
	cout << cnt << endl;
	for(int i=0;i<v.size();i++){
		if(i%(n+1)==n) cout << v[i] << endl;
		else cout << v[i] << " ";
	}
}