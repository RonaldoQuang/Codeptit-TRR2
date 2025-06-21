#include <bits/stdc++.h>
using namespace std;
#define null -1
int n, x, y, z, m=-1e9;
int a[105][105], d[105][105], tsugi[105][105];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					tsugi[i][j]=tsugi[i][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&d[i][j]>m&&d[i][j]!=1e4){
				x=i;
				y=j;
				z=d[i][j];
				m=d[i][j];
			}
		}
	}
}
void path(){
	if(tsugi[x][y]==null) cout << 0;
	else{
		cout << x << " " << y << " " << z << endl;
		vector<int> v;
		v.push_back(x);
		while(x!=y){
			x=tsugi[x][y];
			v.push_back(x);
		}
		for(auto x:v) cout << x << " ";
	}
}
int main(){
	freopen("DN.INP","r",stdin);
	freopen("DN.OUT","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			d[i][j]=a[i][j];
			if(a[i][j]>0&&a[i][j]<=50) tsugi[i][j]=j;
			else tsugi[i][j]=null;
		}
	}
	floyd();
	path();
}