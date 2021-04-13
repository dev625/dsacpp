#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node*left,*right;
    Node(int x)
    {
        this->val = x;
        this->left=this->right=nullptr;
    }   
};

bool findpath(Node*root,vector<Node*>&v,int n)
{
    if(root==nullptr)
        return false;
    v.push_back(root);
    if(root->val==n)
        return true;
    if(findpath(root->left,v,n)||findpath(root->right,v,n))
        return true;
    v.pop_back();
    return false;
}

Node*lca(Node*root,int n1,int n2)
{
    vector<Node*>path1,path2;
    if(!findpath(root,path1,n1) || !findpath(root,path2,n2))
        return nullptr;
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
    {
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    }
    return nullptr;
    
}