//Input
//1
//4 7
//1 2 1
//1 4 2
//2 3 3
//2 4 4
//3 1 5
//3 2 6
//4 3 7

//2
//4 7
//1 2 1
//1 4 2
//2 3 3
//2 4 4
//3 1 5
//3 2 6
//4 3 7
//Output
//1 2
//2 2
//2 2
//2 1

//4
//0 1 10000 2
//10000 0 3 4
//5 6 0 10000
//10000 10000 7 0
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t, n, k; cin >> t >> n >> k;
	int a[n+1][n+1]={};
	while(k--){
		int x, y, z; cin >> x >> y >> z;
		a[x][y]=z;
	}
	if(t==1){
	    map<int,int> mp, ma;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]>0&&a[i][j]<=50){
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
	    cout << n << endl;
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=n;j++){
	    		if(a[i][j]>0&&a[i][j]<=50||i==j) cout << a[i][j] << " ";
	    		else cout << 10000 << " ";
			}
			cout << endl;
		}
	}
}