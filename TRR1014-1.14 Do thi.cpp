//Input
//1
//4
//0 1 0 1
//0 0 1 1
//1 1 0 0
//0 0 1 0

//2
//4
//0 1 0 1
//0 0 1 1
//1 1 0 0
//0 0 1 0
//Output
//1 2
//2 2
//2 2
//2 1

//4 7
//1  1  0  0 -1  0  0
//-1 0  1  1  0 -1  0
//0  0 -1  0  1  1 -1
//0 -1  0 -1  0  0  1
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
	int t, n; cin >> t >> n;
	int a[n+1][n+1]={};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
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
		int cnt=0, dem=0;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1){
				    ++cnt;
				}
		    }
	    }
	    int b[cnt][n];
	    cout << n << " " << cnt << endl;
	    for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(a[i][j]==1){
			    	for(int k=1;k<=n;k++){
			    		if(k==i) b[dem][k-1]=1;
			    		else if(k==j) b[dem][k-1]=-1;
			    		else b[dem][k-1]=0;
					}
					++dem;
				}
		    }
	    }
	    for(int j=0;j<n;j++){
	    	for(int i=0;i<cnt;i++){
	    		cout << b[i][j] << " ";
			}
			cout << endl;
		}
	}
}