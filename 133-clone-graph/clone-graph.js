/**
 * // Definition for a Node.
 * function _Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {_Node} node
 * @return {_Node}
 */
var cloneGraph = function(node) {
    if (!node) return null;

    const visited = new Map();
    
    const cloneGraphHelper = (node) => {
        if (visited.has(node)) return visited.get(node);

        const newNode = new _Node(node.val);
        visited.set(node, newNode);

        newNode.neighbors = node.neighbors.map(cloneGraphHelper);
        return newNode;
    };

    return cloneGraphHelper(node);
};
