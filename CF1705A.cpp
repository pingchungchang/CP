#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> v(2*n);
	for(int i = 0;i<n*2;i++)cin>>v[i];
	sort(v.begin(),v.end());
	multiset<int> st;
	for(int i = n;i<2*n;i++)st.insert(v[i]);
	for(int i = 0;i<n;i++){
		if(v[i]+x>*st.begin()){
			cout<<"NO\n";
			return;
		}
		st.erase(st.begin());
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

