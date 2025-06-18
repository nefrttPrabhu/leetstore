class Solution {
    public String reverseWords(String s) {
        String z = "", y = "";
        s = s.trim();
        s = s + ' ';
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch != ' '){
                y = ch + y;
            }
            else{
                z +=' ' + y;
                y = "";
            }
        }
        return z.trim();
    }
}