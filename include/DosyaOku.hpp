#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include "ArrayList.hpp"
#include <iostream>

using namespace std;

class DosyaOku {
public:
    int satirSayisi;
    int **sayilar;
    int *sayilarToplami;
    ArrayList *satirdakiElemanSayisi;
    DosyaOku();
    void sayilariSirala();
    ~DosyaOku();
};
#endif 

