#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
pii arr[mxn];
int n;
bitset<mxn> pick;
multiset<int> st;

inline bool f(int tar){
	pick.reset();
	st.clear();
	for(int i = n;i>=1;i--){
		if(arr[i].fs == 2)st.insert(arr[i].sc);
		else{
			if(st.find(arr[i].sc) != st.end())pick[i] = true,st.erase(st.find(arr[i].sc));
		}
		if(st.size()>tar)return false;
	}
	return st.empty();
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	int l = 0,r = n+1;
	while(l != r){
		int mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	if(l>n){
		cout<<-1;
		return 0;
	}
	f(l);
	cout<<l<<'\n';
	for(int i = 1;i<=n;i++)if(arr[i].fs == 1)cout<<pick[i]<<' ';
	return 0;
}
