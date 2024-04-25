#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e5+10;
int pref[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	string t;
	cin>>n>>t;
	string arr[n];
	for(auto &i:arr)cin>>i;
	int lp[n] = {},rp[n] = {};
	for(int i = 0;i<n;i++){
		int pt = 0;
		for(int j = 0;j<arr[i].size();j++){
			if(pt<=t.size()&&arr[i][j] == t[pt])pt++;
		}
		lp[i] = pt;
		pt = 0;
		for(int j = arr[i].size()-1;j>=0;j--){
			if(pt<=t.size()&&arr[i][j] == t[t.size()-1-pt])pt++;
		}
		rp[i] = pt;
		pref[pt]++;
	}
	for(int i = 1;i<mxn;i++)pref[i] += pref[i-1];
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(lp[i] == t.size())ans += pref[mxn-1];
		else ans += pref[mxn-1]-pref[t.size()-1-lp[i]];
	}
	cout<<ans;
}
