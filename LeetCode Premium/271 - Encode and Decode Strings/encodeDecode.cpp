// Problem Statement
// Design an algorithm to encode a list of strings to a single string. The encoded string is then sent over the network 
// and is decoded back to the original list of strings.

// Constraints:
// - The string may contain any of the 256 legal ASCII characters.
// - Your algorithm must handle any character that may appear.
// - Do not rely on any libraries; the purpose is to implement the "encode" and "decode" algorithms on your own.

// Examples:

// Example 1:
// Input: ["lint", "code", "love", "you"]
// Output: ["lint", "code", "love", "you"]
// Explanation: One possible encode method is: "4#lint4#code4#love3#you"

// Example 2:
// Input: ["we", "say", ":", "yes"]
// Output: ["we", "say", ":", "yes"]
// Explanation: One possible encode method is: "2#we3#say1#:3#yes"

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string encoded = "";
        for (const string &s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> decoded;
        int i = 0;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '#') {
                j++;
            }
            int len = stoi(str.substr(i, j - i));
            decoded.push_back(str.substr(j + 1, len));
            i = j + 1 + len;
        }
        return decoded;
    }
};
