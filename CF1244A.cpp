#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	for(int i = 0;i<=k;i++){
		int ta = c*i,tb = d*(k-i);
		if(ta>=a&&tb>=b){
			cout<<i<<' '<<k-i<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
