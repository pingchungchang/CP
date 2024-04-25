#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i = 0;i<n;i++){
		cin>>s;
		int l = 0;
		int ans = 0;
		for(int j = 0;j<s.size();j++){
			if(s[j] =='q'&&l>0){
				l--;
				ans++;
			}
			else if(s[j] == 'p')l++;
		}
		cout<<ans<<'\n';
	}
}
