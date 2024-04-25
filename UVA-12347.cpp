#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
void post_order(unordered_map<int,vector<int>>& map, int id){
    if(id != 0){
        post_order(map, map[id][1]);
        post_order(map, map[id][2]);
        cout << map[id][3]<<endl;
    }
}

int findparent(unordered_map<int, vector<int>>& map, int value,int position,int id){
    if(value>=map[position][3]){
        if(map[position][2]==0){
            map[position][2] = id;
            return position;
        }
        else{
            return findparent(map, value, map[position][2], id);
        }
    }
    else{
        if(map[position][1]==0){
            map[position][1] = id;
            return position;
        }
        else{
            return findparent(map, value, map[position][1], id);
        }
    }
}
int main(){
    unordered_map<int, vector<int>> map;
    int a;
    cin >> a;
    map[1].push_back(0);
    map[1].push_back(0);
    map[1].push_back(0);
    map[1].push_back(a);
    int k;
    int i = 2;
    while(cin>>k){
        map[i].push_back(findparent(map, k,1,i));
        for (int j = 0; j < 2;j++) map[i].push_back(0);
        map[i].push_back(k);
        i++;
    }
    post_order(map,1);
}