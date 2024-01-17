class Solution {
    public int lengthOfLongestSubstring(String S) {
        int s=0;
        int i=0;
        int maxi=0;
        StringBuilder temp=new StringBuilder();
        while(i<S.length()){
            String ch=""+S.charAt(i);
            int ind=temp.indexOf(ch,s);
            if(ind!=-1){
                maxi=Math.max(maxi,i-s);
                s=ind+1;
            }
            temp.append(ch);
            i++;
        }
        maxi=Math.max(maxi,i-s);
    return maxi;
    }
}
