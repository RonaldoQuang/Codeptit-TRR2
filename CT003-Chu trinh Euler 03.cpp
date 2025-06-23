#include<bits/stdc++.h>
using namespace std;
int t, n, u, cx=1;
int a[101][101], b[101][101], vs[101];
vector<int> v;
void dfs(int i){
	vs[i]=1;
	for(int j=1;j<=n;j++){
		if(b[i][j]&&!vs[j]){
			++cx;
			dfs(j);
		}
	}
}
void ktra(){
	map<int,int> mp, ma;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				mp[i]++;
				ma[j]++;
			}
		}
	}
	int cnt=0, cnt1=0, cnt2=0;
	for(int i=1;i<=n;i++){
		if(mp[i]==ma[i]) ++cnt;
		else if(mp[i]-ma[i]==1) ++cnt1;
		else if(ma[i]-mp[i]==1) ++cnt2;
	}
	dfs(1);
	if(cx==n){
		if(cnt==n) cout << 1;
		else if(cnt1==1&&cnt2==1&&cnt==n-2) cout << 2;
		else cout << 0;
	}
	else cout << 0;
}
void EC(int u){
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int i=st.top(), ok=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]){
				ok=1;
				a[i][j]=0;
				a[j][i]=0;
				st.push(j);
				break;
			}
		}
		if(!ok){
			v.push_back(st.top());
			st.pop();
		}
	}
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i] << " ";
	}
}
int main(){
	cin >> t >> n;
	if(t==2) cin >> u;
	for(int i=1;i<=n;i++){
		int k; cin >> k;
		for(int j=1;j<=k;j++){
			int x; cin >> x;
			a[i][x]=1;
			b[i][x]=1;
			b[x][i]=1;
		}
	}
	if(t==1) ktra();
	else EC(u);
}