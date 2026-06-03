#include <algorithm>
#include <vector>

#include "TextRevertor.h"

//pre-allocate new string a fill character by character retroactivally
std::string TextRevertor::reverse_words(const std::string &str)
{   
    size_t strSize = str.length();
    std::string reverserStr(strSize, ' ');
    int counter = 0;

    for(size_t i = 0; i < strSize; i++){
        
        counter++;
        char nextChar = str[i + 1];

        if(nextChar == ' ' || nextChar == '\0'){
            
            for(size_t j = 0; j < counter; j++){

                reverserStr[i - j] = str[i - counter + j + 1];
            }
            counter = -1; // skip the space
        }
    }

    return reverserStr; 
}

//
std::string TextRevertor::reverse_words_2(const std::string &str)
{   
    std::string reversedStr(str.length(), ' ');
    std::string_view strView = str;
    size_t pos;
    char delimiter = ' ';
    size_t i = 0;

    while ((pos = strView.find(delimiter)) != strView.npos)
    {
        auto word = strView.substr(0, pos);

        for(auto it = word.rbegin(); it != word.rend(); ++it){
            reversedStr[i++] = *it;
        }
        reversedStr[i++] = ' ';
        strView.remove_prefix(pos + 1);
    }

    for(auto it = strView.rbegin(); it != strView.rend(); ++it){
        reversedStr[i++] = *it;
    }

    return reversedStr;
}

// single allocation + in-place std::reverse per word (SIMD-optimized in libc++)
std::string TextRevertor::reverse_words_3(const std::string &str)
{
    std::string result = str;
    size_t start = 0;
    const size_t n = result.size();

    for (size_t i = 0; i <= n; i++) {
        
        if (i == n || result[i] == ' ') {
            std::reverse(result.begin() + start, result.begin() + i);
            start = i + 1;
        }
    }

    return result;
}

std::vector<std::string_view> Split(const std::string& str, char delimiter){

    std::vector<std::string_view> res;
    std::string_view strView = str;
    size_t pos;

    while ((pos = strView.find(delimiter)) != strView.npos)
    {
        res.push_back(strView.substr(0, pos));
        strView.remove_prefix(pos + 1);
    }
    
    res.push_back(strView);
    return res;
}