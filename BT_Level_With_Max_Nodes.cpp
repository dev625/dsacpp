#include <iostream>
#include <queue>
using namespace std;

class node
{
    public:
        int data;
        node* left, *right;
        node(int data)
        {
            this->data = data;
            this->left = this->right = nullptr;
        }
};

int maxNodeLevel(node* root)
{
    if(root==nullptr)
        return -1;
    queue <node*> Q;
    Q.push(root);
    //current level
    int level = 0;
    //maximum nodes at the same level
    int max = INT64_MIN;
    //level having maximum number of nodes
    int level_no{0};
    while(1)
    {
        //count nodes in a specific level
        int NodeCount = Q.size();
        if(NodeCount==0)
            break; //this happens when the queue is empty
        if(NodeCount>max)
        {
            max = NodeCount;
            level_no = level;
        }
        //Pop the complete current level
        while(NodeCount>0) 
        {
            node * temp  = Q.front();
            Q.pop();
            if(temp->left)                /*Very Important Piece of Code*/
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
            NodeCount--;
        }
        //increment for next level
        level++;
    }
    return level_no;

}

/*Approach 2*/
int height(node* root)
{
    int x,y;
    if(root!=nullptr)
    {
        x = height(root->left);
        y = height(root->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
int nodes_in_level(node*node, int level)
{
    /*Recursive approach to count the number of nodes in a level, this function assumes 1 based indexing of levels */
    if(node==nullptr)
        return 0;
    if(level==1)
        return 1;
    else if(level>1)
    {
        return nodes_in_level(node->left,level-1)+nodes_in_level(node->right,level-1);
    }
}
int maxNodeLevel2(node *root)
{
    int h = height(root);  //gives 1 based height of root
    int maxnodes{1};            //minimum possible value of maximum number of nodes in particular level is 1
    int max_node_level{0};      //setting default value of max node level to 0 
    for(int i=1;i<=h;i++)      //checking all the levels
    {
        if(nodes_in_level(root,i)>maxnodes)
            {
                max_node_level = i-1;
                maxnodes = nodes_in_level(root,i);
            }
    }
    return max_node_level;
}
/*Approach2end*/
int main()
{
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right =  new node(7);
    cout << maxNodeLevel(root);
    cout << maxNodeLevel2(root);
}