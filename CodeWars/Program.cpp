 #include <iostream>  
 #include "TextRevertor.h" 
    
int main()
{
    TextRevertor textRevertor;
    auto result = textRevertor.reverse_words_2("This is an example!");
    auto expected = "sihT si na !elpmaxe";

    if (result != expected)
    {
        std::cout << "Test failed!" << std::endl;
        return 1;
    }

    std::cout << result << std::endl;
    return 0;
}