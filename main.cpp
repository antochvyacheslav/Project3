#include <cstdio>
#include <cstring>
#include <vector>

//���� ��� �������� ��������
struct Pair {
	int X;
	int Y;
};

//����� ��� �������� ������������������ ��������, ������� ����������� �� ��������� X
class PairSequence {
public:
	//�����������
	PairSequence(Pair* pair, unsigned int count) { 
		for (unsigned int i = 0; i < count; i++) {
			this->pair.push_back(pair[i]);
		}
	}
public:
	//����� � ������
	void Trace(const char* str) {
		printf("%s", str);
		for (unsigned int i = 0; i < pair.size(); i++) {
			printf("(%d, %d) ", pair[i].X, pair[i].Y);
		}
		printf("\n\n");
	}
	//������� ������������: � ������ ��������������������� ���������� �������� �������� ������ ������ � ��������� �������, � ��� �� ������ n-��� ������ (n > 2)
	void PairMakeLessOften(int n) {
		int cnt = 0;
		int j = 0;
		//������� ������ ������ �����������, ������� ����� ���������� � 1
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
		//��������� ������ ���� ������ �����������
		pair[j++] = pair[pair.size() - 1];
		pair.resize(j);
	}
private:
	//������ ��� �������� ������������������ ��������
	std::vector <Pair> pair;
};

//������� ��� ������������ ������������ ������������������ ��������
void TestPairMakeLessOften(Pair* pair, int count, int n, const char* str) {
	PairSequence pair_sequence(pair, count);
	pair_sequence.PairMakeLessOften(n);
	pair_sequence.Trace(str);
}

int main() {
	//�������� ������ ��������������� �������� � ������ ��������� (������ �����������)
	Pair pair[] = { {1, 10}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 10}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 10} };
	unsigned int count = sizeof(pair) / sizeof(pair[0]);
	//����� �� ����� ������������������ ��
	PairSequence pair_sequence(pair, count);
	pair_sequence.Trace("Original sequence: ");
	//������������ ������������������ � ����� �� ����� �����
	TestPairMakeLessOften(pair, count, 3, "Sequence for n=3: ");
	TestPairMakeLessOften(pair, count, 4, "Sequence for n=4: ");
	return 0;
}
