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
	char c;
	cin>>n>>c;
	string s;
	cin>>s;
	s+=s;
	int ans = 0;
	deque<int> dq;
	for(int i = 0;i<s.size();i++){
		if(s[i] == c)dq.push_back(i);
		else if(s[i] == 'g'){
			if(!dq.empty()){
				ans = max(ans,i-dq.front());
				dq.clear();
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

