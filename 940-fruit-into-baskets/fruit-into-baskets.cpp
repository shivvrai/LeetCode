class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int lastfruit=fruits[0];
        int secondlastfruit=-1;int cnt=0,maxi=0;int lastfruitstreak=0;
        for(int i=0;i<n;i++){
            if(fruits[i]== lastfruit){
                cnt+=1;
                lastfruitstreak+=1;
            }
            else if(fruits[i]== secondlastfruit || secondlastfruit==-1){
                cnt+=1;
            secondlastfruit=lastfruit;
            lastfruit=fruits[i];   lastfruitstreak=1;         }
            else{
                cnt=lastfruitstreak+1;
                secondlastfruit=lastfruit;
                lastfruit=fruits[i];
                lastfruitstreak=1;
            }
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
};