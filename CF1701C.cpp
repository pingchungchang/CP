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
	int n,m;
	cin>>m>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	set<tuple<int,int,int>> st;
	vector<int> cnt(m+1,0);
	if(m == 1){
		cout<<n<<'\n';
		return;
	}
	for(int i = 0;i<n;i++){
		cnt[v[i]]++;
	}
	for(int i = 1;i<=m;i++){
		st.insert(make_tuple(cnt[i],cnt[i],i));
	}
	while(get<0>(*st.begin())+2<=get<0>(*st.rbegin())){
		auto a= *st.begin();
		st.erase(*st.begin());
		auto b = *st.rbegin();
		st.erase(*st.rbegin());
		if(get<1>(b) == 0){
			st.insert(a);
			st.insert(b);
			break;
		}
		get<1>(b)--;
		get<0>(b)--;
		get<0>(a) += 2;
		st.insert(a);
		st.insert(b);
	}
//	for(auto i:st){
//		cout<<get<0>(i)<<' '<<get<2>(i)<<',';
//	}
	cout<<get<0>(*st.rbegin())<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

