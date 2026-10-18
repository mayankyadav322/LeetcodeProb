class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
     vector<pair<int,int>> cars;
     for(int i=0;i<position.size();i++){
        cars.push_back({position[i],speed[i]});
     }
     sort(cars.rbegin(),cars.rend());
     stack<double> st;
     int fleet = 0;
     for(int i=0;i<cars.size();i++){
       double  time = (double)(target - cars[i].first) / cars[i].second;     
     if(st.empty()){
         st.push(time);
         fleet++;
     }
    else if(st.top() < time){
        fleet++;
        st.push(time);
    
    }
     }
     return fleet;   
    }
};