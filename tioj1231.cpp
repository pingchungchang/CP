#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pii arr[n];
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
	}
	sort(arr,arr+n);
	int lim;
	cin>>lim;
	reverse(arr,arr+n);
	set<int> st;
	for(int i = 1;i<=min(lim,n*2);i++)st.insert(i);
	pii p = {0,0};
	for(auto &i:arr){
		auto it = st.upper_bound(i.sc);
		if(it == st.begin())continue;
		it--;
		p.fs += i.fs;
		p.sc++;
		st.erase(it);
	}
	cout<<p.fs-(lim-p.sc);
}
