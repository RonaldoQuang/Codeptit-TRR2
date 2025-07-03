//Input
//5
//0 1 1 0 0
//1 0 1 0 0
//1 1 0 0 0
//0 0 0 0 1
//0 0 0 1 0
//Output
//2
//1 2 3
//4 5
#include <bits/stdc++.h>
using namespace std;
int chuaxet[101], n;
vector<int> a[101];
vector<vector<int>> v;
void DFS(vector<int> &ve, int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1){
		    ve.push_back(a[i][j]);	
		    DFS(ve,a[i][j]);
		}
	}
}
int main(){
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		int x; cin >> x;
    		if(x==1) a[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		chuaxet[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(chuaxet[i]==1){
			vector<int> ve;
			ve.push_back(i);
			++cnt;
			DFS(ve,i);
			v.push_back(ve);
		}
	}
	cout << cnt << endl;
	for(int i=0;i<v.size();i++){
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}				
}
