#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>

void Zadanie2() {

	std::cout << std::endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl << std::endl;
	std::cout << "Zadanie 2 - badanie granic adresow" << std::endl;

	//Typy do sprawdzenia: char, int, float, double, __m128i (zwi¹zany z technologi¹ SIMD SSE) i  __m256i (zwi¹zany z technologi¹ SIMD AVX)

	char tmp_char;
	std::cout << "---------" << "char" << "---------" << std::endl;

	// Pêtla dla wartoœci "i" od 0 do 7
	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_char;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	int tmp_int;
	std::cout << "---------" << "int" << "---------" << std::endl;

	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_int;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	float tmp_float;
	std::cout << "---------" << "float" << "---------" << std::endl;

	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_float;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	double tmp_double;
	std::cout << "---------" << "double" << "---------" << std::endl;

	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_double;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	__m128i tmp_m128i;
		std::cout << "---------" << "__m128i" << "---------" << std::endl;

	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_m128i;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	__m256i tmp_m256i;
	std::cout << "---------" << "__m256i" << "---------" << std::endl;

	for (int i = 0; i < 8; ++i) {
		int granica = 1 << i; // Obliczamy granicê jako potêgê dwojki (2 do potêgi "i")

		// Pobieramy adres zmiennej "tmp" i zapisujemy jego wartoœæ w zmiennej "adres"
		long long adres = (long long)&tmp_m256i;

		// Wypisujemy informacje o adresie i badanej granicy
		std::cout << "Czy adres: ";
		std::cout << adres;
		std::cout << " jest dopasowany do granicy ";
		std::cout << granica;
		std::cout << " bajtow? ";
		std::cout << std::endl;

		// Sprawdzamy, czy adres jest dopasowany do badanej granicy
		if (adres % granica) {
			std::cout << "Adres nie jest dopasowany do badanej granicy " << granica
				<< " bajtow.";
		}
		else {
			std::cout << "Adres jest dopasowany do badanej granicy " << granica <<
				" bajtow.";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void Zadanie2_2() {
	struct tmpData1 {
		int a;
		double b;
		int c;
	};

	struct tmpData2 {
		int a;
		int c;
		double b;
	};

	struct tmpData3 {
		double b;
		int a;
		int c;
	};

	std::cout << std::endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl << std::endl;
	std::cout << "Zadanie 2.2 - badanie rozmiaru struktury" << std::endl;
	std::cout << "a - int, b - double, c - int" << std::endl;
	std::cout << "Kolejnosc: a, b, c: " << sizeof(tmpData1) << std::endl;
	std::cout << "Kolejnosc: a, c, b: " << sizeof(tmpData2) << std::endl;
	std::cout << "Kolejnosc: b, a, c: " << sizeof(tmpData3) << std::endl;
}

void Zadanie3() {
	struct tmpData1 {
		char a;
		double b;
		int c;
		double d;
		char e;
	};

	struct tmpData2 {
		char a;
		char e;
		int c;
		double b;
		double d;
	};

	struct tmpData3 {
		double b;
		double d;
		char a;
		char e;
		int c;
	};

	struct tmpData4 {
		int c;
		char a;
		double b;
		char e;
		double d;
	};

	struct tmpData5 {
		int c;
		double b;
		char a;
		double d;
		char e;
	};

	std::cout << std::endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl << std::endl;
	std::cout << "Zadanie 3 - optymalizowanie rozmiaru struktury" << std::endl;

	std::cout << "char, double, int, double, char: " << sizeof(tmpData1) << std::endl;
	std::cout << "char, char, int, double, double: " << sizeof(tmpData2) << std::endl;
	std::cout << "double, double, char, char, int: " << sizeof(tmpData3) << std::endl;
	std::cout << "int, char, double, char, double: " << sizeof(tmpData4) << std::endl;
	std::cout << "int, double, char, double, char: " << sizeof(tmpData5) << std::endl;

}

int main() {
	Zadanie2();
	Zadanie2_2();
	Zadanie3();

	return 0;
}
