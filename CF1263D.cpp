#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 27;
int dsu[mxn];

int root(int a){
	return a == dsu[a]?a:dsu[a] = root(dsu[a]);
}

void solve(){
	for(int i = 'a';i<='z';i++){
		dsu[i-'a'] = i-'a';
	}
	int n;
	cin>>n;
	set<char> st;
	string arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		string s = arr[i];
		for(auto &i:s){
			st.insert(i);
			dsu[root(i-'a')] = root(s[0]-'a');
		}
	}
	int ans = 0;
	for(int i = 'a';i<='z';i++){
		if(st.find(i) != st.end()&&dsu[i-'a'] == i-'a')ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
