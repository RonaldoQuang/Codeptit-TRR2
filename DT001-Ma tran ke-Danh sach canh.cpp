#include <bits/stdc++.h>
using namespace std;
int main(){
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
		int cnt=0;
		cout << n << " ";
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1){
				    ++cnt;
				    a[j][i]=0;
				}
		    }
	    }
	    cout << cnt << endl;
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1) cout << i << " " << j << endl;
		    }
	    }
	}
}