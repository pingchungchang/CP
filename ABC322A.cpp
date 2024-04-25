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
	string s;
	cin>>s;
	for(int i = 0;i+2<s.size();i++){
		if(s.substr(i,3) == "ABC"){
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
}
