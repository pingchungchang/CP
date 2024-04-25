#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
pii arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	vector<pii> v;
	vector<pii> t;
	for(int i = 1;i<=n;i++){
		if(t.empty()||t.back().sc<arr[i].fs||t.back().fs>arr[i].sc){
			v.push_back({i,i});
			t.push_back(arr[i]);
		}
		else{
			v.back().sc = i;
			t.back().fs = max(t.back().fs,arr[i].fs);
			t.back().sc = min(t.back().sc,arr[i].sc);
		}
	}
	cout<<v.size()<<'\n';
	for(int i = 0;i<v.size();i++)cout<<t[i].fs<<' '<<v[i].fs<<' '<<v[i].sc<<'\n';
	return 0;
}
