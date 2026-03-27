class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) == string::npos ?-1:int(haystack.find(needle));
    }
};