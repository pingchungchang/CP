#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int n,x;
bool calc(vector<int> v){
	sort(v.begin(),v.end());
	int s = 0;
	for(int i = 1;i+1<v.size();i++)s += v[i];
	return s>=x;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x;
	vector<int> v(n-1);
	for(auto &i:v)cin>>i;
	for(int i = 0;i<=100;i++){
		v.push_back(i);
		if(calc(v)){
			cout<<i;
			return 0;
		}
		v.pop_back();
	}
	cout<<-1;
}
