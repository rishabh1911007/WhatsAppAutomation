/*

Question-

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

*/



//Code//


class Solution {
public:
    int minSwaps(string s) {
        int l=0;
        int r=s.size()-1;
        int swaps=0;
        int close=0;
        int open=0;
        while(l<r){
            if(s[l]=='['){
                l++; // as in left if we have opening brackets then it will be balanced
                open++; 
            }
            else if(s[l]==']' && open>0){
                l++;
                open--;
            }
            else if(s[r]==']'){
                r--;
                close++;
            }
            else if(s[r]=='[' && close>0){
                r--;
                close--;
            }
            else if(s[l]==']' && s[r]=='['){
                swaps++;
                open++;
                close++;
                l++;
                r--;
            }
        }
        return swaps;
    }
};