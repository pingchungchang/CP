#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 4e5+10;
int cnt[mxn];
set<pii> st;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q,x;
	cin>>q>>x;
	for(int i = 0;i<x;i++){
		st.insert({0,i});
	}
	for(int i = 0;i<q;i++){
		int k;
		cin>>k;
		st.erase(make_pair(cnt[k%x],k%x));
		cnt[k%x]++;
		st.insert(make_pair(cnt[k%x],k%x));
		auto big = *st.begin();
		cout<<big.fs*x+big.sc<<'\n';
	}
	return 0;
}
