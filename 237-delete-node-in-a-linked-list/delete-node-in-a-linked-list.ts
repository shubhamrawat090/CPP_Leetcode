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

/**
 Do not return anything, modify it in-place instead.
 */
function deleteNode(node: ListNode | null): void {
    let next = node.next;
    while (next != null) {
        node.val = next.val;
        if (next.next == null) {
            node.next = null; // delete last node
        }
        node = node.next;
        next = next.next;
    }
};