#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


istream &operator>>(istream &in,pii &x){
	in>>x.fs>>x.sc;
	return in;
}

vector<int> ax,ay;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pii arr[6];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<6;i+=2)arr[i].fs--,arr[i].sc--;
	for(auto &i:arr)ax.push_back(i.fs),ay.push_back(i.sc),ax.push_back(i.fs+1),ay.push_back(i.sc+1);
	sort(ax.begin(),ax.end());
	ax.erase(unique(ax.begin(),ax.end()),ax.end());
	sort(ay.begin(),ay.end());
	ay.erase(unique(ay.begin(),ay.end()),ay.end());
	for(auto &i:arr){
		i.fs = lower_bound(ax.begin(),ax.end(),i.fs)-ax.begin();
		i.sc = lower_bound(ay.begin(),ay.end(),i.sc)-ay.begin();
		assert(i.fs>=0&&i.fs<ax.size());
		assert(i.sc>=0&&i.sc<ay.size());
	}
	vector<vector<int>> grid(ax.size(),vector<int>(ay.size(),0));
	//for(auto i:ax)cout<<i<<' ';cout<<endl;
	//for(auto i:ay)cout<<i<<' ';cout<<endl;
	for(int i = arr[2].fs;i<=arr[3].fs;i++)for(int j = arr[2].sc;j<=arr[3].sc;j++)grid[i][j] = 1;
	swap(arr[2],arr[4]);
	swap(arr[3],arr[5]);
	for(int i = arr[2].fs;i<=arr[3].fs;i++)for(int j = arr[2].sc;j<=arr[3].sc;j++)grid[i][j] = 1;
	bool flag = true;
	for(int i = arr[0].fs;i<=arr[1].fs;i++){
		for(int j = arr[0].sc;j<=arr[1].sc;j++)if(!grid[i][j])flag = false;
	}
	if(flag)cout<<"NO";
	else cout<<"YES";
}
