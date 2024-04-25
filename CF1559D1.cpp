#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


const int mxn = 1e3+10;
int dsu[2][mxn];

int findroot(int r,int k){
	while(dsu[r][k] != k){
		dsu[r][k] = dsu[r][dsu[r][k]];
		k = dsu[r][k];
	}
	return k;
}
int main(){
	io
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i = 1;i<mxn;i++){
		dsu[0][i] = i;
		dsu[1][i] = i;
	}
	for(int i = 0;i<m1;i++){
		int a,b;
		cin>>a>>b;
		dsu[0][findroot(0,a)] = dsu[0][findroot(0,b)];
	}
	for(int i = 0;i<m2;i++){
		int a,b;
		cin>>a>>b;
		dsu[1][findroot(1,a)] = dsu[1][findroot(1,b)];
	}
	vector<pii> ans;
	for(int i  = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
//			cout<<i<<' '<<j<<endl;
			if(findroot(1,i) != findroot(1,j)&&findroot(0,i) != findroot(0,j)){
				dsu[1][findroot(1,i)] = dsu[1][findroot(1,j)];
				dsu[0][findroot(0,i)] = dsu[0][findroot(0,j)];
				ans.push_back(make_pair(i,j));
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		cout<<i.fs<<' '<<i.sc<<'\n';
	}
}

