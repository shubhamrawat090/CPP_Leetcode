/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
/* 
    APPROACH
    1. Sort both the g (greed factor) and s (cookie sizes) arrays in ascending order.

    2. Use two pointers, one for children (g) and one for cookies (s).

    3. Try to satisfy each child with the smallest available cookie that is large enough.

    4. If a cookie can satisfy a child (s[j] >= g[i]), move both pointers forward.

    5. Otherwise, just move the cookie pointer forward to find a bigger cookie.

    6.Count how many children are satisfied.    
*/
var findContentChildren = function (g, s) {
    // return findContentChildren_RECURSIVE(g, s);

    // Sort greed factors and cookie sizes in ascending order
    g.sort((a, b) => a - b);
    s.sort((a, b) => a - b);

    let greedIdx = 0, sizeIdx = 0; // Pointers for children and cookies
    let count = 0;

    while (greedIdx < g.length && sizeIdx < s.length) {
        if (s[sizeIdx] >= g[greedIdx]) {
            count++; // Child is satisfied
            greedIdx++; // Move to next child
        }
        sizeIdx++; // Move to next cookie (used or too small)
    }

    return count;
};

var findContentChildren_RECURSIVE = function (g, s) {
    g.sort((a, b) => a - b); // Sort greed values
    s.sort((a, b) => a - b); // Sort cookie sizes

    function maxChildren(greedIdx, sizeIdx) {
        if (greedIdx >= g.length || sizeIdx >= s.length) {
            return 0;
        }

        if (g[greedIdx] <= s[sizeIdx]) {
            return Math.max(1 + maxChildren(greedIdx + 1, sizeIdx + 1), maxChildren(greedIdx, sizeIdx + 1));
        } else {
            return maxChildren(greedIdx, sizeIdx + 1);
        }
    }

    return maxChildren(0, 0);
};