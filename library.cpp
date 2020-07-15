#include "library.h"
#include <string>

std::string converter::int2text(long long int number,  int language) {
    std::string text{};
    if (number == 0){
        return std::string(zero[language]);
    }

    if (number < 0){
        text.append(minus[language]);
        number = -number;
    }

    if (std::abs(number) > MAXIMUM_NUMBER){
        return std::string(owerflowErr[language]);
    }

    int bill = (int)(number / 1000000000);
    int mill = (int)(number % 1000000000) / 1000000;
    int thou = (int)(number % 1000000) / 1000;
    int cent = (int)(number % 1000);

    text.append( blocks(bill, 3,  language));
    text.append( blocks(mill, 2,  language));
    text.append( blocks(thou, 1,  language));
    text.append( blocks(cent, 0,  language));

    return text;
}

std::string converter::blocks(int block, int index, int language) {
    if (!block){ return ""; }
    std::string text {};
    enum formVariables {primary=1, secondary, remaning};
    int form = primary;

    text.append( hundreds[language][block / 100]);
    if (block % 100 > 0){
        if (10 >= (block % 100) >= 19){
            text.append( teens[language][block % 100 /10]);
            form = remaning;
        } else {
            text.append( tens[language][block % 100 / 10]);
            text.append( units[language][block % 10]);

            switch (block % 10){
                case 1:
                    if(language == RUSSIAN) {
                        if (forms[language][index][0] == "t") { text.append("на "); }
                        else { text.append("ин "); }
                    }
                    form = primary;
                    break;
                case 2:
                    if(language == RUSSIAN){
                        if (forms[language][index][0] == "t"){text.append( "е ");}
                        else { text.append( "а "); }
                    }
                    form = secondary;
                    break;
                case 3:
                    form = secondary;
                    break;
                case 4:
                    form = secondary;
                    break;
                default:
                    form = remaning;
                    break;
            }
        }
    }
    text.append(forms[language][index][form]);
    return text;
}


