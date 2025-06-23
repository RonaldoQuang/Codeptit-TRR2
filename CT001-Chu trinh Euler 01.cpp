#include<bits/stdc++.h>
using namespace std;
int t, n, k, u, cx=1;
int a[101][101], vs[101];
vector<int> v;
void dfs(int i){
	vs[i]=1;
	for(int j=1;j<=n;j++){
		if(a[i][j]&&!vs[j]){
			++cx;
			dfs(j);
		}
	}
}
void ktra(){
	int cnt=0, cnt1=0;
	for(int i=1;i<=n;i++){
		int dem=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]) ++dem;
		}
		if(dem%2==0) ++cnt;
		else ++cnt1;
	}
	dfs(1);
	if(cx==n){
		if(cnt==n) cout << 1;
		if(cnt1==2) cout << 2;
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
	cin >> t >> n >> k;
	if(t==2) cin >> u;
	while(k--){
		int x, y; cin >> x >> y;
		a[x][y]=1;
		a[y][x]=1;
	}
	if(t==1) ktra();
	else EC(u);
}
