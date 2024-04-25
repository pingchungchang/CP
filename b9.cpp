#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

int x,y,n,m;

ll mad(ll a,ll b){
	a += b;
	return a>=m?a-m:a;
}

vector<vector<ll>> mul(vector<vector<int>> a,vector<vector<int>> b){
	vector<vector<int>> re(a.size(),vector<int>(b[0].size(),0));
	for(int i = 0;i<x;i++){
		for(int j = 0;j<x;j++){
			for(int k = 0;k<x;k++){
				re[i][j] = mad(re[i][j],a[i][k]*b[k][j]%m);
			}
		}
	}
	return re;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x>>y>>n>>m;
	vector<vector<int>> p(x,vector<int>(x,0));
	auto now = p;
	for(int i = 0;i<x;i++)now[i][i] = 1;
	for(int i = 0;i<y;i++){
		int a,b,c;
		cin>>a>>b>>c;
		swap(a,b);
		p[a][b] = c;
	}
	while(n){
		if(n&1)now = mul(now,p);
		p = mul(p,p);
		n>>=1;
	}
	int arr[x];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<x;i++){
		ll total = 0;
		for(int j = 0;j<x;j++){
			total = mad(total,arr[j]*now[i][j]%m);
		}
		cout<<total<<'\n';
	}
	return 0;
}
