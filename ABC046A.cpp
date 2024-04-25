#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bitset<101> bs;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c;
	cin>>a>>b>>c;bs[a] = bs[b] = bs[c] = true;
	cout<<bs.count();
}
