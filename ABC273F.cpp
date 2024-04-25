#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#define int ll
const ll inf = 1e18;
main(){
	io
	int n,x;
	cin>>n>>x;
	vector<pii> v[2];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(k>0)v[0].push_back({k,i});
		else v[1].push_back({k,i});
	}
	for(int i =1;i<=n;i++){
		int k;
		cin>>k;
		if(k>0)v[0].push_back({k,-i});
		else v[1].push_back({k,-i});
	}
	if(x>0)v[0].push_back({x,INT_MIN});
	else v[1].push_back({x,INT_MIN});
	sort(_all(v[0]));
	sort(_all(v[1]),greater<pll>());
//	for(auto &i:v){
//		for(auto &j:i)cout<<j.fs<<' '<<j.sc<<',';
//		cout<<endl;
//	}
//	return 0;
	int now = 0;
	short dir = 0;
	int p[2] = {0,0};
	int dist =0,ans = inf;
	set<int> st;
	int cnt = 0;
	bool done = false;
	while(!done&&cnt<=4){
		cnt++;
		while(p[dir] != v[dir].size()&&(st.find(v[dir][p[dir]].sc) != st.end()||v[dir][p[dir]].sc<0)){
			cnt = 0;
			dist += abs(now-v[dir][p[dir]].fs);
			now = v[dir][p[dir]].fs;
			st.insert(-v[dir][p[dir]].sc);
			if(v[dir][p[dir]].sc == INT_MIN){
				ans = min(ans,dist);
				done = true;
			}
			p[dir]++;
		}
		dir ^= 1;
	}
	st.clear();done = false;cnt = 0;p[0] = p[1] = now = dist = 0;
	while(!done&&cnt<=4){
		cnt++;
		while(p[dir] != v[dir].size()&&(st.find(v[dir][p[dir]].sc) != st.end()||v[dir][p[dir]].sc<0)){
			cnt = 0;
			dist += abs(now-v[dir][p[dir]].fs);
			now = v[dir][p[dir]].fs;
			st.insert(-v[dir][p[dir]].sc);
			if(v[dir][p[dir]].sc == INT_MIN){
				ans = min(ans,dist);
				done = true;
			}
			p[dir]++;
		}
		dir ^= 1;
	}
	if(ans >= inf)cout<<-1;
	else cout<<ans;	
}

