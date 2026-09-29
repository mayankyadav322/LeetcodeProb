class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n=citations.size();
        for(int i=0;i<citations.size();i++){
            int paper = n-i;
            if(citations[i] >= paper){
            return paper;
        }
        }
        return 0;
    }
};