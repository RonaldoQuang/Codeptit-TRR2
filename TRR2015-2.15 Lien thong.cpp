//Input
//4
//0 0 1 0
//0 0 0 1
//0 1 0 0
//1 0 0 0

//4
//0 0 1 0 
//0 0 0 1
//0 1 0 0
//0 0 1 0
//Output
//1

//2
#include <bits/stdc++.h>
using namespace std;
int c[101][101], n;
int chuaxet[101], cnt=0, dem=0;
int DFS(vector<int> a[101], int x){
	stack<int> st;
	st.push(x);
	chuaxet[x]=0;
	vector<int> v;
	v.push_back(x);
	while(!st.empty()){
		int s=st.top();
		st.pop();
		for(int i=0;i<a[s].size();i++){
			if(chuaxet[a[s][i]]){
				chuaxet[a[s][i]]=0;
				st.push(s);
				st.push(a[s][i]);
				v.push_back(a[s][i]);
			}
		}
	}
	return v.size();
}
int main(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
	cin >> n;
	vector<int> a[101], b[101];
	for(int i=1;i<=100;i++) chuaxet[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==1){
				a[i].push_back(j);
				b[i].push_back(j);
				b[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(DFS(a,i)!=n) ++cnt;
		for(int j=1;j<=n;j++) chuaxet[j]=1;
	}
	for(int i=1;i<=n;i++){
		if(DFS(b,i)!=n) ++dem;
		for(int j=1;j<=n;j++) chuaxet[j]=1;
	}
	if(cnt==0) cout << "1";
	else if(dem==0) cout << "2";
	else cout << "0";
}