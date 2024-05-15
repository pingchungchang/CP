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
	int N;
	cin>>N;
	vector<int> v(N);
	for(auto &i:v)cin>>i;
	for(int i = 1;i<N;i++){
		if(v[i]>v[0]){
			cout<<i+1<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}
