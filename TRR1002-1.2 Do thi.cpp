//Input
//1
//4
//0 1 0 1
//1 0 1 0
//0 1 0 0
//1 0 0 0

//2
//4
//0 1 0 1
//1 0 1 0
//0 1 0 0
//1 0 0 0
//Output
//2 2 1 1

//4
//2 2 4
//2 1 3
//1 2
//1 1
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t, n; cin >> t >> n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
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
		cout << n << endl;
		map<int,int> mp;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1){
				    mp[i]++;
				}
		    }
	    }
	    for(int i=1;i<=n;i++){
	    	cout << mp[i] << " ";
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1) cout << j << " ";
		    }
		    cout << endl;
	    }
	}
}