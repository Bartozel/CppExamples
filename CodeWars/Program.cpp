 #include <iostream>
 #include <chrono>
 #include <stdexcept>
 #include "TextRevertor.h" 

 const size_t ITERATION = 100000000;
    
 std::chrono::duration<double> Measurement(TextRevertor& tr, std::string (TextRevertor::*m)(const std::string&));
int main()
{
    TextRevertor textRevertor;

    auto res_1 = Measurement(textRevertor, &TextRevertor::reverse_words);
    std::cout << "result reverse_word " << res_1.count() << std::endl;

    auto res_2 = Measurement(textRevertor, &TextRevertor::reverse_words_2);
    std::cout << "result reverse_word_2 " << res_2.count() << std::endl;

    return 0;
}

std::chrono::duration<double> Measurement(TextRevertor& tr, std::string (TextRevertor::*m)(const std::string&)){

    auto startPoint = std::chrono::system_clock::now();

    for(int i = 0; i < ITERATION; i++){
        auto result = (tr.*m)("This is an example!");
        if (result != "sihT si na !elpmaxe")
        {
            std::cout << "Test failed!" << std::endl;
            throw std::logic_error("Invalid result");
        }
    }

    return std::chrono::system_clock::now() - startPoint;
}