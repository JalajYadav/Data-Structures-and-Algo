#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second,int weight){
        u=first;
        v=second;
        wt=weight;
    }
};

int main(){
    int nodes,edges;
    cout<<"Enter the number of nodes: ";
    cin>>nodes;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    //Remeber : If there is an undirected graph then it must be converted into directd graph by
    //splitting each edge into two directed edges, and in case if there is a -ve undirected edge
    //then on converting it to two directed edges a -ve cycle will come into existance which will
    //choke the bellman ford algorithm...
    cout<<"Enter directed edges in pair of u and v and wt : "<<endl;
    vector <node> edgelist;

    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edgelist.push_back(node(u,v,wt));
    }

    int src;
    cout<<"Enter the source node : ";
    cin>>src;
    cout<<endl;
    
    vector<int> dist(nodes,100000000);
    dist[src]=0;

    //Bellman Relaxation
    for(int i=1;i<=nodes-1;i++){
        for(node nd:edgelist){
            if(dist[nd.u]+nd.wt<dist[nd.v]){
                dist[nd.v]= dist[nd.u]+nd.wt;
            }
        }
    }   

    int flag = 1;
    for(node nd:edgelist){
        if(dist[nd.u]+nd.wt<dist[nd.v]){
            cout<<"Negative Cycle Exist in the Graph";
            flag=0;
            break;
        }
    }

    if(flag){
        for(int i=0;i<nodes;i++){
            cout<<"Min Dist to Reach "<<i<<" is "<<dist[i]<<endl;
        }
    }

    return 0;
}