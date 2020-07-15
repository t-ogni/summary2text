#include <iostream>
#include "library.h"
#include <string>
converter C;
int main(){
    setlocale(LC_ALL,"Rus");
    long long int get = 1;
    std::string a;
    while(get){
        std::cin >> get;
        std::cout << "\n ok: \n";
        a = C.int2text(get, RUSSIAN);
        std::cout << a << " \n";
        a = C.int2text(get, ENGLISH);
        std::cout << a << " \n ";
    }
    return 0;
}