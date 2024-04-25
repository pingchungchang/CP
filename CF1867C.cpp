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
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	int mex = 0;
	for(;mex<n*2+1&&st.find(mex) != st.end();mex++);
	cout<<mex<<endl;
	int re;
	while(cin>>re){
		if(re == -1)return;
		else if(re == -2)exit(0);
		cout<<re<<endl;
	}
	assert(false);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
