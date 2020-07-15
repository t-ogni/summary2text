#include "library.h"

#include <iostream>
#include <string>

std::string converter::int2text(long long int number) {
    std::string text;
    if (number == 0){
        return std::string("Ноль");
    }

    if (number < 0){
        text.append("Минус ");
        number = -number;
    }

    if (std::abs(number) > MAXIMUM_NUMBER){
        return std::string("Число слижком большое для вывода.");
    }

    int bill = (int)(number / 1000000000);
    int mill = (int)(number % 1000000000) / 1000000;
    int thou = (int)(number % 1000000) / 1000;
    int cent = (int)(number % 1000);

    text.append( blocks(bill, 3));
    text.append( blocks(mill, 2));
    text.append( blocks(thou, 1));
    text.append( blocks(cent, 0));

    return text;
}

std::string converter::blocks(int block, int index) {
    if (!block){ return ""; }
    std::string text;
    enum formVariables {primary=1, secondary, remaning};
    int form = primary;

    text.append( hundreds[block / 100]);
    if (block % 100 > 0){
        if (10 >= block % 100 >= 19){
            text.append( teens[block % 100 /10]);
            form = remaning;
        } else {
            text.append( tens[block % 100 / 10]);
            text.append( units[block % 10]);

            switch (block % 10){
                case 1:
                    if (forms[index][0] == "t"){text.append( "на ");}
                    else { text.append( "ин "); }
                    form = primary;
                    break;
                case 2:
                    if (forms[index][0] == "t"){text.append( "е ");}
                    else { text.append( "а "); }
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
    text.append(forms[index][form]);
    return text;
}

