ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode *dummy, *temp;
        dummy = temp = new ListNode();
        int carry=0, sum=0;
        while(list1!=nullptr || list2!=nullptr || carry){
            sum=0;
            if(list1!=nullptr){
                sum+=list1->val;
                list1 = list1->next;
            }
            if(list2!=nullptr){
                sum+=list2->val;
                list2 = list2->next;
            }
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            ListNode *node = new ListNode(sum);
            temp->next = node;
            temp = node;
        }
        temp->next = nullptr;
        return dummy->next;
    }