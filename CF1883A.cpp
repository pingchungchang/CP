#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	cin>>s;
	int ans = 0;
	int now = 1;
	for(int i = 0;i<4;i++){
		int tmp = s[i]-'0';
		if(tmp == 0)tmp = 10;
		ans += abs(now-tmp);
		now = tmp;
	}
	cout<<ans+4<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
