#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll x;
	ll y;
	mutable deque<ll> dq;
	node(ll a,ll b){
		x = a,y = b;
	}
	node(){
		x = y = INT_MAX;
	}
	bool operator<(const node &b)const{
		if(x*x+y*y != b.x*b.x+b.y*b.y)return x*x+y*y<b.x*b.x+b.y*b.y;
		else if(x != b.x)return x<b.x;
		else return y<b.y;
	}
};
int main(){
	io
	ll n;
	cin>>n;
	set<node> st;
	while(n--){
		int t;
		cin>>t;
		if(t == 1){
			ll a,b,c;
			cin>>a>>b>>c;
			auto it = st.lower_bound(node(a,b));
			if(it != st.end()&&it->x == a&&it->y == b)it->dq.push_front(c);
			else{
				it = st.insert(node(a,b)).fs;
				it->dq.push_front(c);
			}
		}
		else if(t == 2){
			ll a,b,c;
			cin>>a>>b>>c;
			auto it = st.lower_bound(node(a,b));
			if(it != st.end()&&it->x == a&&it->y == b)it->dq.push_back(c);
			else{
				it = st.insert(node(a,b)).fs;
				it->dq.push_back(c);
			}
		}
		else if(t == 3){
			ll a,b;
			cin>>a>>b;
			auto it = st.lower_bound(node(a,b));
			node close;
			if(it != st.begin()){
				it--;
				close = node(it->x,it->y);
				it++;
			}
			if(it->x == a&&it->y == b&&it == st.end());
			else{
				if(it->x == a&&it->y == b)it++;
				if(abs(a*a+b*b-close.x*close.x-close.y*close.y)>abs(a*a+b*b-it->x*it->x-it->y*it->y))close = (*it);
			}
			auto it2 = st.lower_bound(close);
			it = st.insert(node(a,b)).fs;
			it->dq.push_front(it2->dq.front());
			it2->dq.pop_front();
			if(it2->dq.empty())st.erase(it2);
		}
		else if(t == 4){
			ll a,b;
			cin>>a>>b;
			auto it = st.lower_bound(node(a,b));
			node close;
			if(it != st.begin()){
				it--;
				close = node(it->x,it->y);
				it++;
			}
			if(it->x == a&&it->y == b&&it == st.end());
			else{
				if(it->x == a&&it->y == b)it++;
				if(abs(a*a+b*b-close.x*close.x-close.y*close.y)>abs(a*a+b*b-it->x*it->x-it->y*it->y))close = (*it);
			}
			auto it2 = st.lower_bound(close);
			it = st.insert(node(a,b)).fs;
			it->dq.push_back(it2->dq.back());
			it2->dq.pop_back();
			if(it2->dq.empty())st.erase(it2);			
		}
//		for(auto i:st){
//			cout<<i.x<<' '<<i.y<<": ";
//			for(int j = 0;j<i.dq.size();j++)cout<<i.dq[j]<<',';cout<<'\n';
//		}
//		cout<<'\n';
	}
	vector<pair<ll,node>> v;
	for(auto it:st){
		for(int i = 0;i<it.dq.size();i++){
			v.push_back(make_pair(it.dq[i],node(it.x,it.y)));
		}
	}
	sort(v.begin(),v.end());
	for(auto i:v){
		cout<<i.sc.x<<' '<<i.sc.y<<'\n';
	}
	return 0;
}

