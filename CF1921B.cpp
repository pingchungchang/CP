#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	string a,b;
	cin>>n>>a>>b;
	int cnt[2] = {};
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])cnt[a[i]-'0']++;
	}
	cout<<max(cnt[0],cnt[1])<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
