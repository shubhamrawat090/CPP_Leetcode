/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    const wordSet = new Set(wordList);
    const queue = [];

    if(!wordSet.has(endWord)) {
        return 0;
    }

    queue.push([beginWord, 1]);

    while(queue.length) {
        const [currWord, level] = queue.shift();
        for(let i=0; i<currWord.length; i++) {
            for(let j=0; j<26; j++) {
                const nextChar = String.fromCharCode("a".charCodeAt(0) + j);
                if(nextChar !== currWord[i]) {
                    const newWord = currWord.slice(0, i) + nextChar + currWord.slice(i+1);
                    if(newWord === endWord) {
                        return level + 1;
                    }
                    if(wordSet.has(newWord)) {
                        queue.push([newWord, level + 1]);
                        wordSet.delete(newWord);
                    }
                }
            }
        }
    }

    return 0;
};