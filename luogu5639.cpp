#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int pre;
	cin>>pre;
	int ans = 1;
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		ans += (k != pre);
		pre = k;
	}
	cout<<ans;
}
