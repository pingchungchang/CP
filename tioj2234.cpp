#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

#define ll int
#define fs first
#define sc second
#define _all(T) T.begin(),T.end()
const int mxn = 1e6+10;

bitset<mxn> row,col,pp,mm;
vector<ll> allr,allc,allp,allm;
int n;
pair<ll,ll> arr[mxn];

inline void dis(vector<ll>&v){
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		allr.push_back(arr[i].fs);
		allc.push_back(arr[i].sc);
		allp.push_back(arr[i].fs+arr[i].sc);
		allm.push_back(arr[i].fs-arr[i].sc);
	}
	dis(allr);dis(allc);dis(allp);dis(allm);
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		auto p = lower_bound(_all(allr),arr[i].fs)-allr.begin();
		ans += row[p];
		row[p] = true;
		p = lower_bound(_all(allc),arr[i].sc)-allc.begin();
		ans += col[p];
		col[p] = true;
		p = lower_bound(_all(allp),arr[i].fs+arr[i].sc)-allp.begin();
		ans += pp[p];
		pp[p] = true;
		p = lower_bound(_all(allm),arr[i].fs-arr[i].sc)-allm.begin();
		ans += mm[p];
		mm[p] = true;
	}
	cout<<ans;
}
