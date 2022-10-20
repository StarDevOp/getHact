//Iterative
ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

//Recursive
ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *next = head->next;
        ListNode *new_head = reverseList(head->next);
        next->next = head;
        head->next=nullptr;
        return new_head;
    }