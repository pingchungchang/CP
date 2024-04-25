#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	string B = "FastestFinger",A = "Ashishgup";
	if(n == 1)cout<<B;
	else if(n&1)cout<<A;
	else if(n == 2)cout<<A;
	else{
		map<int,int> mp;
		bool flag = true;
		while(flag){
			flag = false;
			for(int i = 2;i*i<=n;i++){
				if(n%i == 0){
					mp[i]++;
					n/=i;
					flag = true;
					break;
				}
			}
		}
		if(n != 1)mp[n]++;
		int cnt = 0;
		for(auto &i:mp)if(i.fs != 2)cnt+=i.sc;
		if(mp.size() == 1)cout<<B;
		else if(mp[2]>1){
			cout<<A;
		}
		else{
			if(cnt == 1)cout<<B;
			else cout<<A;
		}
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
