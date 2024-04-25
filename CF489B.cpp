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
	vector<int> a(n);
	for(auto &i:a)cin>>i;
	int m;
	cin>>m;
	vector<int> b(m);
	for(auto &i:b)cin>>i;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int p1 = 0,p2 = 0;
	int ans = 0;
	while(p1 != n&&p2 != m){
		if(abs(a[p1]-b[p2]) <= 1){
			ans++;
			p1++;
			p2++;
		}
		else if(a[p1]>b[p2])p2++;
		else p1++;
	}
	cout<<ans;
}

