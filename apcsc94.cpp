#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	ll n,m,q;
	cin>>n>>m>>q;
	vector<deque<int>> v(m+1);
	ll cnt = 0;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		for(int j = 0;j<k;j++){
			v[i].push_back(++cnt);
		}
	}
	while(q--){
		char t;
		cin>>t;
		if(t == 'q'){
			int k;
			cin>>k;
			v[k].pop_front();
		}
		else if(t == 'b'){
			int k;
			cin>>k;
			v[k+1].push_front(v[k].back());
			v[k].pop_back();
		}
		else if(t == 'd'){
			int k;
			cin>>k;
			v[k-1].push_back(v[k].front());
			v[k].pop_front();
		}
		else if(t == 'p'){
			int k;
			cin>>k;
			v[k].pop_back();
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<v[i].size()<<' ';
		for(auto j:v[i])cout<<j<<' ';cout<<'\n';
	}
	return 0;
}

