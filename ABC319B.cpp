#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string ans = "1";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=9;j++){
			if(n%j == 0&&i%(n/j) == 0){
				ans += '0'+j;
				break;
			}
			if(j == 9)ans += '-';
		}
	}
	cout<<ans;
}
