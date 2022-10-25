#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int v;cin >> v;
    int adj[v+1][v+1];
    for(int i = 0;i <= v;i++){
        for(int j = 0;j <= v;j++){
            adj[i][j] = 0;
        }
    }

    int e;cin >> e;
    for(int i = 0;i < e;i++){
        int a,b,w;cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
    }

    int parent[v+1];
    for(int i = 0;i <= v;i++)
       parent[i] = -1;

    bool mst[v+1];
    for(int i = 0;i <= v;i++){
        mst[v] = false;
    }   

    int key[v+1];
    for(int i = 0;i <= v;i++)
        key[i] = INT_MAX;

    key[1] = 0;
    int count = v;
    while(count--){

        int minKey = INT_MAX,minVertex = 1;
        for(int i = 1;i <= v;i++){
            if((!mst[i])&&(key[i] < minKey)){
                minKey = key[i];
                minVertex = i;
            }
        }

        mst[minVertex] = true;
        
        for(int i = 1;i <= v;i++){
            if((adj[minVertex][i])&&(!mst[i])&&(key[i] > adj[minVertex][i])){
                parent[i] = minVertex;
                key[i] = adj[minVertex][i];
            }
        }
    }

    for(int i = 1;i <= v;i++){
        cout << i << " " << parent[i] << endl;
    }   
    return 0;
}