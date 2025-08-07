class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";

        int mini = Integer.MAX_VALUE;
        for (String s : strs) {
            mini = Math.min(mini, s.length());
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < mini; i++) {
            char ch = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].charAt(i) != ch) {
                    return result.toString();
                }
            }
            result.append(ch);
        }

        return result.toString();
    }
}
