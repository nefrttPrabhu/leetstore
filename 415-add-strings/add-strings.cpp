// https://chatgpt.com/share/68ab58de-008c-8002-9bf0-dc9ecb4460d1

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string a = "";

        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0) sum += num1[i--] - '0';
            if(j >= 0) sum += num2[j--] - '0';
            a.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        reverse(a.begin(), a.end());
        // a += ans;
        return a;
    }
};


