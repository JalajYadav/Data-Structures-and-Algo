#include<iostream>
#include"TreeNode.h"
#include<queue>
#include<map>
using namespace std; 
// Here we are taking input by recirion 
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;

    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter number of Children"<<rootData<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        TreeNode<int>*child = takeInput();
        root->children.push_back(child);
    }
return root;
}

//Here we would be taking data throudh level order traversal
TreeNode<int>*takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data"<<endl;
    cin>>rootData;
    TreeNode <int>*root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i =0;i<numChild;++i){
            int chilData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>chilData;
            TreeNode<int>* child=new TreeNode<int>(chilData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

//No fo Nodes int the treee
int numNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans = 1;
    for(int i =0;i<root->children.size();++i){
       ans = ans + numNodes(root->children[i]);
    }
    return ans;
}
int height(TreeNode<int>*root){
    int ans = 1;
    int mx_height=0;
    for(int i = 0;i<root->children.size();++i){
        mx_height=max(mx_height,height(root->children[i]));
    }
    return (ans+mx_height);
}
void deleteTree(TreeNode<int>* root){
    for(int i = 0;i<root->children.size();++i){
        deleteTree(root->children[i]);
    }
    delete root;
}
void printAtDepthLevelK(TreeNode<int>*root,int k){
    if(root==NULL)
    return;
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i = 0;i<root->children.size();++i){
        printAtDepthLevelK(root->children[i],k-1);
    }

}
void printTree(TreeNode<int>*root){
    if(root==NULL)
    return;

    cout<<root->data<<": ";
    for(int i = 0;i<root->children.size();i++){
       cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main(){
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode <int>* root = takeInputLevelWise();
    printTree(root);

    cout<<"Total No of Nodes is "<<numNodes(root)<<endl;
    //I consider base as 1 while calc. height
    cout<<"Height of Tree is "<<height(root)<<endl;
    
    cout<<"Print at Depth Level 2"<<endl;
    printAtDepthLevelK(root,2);
    

    //Deletion Can be performed in 2 ways withthe custom delete function or by creating a destructor for TreeNode header file
    /* 1 */deleteTree(root);
    // Destructor for TreenNode Header File
    /* 2 */delete root;


 //Sample Input   
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
}