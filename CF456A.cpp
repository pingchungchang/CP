#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<pii> v(n);
	for(int i = 0;i<n;i++)cin>>v[i].fs>>v[i].sc;
	sort(v.begin(),v.end());
	int big = 0;
	for(int i  =0;i<n;i++){
		if(v[i].sc<big){
			cout<<"Happy Alex";
			return 0;
		}
		big = max(big,v[i].sc);
		
	}
	cout<<"Poor Alex";
}

