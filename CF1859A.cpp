#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	set<int> st;
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
		st.insert(i);
	}
	sort(arr,arr+n);
	vector<int> a,b;
	for(int i = n-1;i>=0;i--){
		if(arr[i] == *st.rbegin())a.push_back(arr[i]);
		else b.push_back(arr[i]);
	}
	if(b.empty())cout<<"-1\n";
	else{
		cout<<b.size()<<' '<<a.size()<<'\n';
		for(auto &i:b)cout<<i<<' ';cout<<'\n';
		for(auto &i:a)cout<<i<<' ';cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
