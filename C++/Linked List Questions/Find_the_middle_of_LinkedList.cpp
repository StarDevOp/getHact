//T/C: O(2n)
ListNode* middleNode(ListNode* head) {
        int len = 0, i=0;
        ListNode *curr = head, *mid = head;
        while(curr!=nullptr){
            len++;
            curr = curr->next;
        }
        while(i<(len)/2){
            mid = mid->next;
            i++;
        }
        return mid;
    }

//T/C: O(mid)
ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }