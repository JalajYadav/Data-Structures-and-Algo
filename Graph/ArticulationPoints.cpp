#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<int>&tin,vector<int>&low,vector<int>&vis,vector<int>&isArticulation,int &timer,int parent,int node){
        int child = 0;
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(int it : adj[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                child++;
                dfs(adj,tin,low,vis,isArticulation,timer,node,it);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] and parent!=-1){
                    isArticulation[node]=1;
                }
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(parent == -1 and child>1){
            isArticulation[node]=1;
        }
}
int main(){
    int nodes;
    cout<<"enter the number of Nodes ";
    cin>>nodes;


    int edges;
    cout<<"Enter the number of edges: ";
    cin>>edges;


    vector<int> adj[nodes];

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    // for(vector<int> v: adj){
    //     for(int e:v){
    //         cout<<e;
    //     }
    //     cout<<endl;
    // }
    vector<int> tin(nodes,-1);
    vector<int> low(nodes,-1);
    vector<int> vis(nodes,0);

    vector<int> isArticulation(nodes,0);

    int timer =0;
    for(int i =0;i<nodes;i++){
        cout<<"Dafaq";
        if(!vis[i]){
            cout<<"Dafaq3";
            dfs(adj,tin,low,vis,isArticulation,timer,-1,i);
        }
    }
    
    for(int i=0;i<nodes;i++){
        cout<<"Dafaq2";
        if(isArticulation[i]==1){
            cout<<"The Node "<<i<<" is an Articulation Point.";
        }
    }
    
    return 0;
}