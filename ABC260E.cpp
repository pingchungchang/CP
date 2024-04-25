#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 2e5+10;
int ans[mxn];
int main(){
	io
	int n,m;
	cin>>n>>m;
	pii arr[n+1];
	multiset<pii> st;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		if(arr[i].fs>arr[i].sc)swap(arr[i].fs,arr[i].sc);
		st.insert({arr[i].fs,i});
	}
	bool flag = false;
	for(int i = 1;i<=m;i++){
		while(st.begin()->fs<i){
			int pos = st.begin()->sc;
			st.erase(st.find(*st.begin()));
			if(arr[pos].sc<i){
				flag = true;
				break;
			}
			else{
				st.insert({arr[pos].sc,pos});
			}
		}
		if(flag)break;
		ans[st.rbegin()->fs-i+1]++;
		ans[m-i+2]--;
	}
	for(int i = 1;i<=m;i++){
		ans[i] += ans[i-1];
		cout<<ans[i]<<' ';
	}
}

