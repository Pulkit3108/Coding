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
