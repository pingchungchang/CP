#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


bool ask(int now){
	cout<<now<<endl;
	int k;
	cin>>k;
	return k;
}
void solve(){
	int n,k;
	cin>>n>>k;
	int pre = 0;
	for(int i = 0;i<n;i++){
		if(ask(pre^i)){
			return;
		}
		pre = i;;
	}
	cout<<-1<<endl;
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}
