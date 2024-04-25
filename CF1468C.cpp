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
const int mxn = 5e5+10;
int main(){
	io
	int q;
	set<pll> s1;
	set<ll> s2;
	ll cnt = 1;
	int pt = 1;
	bitset<mxn> done;
	done.reset();
	priority_queue<pii,vector<pii>,less<pii>> pq;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll m;
			cin>>m;
			pq.push(make_pair(m,-cnt));
			cnt++;
		}
		else if(t == 2){
			while(done[pt] == true)pt++;
			done[pt] = true;
			cout<<pt<<' ';
		}
		else{
			while(done[-pq.top().sc] == true)pq.pop();
			done[-pq.top().sc] = true;
			cout<<-pq.top().sc<<' ';
			pq.pop();
		}
	}
	return 0;
}

