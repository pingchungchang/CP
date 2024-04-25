#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n;
string s;
ll ans[mxn];

void solve(){
	cin>>n>>s;
	for(int i = 0;i<=n;i++)ans[i] = -1;
	deque<int> one;
	int zc = 0;
	ll sum = 0;
	for(int i = n-1;i>=0;i--){
		if(s[i] == '0'){
			zc++;
			if(!one.empty()){
				sum += one.front()-i;
				one.push_back(i);
				one.pop_front();
			}
			ans[zc] = sum;
		}
		else one.push_back(i);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
