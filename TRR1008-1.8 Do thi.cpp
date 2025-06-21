//Input
//1
//4
//2 2 4
//2 1 3
//1 2
//1 1

//2
//4
//2 2 4
//2 1 3
//1 2
//1 1
//Output
//2 2 1 1

//4 3
//1 2
//1 4
//2 3
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t, n; cin >> t >> n;
	int a[n+1][n+1]={};
	for(int i=1;i<=n;i++){
		int k; cin >> k;
		while(k--){
			int x; cin >> x;
			a[i][x]=1;
		}
	}
	if(t==1){
		for(int i=1;i<=n;i++){
			int cnt=0;
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1) ++cnt;
		    }
		    cout << cnt << " ";
	    }
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==1){
					++cnt;
					a[j][i]=0;
				}
			}
		}
		cout << n << " " << cnt << endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==1) cout << i << " " << j << endl;
			}
		}
	}
}