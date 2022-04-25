//  ██████╗ ███████╗████████╗███╗   ███╗██╗███╗   ██╗    ██╗███╗   ██╗     ██████╗  ██╗ ██╗██╗     ████████╗██╗███╗   ███╗███████╗
// ██╔════╝ ██╔════╝╚══██╔══╝████╗ ████║██║████╗  ██║    ██║████╗  ██║    ██╔═══██╗██╔╝███║╚██╗    ╚══██╔══╝██║████╗ ████║██╔════╝
// ██║  ███╗█████╗     ██║   ██╔████╔██║██║██╔██╗ ██║    ██║██╔██╗ ██║    ██║   ██║██║ ╚██║ ██║       ██║   ██║██╔████╔██║█████╗  
// ██║   ██║██╔══╝     ██║   ██║╚██╔╝██║██║██║╚██╗██║    ██║██║╚██╗██║    ██║   ██║██║  ██║ ██║       ██║   ██║██║╚██╔╝██║██╔══╝  
// ╚██████╔╝███████╗   ██║   ██║ ╚═╝ ██║██║██║ ╚████║    ██║██║ ╚████║    ╚██████╔╝╚██╗ ██║██╔╝       ██║   ██║██║ ╚═╝ ██║███████╗
//  ╚═════╝ ╚══════╝   ╚═╝   ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝    ╚═╝╚═╝  ╚═══╝     ╚═════╝  ╚═╝ ╚═╝╚═╝        ╚═╝   ╚═╝╚═╝     ╚═╝╚══════╝
// ██████╗ ██╗   ██╗████████╗     ██████╗  ██╗███╗   ██╗██╗     ███████╗██████╗  █████╗  ██████╗███████╗
// ██╔══██╗██║   ██║╚══██╔══╝    ██╔═══██╗██╔╝████╗  ██║╚██╗    ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝
// ██████╔╝██║   ██║   ██║       ██║   ██║██║ ██╔██╗ ██║ ██║    ███████╗██████╔╝███████║██║     █████╗  
// ██╔══██╗██║   ██║   ██║       ██║   ██║██║ ██║╚██╗██║ ██║    ╚════██║██╔═══╝ ██╔══██║██║     ██╔══╝  
// ██████╔╝╚██████╔╝   ██║       ╚██████╔╝╚██╗██║ ╚████║██╔╝    ███████║██║     ██║  ██║╚██████╗███████╗
// ╚═════╝  ╚═════╝    ╚═╝        ╚═════╝  ╚═╝╚═╝  ╚═══╝╚═╝     ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝╚══════╝
//

#include<bits/stdc++.h>
using namespace std;
class Stacker{
    stack <int> s;
    public:
    void push(int);
    void pop();
    void getMin();
};
stack <int> global_stk;
void Stacker :: push(int x){
    if(global_stk.empty() or global_stk.top()>x){
       global_stk.push(x);
   }
   s.push(x);
}
void Stacker:: pop(){
    if(s.empty() or global_stk.empty()){cout<<"EMpty Yaar";}
    if(s.top()==global_stk.top()){
       global_stk.pop();
   }
   cout<<s.top();
   s.pop();
}
void Stacker:: getMin(){
    if(s.empty() or global_stk.empty()){cout<<"EMpty Yaar";}
     
   cout<<global_stk.top();
}
void show(stack<int>&x){
    int sz = x.size();
    while(sz--){
        cout<<x.top();
        x.pop();
    }
}
int main(){

    int queryLength;
    cin>>queryLength;
    Stacker s;
    static int q;
    static int x;
    while (queryLength--)
    {
        cin>>q;
        if(q==1){
            cin>>x;
            s.push(x);
        }else if(q==2){
            s.pop();
        }else if(q==3){
            s.getMin();
        }else{
            cout<<"Enter 1 for push, 2 for pop,3 for getMin\n";
        }
    }
    return 0;
}