#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s;

void solve(){
	sort(s.begin(),s.end());
	do{
		cout<<s<<'\n';
	}while(next_permutation(s.begin(),s.end()));
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s)solve();
}
