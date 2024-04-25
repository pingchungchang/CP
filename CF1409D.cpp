#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

ll calc(ll n){
	ll re = 0;
	while(n){
		re += n%10;
		n/=10;
	}
	return re;
}
ll calc(string s){
	return calc(stoll(s));
}

void solve(){
	ll n,ss;
	cin>>n>>ss;
	if(calc(n)<=ss){
		cout<<"0\n";
		return;
	}
	string s = to_string(n);
	for(int i = s.size()-2;i>=0;i--){
		s[i+1] = '0';
		if(s[i] == '9')continue;
		s[i]++;
		if(calc(s)<=ss){
			cout<<stoll(s)-n<<'\n';
			return;
		}
	}
	for(auto &i:s)i = '0';
	s = "1"+s;
	cout<<(stoll(s)-n)<<'\n';

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
