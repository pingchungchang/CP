#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	set<int> st;
	for(int i = 0;i<n;i++){
		cin>>v[i];
		st.insert(v[i]);
	}
	if(n == 1){
		cout<<-1<<'\n';
		return;
	}
	vector<int> ans(n);
	for(int i = 0;i<n;i++){
		ans[i] = -1;
		for(auto it:st){
			if(it != v[i]){
				ans[i] = it;
				st.erase(it);
				break;
			}
		}
		if(ans[i] == -1){
			ans[i] = *st.begin();
			swap(ans[i],ans[i-1]);
		}
	}
	for(auto i:ans)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

