#include "utilitaire.hpp"
#include "Lexique.hpp"
#include "iostream"

int main() {
    std::cout<<"first";

    Lexique l1 = Lexique("files/lesMiserables_A.txt");

    l1.writeFile();

    return 0; 
}