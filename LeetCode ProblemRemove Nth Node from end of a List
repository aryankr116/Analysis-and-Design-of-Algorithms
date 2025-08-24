struct ListNode* removeNthFromEnd(struct ListNode* head,
int n) {
struct ListNode* temp1=(head);
struct ListNode* temp2=(head);
for (int i=0;i<n;i++){
temp1=temp1->next;
}
if (head->next==NULL){
return NULL;
}
if(temp1==NULL){
head=head->next;
return head;
}
while(temp1->next!=NULL){
temp1=temp1->next;
temp2=temp2->next;
}
temp2->next=temp2->next->next;
return head;
}
