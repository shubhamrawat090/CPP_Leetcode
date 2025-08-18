class Solution:
    def isValid(self, s: str) -> bool:
        lst = []
        open_bracket = "({["

        for char in s:
            if char in open_bracket:
                lst.append(char)
            else:
                if not lst:
                    return False
                if char == ")" and lst.pop() != "(":
                    return False
                elif char == "]" and lst.pop() != "[":
                    return False
                elif char == "}" and lst.pop() != "{":
                    return False

        return len(lst) == 0
