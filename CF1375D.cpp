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
	multiset<int> st;
	vector<int>ans;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		st.insert(arr[i]);
	}
	auto getmex = [&](){
		for(int i = 0;i<=n;i++){
			if(st.find(i) == st.end())return i;
		}
		assert(false);
	};
	auto check = [&](){
		for(int i = 0;i<n;i++)if(arr[i] != i)return i;
		return n;
	};
	int mex = getmex();
	int tar;
	while((tar = check()) != n){
		if(mex == n){
			ans.push_back(tar);
			st.erase(st.find(arr[tar]));
			arr[tar] = mex;
			st.insert(arr[tar]);
		}
		else{
			ans.push_back(mex);
			st.erase(st.find(arr[mex]));
			arr[mex] = mex;
			st.insert(arr[mex]);
		}
		mex = getmex();
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<1+i<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
