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
            for(let char = 'a'; char <= 'z'; char = String.fromCharCode(char.charCodeAt(0) + 1)) {
                if(char !== currWord[i]) {
                    const newWord = currWord.slice(0, i) + char + currWord.slice(i+1);
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