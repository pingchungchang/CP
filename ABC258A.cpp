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
	int k;
	cin>>k;
	int h = 21,m = 0;
	h += k/60;
	m += k%60;
	cout<<h<<":"<<(to_string(m).size() <2?"0":"")<<m<<'\n';
}

