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
	cin>>n;
	stack<int> st;
	set<int> s;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.push(k);
		s.insert(i+1);
	}
	vector<int> ans;
	stack<int> q;
	while(!st.empty()){
		while(st.top() != *s.rbegin()){
			q.push(st.top());
			s.erase(st.top());
			st.pop();
		}
		s.erase(st.top());
		q.push(st.top());
		st.pop();
		while(!q.empty()){
			ans.push_back(q.top());
			q.pop();
		}
	}
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

