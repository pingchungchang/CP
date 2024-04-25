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
	int  n;
	cin>>n;
	int arr[n];
	int total = 0;
	for(auto &i:arr){
		cin>>i;
		total += i;
	}
	if(n&1){
		cout<<"-1\n";
		return;
	}
	int tar = 1;
	if(total<0)tar = -1;
	set<int> st;
	for(int i = 0;i<n;i++)st.insert(i);
	for(int i = 0;i<n-1;i++){
		if(st.find(i) == st.end())continue;
		else if(tar == arr[i]&&tar == arr[i+1]&&total != 0){
			total -= tar*2;
			st.erase(i+1);
		}
	}
	vector<pii> ans;
	for(int i = 0;i<n;i++){
		if(st.find(i) == st.end())ans.back().sc = i;
		else ans.push_back({i,i});
	}
//	for(auto &i:st)cout<<i<<' ';cout<<'\n';
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

