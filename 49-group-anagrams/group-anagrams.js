/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const sortKeyGroupMap = {};
    for(let str of strs) {
        const sortStr = str.split("").sort().join("");
        if(sortKeyGroupMap[sortStr]) {
            sortKeyGroupMap[sortStr].push(str);
        } else {
            sortKeyGroupMap[sortStr] = [str];
        }
    }
    return Object.values(sortKeyGroupMap);
};