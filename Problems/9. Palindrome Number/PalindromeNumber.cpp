class Solution {
public:
    long long reverseInt(int num) {
        long long reversedNumber = 0;
        while (num != 0) {
            int remainder = num % 10;
            reversedNumber = reversedNumber * 10 + remainder;
            num /= 10;
        }
        return reversedNumber;
    }

    bool isPalindrome(int x) {
        int n = x;
        long long reversedNumber = reverseInt(x);
        if (x < 0) {
            return false;
        }
        
        return n == reversedNumber;
    }
};