#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
set<ll> st;

bool isempty(){
	if(st.empty()){
		cout<<"error\n";
		return true;
	}
	return false;
}
int main(){
	io
	ll n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		if(t == 1){
			ll k;
			cin>>k;
			st.insert(k);
		}
		else if(t == 2){
			ll k;
			cin>>k;
			if(st.find(k) == st.end())cout<<"error\n";
			else st.erase(k);
		}
		else if(t == 3){
			cout<<st.size()<<'\n';
		}
		else if(t == 4){
			if(!isempty())cout<<*st.begin()<<'\n';
		}
		else if(t == 5){
			if(!isempty())cout<<*st.rbegin()<<'\n';
		}
	}
	return 0;
}

