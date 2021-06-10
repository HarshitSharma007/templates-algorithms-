Node * merge (Node * a,Node * b){
    Node * t=new Node(0);
    Node * t2=t;
    while(a&&b){
        if(a->data<b->data){
            t->bottom=a;
            a=a->bottom;
            t=t->bottom;
        }
        else {
            t->bottom=b;
            b=b->bottom;
             t=t->bottom;
        }
    }
    while(a){
       t->bottom=a;
            a=a->bottom;
             t=t->bottom;
    }
    while(b){
          t->bottom=b;
            b=b->bottom;
             t=t->bottom;
    }
    
    return t2->bottom;
}
