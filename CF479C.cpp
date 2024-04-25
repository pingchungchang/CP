#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(int i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
	sort(v.begin(),v.end());
	int now = v[0].sc;
	for(int i = 0;i<n;i++){
		if(v[i].sc>=now)now = v[i].sc;
		else now = v[i].fs;
	}
	cout<<now;
	return 0;
}

