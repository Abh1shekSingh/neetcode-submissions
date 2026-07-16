class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> que;
        que.push({beginWord, 1});

        while(!que.empty()) {
            string word = que.front().first;
            int steps = que.front().second;

            que.pop();

            if(word == endWord) return steps;

            for(int i = 0 ; i < word.size() ; i++) {
                char original = word[i];
                for(int ch = 'a' ; ch <= 'z' ; ch++) {
                    word[i] = ch;
                    if(s.find(word) != s.end()) {
                        que.push({word,steps + 1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
