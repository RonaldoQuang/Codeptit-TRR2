#include <bits/stdc++.h>
using namespace std;
struct Canh{
	int u, v, g;
};
typedef struct Canh canh;
int n, s, a[101][101], dT=0;
vector<canh> v, v1;
vector<bool> vs(n+1,false);
bool cmp(canh a, canh b){
	if(a.g==b.g){
		if(a.u==b.u){
			return a.v<b.v;
		}
		return a.u<b.u;
	}
	return a.g<b.g;
}
void prim(){
	vs[s]=true;
	while(v1.size()<n-1){
		for(auto x:v){
			if((vs[x.u]&&!vs[x.v])||(!vs[x.u]&&vs[x.v])){
				dT+=x.g;
				v1.push_back({x.u,x.v,x.g});
				vs[x.u]=vs[x.v]=true;
				break;
			}
		}
	}
	if(v1.size()==n-1){
		cout << dT << endl;
	    for(auto x:v1) cout << x.u << " " << x.v << " " << x.g << endl;
	}
	else cout << 0;
}
int main(){
    freopen("CK.INP","r",stdin);
	freopen("CK.OUT","w",stdout);
	cin >> n >> s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]>0&&a[i][j]<=50&&i<j) v.push_back({i,j,a[i][j]}); 
		}
	}
	sort(v.begin(),v.end(),cmp);
	prim();
}