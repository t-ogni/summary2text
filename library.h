#include <iostream>
#include <string>
#ifndef STRINGTOTEXT_LIBRARY_H
#define STRINGTOTEXT_LIBRARY_H


class converter {
private:
    long long int MAXIMUM_NUMBER = 999999999999;
    std::string units[10] = {"", "од", "дв",
            "три ", "четыре ", "п€ть ",
            "шесть ", "семь ", "восемь ", "дев€ть "};

    std::string teens[10] =  {"дес€ть ", "одинадцать ",
                              "двенадцать ", "тринадцать ",
                              "четырнадцать ", "п€тнадцать ",
                              "шеснадцать ", "семьнадцать ",
                              "восемьнадцать ", "дев€тнадцать "};
    std::string tens[10] = {
                            "", "", "двадцать ", "тридцать ",
                            "сорок ", "п€тьдес€т ",
                            "шестьдес€т ", "семьдес€т ",
                            "восемьдес€т ", "дев€носто "
    };

    std::string hundreds[10] = {
            "", "сто ", "двести ",
            "триста ", "четыреста ",
            "п€тьсот ", "шестьсот ",
            "семьсот ", "восемьсот ",
            "дев€тьсот " };

    std::string forms[4][4] = {
            {"m"},
            {"t", "тыс€ча ",   "тыс€чи ",    "тыс€ч "},
            {"m", "миллион ",  "миллиона ",  "миллионов "},
            {"m", "миллиард ", "миллиарда ", "миллиардов "}
    }; //   primary,    secondary,  remaning, form



    std::string blocks(int block, int index);
public:
    std::string int2text(long long int number);

};

#endif //STRINGTOTEXT_LIBRARY_H
