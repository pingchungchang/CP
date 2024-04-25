#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int row[n+1],col[m+1];
	row[0] = col[0] = 0;
	for(int i = 1;i<=n;i++)cin>>row[i],row[i] += row[i-1];
	for(int i = 1;i<=m;i++)cin>>col[i],col[i] += col[i-1];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		if(k%i != 0)continue;
		int h = i,w = k/i;
		if(w>m)continue;
		ll c1 = 0,c2 = 0;
		for(int j = h;j<=n;j++){
			if(row[j]-row[j-h] == h)c1++;
		}
		for(int j = w;j<=m;j++){
			if(col[j]-col[j-w] == w)c2++;
		}
		ans += c1*c2;
	}
	cout<<ans;
}
