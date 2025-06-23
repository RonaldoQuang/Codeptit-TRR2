#include<bits/stdc++.h>
using namespace std;
struct Canh{
	int u, v, w;
};
typedef struct Canh canh;
int n, s, dT=0;
int vs[101];
vector<canh> v, ve;
bool cmp(canh a, canh b){
	if(a.w==b.w){
		if(a.u==b.u) return a.v<b.v;
		return a.u<b.u; 
	}
	return a.w<b.w;
}
void prim(){
	vs[s]=1;
	while(ve.size()<n-1){
		for(auto x:v){
			if(!vs[x.u]&&vs[x.v]||vs[x.u]&&!vs[x.v]){
				dT+=x.w;
				vs[x.u]=vs[x.v]=1;
				ve.push_back({x.u,x.v,x.w});
				break;
			}
		}
	}
	if(ve.size()==n-1){
		cout << dT << endl;
		for(auto x:ve) cout << x.u << " " << x.v << " " << x.w << endl;
 	}
 	else cout << 0;
}
int main(){
	freopen("CK.INP","r",stdin);
	freopen("CK.OUT","w",stdout);
	cin >> n >> s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x; cin >> x;
			if(x>0&&x<=50) v.push_back({i,j,x});
		}
	}
	sort(v.begin(),v.end(),cmp);
	prim();
}