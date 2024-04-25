#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	bool flag = false;
	int n,T;
	cin>>n>>T;
	int arr[n];
	for(auto &i:arr){
		cin>>i;
	}
	set<int> st;
	for(auto &i:arr){
		if(i+i == T){
			cout<<flag<<' ';
			flag ^= 1;
			continue;
		}
		if(st.find(T-i) == st.end()){
			cout<<"1 ";
			st.insert(i);
		}
		else cout<<"0 ";
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
