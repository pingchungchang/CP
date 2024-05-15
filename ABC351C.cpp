#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int N;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	while(N--){
		int k;
		cin>>k;
		while(!v.empty()&&v.back() == k){
			k++;
			v.pop_back();
		}
		v.push_back(k);
	}
	cout<<v.size()<<'\n';
	return 0;
}
