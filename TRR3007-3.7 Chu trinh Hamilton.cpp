#include<bits/stdc++.h>
using namespace std;
int n, u, cnt=0;
int b[101], vs[101];
vector<int> a[101];
void kq(){
	for(int i=1;i<=n;i++){
		cout << b[i] << " ";
	}
	cout << u << endl;
}
void hamilton(int i){
	int t=b[i-1];
	for(auto j:a[t]){
		if(i==n+1&&j==u){
			++cnt;
			kq();
		}
		else if(!vs[j]){
			vs[j]=1;
			b[i]=j;
			hamilton(i+1);
		    vs[j]=0;
		}
	}
}
int main(){
	freopen("CT.INP","r",stdin);
	freopen("CT.OUT","w",stdout);
	cin >> n >> u;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x; cin >> x;
			if(x) a[i].push_back(j);
		}
	}
	b[1]=u;
	vs[u]=1;
	hamilton(2);
	cout << cnt << endl;
}
