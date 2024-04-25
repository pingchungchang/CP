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
		cout<<"done\n";
		return true;
	}
	return false;
}
int main(){
	io
	int n;
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
			if(!isempty()){
				cout<<*st.begin()<<'\n';
				st.erase(*st.begin());
			}
		}
		else {
			if(!isempty()){
				cout<<*st.rbegin()<<'\n';
				st.erase(*st.rbegin());
			}
		}
	}
}

