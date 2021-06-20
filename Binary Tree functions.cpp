//binary-tree
//#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
     int data;
     node* left;
     node* right;
};
void insert(node** root,int val){                                                            // Inserting a Node
  node *t= new node,*temp;
  t->data=val;
  t->left=NULL;
  t->right=NULL;
    if(*root==NULL)  *root=t;
    else if(!(*root)->left) (*root)->left=t;
    else if(!(*root)->right) (*root)->right=t;
    else {
     queue<node *> q;
     q.push(*root);
     while(!q.empty()){
       temp=q.front(); q.pop();
       if(!temp->left) {temp->left=t;break;}
       else if(!temp->right) {temp->right=t;break;}
       if(temp->left) q.push(temp->left);
       if(temp->right)q.push(temp->right);
     }
 }
}
void lo_display(node *root){                                                                   // Level Order Traversal 
  node *temp;
  queue<node *> q;
  if(root) q.push(root);
  else cout<<"empty!!"<<endl;
  while(!q.empty()){
    temp=q.front(); q.pop();
    cout<<temp->data<<" ";
    if(temp->left) q.push(temp->left);
    if(temp->right)q.push(temp->right);
  }
}
int maxi(node *root){                                                                         // Maximum element -- using recursion
  node *t=root;
  int m;
  if(root ==NULL)return INT_MIN;
  if(t->left==NULL && t->right== NULL) return t->data;
  else {
    m=max(maxi(t->left),maxi(t->right));
    return max(m,t->data);
  }
}
int mini(node* root){                                                                          // Minimum element --- Iterative       
  if (!root) return INT_MAX;
  node *temp;
  int min=INT_MAX;
   queue <node *> q;
   q.push(root);
    while(!q.empty()){
       temp=q.front();
       q.pop();
      if(temp->data < min) min=temp->data;
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
    return min;
}
node* search(node* root,int x){                                                              // Searching a Node
   if(!root) return NULL;
   //recursive:
   // else {  if(root->data==x) return root;
   //   else return(search(root->left,x)?search(root->left,x):search(root->right,x)); }
    node*temp;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
         temp=q.front(); q.pop();
         if(temp->data==x) return temp;
         if(temp->left) q.push(temp->left);
         if(temp->right) q.push(temp->right);
    }
    return NULL;
}
int main(){
  node* root = NULL;
  insert(&root,10);
  insert(&root,-20);
  insert(&root,30);
  insert(&root,40);
  insert(&root,50);
  insert(&root,60);
  insert(&root,-70);
  lo_display(root);
  getch();
  int c,x;
  while(1){                                                                                     // Menu driver Program
    system("CLS");
    cout<<"\nenter query :"<<endl;
    cout<<"1.insert \n2.delete \n3.display \n4.max and min element \n5.search \n6.size \n7.exit"<<endl;
    cin>>c;
    switch(c){
         case 1: cout<<"enter value : ";
                 cin>>x;
                 insert(&root,x);
                 getch();
           break;
         case 2: cout<<"del";
                 getch();
                 break;
         case 3: cout<<"level order : ";
                 lo_display(root); cout<<endl;
                 getch();
           break;
         case 4:  cout<<"maximum element : "<<maxi(root)<<endl;
                  cout<<"minimum element : "<<mini(root)<<endl;
                  getch();
           break;
         case 5:  cout<<"enter value to be searched: ";
                  cin>>x;
                  if(search(root,x)) cout<<"yes the value exists in the tree with node address: "<<search(root,x)<<endl;
                  else cout<<"This element does not exist in the tree"<<endl;
                  getch();
            break;
         case 6: cout<<"size of the tree is :"<<size(root)<<endl;;
                    getch();
             break;
         case 7: exit(0);
            break;
         default: cout<<"enter a valid query please!"<<endl;
           getch();
           break;
    }
  }
}
