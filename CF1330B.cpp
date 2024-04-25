#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int l1 = *max_element(arr,arr+n);
	if(l1>=n){
		cout<<"0\n";
		return;
	}

	set<int> st;
	vector<pii> ans;
	bool flag = true;
	for(int i = 0;i<l1;i++)st.insert(arr[i]);
	for(int i = 1;i<=l1;i++)if(st.find(i) == st.end())flag = false;
	st.clear();
	for(int i = l1;i<n;i++)st.insert(arr[i]);
	for(int i = 1;i<=n-l1;i++)if(st.find(i) == st.end())flag = false;
	if(flag)ans.push_back({l1,n-l1});

	st.clear();
	flag = true;
	l1 = n-l1;
	for(int i = 0;i<l1;i++)st.insert(arr[i]);
	for(int i = 1;i<=l1;i++)if(st.find(i) == st.end())flag = false;
	st.clear();
	for(int i = l1;i<n;i++)st.insert(arr[i]);
	for(int i = 1;i<=n-l1;i++)if(st.find(i) == st.end())flag = false;
	if(flag)ans.push_back({l1,n-l1});

	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
