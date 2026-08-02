struct Node* open(struct Node* head){
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    while(temp2!=NULL && temp2->next!=NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if(temp1 == temp2)
        {
            return p = 1;
        }
    }
if(p=1){
    return true;
}
else{
    return false;
}
}