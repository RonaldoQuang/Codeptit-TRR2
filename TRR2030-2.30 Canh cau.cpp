//Input
//1
//4
//0 1 0 1
//1 0 1 0
//0 1 0 0
//1 0 0 0

//5
//0 1 0 0 0
//1 0 1 0 0
//0 1 0 1 1
//0 0 1 0 1
//0 0 1 1 0
//Output
//2
//1 2
//2 3
#include <bits/stdc++.h>
using namespace std;
int a[101][101], b[101][101], n;
int chuaxet[101], cnt=0, dem=0, cnt1=0;
queue<pair<int,int>> q;
vector<pair<int,int>> v;
void DFS(int i){
	chuaxet[i]=0;
	for(int j=1;j<=n;j++){
		if(a[i][j]==1&&chuaxet[j]==1){
			DFS(j);
		}
	}
}
int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) chuaxet[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(chuaxet[i]){
			++cnt;
			DFS(i);
		}
	}
	for(int i=1;i<=n;i++) chuaxet[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==1){
				q.push({i,j});
				b[j][i]=0;
			}
		}
	}
	while(!q.empty()){
		pair<int,int> x=q.front();
		a[x.first][x.second]=0;
		a[x.second][x.first]=0;
		q.pop();
		int dem1=0;
		for(int i=1;i<=n;i++){
			if(chuaxet[i]){
				++dem1;
				DFS(i);
			}
		}
		a[x.first][x.second]=1;
		a[x.second][x.first]=1;
		for(int i=1;i<=n;i++) chuaxet[i]=1;
		if(dem1>cnt){
			++cnt1;
			v.push_back(x);
		}
	}
	sort(v.begin(),v.end());
	cout << cnt1 << endl;
	for(auto x:v){
		cout << x.first << " " << x.second << endl;
	}
}