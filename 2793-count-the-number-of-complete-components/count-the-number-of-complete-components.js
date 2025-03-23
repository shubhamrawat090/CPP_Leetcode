/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countCompleteComponents = function(n, edges) {
    const visited = Array(n).fill(false);
    const adjList = Array(n).fill(null).map(() => []);

    for (const [u, v] of edges) {
        adjList[u].push(v);
        adjList[v].push(u);
    }

    let completeComponentCount = 0;

    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            if (checkCompleteComponent(i, visited, adjList)) {
                completeComponentCount++;
            }
        }
    }

    return completeComponentCount;
};

/**
 * Checks if a connected component is a complete graph
 */
var checkCompleteComponent = function(startingNode, visited, adjList) {
    const componentNodes = new Set();
    let edgeCount = 0;

    const queue = [startingNode];
    visited[startingNode] = true;
    componentNodes.add(startingNode);

    while (queue.length) {
        const node = queue.shift();
        for (const neighbor of adjList[node]) {
            edgeCount++; // Count edges
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
                componentNodes.add(neighbor);
            }
        }
    }

    // A complete graph of k nodes must have k * (k - 1) / 2 edges (since it's undirected)
    let k = componentNodes.size;
    return edgeCount / 2 === (k * (k - 1)) / 2;
};
