#include <bits/stdc++.h>
using namespace std;
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
		queue<int> q;
		q.push(x);
		chuaxet[x]=0;
		while(!q.empty()){
			int s=q.front();
			q.pop();
			for(int i=0;i<a[s].size();i++){
				if(chuaxet[a[s][i]]){
					chuaxet[a[s][i]]=0;
					q.push(a[s][i]);
					truoc[a[s][i]]=s;
				}
			}
		}
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