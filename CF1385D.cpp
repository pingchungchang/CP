#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n;
string s;

int f(char c,int l,int r){
	if(l == r){
		if(s[l] == c)return 0;
		else return 1;
	}
	int mid = (l+r)>>1;
	int s1 = 0;
	for(int i = l;i<=mid;i++)if(s[i] != c)s1++;
	int s2 = 0;
	for(int i = mid+1;i<=r;i++)if(s[i] != c)s2++;
	return min(f(c+1,l,mid)+s2,f(c+1,mid+1,r)+s1);
}

void solve(){
	cin>>n>>s;
	cout<<f('a',0,n-1)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
