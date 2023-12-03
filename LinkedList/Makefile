# Varsayılan hedef
all: derle bagla calistir

# Derleme kuralları
derle:
	g++ -I ./include/ -c ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -I ./include/ -c ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -I ./include/ -c ./src/SayiListesi.cpp -o ./lib/SayiListesi.o

# Bağlama kuralı
bagla:
	g++ -I ./include/ -o ./bin/program ./src/main.cpp ./lib/Basamak.o ./lib/Sayi.o ./lib/SayiListesi.o

# Çalıştırma kuralı
calistir:
	./bin/program
# Temizleme kuralı
temizle:
	rm -f ./lib/*.o
	rm -f ./bin/program