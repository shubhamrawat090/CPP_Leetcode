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

function reverseList(head: ListNode | null): ListNode | null {
    if(head == null) return head;


    let prev: ListNode | null = null, curr = head, next = head.next;
    while(curr != null) {
        curr.next = prev;
        prev = curr;
        curr = next;
        if(curr != null) {
            next = curr.next;
        }
    }
    head = prev;
    return head;
};