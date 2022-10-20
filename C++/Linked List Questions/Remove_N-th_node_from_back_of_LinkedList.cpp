// 2 traversal
ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0, till;
        ListNode *curr = head, *prev = head;
        while(curr!=nullptr){
            len++;
            curr=curr->next;
        }
        till = len-n;
        for(int i=1; i<till; i++){
            prev = prev->next;
        }
        if(till==0){
            ListNode *temp = head;
            head = head->next;
            delete(temp);
            return head;
        }
        ListNode *temp = prev->next;
        prev->next = temp->next;
        delete(temp);
        return head;
    }
//1 traversal
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *d = new ListNode(0), *fast, *slow;
        d->next = head;
        slow = d, fast = d;
        for(int i=1; i<=n; i++){
            fast = fast->next; 
        }
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return d->next;   
    }    