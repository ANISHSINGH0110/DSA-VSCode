class Solution {
    public:
        string intToRoman(int num) {
        //  vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        //  vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
        //  string result = "";
        // //  int i = 0;
    
        // //  while (num > 0) {
        // //     if (num >= values[i]) {
        // //         result += symbols[i];
        // //         num -= values[i];
        // //     } else {
        // //         i++;
        // //     }
        // //  }
        //   for (int i = 0; i < values.size(); i++) {
        //     while (num >= values[i]) {
        //         result += symbols[i];
        //         num -= values[i];
        //     }
        //  }
        //  return result;
    
    
        string romanSymbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans = "";
        for(int i=0;i<13;i++)
        {
            while(num >= value[i])
            {
                ans += romanSymbol[i];
                num -= value[i];
            }
        }
        return ans;
        }
    };