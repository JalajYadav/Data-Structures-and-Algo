// this is code for Lecture No. 14 as taught by Striver in Striver Graph series

// the graph is supposed to be an unweighted graph 

// i think it is connected 

// agar disconnected hoga to kya hi matlab banega



#include<bits/stdc++.h>
using namespace std;


void bfs(vector<int> adj[],int src,vector<int>&dist){
    dist[src]=min(dist[src],0);
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int curr = q.front();q.pop();
        for(int ele:adj[curr]){
            dist[ele]=min(dist[ele] , (dist[curr]+1));
            if(dist[ele]==(dist[curr]+1)){
                q.push(ele);
            }
        }
    }
}
int main(){
    int V=0;
    cout<<"Enter the number of vertices : ";
    cin>>V;
    vector<int> adj[V];
    int x=0,y=0;
    for(int i=0;i<V;i++){
        cout<<"Enter no. of adjacent vertexes of vertex no. "<<i<<" : ";
        cin>>x;
        
        for(int j=0;j<x;j++){
            cin>>y;
            adj[i].push_back(y);
        }
    }
    vector<int>dist(V,INT_MAX);
    bfs(adj,0,dist);
    cout<<endl<<"==========================Result=========================="<<endl; 
    for(int ele:dist){
        cout<<ele<<" ";
    }
    return 0;
}