    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    // vector<string>ans;
    // vector<string>currentLine; 
    // int currentLineTotalChars = 0;
    // for(int i=0;i<words.size();i++)
    // {
    //     string &currentWord = words[i];
    //     int currentLineNeededNumberOfSpaces = currentLine.size();
    //     //single space after word
    //     if(currentLineTotalChars+currentLineNeededNumberOfSpaces + currentWord.size() > maxWidth)
    //     {
    //         int extraSpaces = maxWidth-currentLineTotalChars;
    //         int spacesGoInBetweenWords = extraSpaces/(max(1,(int)currentLine.size()));
    //         int remainder = extraSpaces%max(1,(int)(currentLine.size()-1));
    //         // we don't need spaces after last word
    //         for(int j=0;j<currentLine.size()-1;j++)
    //         {
    //             //add even spaces
    //             for(int k=0;k<spacesGoInBetweenWords;k++)
    //             {
    //                 currentLine[j] += " ";  // add spaces after the word
    //                 if(remainder >0)
    //                 {
    //                     currentLine[j] += "";
    //                     remainder--;
    //                 }
    //             }
    //             if(currentLine.size() == 1)
    //             {//left justified case
    //                 while(extraSpaces--)
    //                 {
    //                     currentLine[0] += "";
    //                 }
    //             }
    //             //let's prepare for final line
    //             string finalLine = "";
    //             for(string wordWithSpaces : currentLine)
    //                finalLine += wordWithSpaces;
    //             ans.push_back(finalLine);
    //             currentLine.clear();
    //             currentLineTotalChars = 0;   
    //         }
    //         //current line is not complete
    //         currentLine.push_back(currentWord);
    //         currentLineTotalChars += currentWord.size(); //not including spaces

    //     }
    //     //lets take care of last line
    //     //add 1 spaces b/w words
    //     string finalLine = "";
    //     for(auto word:currentLine)
    //        finalLine += word +" ";
    //     fianlLine.pop_back(); //remove extra added spaces
    //     int leftSpaces = maxWidth - finalLine.size();
    //     while(leftSpaces--)
    //     {
    //         finalLine += " ";
    //     } 
    //     ans.push_back(finalLine);
    //     return ans;  


    vector<string> ans;
    vector<string> currentLine;
    int currentLineTotalChars = 0;

    for (int i = 0; i < words.size(); i++) {
        string &currentWord = words[i];
        int currentLineNeededNumberOfSpaces = currentLine.size();
        
        // Check if adding the current word would exceed the maxWidth
        if (currentLineTotalChars + currentLineNeededNumberOfSpaces + currentWord.size() > maxWidth) {
            int extraSpaces = maxWidth - currentLineTotalChars;
            int spacesGoInBetweenWords = extraSpaces / max(1, (int)(currentLine.size() - 1));
            int remainder = extraSpaces % max(1, (int)(currentLine.size() - 1));
            
            // We don't need spaces after the last word
            for (int j = 0; j < currentLine.size() - 1; j++) {
                // Add even spaces
                currentLine[j] += string(spacesGoInBetweenWords, ' ');
                if (remainder > 0) {
                    currentLine[j] += " ";
                    remainder--;
                }
            }
            
            // Left-justified case (for single-word line)
            if (currentLine.size() == 1) {
                while (extraSpaces--) {
                    currentLine[0] += " ";
                }
            }
            
            // Prepare the final line
            string finalLine = "";
            for (string wordWithSpaces : currentLine)
                finalLine += wordWithSpaces;
            ans.push_back(finalLine);
            
            // Clear the current line and reset character count
            currentLine.clear();
            currentLineTotalChars = 0;
        }
        
        // Add the current word to the line
        currentLine.push_back(currentWord);
        currentLineTotalChars += currentWord.size();  // Not including spaces
    }

    // Last line: add 1 space between words and left justify
    string finalLine = "";
    for (auto word : currentLine)
        finalLine += word + " ";
    finalLine.pop_back();  // Remove the extra space

    int leftSpaces = maxWidth - finalLine.size();
    while (leftSpaces--) {
        finalLine += " ";
    }
    ans.push_back(finalLine);

    return ans;
    }
    int main()
    {
        int n;
        cout << "enter number of element in words array :" << endl;
        cin >> n;
        vector<string>words(n);
        cout << "Enter elements of words array : " << endl;
        for(int i=0;i<n;i++)
        {
            cin >> words[i] ;
        }
        int maxWidth;
        cout << "Enter maxWidth : " << endl;
        cin >> maxWidth;
        vector<string>ans = fullJustify(words,maxWidth);
        for(auto each : ans)
        {
            cout << each << endl;
        }
        return 0;
    }