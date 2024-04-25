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
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	for(int i = *st.begin();i != *st.rbegin();i++){
		if(st.find(i) == st.end()){
			cout<<i;
			return 0;
		}
	}
	assert(false);
	return 0;
}
