#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n, s, t;
vector<pair<int,int>> a[101];
int truoc[101];
vector<int> d(101,inf);
void dijkstra(){
	d[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while(!q.empty()){
		pair<int,int> p=q.top(); q.pop();
		int u=p.second;
		for(auto it:a[u]){
			int v=it.first, w=it.second;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				truoc[v]=u;
				q.push({d[v],v});
			}
		}
	}
	if(d[t]==inf) cout << 0;
	else{
		vector<int> v;
		cout << d[t] << endl;
		while(t!=s){
			v.push_back(t);
			t=truoc[t];
		}
		v.push_back(s);
		for(int i=v.size()-1;i>=0;i--){
			cout << v[i] << " ";
		}
	}
}
int main(){
	freopen("DN.INP","r",stdin);
	freopen("DN.OUT","w",stdout);
	cin >> n >> s >> t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int w; cin >> w;
			if(w>0&&w<=50) a[i].push_back({j,w});
		}
	}
	dijkstra();
}
