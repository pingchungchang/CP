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
#define int128 __int128_t
void print(int128 k){
	string s;
	while(k>0){
		s += '0'+k%10;
		k/=10;
	}
	reverse(_all(s));
	cout<<s;
}
void solve(){
	ll n;
	cin>>n;
	int128 now = 1LL;
	while(n%now == 0)now<<=1;
//	cout<<now*(now+1)<<endl;
//	cout<<now<<endl;
	if((now>>1) == n)cout<<"-1\n";
	else if(now == 1)cout<<"2\n";
	else{
		if(now*(now+1)/2>n)now = n*2/(now);
		print(now);cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

