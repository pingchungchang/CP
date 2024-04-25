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
	string s;
	cin>>n>>s;
	ll sum = 0;
	for(auto &i:s)sum += i-'0';
	string ans;
	ll carry = 0;
	for(auto it = s.rbegin();it != s.rend();it++){
		ans += '0'+(carry+sum)%10;
		carry = (carry+sum)/10;
		sum -= *it-'0';
	}
	sum+=carry;
	while(sum){
		ans += '0'+sum%10;
		sum/=10;
	}
	while(ans.back() == '0')ans.pop_back();
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
