//Cho đồ thị vô hướng có trọng số G=<V, E, W>. 
//Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.
//Input
//1
//6 9
//1 2 12
//1 3 4
//2 3 1
//2 4 5
//2 5 3
//3 5 2
//4 5 3
//4 6 10
//5 6 8
//Ouput
//18
#include <bits/stdc++.h>
using namespace std;
struct Canh{
	int u, v, g;
};
typedef struct Canh canh;
int n, a[101][101], dT=0;
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
void kruscal(){
	for(auto x:v){
		if(!vs[x.u]||!vs[x.v]){
			dT+=x.g;
			vs[x.u]=vs[x.v]=true;
			v1.push_back({x.u,x.v,x.g});
		}
	}
	if(v1.size()==n-1){
		cout << dT << endl;
	    for(auto x:v1) cout << x.u << " " << x.v << " " << x.g << endl;
	}
	else cout << 0;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]>0&&a[i][j]<=50&&i<j) v.push_back({i,j,a[i][j]}); 
		}
	}
	sort(v.begin(),v.end(),cmp);
	kruscal();
}