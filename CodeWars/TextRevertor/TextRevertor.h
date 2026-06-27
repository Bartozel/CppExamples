/* 
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"

#include <string>

std::string reverse_words(std::string str)
{
  return "";
} 
*/

#include <string>

class TextRevertor
{
public:
    std::string reverse_words(std::string str);
    std::string reverse_words_2(std::string str);
    std::string reverse_words_3(std::string str);    
    std::string reverse_words_4(std::string str);    
    std::string reverse_words_5(std::string str);

private:
    std::vector<std::string_view> Split(const std::string& str, char delimiter);
};