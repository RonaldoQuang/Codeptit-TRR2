#include<bits/stdc++.h>
using namespace std;
const int null=-1;
int n, s, t, x, y, a[101][101], d[101][101], tiep[101][101], z=-1e9;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(d[u][k]+d[k][v]<d[u][v]){
					d[u][v]=d[u][k]+d[k][v];
					tiep[u][v]=tiep[u][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&d[i][j]>z&&d[i][j]!=1e4){
				z=d[i][j];
				x=i;
				y=j;
			}
		}
	}
}
void path(){
	if(tiep[x][y]==null) cout << 0;
	else{
		cout << x << " " << y << " " << z << endl;
		while(x!=y){
			cout << x << " ";
			x=tiep[x][y];
		}
		cout << y;
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
			if(a[i][j]>0&&a[i][j]<=50) tiep[i][j]=j;
			else tiep[i][j]=null;
		}
	}
	floyd();
	path();
}