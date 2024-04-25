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
	vector<pii> v;
	for(int i = 1;i<=n;i++){
		int C = 0;
		for(int j = 1;j<=n;j++){
			char c;
			cin>>c;
			if(c == 'o')C++;
		}
		v.push_back({C,-i});
	}
	sort(v.rbegin(),v.rend());
	for(auto &i:v)cout<<-i.sc<<' ';
	return 0;
}
