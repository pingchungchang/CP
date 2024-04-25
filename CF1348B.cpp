#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	set<int> st;
	int arr[n];
	for(auto &i:arr)cin>>i,st.insert(i);
	if(st.size()>k){
		cout<<"-1\n";
		return;
	}
	cout<<k*n<<'\n';
	for(int i= 0;i<n;i++){
		for(int j = 0;j<k-st.size();j++)cout<<"1 ";
		for(auto &j:st)cout<<j<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
