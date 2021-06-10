
Node* sortedMerge(Node* a, Node* b)  
{  
        Node * t=new   Node(0);
    Node * t2=t;
    while(a&&b){
        if(a->data<b->data){
            t->next=a;
            a=a->next;
            t=t->next;
        }
        else {
            t->next=b;
            b=b->next;
             t=t->next;
        }
    }
    while(a){
       t->next=a;
            a=a->next;
             t=t->next;
    }
    while(b){
          t->next=b;
            b=b->next;
             t=t->next;
    }
    
    return t2->next ;// code here
}  
