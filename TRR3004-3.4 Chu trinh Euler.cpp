#include <bits/stdc++.h>
using namespace std;
int a[101][101], b[101][101], n;
int chuaxet[101];
int BFS(int i){
	queue<int> q;
	q.push(i);
	vector<int> v;
	v.push_back(i);
	chuaxet[i]=0;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int j=1;j<=n;j++){
			if(b[s][j]==1&&chuaxet[j]==1){
				b[j][s]=0;
				chuaxet[j]=0;
				q.push(j);
				v.push_back(j);
			}
		}
	}
	return v.size();
}
void EC(int x){
	stack<int> st;
	vector<int> v;
	st.push(x);
	while(!st.empty()){
		int s=st.top();
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[s][i]==1) ++cnt;
		}
		if(cnt){
			for(int i=1;i<=n;i++){
				if(a[s][i]==1){
					st.push(i);
					a[s][i]=0;
					break;
				}
			}
		}
		else{
			v.push_back(st.top());
			st.pop();
		}
	}
	for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
}
int main(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);
	int t; cin >> t;
	for(int i=1;i<=100;i++) chuaxet[i]=1;
	if(t==1){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
				if(a[i][j]==1){
					b[i][j]=1;
					b[j][i]=1;
				}
			}
		}
		map<int,int> mp, ma;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==1){
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
		if(BFS(1)==n){
			if(cnt==n) cout << "1";
		    else if(cnt1==1&&cnt2==1&&cnt==n-2) cout << "2";
		    else cout << "0";
		}
		else if(BFS(1)!=n) cout << "0";
	}
	else{
		cin >> n;
		int k; cin >> k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> a[i][j];
			}
		}
		EC(k);
	}	
}