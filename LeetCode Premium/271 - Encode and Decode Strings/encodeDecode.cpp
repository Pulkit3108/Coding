// Description
// Design an algorithm to encode a list of strings to a string. 
// The encoded string is then sent over the network and is decoded back to the original list of strings.

// Please implement encode and decode

// Input: ["lint","code","love","you"]
// Output: ["lint","code","love","you"]

// Explanation:
// One possible encode method is: "lint:;code:;love:;you"

class Solution {
public:
    string encode(vector<string> &strs) {
        int n = strs.size();
        string encode = "";
        for(int i=0;i<n;i++){
            encode += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encode;
    }
    vector<string> decode(string &str) {
        vector<string> decode;
        int n = str.size();
        int i = 0;
        while(i<n){
            int j = i;
            while(str[j]!='#'){
                j++;
            }
            int len = stoi(str.substr(i,j-i));
            decode.push_back(str.substr(j+1,len));
            i = j+1+len;
        }
        return decode;
    }
};
