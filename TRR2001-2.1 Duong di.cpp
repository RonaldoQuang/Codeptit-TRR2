//Input
//1
//4 2 4
//0 1 0 1
//1 0 1 0
//0 1 0 1
//1 0 1 0

//2
//4 1 4
//0 0 1 0
//0 0 0 1
//0 1 0 1
//1 0 0 0
//Output
//2

//1 3 2 4
#include <bits/stdc++.h>
using namespace std;
void Try(vector<int> a[], int chuaxet[], int truoc[], int i){
	chuaxet[i]=0;
	for(int j=0;j<a[i].size();j++){
		if(chuaxet[a[i][j]]==1){
			truoc[a[i][j]]=i;
		    Try(a,chuaxet,truoc,a[i][j]);
		}
	}
}
int main(){ 
    freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
    int t; cin >> t;
    int n, x, y; cin >> n >> x >> y;
    int c[n+1][n+1], chuaxet[n+1], truoc[n+1];
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin >> c[i][j];
		}
	}
	vector<int> a[n+1];
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(c[i][j]==1){
    			a[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		chuaxet[i]=1;
		truoc[i]=0;
	}
	if(t==1){
	    int b[n+1][n+1];
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					b[i][j]+=c[i][k]*c[k][j];
				}
			}
		}
		cout << b[x][y];	
	}
	else{
		Try(a,chuaxet,truoc,x);
		if(truoc[y]==0) cout << "0";
		else{
			vector<int> v;
			int u=truoc[y];
			v.push_back(y);
			while(u!=0){
				y=u;
				u=truoc[y];
				v.push_back(y);
			}
			for(int i=v.size()-1;i>=0;i--){
				cout << v[i] << " ";
			}
		}
	}
}