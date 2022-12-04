#include "FailoNuskaitymas.h"

bool tryCatch(string s) {


        try {
            if (s.find_first_of("0123456789,./;'[]-= ") != string::npos) {
                
                throw "Ivedete neteisnga simboli\n";
            }
            else
                return true;

        }
        catch (const char* txtException) {
            std::cout << txtException;
            std::cin.clear();
            std::cin.ignore();
            return false;
        }
};