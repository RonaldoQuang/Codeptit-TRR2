#include<bits/stdc++.h>
using namespace std;
struct Canh{
	int u, v, w;
};
typedef struct Canh canh;
int n, k, dT=0, truoc[101], sz[101];
vector<canh> ve;
vector<pair<int,int>> v;
bool cmp(canh a, canh b){
	if(a.w==b.w){
		if(a.u==b.u) return a.v<b.v;
		return a.u<b.u; 
	}
	return a.w<b.w;
}
int find(int v){
	if(v==truoc[v]) return v;
	return find(truoc[v]);
}
bool unit(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b) return false;
	if(sz[a]<sz[b]) swap(a,b);
	truoc[b]=a;
	sz[a]+sz[b];
	return true;
}
void kruscal(canh a[]){
	int i=0;
	while(ve.size()<n-1&&v.size()>0){
		v.erase(v.begin()+i);
		if(unit(a[i].u,a[i].v)){
			dT+=a[i].w;
			ve.push_back({a[i].u,a[i].v,a[i].w});
		}
		++i;
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
	cin >> n >> k;
	canh a[k];
	for(int i=0;i<k;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		v.push_back({a[i].u,a[i].v});
	}
	for(int i=1;i<=n;i++){
		truoc[i]=i;
		sz[i]=1;
	}
	sort(a,a+k,cmp);
	kruscal(a);
}