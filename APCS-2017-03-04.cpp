#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
int countused(int K,vector<int> places,int distance){
    int covered = 0;
    for(int i =0;i<places.size();i++){
        if(places[i]>covered){
            covered = distance + places[i];
        }
        K--;
    }
    return K;
}

int main(){
    int N,K;
    vector<int> places;
    cin>>N>>K;
    for(int i =0;i<N;i++){
        int j;
        cin>>j;
        places.push_back(j);
    }
    sort(places.begin(),places.end());
    int distance = places[places.size()-1]-places[0];
    while(1){
        int f = countused(K,places,distance);
        if(f>0){
            distance%=2;
        }
        else if(f<0){
            distance += distance/2;
        }
        else{
            if(countused(K,places,distance-1) <0) break;
        }
    }
    cout<<distance;
}
