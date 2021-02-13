// the key is to keep the stones balanced, without ignoring one group of stones 
// that could have been combined with others 
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // make sure a <= b <= c
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        
        // if a + b still cannot consume all from c, that means a and b will be empty 
        // with combination to c one by one
        if (c >= a + b) return a + b;

        // otherwise, consume c first and at the mean time keep a and b balanced 
        // so that they can be consumed with each other as much as possible
        return c + (a + b - c) / 2;
    }
};