// Description
// There is a new alien language which uses the latin alphabet. 
// However, the order among letters are unknown to you. 
// You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
// Derive the order of letters in this language.

// 1. You may assume all letters are in lowercase.
// 2. The dictionary is invalid, if string a is prefix of string b and b is appear before a.
// 3. If the order is invalid, return an empty string.
// 4. There may be multiple valid order of letters, return the smallest in normal lexicographical order.
// 5. The letters in one string are of the same rank by default and are sorted in Human dictionary order.

class Solution {
public:
    string alienOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, -1);
        int charactersCount = 0;
        for(int i = 0; i < n; i++) {
            for(char c : words[i]) {
                if(indegree[c - 'a'] == -1) {
                    indegree[c - 'a'] = 0;
                    charactersCount++;
                }
            }
        }
        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";
            }
            int j = 0;
            while(j < s1.size() && j < s2.size() && s1[j] == s2[j]) {
                j++;
            }
            if(j < s1.size() && j < s2.size()) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < 26; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        string order = "";
        while(!q.empty()) {
            int u = q.top();
            q.pop();
            order += ('a' + u);
            for(int v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(order.size() != charactersCount) {
            return "";
        }
        return order;
    }
};
