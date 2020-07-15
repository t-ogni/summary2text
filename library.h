#include <iostream>
#include <string>
#ifndef STRINGTOTEXT_LIBRARY_H
#define STRINGTOTEXT_LIBRARY_H


enum a {  RUSSIAN=0,
        ENGLISH,
        LEN_LANGS};


//sorry, if i maked a mistake in ENGLISH translation :(
class converter {
private:
    long long int MAXIMUM_NUMBER = 999999999999;
    std::string units[LEN_LANGS][10] = {
            {
                "", "од", "дв", "три ",
                "четыре ", "пять ", "шесть ",
                "семь ", "восемь ", "девять "
            },
            {
                "", "one ", "two ", "three ",
                "four ", "five ", "six ",
                "seven ", "eight ", "nine "
            }
    };

    std::string teens[LEN_LANGS][10] =  {
            {
                    "десять ", "одинадцать ",
                  "двенадцать ", "тринадцать ",
                  "четырнадцать ", "пятнадцать ",
                  "шеснадцать ", "семьнадцать ",
                  "восемьнадцать ", "девятнадцать "
            },
            {
                  "ten ", "eleven ",
                  "twelve ", "thirteen ",
                  "fourteen ", "fifteen ",
                  "sixteen ", "seventeen ",
                  "eighteen ", "nineteen "
             }
    };
    std::string tens[LEN_LANGS][10] = {
            {
                "", "", "двадцать ", "тридцать ",
                "сорок ", "пятьдесят ",
                "шестьдесят ", "семьдесят ",
                "восемьдесят ", "девяносто "
            },
            {
                "", "", "twenty ", "thirty ",
                "forty ", "fifty ",
                "sixty ", "seventy ",
                "eighty ", "ninety "
            }
    };

    std::string hundreds[LEN_LANGS][10] = {
            {
                "", "сто ", "двести ",
                "триста ", "четыреста ",
                "пятьсот ", "шестьсот ",
                "семьсот ", "восемьсот ",
                "девятьсот "
            },
            {
                "", "one hundred ", "two hundred",
                "three hundred ", "four hundred ",
                "five hundred ", "six hundred ",
                "seven hundred ", "eight hundred ",
                "nine hundred "
            }
    };

    std::string forms[LEN_LANGS][4][4] = {
            {
                  {"m"},
                  {"t", "тысяча ", "тысячи ", "тысяч "},
                  {"m", "миллион ", "миллиона ", "миллионов "},
                  {"m", "миллиард ", "миллиарда ", "миллиардов "}
            },
            {
                   {"m"},
                   {"t", "thousand ", "thousand ", "thousand "},
                   {"m", "million ", "million ", "million "},
                   {"m", "billion ", "billion ", "billion "},
            }
    }; //   primary,    secondary,  remaning, form

    std::string zero[LEN_LANGS] = {"Ноль ", "Zero "};
    std::string minus[LEN_LANGS] = {"Минус ", "Minus "};
    std::string owerflowErr[LEN_LANGS] = {"Число слижком большое для вывода.",
                                          "Number is too big for output"};
    std::string blocks(int block, int index, int language);
public:
    std::string int2text(long long int number, int language = RUSSIAN);

};

#endif //STRINGTOTEXT_LIBRARY_H
