#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int,int> locations;
vector<int> places;
void changeplace(int a,int b){
    int c = places[a];
    places[a] = a;
    locations[a] = a;
    places[b] = c;
    locations[c] = b;
}

int main(){
    int N;
    int ans = 0;
    cin>>N;
    places.push_back(0);
    for(int i = 1;i <=N;i++){
        int j;
        cin>>j;
        places.push_back(j);
        locations[j] = i;
    }
    for(int i =1;i<=N;i++){
        if(places[i] !=i){
            changeplace(i,locations[i]);
            ans++;
        }
    }
    cout<<ans;

}
