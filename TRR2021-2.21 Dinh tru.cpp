//Input
//5
//0 1 0 0 0
//1 0 1 0 0
//0 1 0 1 1
//0 0 1 0 1
//0 0 1 1 0
//Output
//2
//2 3
#include <bits/stdc++.h>
using namespace std;
int c[101][101], n;
int chuaxet[101], cnt=0, dem=0, cnt1=0;
vector<int> a[101], v;
void DFS(int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1){	
		    DFS(a[i][j]);
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
			cin >> c[i][j];
			if(c[i][j]) a[i].push_back(j);
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
		int dem1=0;
		chuaxet[i]=0;
		for(int j=1;j<=n;j++){
			if(chuaxet[j]){
			    ++dem1;
			    DFS(j);
		    }
		}
		for(int j=1;j<=n;j++) chuaxet[j]=1;
		if(dem1>cnt){
			++cnt1;
			v.push_back(i);
		}
	}
	sort(v.begin(),v.end());
	cout << cnt1 << endl;
	for(auto x:v) cout << x << " ";
}