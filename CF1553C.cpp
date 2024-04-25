#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	string s;
	cin>>s;
	int ans = 10;
	int a = 0,b = 0;
	for(int i = 1;i<=10;i++){
		if(i%2 == 1&&s[i-1] != '0')a++;
		else if(i%2 == 0&&s[i-1] == '1')b++;
		if((10-i+1)/2<a-b){
			ans = min(ans,i);
			break;
		}
	}
	a = 0,b = 0;
	for(int i = 1;i<=10;i++){
		if(i%2 == 1&&s[i-1] == '1')a++;
		else if(i%2 == 0&&s[i-1] != '0')b++;
		if((10-i)/2<b-a){
			ans = min(ans,i);
			break;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

