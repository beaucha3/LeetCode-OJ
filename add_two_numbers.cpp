/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            /* Assume that the input data is valid- but we can't assume the lists have the same number of elements */
            
            ListNode* ret = NULL; /* Pointer to the final list to be returned */
            ListNode* curSol, *prevSol;
            
            ListNode* cur1 = l1; /* Pointers used to step through the two input lists */
            ListNode* cur2 = l2;
            
            int sum, carryOut = 0, carryIn = 0; /* Declare variables for sum, carry-in (initially 0), and carry-out */
            int i = 0; /* Used to set ret to point to the first node in the allocated list */
            
            while((cur1 != NULL) || (cur2 != NULL)) /* Step through the two linked lists */
            {
                if(cur1 == NULL) /* i.e. if the first number has fewer digits than the second */
                {
                    sum = (carryIn + cur2->val) % 10; /* Calculate the sum and carry-out on each pass through */
                    carryOut = (carryIn + cur2->val)/10;
                    carryIn = carryOut; /* New carry-in is the previous carry-out */
                    cur2 = cur2->next; /* Step through the list */
                }
                
                else if(cur2 == NULL) /* i.e. if the second number has fewer digits than the first */
                {
                    sum = (carryIn + cur1->val) % 10; /* Calculate the sum and carry-out on each pass through */
                    carryOut = (carryIn + cur1->val)/10;
                    carryIn = carryOut; /* New carry-in is the previous carry-out */
                    cur1 = cur1->next; /* Step through the list */
                }
                
                else
                {
                    sum = (carryIn + cur1->val + cur2->val) % 10; /* Calculate the sum and carry-out on each pass through */
                    carryOut = (carryIn + cur1->val + cur2->val)/10;
                    carryIn = carryOut; /* New carry-in is the previous carry-out */
                    cur1 = cur1->next; /* Step through the list */
                    cur2 = cur2->next;
                }
                
                if(i == 0) /* This ensures that "ret" points to the first node, and generally accounts for the first iteration edgecase */
                {
                    i++;
                    prevSol = new ListNode(sum);
                    ret = prevSol;
                }
                
                else /* Else, we can actually use the variable "curSol" */
                {
                    curSol = new ListNode(sum); /* Allocate a new ListNode for the current digit */
                    prevSol->next = curSol;
                    prevSol = curSol; /* New "prevSol" is the current "curSol" */
                }
            }
            
            if(carryOut) /* Account for case of nonzero final carry-out */
            {
                curSol = new ListNode(carryOut);
                prevSol->next = curSol;
            }
            
            return ret; /* Return pointer to the final list */
        }
};
