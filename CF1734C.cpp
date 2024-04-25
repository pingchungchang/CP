#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool arr[n+1];
	for(int i = 1;i<=n;i++)arr[i] = s[i-1]-'0';
	bool done[n+1] = {};
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j*i<=n;j++){
			if(!arr[j*i]){
				if(done[j*i])continue;
				else{
					ans += i;
					done[j*i] = true;
				}
			}
			else{
				break;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

