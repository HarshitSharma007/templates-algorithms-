//AVL Tree
#include<bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node* left;
  Node* right;
  int height;
  Node(int v){
    val=v;
    left=nullptr;
    right=nullptr;
    height=1;
  }
};
void lo_display(Node *root) //level order display
{
  Node *temp;
  queue<Node *> q;
  if(root) q.push(root);
  else cout<<"empty!!"<<endl;
  while(!q.empty()){
    temp=q.front(); q.pop();
    cout<<temp->val<<" ";
    if(temp->left)
     q.push(temp->left);
    if(temp->right)
    q.push(temp->right);
  }
}
void inorder(Node *root)    //inorder display-- sorted
{
if(root==NULL)
    return ;
else
{
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
}
Node* rightrot(Node *node) // right rotate
{
  Node* temp=node->left->right;
  node->left->right=node;
  node=node->left;
  node->right->left=temp;
    return node;
}
Node* leftrot(Node *node) // left rotate
{
  Node* temp=node->right->left;
  node->right->left=node;
  node=node->right;
  node->left->right=temp;
    return node;
}
int heightn(Node* n)  //calculate height of a node
{
  if(!n) return 0;
  else return n->height;
}
Node* insert(Node* root, int data)  //insert node
{
   if(!root) {root = new Node(data);
     return root;
   }
    if(root->val>data){
      if(!root->left) root->left= new Node(data);
      else root->left=insert(root->left,data);
     }
    else {
      if(!root->right) root->right= new Node(data);
      else root->right=insert(root->right,data);
    }
    root->height=1+max(heightn(root->left),heightn(root->right));
    int bf;
    if(!root->left&&!root->right) bf=0;
    else if(!root->left) bf=0-root->right->height;
    else if(!root->right) bf=root->left->height;
    else bf=root->left->height-root->right->height;

    if(bf>1 && data<root->left->val){
      root=rightrot(root); //ll
    }

    if(bf>1 && data>root->left->val){ //lr
        root->left==leftrot(root->left);
        root=rightrot(root);
    }

    if(bf<-1 && data>root->right->val){
        root=leftrot(root); //rr
    }
    if(bf<-1 && data<root->right->val){
          root->right=rightrot(root->right);
          root=leftrot(root);//rl rotation
    }
      return root;
 }
int main(){
  cout<<"avl\n";
    Node* root= NULL;
    root=insert(root,10);
    root=insert(root,5);
    root=insert(root,25);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,22);
    root=insert(root,30);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,6);
    root=insert(root,9);
    root=insert(root,15);
    root=insert(root,24);
    root=insert(root,32);
    root=insert(root,1);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,19);
    root=insert(root,23);
    cout<<"inorder : ";
    inorder(root);
    cout<<endl;
    lo_display(root);
    cout<<endl;
  }
}
