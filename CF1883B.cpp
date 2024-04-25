#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt[26] = {};
	for(auto &i:s)cnt[i-'a']++;
	for(auto &i:cnt){
		if((i&1)&&k){
			k--;
			i--;
		}
	}
	int od = 0;
	for(auto &i:cnt)od += i&1;
	if(od>1){
		cout<<"no\n";
		return;
	}
	else cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
