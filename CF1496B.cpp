#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,k;
	cin>>n>>k;
	multiset<int> st;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		st.insert(tmp);
	}
	int mex = 0,big = *st.rbegin();
	for(mex = 0;mex<n;mex++)if(st.find(mex) == st.end())break;
	if(big < mex)cout<<n+k<<'\n';
	else{
		while(k--&&st.find((big+mex+1)/2) == st.end()){
			st.insert((big+mex+1)/2);
			n++;
			big = max(big,*st.rbegin());
		}
		cout<<n<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

