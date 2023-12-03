#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi {
public:
    int sayi;
    Basamak* ilkBasamak;
    Sayi* sonrakiSayi;

    Sayi(int sayi);
};

#endif // SAYI_HPP
