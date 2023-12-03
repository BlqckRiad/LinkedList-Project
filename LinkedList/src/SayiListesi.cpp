#include "SayiListesi.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


SayiListesi::SayiListesi() : ilkSayi(nullptr) {}

SayiListesi::~SayiListesi() {
    // Destructor implementasyonu (gerekirse)
}
void SayiListesi::ekleSayi(int sayi) {
    Sayi* yeniSayi = new Sayi(sayi);
    yeniSayi->ilkBasamak = yeniBasamak(sayi);

    if (!ilkSayi) {
        ilkSayi = yeniSayi;
    } else {
        Sayi* current = ilkSayi;
        while (current->sonrakiSayi) {
            current = current->sonrakiSayi;
        }
        current->sonrakiSayi = yeniSayi;
    }
}

Basamak* SayiListesi::yeniBasamak(int sayi) {
    Basamak* ilk = nullptr;
    Basamak* onceki = nullptr;

    while (sayi > 0) {
        int basamak = sayi % 10;
        Basamak* yeniBasamak = new Basamak(basamak);
        yeniBasamak->sonraki = ilk;
        ilk = yeniBasamak;
        sayi /= 10;
    }
    return ilk;
}

Basamak* SayiListesi::getBasamaklar(int sayi) {
    Sayi* current = ilkSayi;
    while (current) {
        if (current->sayi == sayi) {
            return current->ilkBasamak;
        }
        current = current->sonrakiSayi;
    }
    return nullptr;
}

void SayiListesi::gosterSayilar() {
    Sayi* current = ilkSayi;
    while (current) {
        Basamak* basamak = current->ilkBasamak;
        std::cout << "Sayi: " << current->sayi << " Basamaklar: ";
        while (basamak) {
            std::cout << basamak->veri << " ";
            basamak = basamak->sonraki;
        }
        std::cout << std::endl;
        current = current->sonrakiSayi;
    }
}

void SayiListesi::bosYaz(int x) {
    for (int i = 0; i < 9 - x; i++) {
        std::cout << " ";
    }
}

void SayiListesi::SayiMenusu(Basamak* basamak, int arananSayimiz) 
{   
            aa=aa+1;
            int sayimizinBasamakAdedi=0;
            
            
            if(ilkSayi!=NULL)
            {   
                int geciciArananSayi=arananSayimiz;
                
                int  no=ilkSayi->sayi;
                int sayimizinBasamakAdedi=0;
                  while (arananSayimiz != 0) {
                        arananSayimiz /= 10;
                        sayimizinBasamakAdedi++;
                 }
                 
                

                 arananSayimiz=geciciArananSayi;
                 // İlk satırımız
                 cout<<"###########"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi;i++)
                 {
                    cout<<"*******" <<"  ";
                 }
                 cout << endl;
                // İkinci Satırımız
                
                
                Basamak*gecici=basamak;
                Sayi* geciciX = ilkSayi;
                cout<<"#";
                if(aa==1)
                {
                    cout<<geciciX;
                }
                else{
                     for(int i=1;i<aa;i++)
                {
                    geciciX=geciciX->sonrakiSayi;
                    
                }
                    cout<<geciciX;
                  
                }
                
                cout<<"#"<<"  ";
                
                   for(int i=0;i<sayimizinBasamakAdedi;i++)
                 {
                        Basamak* gecici2=gecici;
                        uintptr_t address = reinterpret_cast<uintptr_t>(gecici2);
                        uintptr_t lastThreeDigits = address & 0xFFF;

                    
                    cout<<"* ";
                    cout<<hex<<setw(3)<<setfill('0')<<lastThreeDigits;
                    cout<<dec<<" *  ";
                    gecici=gecici->sonraki;
                    
                 }
                 cout <<endl;
                 //3. Satır
                   cout<<"#---------#"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi;i++)
                 {
                    cout<<"*-----*" <<"  ";
                 }
                 cout <<endl;
                 //4.Satır
                  cout<<"#"<<arananSayimiz;
                  bosYaz(sayimizinBasamakAdedi);
                  cout<<"#  "<<"";
                  Basamak*geciciSayi=basamak;
                   for(int i=0;i<sayimizinBasamakAdedi;i++)
                 {
                    cout<<"*  " <<geciciSayi->veri<<"  *"<<"  ";
                    geciciSayi=geciciSayi->sonraki;
                 }
                 cout <<endl;
                 //5.Satır
                  cout<<"###########"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi;i++)
                 {
                    cout<<"*******" <<"  ";
                 }
                
                 cout <<endl<<endl;
            }
        }

        void SayiListesi::Yazdir() 
          {   
         Sayi* gecici3 = ilkSayi;
        

         while(gecici3 !=0)
         {
            int sayimiz= gecici3->sayi;
        Basamak*gecici3b = gecici3->ilkBasamak;
        Basamak*gecici3b2 = gecici3->ilkBasamak;
            int sayimizinBasamakAdedi2=0;
                  while (sayimiz != 0) {
                        sayimiz /= 10;
                        sayimizinBasamakAdedi2++;
                 }
        //İlk satırın kodları

                 cout<<"###########"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi2;i++)
                 {
                    cout<<"*******" <<"  ";
                 }
                 cout << endl;
        //İkinci Satırın Kodları
                
                cout<<"#";
                    cout<<hex<<setw(9)<<setfill('0')<<gecici3;
                    cout<<dec<<"#  ";
                for(int i=0;i<sayimizinBasamakAdedi2;i++)
                {
                    Basamak* gecici2=gecici3b;
                        uintptr_t address = reinterpret_cast<uintptr_t>(gecici2);
                        uintptr_t lastThreeDigits = address & 0xFFF;

                    
                    cout<<"* ";
                    cout<<hex<<setw(3)<<setfill('0')<<lastThreeDigits;
                    cout<<dec<<" *  ";
                   
                   gecici3b=gecici3b->sonraki;
                }
                delete gecici3b;
                cout<<endl;
        // 3.Satırın Kodları
                   cout<<"#---------#"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi2;i++)
                 {
                    cout<<"*-----*" <<"  ";
                 }
                 cout<<endl;
        //4. Satırın Kodları 
            cout<<"#"<<gecici3->sayi;
            bosYaz(sayimizinBasamakAdedi2);
            cout<<"#"<<"  ";
        /*-------------------*/
             for(int i=0;i<sayimizinBasamakAdedi2;i++)
                 {
                    cout<<"*  "<<gecici3b2->veri<<"  *  ";
                    gecici3b2=gecici3b2->sonraki;
                 }
                cout<<endl;
        //5.Satırın Kodları
          cout<<"###########"<<"  ";
                 for(int i=0;i<sayimizinBasamakAdedi2;i++)
                 {
                    cout<<"*******" <<"  ";
                 }
                 cout << endl;
                 cout << endl;

            gecici3=gecici3->sonrakiSayi;
         }
    }
    void SayiListesi::EnBuyukSil() {
    Sayi* current = ilkSayi;
    Sayi* enBuyuk = current;
    int max = current->sayi;

    while (current != nullptr) {
        if (current->sayi > max) {
            max = current->sayi;
            enBuyuk = current;
        }
        current = current->sonrakiSayi;
    }

    // En büyük elemanı bulduk, şimdi listeden çıkaralım
    if (enBuyuk == ilkSayi) {
        ilkSayi = enBuyuk->sonrakiSayi;
    } else {
        current = ilkSayi;
        while (current->sonrakiSayi != enBuyuk) {
            current = current->sonrakiSayi;
        }
        current->sonrakiSayi = enBuyuk->sonrakiSayi;
    }

    // En büyük elemanı temizle
    delete enBuyuk;

      
}
Basamak* SayiListesi::tersCevir(Basamak* basamak) {
    Basamak* prev = nullptr;
    Basamak* current = basamak;
    Basamak* next = nullptr;

    while (current != nullptr) {
        next = current->sonraki;
        current->sonraki = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void SayiListesi::basamaklariTersCevir()  {
        Sayi* current = ilkSayi;

        while (current != nullptr) {
            current->ilkBasamak = tersCevir(current->ilkBasamak);
            current = current->sonrakiSayi;
        }
    }

    Basamak* SayiListesi::tekleriBasaAl(Basamak* basamak) {
    Basamak* tekler = nullptr;
    Basamak* ciftler = nullptr;
    Basamak* teklerSonu = nullptr;
    Basamak* ciftlerSonu = nullptr;
    Basamak* current = basamak;

    while (current != nullptr) {
        if (current->veri % 2 != 0) {  // Eğer tek sayıysa
            if (tekler == nullptr) {
                tekler = current;
                teklerSonu = current;
            } else {
                teklerSonu->sonraki = current;
                teklerSonu = current;
            }
        } else {
            if (ciftler == nullptr) {
                ciftler = current;
                ciftlerSonu = current;
            } else {
                ciftlerSonu->sonraki = current;
                ciftlerSonu = current;
            }
        }
        current = current->sonraki;
    }

    if (tekler != nullptr) {
        teklerSonu->sonraki = ciftler;
        if (ciftler != nullptr) {
            ciftlerSonu->sonraki = nullptr;
        }
        return tekler;
    }

    return ciftler;
}
    void SayiListesi::tekleriBasaAl() {
        Sayi* current = ilkSayi;

        while (current != nullptr) {
            current->ilkBasamak = tekleriBasaAl(current->ilkBasamak);
            current = current->sonrakiSayi;
        }
    }
