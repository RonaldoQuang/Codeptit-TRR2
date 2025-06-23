#include<bits/stdc++.h>
using namespace std;
int t, n, u;
int vs[101];
vector<int> a[101];
vector<pair<int,int>> v;
void dfs(int i){
	vs[i]=1;
	for(int j=0;j<a[i].size();j++){
		if(!vs[a[i][j]]){
			v.push_back({i,a[i][j]});
			dfs(a[i][j]);
		}
	}
}
void bfs(int i){
	queue<int> q;
	q.push(i);
	vs[i]=1;
	while(!q.empty()){
		int s=q.front(); q.pop();
		for(int j=0;j<a[s].size();j++){
			if(!vs[a[s][j]]){
				v.push_back({s,a[s][j]});
				q.push(a[s][j]);
				vs[a[s][j]]=1;
			}
		}
	}
}
int main(){
	freopen("CK.INP","r",stdin);
	freopen("CK.OUT","w",stdout);
	cin >> t >> n >> u;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x; cin >> x;
			if(x) a[i].push_back(j);
		}
	}
	if(t==1) dfs(u);
	else bfs(u);
	if(v.size()==n-1){
		cout << n-1 << endl;
		for(auto x:v) cout << min(x.first,x.second) << " " << max(x.first,x.second) << endl;
	}
	else cout << 0;
}
