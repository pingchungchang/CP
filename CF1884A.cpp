#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

inline bool check(int a,int b){
	int s = 0;
	while(a)s += a%10,a /=10;
	return s%b == 0;
}

void solve(){
	int n,k;
	cin>>n>>k;
	while(!check(n,k))n++;
	cout<<n<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
