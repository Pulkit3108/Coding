// Problem Statement
// There is a new alien language that uses the Latin alphabet. However, the order among letters is unknown. 
// You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
// Derive the order of letters in this language.

// Constraints:
// - All letters are in lowercase.
// - At the first different letter, if the letter in s precedes the letter in t in the given list order, 
//   then the dictionary order of s is less than t.
// - The dictionary is invalid if string a is a prefix of string b and b appears before a.
// - If the order is invalid, return an empty string.
// - There may be multiple valid orders of letters; return the smallest in normal lexicographical order.
// - The letters in one string are of the same rank by default and are sorted in human dictionary order.

// Examples:

// Example 1:
// Input: ["wrt", "wrf", "er", "ett", "rftt"]
// Output: "wertf"
// Explanation:
// - From "wrt" and "wrf", we get 't' < 'f'.
// - From "wrt" and "er", we get 'w' < 'e'.
// - From "er" and "ett", we get 'r' < 't'.
// - From "ett" and "rftt", we get 'e' < 'r'.
// So the order is "wertf".

// Example 2:
// Input: ["z", "x"]
// Output: "zx"
// Explanation:
// - From "z" and "x", we get 'z' < 'x'.
// So the order is "zx".

class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, -1);
        int charactersCount = 0;

        for (const string &word : words) {
            for (char c : word) {
                if (indegree[c - 'a'] == -1) {
                    indegree[c - 'a'] = 0;
                    charactersCount++;
                }
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";
            }
            int j = 0;
            while (j < s1.size() && j < s2.size() && s1[j] == s2[j]) {
                j++;
            }
            if (j < s1.size() && j < s2.size()) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
            }
        }

        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        string order = "";
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            order += ('a' + u);
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return order.size() == charactersCount ? order : "";
    }
};
