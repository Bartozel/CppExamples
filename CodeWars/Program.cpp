 #include <iostream>
 #include <chrono>
 #include <stdexcept>
 #include "TextRevertor.h" 

 const size_t ITERATION = 100000000;
    
 std::chrono::duration<double> Measurement(TextRevertor& tr, std::string (TextRevertor::*m)(std::string));

/*
Note:
Change reverse_words definition from const std::sring& to std::string caused significan time improvement. Bellow is explenation.


"This is an example!" is a string literal, which produces a temporary (rvalue) std::string at the call site. 
That changes the math entirely:

                        const std::string&	                    std::string (value)
Call site	            Construct temporary, bind ref	        Move temporary into param
Inside method	        Must copy (std::string result = str)	Already owns it — can work on it directly
Total constructions	    2 (construct + copy)	                1 (construct + 0-cost move)

For an rvalue argument, pass-by-value lets the compiler move the temporary directly into the parameter — no extra copy. Then each method already has an owned, mutable string and doesn't need the internal std::string result = str copy at all (though as written the bodies still do it).

The rule is:

Lvalue (std::string s; f(s);) → const string& wins, avoids the copy entirely
Rvalue (f("literal") or f(std::move(s))) → string by value wins or ties, because the move is essentially free
Since the benchmark always passes the same literal (an rvalue), pass-by-value avoids one string construction per call × 100M iterations — that's real time saved.
*/


int main()
{
    TextRevertor textRevertor;

    auto res_1 = Measurement(textRevertor, &TextRevertor::reverse_words);
    std::cout << "result reverse_word   " << res_1.count() << std::endl; // last test = 3.20466

    auto res_2 = Measurement(textRevertor, &TextRevertor::reverse_words_2);
    std::cout << "result reverse_word_2 " << res_2.count() << std::endl;// last test = 3.60666

    auto res_3 = Measurement(textRevertor, &TextRevertor::reverse_words_3);
    std::cout << "result reverse_word_3 " << res_3.count() << std::endl;// last test = 1.87755

    auto res_4 = Measurement(textRevertor, &TextRevertor::reverse_words_4);
    std::cout << "result reverse_word_4 " << res_4.count() << std::endl;// last test = 7.75889

    auto res_5 = Measurement(textRevertor, &TextRevertor::reverse_words_5);
    std::cout << "result reverse_word_5 " << res_5.count() << std::endl;// last test = 7.75889

    return 0;
}

std::chrono::duration<double> Measurement(TextRevertor& tr, std::string (TextRevertor::*m)(std::string)){

    auto startPoint = std::chrono::system_clock::now();

    for(int i = 0; i < ITERATION; i++){
        auto result = (tr.*m)("This is an example!");
        if (result != "sihT si na !elpmaxe")
        {
            std::cout << "Test failed!" << std::endl;
            return std::chrono::duration<double>(0);
        }
    }

    return std::chrono::system_clock::now() - startPoint;
}