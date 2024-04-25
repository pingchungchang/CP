#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	deque<char> dq;
	string s;
	cin>>s;
	for(auto &i:s)dq.push_back(i);
	for(char c = 'a'+s.size()-1;c>='a';c--){
		if(dq.back() == c)dq.pop_back();
		else if(dq.front() == c)dq.pop_front();
		else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
