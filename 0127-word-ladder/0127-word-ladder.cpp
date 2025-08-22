class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());



        q.push({beginWord,1});


        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(endWord==word)return steps;
            

            for(int i=0;i<word.size();i++){

                char orignal=word[i];

                for(char j='a';j<='z';j++){

                    word[i]=j;

                    if(st.find(word)!=st.end()){
                        q.push({word, steps+1});
                        st.erase(word);
                    }


                }
                word[i]=orignal;
            }



        }
        return 0;











        
    }
};