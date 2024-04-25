#include <bits/stdc++.h>
using namespace std;

void solve(){
	string a;
	string b;
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	int p = 0;
	bool ans = false;
	for(int i = 2;i<=n;i+=2){
		if(a[i-1] == b[p]){
			i = i-1;
			p++;
		}
		if(p == m&&i == n-1){
			ans = true;
			break;
		}
	}
	p = 0;
	for(int i = 1;i<=n;i+=2){
		if(a[i-1] == b[p]){
			i--;
			p++;
		}
		if(p == m&&i == n-1){
			ans = true;
			break;
		}
	}
	if(ans)cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
} 

/*
ababababababababab
babababa
*/
