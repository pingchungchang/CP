#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	bitset<30> done;
	int n;
	cin>>n;
	string s;
	cin>>s;
	char now = s[0];
	for(auto &i:s){
		if(now != i){
			done[now-'a'] = true;
			now = i;
		}
		if(done[now-'a']){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YEs\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
