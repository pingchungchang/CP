#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll s;
	cin>>s;
	string ans;
	for(int i = 9;i>=1;i--){
		if(s<i){
			ans+=(char)('0'+s);
			break;
		}
		ans += (char)('0'+i);
		s -= i;
	}
	sort(ans.begin(),ans.end());
	cout<<stoll(ans)<<"\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

