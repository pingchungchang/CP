#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int N,Q;
vector<pii> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>Q;
	for(int i = N;i>=1;i--)v.push_back({i,0});
	while(Q--){
		int t;
		cin>>t;
		if(t == 1){
			auto now = v.back();
			char c;
			cin>>c;
			switch(c){
				case 'L':
					now.fs--;
					break;
				case 'R':
					now.fs++;
					break;
				case 'U':
					now.sc++;
					break;
				case 'D':
					now.sc--;
					break;
			}
			v.push_back(now);
		}
		else{
			int p;
			cin>>p;
			auto now = v.end()[-p];
			cout<<now.fs<<' '<<now.sc<<'\n';
		}
	}
	return 0;
}
