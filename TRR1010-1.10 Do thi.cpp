//Input
//1
//4
//0 1 10000 2
//1 0 3 10000
//10000 3 0 0
//2 10000 10000 0

//2
//4
//0 1 10000 2
//1 0 3 10000
//10000 3 0 0
//2 10000 10000 0
//Output
//2 2 1 1

//4 3
//1 2 1
//1 4 2
//2 3 3
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
			    if(a[i][j]>0&&a[i][j]<=50) ++cnt;
		    }
		    cout << cnt << " ";
	    }
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]>0&&a[i][j]<=50){
				    ++cnt;
				    a[j][i]=0;
				}
		    }
	    }
	    cout << n << " " << cnt << endl;
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=n;j++){
	    		if(a[i][j]>0&&a[i][j]<=50) cout << i << " " << j << " " << a[i][j] << endl;
			}
		}
	}
}