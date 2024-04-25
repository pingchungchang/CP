#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

set<pll> st;
const int inf = 1e9+10;
int ans = 0;
void split(int p){
	auto it = --st.upper_bound({p,inf});
	if(it->fs == p){
		return it;
	}
}
int main(){
	int n;
	cin>>n;
	ans = n;
	st.insert({1,n});
	while(q--){
		int l,r,t;
		cin>>l>>r>>t;
		if(t == 1){
			
		}
	}
}
/*
3
8
2 2 1
3 3 2
1 1 1
1 3 2
2 3 2
3 3 1
1 2 1
2 2 2

1 1 1
1 0 1
1 0 1
0 0 1
1 1 1
1 1 1
1 1 0
0 0 0
1 1 0
*/
