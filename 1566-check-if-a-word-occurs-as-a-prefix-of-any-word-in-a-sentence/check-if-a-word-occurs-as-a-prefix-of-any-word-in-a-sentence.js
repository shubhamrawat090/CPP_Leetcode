/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
    const indexOfWordPrefixExists = sentence.split(" ").findIndex(word => word.startsWith(searchWord));
    return indexOfWordPrefixExists == -1 ? -1 : indexOfWordPrefixExists + 1;
};