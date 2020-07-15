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
         a = C.int2text(get);

        std::cout << a << std::endl;
    }
    return 0;
}
