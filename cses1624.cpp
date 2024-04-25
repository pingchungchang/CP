#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<string> board(8);
int ans=0;
void recursive(pair<int,int> now,vector<int> used){
//	cout<<now.first<<' '<<now.second<<' ';
//	for(int i =0;i<used.size();i++)cout<<used[i]<<' ';
//	cout<<endl;
	if(used.size()==8){
		ans++;
		return;
	}
	if(now.second>=8)return;
	for(int i =0;i<used.size();i++){
		if(abs(now.first-i)== abs(now.second-used[i])){
			recursive(make_pair(now.first,now.second+1),used);
			return;
		}
		else if(now.second==used[i]){
			recursive(make_pair(now.first,now.second+1),used);
			return;
		}
	}
	recursive(make_pair(now.first,now.second+1),used);
	if(board[now.first][now.second] != '*'){
		used.push_back(now.second);
		recursive(make_pair(now.first+1,0),used);
	}
	return;
}

int main(){
	for(int i =0;i<8;i++)cin>>board[i];
	recursive(make_pair(0,0),vector<int>(0));
	cout<<ans;
}
