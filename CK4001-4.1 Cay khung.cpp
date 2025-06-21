#include <bits/stdc++.h>
using namespace std;
int n, u;
int chuaxet[105];
vector<int> a[105];
vector<pair<int,int>> v;
void Tree_DFS(int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]){
			v.push_back({i,a[i][j]});
			Tree_DFS(a[i][j]);
		}
	}
}
void Tree_BFS(int i){
	queue<int> q;
	q.push(i);
	chuaxet[i]=0;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int j=0;j<a[s].size();j++){
			if(chuaxet[a[s][j]]){
				q.push(a[s][j]);
				v.push_back({s,a[s][j]});
				chuaxet[a[s][j]]=0;
			}
		}
	}
}
int main(){
//	freopen("CK.INP","r",stdin);
//	freopen("CK.OUT","w",stdout);
	int t; cin >> t;
	cin >> n >> u;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x; cin >> x;
			if(x==1){
				a[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		chuaxet[i]=1;
	}
	if(t==1) Tree_DFS(u);
	else Tree_BFS(u);
	if(v.size()==n-1){
		cout << n-1 << endl;
		for(auto x:v){
			cout << x.first << " " << x.second << endl;
		}
	}
	else cout << 0;
}