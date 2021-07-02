#include <cstdio>
#include <cstring>
#include <vector>

//Пара для хранения отсчётов
struct Pair {
	int X;
	int Y;
};

//Класс для хранения последовательности отсчётов, отсчёты упорядочены по значениям X
class PairSequence {
public:
	//Конструктор
	PairSequence(Pair* pair, unsigned int count) { 
		for (unsigned int i = 0; i < count; i++) {
			this->pair.push_back(pair[i]);
		}
	}
public:
	//Вывод в трассу
	void Trace(const char* str) {
		printf("%s", str);
		for (unsigned int i = 0; i < pair.size(); i++) {
			printf("(%d, %d) ", pair[i].X, pair[i].Y);
		}
		printf("\n\n");
	}
	//Функция прореживания: в каждой подпоследовательности идентичных отсчётов оставить только первый и последний отсчёты, а так же каждый n-ный отсчёт (n > 2)
	void PairMakeLessOften(int n) {
		int cnt = 0;
		int j = 0;
		//нулевой символ всегда сохраняется, поэтому нужно нумеровать с 1
		pair[j++] = pair[0];
		for (unsigned int i = 1; i < pair.size() - 1; i++) {
			if (pair[i].Y != pair[i + 1].Y) {
				pair[j++] = pair[i];
				cnt = 0;
			}
			else {
				if (cnt % (n - 1) == 0) {
					pair[j++] = pair[i];
				}
				cnt++;
			}
		}
		//последний символ тоже всегда сохраняется
		pair[j++] = pair[pair.size() - 1];
		pair.resize(j);
	}
private:
	//Вектор для хранения последовательности отсчётов
	std::vector <Pair> pair;
};

//Функция для тестирования прореживания последовательности отсчётов
void TestPairMakeLessOften(Pair* pair, int count, int n, const char* str) {
	PairSequence pair_sequence(pair, count);
	pair_sequence.PairMakeLessOften(n);
	pair_sequence.Trace(str);
}

int main() {
	//Исходные данные непосредственно заданные в тексте программы (жёсткое кодирование)
	Pair pair[] = { {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10} };
	unsigned int count = sizeof(pair) / sizeof(pair[0]);
	//Вывод на экран последовательности до
	PairSequence pair_sequence(pair, count);
	pair_sequence.Trace("Original sequence: ");
	//Прореживание последовательности и вывод на экран после
	TestPairMakeLessOften(pair, count, 3, "Sequence for n=3: ");
	TestPairMakeLessOften(pair, count, 4, "Sequence for n=4: ");
	return 0;
}
