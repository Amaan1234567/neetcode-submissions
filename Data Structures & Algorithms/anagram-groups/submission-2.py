class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        data ={}
        
        for s in strs:
            mp=[0]*26
            for ch in s:
                # print(ch)
                mp[ord(ch)-97] += 1
            # print(str(mp))
            if str(mp) in data:
                data[str(mp)].append(s)
            else:
                data[str(mp)]=[s]
        ans = []
        for _,val in data.items():
            ans.append(val)
        return ans;