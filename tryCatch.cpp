#include "FailoNuskaitymas.h"


int tryCatch(int i) {

    do {
        try {
            if (std::cin.fail())
                throw "Ivedete neteisnga simboli\n";

        }
        catch (const char* txtException) {
            std::cout << txtException;
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Iveskite pazymiu skaiciu dar karta: ";
            std::cin >> i;
        }
    } while (std::cin.fail());

    return i;
};