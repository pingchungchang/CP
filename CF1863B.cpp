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
		if(st.find(i-1) != st.end()){
			st.erase(i-1);
		}
		st.insert(i);
	}
	cout<<(int)st.size()-1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
