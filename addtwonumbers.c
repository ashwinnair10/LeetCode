typedef struct ListNode* node;
node create(int k){
    node temp=(node)malloc(sizeof(struct ListNode));
    temp->val=k;
    temp->next=NULL;
    return temp;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* t1=l1;
    struct ListNode* t2=l2;
    int c=0,s;
    node head=NULL;
    node tail=NULL;
    while(t1!=NULL||t2!=NULL){
        if(t1!=NULL&&t2!=NULL)
        s=t1->val+t2->val+c;
        else if(t1==NULL)
        s=t2->val+c;
        else
        s=t1->val+c;
        if(s<=9){
            c=0;
            if(head==NULL){
                head=create(s);
                tail=head;
            }
            else{
                tail->next=create(s);
                tail=tail->next;
            }
        }
        else{
            c=1;
            if(head==NULL){
                head=create(s%10);
                tail=head;
            }
            else{
                tail->next=create(s%10);
                tail=tail->next;
            }
        }
        if(t1!=NULL)
        t1=t1->next;
        if(t2!=NULL)
        t2=t2->next;
    }
    if(c)
    tail->next=create(1);
    return head;
}