//T/C: O(n+m) S/C: O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *d = new ListNode(0), *dd, *temp;
        dd = d;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
            temp = new ListNode(list1->val);
            list1=list1->next;
        }else{
            temp = new ListNode(list2->val);
            list2=list2->next;
            }
            dd->next = temp;
            dd = temp;
        }
        while(list1!=nullptr){
            temp = new ListNode(list1->val);
            list1=list1->next;
            dd->next = temp;
            dd = temp;
        }
        while(list2!=nullptr){
            temp = new ListNode(list2->val);
            list2=list2->next;
            dd->next = temp;
            dd = temp;
        }
        dd->next = nullptr;
        return d->next;
    }
//T/C: O(n+m) S/C: O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }else if(list2==nullptr){
            return list1;
        }
        ListNode* head, *tail;
        ListNode* dummy = new ListNode(0), *curr;
        curr = dummy;
        while(list1 && list2){
            if(list1->val<=list2->val){
                curr->next = list1;
                list1=list1->next;
                curr=curr->next;
            }else{
                curr->next = list2;
                list2=list2->next;
                curr=curr->next;
            }
        }
        if(list1){
            curr->next = list1;
        }else if(list2){
            curr->next = list2;
        }
        return dummy->next;
    }

    //OR
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }else if(list2==nullptr){
            return list1;
        }
        if(list1->val>list2->val){
            swap(list1, list2);
        }
        ListNode* res = list1;
        while(list1 && list2){
            ListNode* temp = nullptr;
            while(list1 && list1->val<=list2->val){
                temp = list1;
                list1= list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;     
            
    }    