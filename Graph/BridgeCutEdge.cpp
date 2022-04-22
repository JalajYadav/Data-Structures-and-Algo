#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<int>&vis,vector<int>&tin,vector<int>&low,int &timer,int node,int parent){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    for(int e:adj[node]){
        if(e==parent)continue;//this is the basic roll for dfs traversal on a graph

        else if(!vis[e]){
            dfs(adj,vis,tin,low,timer,e,node);
            low[node]=min(low[node],low[e]);
            if(low[e]>tin[node]){
                cout<<"Node"<<node<<" and eleNode "<<e<<" are a Bridge"<<endl;
            }    
        }
        else{
             low[node] = min(low[node], tin[e]); 
        }

    }
}

int main(){
    int nodes;
    cout<<"Enter the number of nodes: ";
    cin>>nodes;
    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    cout<<"Now Enter the edges that are connected u-v"<<endl;
    vector<int> adj[nodes];
    for(int i =0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(nodes,0);
    vector<int>tin(nodes,-1);//tin stands for time of insertion when we do a dfs walkover
    vector<int>low(nodes,-1);
    int timer = 0;
    for(int i=0;i<nodes;i++){
        if(vis[i]==0){
            dfs(adj,vis,tin,low,timer,i,-1);
        }
    }
    
    return 0;
}