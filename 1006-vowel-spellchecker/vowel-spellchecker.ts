function spellchecker(wordlist: string[], queries: string[]): string[] {
    const { normalWordMap = {}, capitalizeMap = {}, vowelRemoveMap = {} } = getWordMaps(wordlist);

    const answers = [];
    for (let query of queries) {
        let answer = "";
        if (normalWordMap[query]) {
            answer = normalWordMap[query];
        }

        const lowerCaseQuery = query.toLowerCase();
        if (answer == "" && capitalizeMap[lowerCaseQuery]) {
            answer = capitalizeMap[lowerCaseQuery];
        }

        const vowelRemovedQuery = removeVowels(lowerCaseQuery);
        if (answer == "" && vowelRemoveMap[vowelRemovedQuery]) {
            answer = vowelRemoveMap[vowelRemovedQuery];
        }

        answers.push(answer);
    }

    return answers;
};

function getWordMaps(wordlist) {
    const normalWordMap = {}, capitalizeMap = {}, vowelRemoveMap = {};

    for (let word of wordlist) {
        normalWordMap[word] = word;

        const lowerCaseWord = word.toLowerCase();
        if (!capitalizeMap[lowerCaseWord]) {
            capitalizeMap[lowerCaseWord] = word;
        }

        const vowelRemovedWord = removeVowels(lowerCaseWord);
        if (!vowelRemoveMap[vowelRemovedWord]) {
            vowelRemoveMap[vowelRemovedWord] = word;
        }
    }

    return { normalWordMap, capitalizeMap, vowelRemoveMap }
}

function removeVowels(word) {
    let result = "";
    const vowelList = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];

    for (let i = 0; i < word.length; i++) {
        let char = word[i];
        let isVowel = false;

        // check if current char is a vowel
        for (let j = 0; j < vowelList.length; j++) {
            if (char === vowelList[j]) {
                isVowel = true;
                break;
            }
        }

        // if not a vowel, add to result
        if (!isVowel) {
            result += char;
        } else {
            result += "_";
        }
    }

    return result;
}