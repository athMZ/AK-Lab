#include <iostream> // Biblioteka wej�cia/wyj�cia strumieniowego.
#include <bitset> // Biblioteka do operacji na bitach.
#include <limits> // Biblioteka do uzyskiwania informacji o ograniczeniach typ�w danych.
#include <iomanip> // Biblioteka do manipulacji strumieniami, np. do ustawienia precyzji wyj�cia.
#include <cmath> // Biblioteka do oblicze� matematycznych

// Funkcja szablonowa do wy�wietlania binarnej reprezentacji 32-bitowego typu danych.
template<typename T>
void show_32_bits(T tmp) {
	const unsigned int tmpSize = 32; // Rozmiar (liczba bit�w) do wy�wietlenia.
	unsigned long int bits = *(unsigned long int*) (&tmp); // Konwersja wska�nika na zmienn� tmp na typ unsigned long int i odczytanie bit�w.
	std::bitset<tmpSize> tmpBits(bits); // Utworzenie obiektu bitset o podanej liczbie bit�w.
	std::cout << tmpBits << "\t" << tmpSize << " bits" << "\t" << std::fixed << std::setprecision(20) << tmp << std::endl;
}

// Funkcja szablonowa do wy�wietlania binarnej reprezentacji 64-bitowego typu danych.
template<typename T>
void show_64_bits(T tmp) {
	const unsigned int tmpSize = 64; // Rozmiar (liczba bit�w) do wy�wietlenia.
	unsigned long long int bits = *(unsigned long long int*) (&tmp); // Konwersja wska�nika na zmienn� tmp na typ unsigned long long int i odczytanie bit�w.
	std::bitset<tmpSize> tmpBits(bits); // Utworzenie obiektu bitset o podanej liczbie bit�w.
	std::cout << tmpBits << "\t" << tmpSize << " bits" << "\t" << std::fixed << std::setprecision(20) << tmp << std::endl;
}

void SumAndTest() {

	double a, b, expected;

	std::cout << "Podaj a:" << std::endl;
	std::cin >> a;
	std::cout << "Podaj b:" << std::endl;
	std::cin >> b;

	std::cout << "Podaj oczekiwana wartosc dodawania: " << std::endl;
	std::cin >> expected;

	std::cout << "Wynik: a + b = " << a + b << std::endl;
	std::cout << "Wartosc oczekiwana: " << expected << std::endl;
	std::cout << "Czy wynik = wartosc oczekiwana: " << ((a + b) == expected) << std::endl;
}

void Loop() {

	float suma = 0;
	int expected = 1;

	for (int i = 0; i < 100; i++) {
		suma += 0.1;

		if (i % 10 == 0) {
			std::cout << "Wartosc w petli: " << suma << std::endl;

			float delta = abs(suma - expected);

			std::cout << "Wartosc oczekiwana: " << expected << std::endl;
			std::cout << "Roznica: " << delta << std::endl;
			std::cout<<std::endl;

			expected++;
		}
	}

}

int main() {
	int a = -91; // Przyk�adowa zmienna typu int.
	show_32_bits(a); // Wywo�anie funkcji show_32_bits zmienn� a.

	int b = 91; // Przyk�adowa zmienna typu int.
	show_32_bits(b); // Wywo�anie funkcji show_32_bits zmienn� b.

	int c = std::numeric_limits<int>::min(); // Pobranie minimalnej warto�ci typu int.
	show_32_bits(c); // Wywo�anie funkcji show_32_bits zmienn� c.

	int d = std::numeric_limits<int>::max(); // Pobranie maksymalnej warto�ci typu int.
	show_32_bits(d); // Wywo�anie funkcji show_32_bits zmienn� d.

	double e = -100; // Przyk�adowa zmienna typu double.
	show_64_bits(e); // Wywo�anie funkcji show_64_bits zmienn� e.

	double f = std::numeric_limits<double>::max(); // Pobranie maksymalnej warto�ci typu double.
	show_64_bits(f); // Wywo�anie funkcji show_64_bits zmienn� f.

	std::cout << "------------" << std::endl;

	//Badanie zakresu typu int
	int intMin = std::numeric_limits<int>::min();
	int intMax = std::numeric_limits<int>::max();

	std::cout << "int:" << std::endl;
	show_32_bits(intMin);
	show_32_bits(intMax);

	//Badanie zakresu typu float
	float floatMin = std::numeric_limits<float>::min();
	float floatMax = std::numeric_limits<float>::max();

	std::cout << "float:" << std::endl;
	show_32_bits(floatMin);
	show_32_bits(floatMax);

	//Badanie zakresu typu double
	double doubleMin = std::numeric_limits<double>::min();
	double doubleMax = std::numeric_limits<double>::max();

	std::cout << "double:" << std::endl;
	show_64_bits(doubleMin);
	show_64_bits(doubleMax);

	std::cout << "------------" << std::endl;

	//Por�wnywanie reprezentacji liczby 124:
	int intTest = 124;
	show_32_bits(intTest);

	float floatTest = 124.0f;
	show_32_bits(floatTest);

	double doubleTest = 124.0;
	show_64_bits(doubleTest);

	std::cout << "------------" << std::endl;

	int int91 = 91;
	show_32_bits(int91);

	int int_100 = -100;
	show_32_bits(int_100);

	int int60 = 60;
	show_32_bits(int60);

	std::cout << "------------" << std::endl;

	SumAndTest();

	std::cout << "------------" << std::endl;

	Loop();

	return 0;
}