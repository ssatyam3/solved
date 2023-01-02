class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.length()<1){
            return true;
        }
        
        int sm=0,cap=0,first=0;
        
        for(int i=0 ; i<word.length() ; i++){
            if(i==0){
                if(!(word.charAt(i)>=97 && word.charAt(i)<=122)){
                    first++;
                }
            }
            if(word.charAt(i)>=97 && word.charAt(i)<=122){
                sm++;
            }
            else {
                cap++;
            }
        }
        int len = word.length();
        
        if(cap == len || sm == len || (cap==first)){
            return true;
        }
        return false;
    }
}