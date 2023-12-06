#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int binaryToDecimal(string binary) {
	return bitset<32>(binary).to_ulong();
}

string RemoveLeadingZeros(string str) {
	str.erase(0, std::min(str.find_first_not_of('0'), str.size() - 1));
	return str;
}

string ConvertToBinary(int number) {
	std::string str = bitset<32>(number).to_string();
	str = RemoveLeadingZeros(str);
	return str;
}

string ConvertToOct(int number) {
	std::stringstream stream;
	stream << std::oct << number;
	std::string result(stream.str());

	return result;
}

string ConvertToHex(int number) {
	std::stringstream stream;
	stream << std::hex << number;
	std::string result(stream.str());

	return result;
}

string AddBinary(string a, string b) {
	if (a.length() > b.length())
		return AddBinary(b, a);

	int diff = b.length() - a.length();

	string padding;
	for (int i = 0; i < diff; i++)
		padding.push_back('0');

	a = padding + a;

	string result;
	char carry = '0';

	for (int i = a.length() - 1; i >= 0; i--)
	{
		if (a[i] == '1' && b[i] == '1') {
			if (carry == '1')
				result.push_back('1'), carry = '1';
			else
				result.push_back('0'), carry = '1';
		}
		else if (a[i] == '0' && b[i] == '0') {
			if (carry == '1')
				result.push_back('1'), carry = '0';
			else
				result.push_back('0'), carry = '0';
		}
		else if (a[i] != b[i]) {
			if (carry == '1')
				result.push_back('0'), carry = '1';
			else
				result.push_back('1'), carry = '0';
		}
	}

	if (carry == '1')
		result.push_back(carry);

	reverse(result.begin(), result.end());

	result = RemoveLeadingZeros(result);

	return result;
}

string SubtractBinary(string a, string b) {
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	string result = "";

	while (i >= 0 || j >= 0) {
		int sum = carry;
		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum -= b[j--] - '0';

		if (sum < 0) {
			sum += 2;
			carry = -1;
		}
		else {
			carry = 0;
		}

		result += to_string(sum);
	}

	reverse(result.begin(), result.end());

	return result;
}

string MultiplyBinary(string a, string b) {
	int n = a.size(), m = b.size();
	vector<int> result(n + m, 0);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[i + j] += (a[i] - '0') * (b[j] - '0');
		}
	}

	for (int i = 0; i < n + m; i++) {
		if (result[i] >= 2) {
			result[i + 1] += result[i] / 2;
			result[i] %= 2;
		}
	}

	string finalResult = "";
	bool found = false;
	for (int i = n + m - 1; i >= 0; i--) {
		if (!found && result[i] == 0)
			continue;
		found = true;
		finalResult += to_string(result[i]);
	}

	return finalResult == "" ? "0" : finalResult;
}

string DivideBinary(string a, string b) {

	int decimalA = binaryToDecimal(a);
	int decimalB = binaryToDecimal(b);

	if (decimalB == 0) return "B jest 0!";

	return RemoveLeadingZeros(bitset<32>(decimalA / decimalB).to_string());

}

int OctalToDecimal(int octalNumber)
{
	int decimalNumber = 0, i = 0, rem;
	while (octalNumber != 0)
	{
		rem = octalNumber % 10;
		octalNumber /= 10;
		decimalNumber += rem * pow(8, i);
		++i;
	}
	return decimalNumber;
}

int HexToDecimal(string hex) {
	int decimalNumber = std::stoi(hex, nullptr, 16);
	return decimalNumber;
}

void Konwersje() {
	cout <<endl<< "Konwersje: " << endl;
	int liczba = 0;
	do {
		cout << "Podaj liczbe w systemie 10 wieksza od 0: ";
		cin >> liczba;
	} while (liczba < 0);

	cout << "Liczba w systemie 2: " << ConvertToBinary(liczba) << endl;
	cout << "Liczba w systemie 8: " << ConvertToOct(liczba) << endl;
	cout << "Liczba w systemie 16: " << ConvertToHex(liczba) << endl;
}

void Op_Arytmetyczne() {
	cout << endl << "Operacje arytmetyczne - system 2:" << endl;

	string liczbaA = "", liczbaB = "";
	cout << "Podaj dwie liczby w systemie 2: " << endl;
	cout << "Liczba a: "; cin >> liczbaA;
	cout << "Liczba b: "; cin >> liczbaB;

	string suma = AddBinary(liczbaA, liczbaB);
	string roznica = SubtractBinary(liczbaA, liczbaB);
	string iloczyn = MultiplyBinary(liczbaA, liczbaB);

	cout << "Suma: " << suma << endl;
	cout << "Roznica: " << roznica << endl;
	cout << "Iloczyn: " << iloczyn << endl;
}

void Oct_Ten_Bin() {

	int octalNumber;

	std::cout << "Podaj liczbe w systemie 8: ";
	std::cin >> octalNumber;

	int decimalNumber = OctalToDecimal(octalNumber);
	auto binNumber = ConvertToBinary(decimalNumber);

	cout << "System 8: " << octalNumber << endl;
	cout << "System 10: " << decimalNumber << endl;
	cout << "System 2: " << binNumber << endl;
}

void Hex_Dec_Bin() {
	string hexNumber;

	std::cout << "Podaj liczbe w systemie 16: ";
	std::cin >> hexNumber;

	int dec = HexToDecimal(hexNumber);
	auto binNumber = ConvertToBinary(dec);

	cout << "System 16: " << hexNumber << endl;
	cout << "System 10: " << dec << endl;
	cout << "System 2: " << binNumber << endl;
}

void Zadanie2_1() {
	cout << "Zadanie 2.1:" << endl;
	Konwersje();
	Op_Arytmetyczne();
	Oct_Ten_Bin();
	Hex_Dec_Bin();
}

void Zadanie2_2() {

	string l1, l2;

	cout << endl << "Zadanie 2.2:" << endl << endl;
	cout << "Podaj liczby binarne:" << endl;
	cout << "Liczba 1: "; cin >> l1;
	cout << "Liczba 2: "; cin >> l2;

	cout << "l1 + l2 = " << AddBinary(l1, l2) << endl;
	cout << "l1 - l2 = " << SubtractBinary(l1, l2) << endl;
	cout << "l1 * l2 = " << MultiplyBinary(l1, l2) << endl;
	cout << "l1 / l2 = " << DivideBinary(l1, l2) << endl;
}

void Zadanie2_3() {

	int x, y;

	cout << endl << "Zadanie 2.3:" << endl << endl;
	cout << "Podaj liczbe x: "; cin >> x;
	cout << "Podaj liczbe n: "; cin >> y;

	cout << "(x << 1) & (y >> 1) = " << ((x << 1) & (y >> 1)) << endl;
	cout << "( (x ^ y) >> 2) | (y << 3) = " << (((x ^ y) >> 2) | (y << 3)) << endl;
	cout << "~x & (y << 2)) ^ ( (x << 1) >> 1) = " << (~x & (y << 2) ^ ((x << 1) >> 1)) << endl;
}

int main()
{
	Zadanie2_1();
	Zadanie2_2();
	Zadanie2_3();
}