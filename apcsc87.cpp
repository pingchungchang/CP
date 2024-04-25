#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll

class Compare{
	public:
		bool operator()(tuple<int,int,int> a,tuple<int,int,int> b){
			ll d1 = get<0>(a)*get<0>(a)+get<1>(a)*get<1>(a)+get<2>(a)*get<2>(a);
			ll d2 = get<0>(b)*get<0>(b)+get<1>(b)*get<1>(b)+get<2>(b)*get<2>(b);
			if(d1 != d2)return d1>d2;
			else return a>b;
		}
};
main(){
	io
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,Compare> pq;
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		if(k == 1){
			ll a,b,c;
			cin>>a>>b>>c;
			pq.push(make_tuple(a,b,c));
		}
		else{
			if(pq.empty())cout<<"none\n";
			else{
				cout<<get<0>(pq.top())<<' '<<get<1>(pq.top())<<' '<<get<2>(pq.top())<<'\n';
				pq.pop();	
			}
		}
	}
}

