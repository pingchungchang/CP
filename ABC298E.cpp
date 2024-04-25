#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
const ll mod = 998244353;
const ll mxn = 110;

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}

ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

ll dist[mxn][mxn][2];


int main(){
	int n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	dist[a][b][0] = 1;

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == n||j == n)continue;
			for(int k = 1;k<=p;k++){
				dist[min(n,i+k)][j][1] = mad(dist[min(n,i+k)][j][1],dist[i][j][0]*inv(p)%mod);
			}
			for(int k = 1;k<=q;k++){
				dist[i][min(n,j+k)][0] = mad(dist[i][min(n,j+k)][0],dist[i][j][1]*inv(q)%mod);
			}
		}
	}
	ll total = 0,win = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == n||j == n)total = mad(total,mad(dist[i][j][1],dist[i][j][0]));
			if(i == n)win = mad(win,mad(dist[i][j][1],dist[i][j][0]));
		}
	}
	cout<<win*inv(total)%mod;
	return 0;
}
