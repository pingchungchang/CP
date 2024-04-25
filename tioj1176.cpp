#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	stack<int> st;
	st.push(0);
	vector<int> ans(n,0);
	for(int i = 1;i<n;i++){
		while(!st.empty()&&v[st.top()]<=v[i]){
			ans[st.top()] = i-st.top();
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()] = n-1-st.top();
		st.pop();
	}
	for(auto i:ans)cout<<i<<'\n';
	return 0;
}

