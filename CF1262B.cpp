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
	for(auto &i:arr){
		cin>>i;
	}
	set<int> st;
	for(int i = 1;i<=n;i++)st.insert(i);
	int ans[n];
	ans[0] = arr[0];st.erase(arr[0]);
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1]){
			cout<<"-1\n";
			return;
		}
		else if(arr[i] >arr[i-1]){
			st.erase(arr[i]);
			ans[i] = arr[i];
		}
		else{
			ans[i] = *st.begin();
			st.erase(ans[i]);
		}
	}
	int p = 0;
	for(int i = 0;i<n;i++){
		p = max(p,ans[i]);
		if(p != arr[i]){
			cout<<"-1\n";
			return;
		}
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
