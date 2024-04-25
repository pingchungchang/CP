#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<int> pos;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	set<char> st;
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		char c;
		cin>>c;
		st.insert(c);
	}
	int ans = 0;
	int pre = -1;
	pos = {0};
	for(int i = 0;i<s.size();i++){
		if(st.find(s[i]) != st.end())pos.push_back(i);
	}
	for(int i = 1;i<pos.size();i++){
		ans = max(ans,pos[i]-pos[i-1]);
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

