class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        formated=""
        for i in range(len(s)):
            if s[i].isalnum():
                formated+=s[i]
        print(formated[-1::-1])
        if formated == formated[-1::-1]:
            return True
        else:
            return False