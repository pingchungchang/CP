#include <iostream>
#include <unordered_map>
#include <vector>
#include<algorithm>

using namespace std;

int main(){
    unordered_map<int,int> map;
    int N;
    cin>>N;
    vector<int> friends;
    int ans = 0;
    for(int i =0;i<N;i++){
        int a;
        cin>>a;
        friends.push_back(a);
    }
    for(int i =0;i<friends.size();i++){
        if(map.count(friends[i])==0){
            int j =friends[i];
            while(map.count(j)==0){
                map[j]=1;
                j = friends[j];
            }
            ans ++;
        }
    }
    cout<<ans;
}
