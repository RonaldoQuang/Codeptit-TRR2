#include <bits/stdc++.h>
using namespace std;
int c[101][101], n, k, cnt=0;
vector<vector<int>> a;
vector<int> b;
vector<bool> chuaxet;
void kq(){
    for(int i=1;i<=n;i++){
		cout << b[i] << " ";
	}
	cout << k << endl;
}
void Hamilton(int i){
	int t=b[i-1];
	for(int y:a[t]){
		if(i==n+1&&y==k){
			++cnt;
			kq();
		}
		else if(!chuaxet[y]){
			chuaxet[y]=true;
			b[i]=y;
			Hamilton(i+1);
			chuaxet[y]=false;
		}
	}	
}
int main(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);
	cin >> n >> k;
	a.resize(n+10);
	b.resize(n+10);
	chuaxet.resize(n+10,false);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
			if(c[i][j]==1) a[i].push_back(j);
		}
	}
	b[1]=k;
	chuaxet[k]=true;
	Hamilton(2);
	cout << cnt;
}