class Solution {
public:
    int hIndex(vector<int>& citations) {
       int low=0;
       int high=citations.size()-1;
       int ans=0;
       while(low<=high){
        int mid = low+(high-low)/2;
        int paper = citations.size()-mid;
        if(paper <= citations[mid]){
        ans = paper;
        high = mid-1;
        }
        else low = mid+1;
       } 
       return ans;
    }
};