#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,k;
	cin>>n>>k;
	set<pair<int,int>> st;
	for(int i = 1;i<=n;i++){
		int t;
		cin>>t;
		st.insert(make_pair(t,i));
	}
	int t = 0;
	bool mv[n+1][n+1] = {};
	vector<pii> ans;
	while(t<k){
		auto it1 = --st.end();
		auto it2 = st.begin();
		if(it1->fs == it2->fs)break;
		ans.push_back(make_pair(it1->sc,it2->sc));
		st.insert(make_pair(it1->fs-1,it1->sc));
		st.insert(make_pair(it2->fs+1,it2->sc));
//		cout<<it1->fs<<' '<<it1->sc<<' '<<it2->fs<<' '<<it2->sc<<' '<<st.size()<<endl;
		st.erase(it1);
		st.erase(it2);
		t++;
	}
	cout<<st.rbegin()->fs-st.begin()->fs<<' '<<t<<'\n';
	for(auto i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}

