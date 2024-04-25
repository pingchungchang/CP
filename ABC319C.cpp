#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
bool done[3][3] = {};
int arr[3][3];

bool check(){
	for(int i = 0;i<3;i++){
		int C = 0;
		map<int,int> mp;
		for(int j = 0;j<3;j++){
			if(!done[i][j]){
				C++;
				continue;
			}
			mp[arr[i][j]]++;
		}
		for(auto &i:mp){
			if(i.sc>1&&C)return false;
		}
		mp.clear();
		C = 0;
		for(int j = 0;j<3;j++){
			if(!done[j][i]){
				C++;
				continue;
			}
			mp[arr[j][i]]++;
		}
		for(auto &i:mp){
			if(i.sc>1&&C)return false;
		}
	}
	int C = 0;
	map<int,int> mp;
	for(int i = 0;i<3;i++){
		if(!done[i][i]){
			C++;
			continue;
		}
		mp[arr[i][i]]++;
	}
	for(auto &i:mp){
		if(i.sc>1&&C)return false;
	}
	mp.clear();C = 0;
	for(int i = 0;i<3;i++){
		if(!done[i][2-i]){
			C++;
			continue;
		}
		mp[arr[i][2-i]]++;
	}
	for(auto &i:mp){
		if(i.sc>1&&C)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:arr)for(auto &j:i)cin>>j;
	vector<pii> v;
	for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)v.push_back({i,j});
	int total = 0,ans = 0;
	do{
		total++;
		memset(done,0,sizeof(done));
		//for(auto &i:v)cout<<i.fs*3+i.sc<<' ';cout<<endl;
		for(auto &i:v){
			done[i.fs][i.sc] = true;
			if(!check()){
				ans++;
				break;
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	cout<<fixed<<setprecision(10)<<(double)(total-ans)/total;
}
