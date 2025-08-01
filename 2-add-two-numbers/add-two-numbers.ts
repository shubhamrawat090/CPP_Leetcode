/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    if (l1 == null) return l2;
    if (l2 == null) return l1;

    let n1 = l1, n2 = l2, carry = 0, ans = new ListNode();
    let ansPtr = ans;

    while (n1 != null || n2 != null) {
        const n1Val = n1 != null ? n1.val : 0;
        const n2Val = n2 != null ? n2.val : 0;
        console.log("\nBefore adding: ", {n1Val, n2Val, carry});
        let sum = (n1Val + n2Val + carry);
        let remainder = sum % 10;
        carry = Math.floor(sum / 10);
        console.log("After adding: ", {sum, carry, remainder})

        ansPtr.next = new ListNode(remainder);
        ansPtr = ansPtr.next;

        if (n1 != null) {
            n1 = n1.next;
        }
        if (n2 != null) {
            n2 = n2.next;
        }
    }

    if(carry != 0) {
        ansPtr.next = new ListNode(carry);
    }

    return ans.next;
};