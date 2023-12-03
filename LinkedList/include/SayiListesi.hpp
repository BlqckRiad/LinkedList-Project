#ifndef SAYILISTESI_HPP
#define SAYILISTESI_HPP

#include "Sayi.hpp"

class SayiListesi {
public:
    SayiListesi();
    ~SayiListesi();
    int aa=0;
    void ekleSayi(int sayi);
    Basamak* yeniBasamak(int sayi);
    Basamak* getBasamaklar(int sayi);
    void gosterSayilar();
    void bosYaz(int x);
    void SayiMenusu(Basamak* basamak, int arananSayimiz);
    void Yazdir();
    void Bilgi();
    void EnBuyukSil();
    Basamak* tersCevir(Basamak* basamak);
    void basamaklariTersCevir();
    Basamak* tekleriBasaAl(Basamak* basamak);
    void tekleriBasaAl();


    Sayi* ilkSayi;
    private:
};

#endif // SAYILISTESI_HPP
