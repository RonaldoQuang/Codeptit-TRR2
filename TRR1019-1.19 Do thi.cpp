//Input
//1
//4
//2 2 4
//2 3 4
//2 1 2
//1 3

//2
//4
//2 2 4
//2 3 4
//2 1 2
//1 3
//Output
//1 2
//2 2
//2 2
//2 1

//4 7
//1 2
//1 4
//2 3
//2 4
//3 1
//3 2
//4 3
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
	    map<int,int> mp, ma;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1){
			    	mp[i]++;
			    	ma[j]++;
				}
		    }
	    }
	    for(int i=1;i<=n;i++){
	    	cout << ma[i] << " " << mp[i] << endl;
		}
	}
	else{
	    int cnt=0;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1) ++cnt;
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