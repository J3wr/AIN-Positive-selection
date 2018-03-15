#include "declaration.h"
#include <string>
#include <random>

void init(vector<vector<int> > &S,
	vector<vector<int> > &R)
{
	S = {
			{ 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 },
			{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1 },
			{ 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 },
			{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 }
	};

	//    R.resize(10);
	//    for (size_t i = 0; i < R.size(); ++i)
	//        R[i].resize(12);

	//    for (size_t i = 0; i < R.size(); ++i)
	//            R[i] = generateCandidateToDetector();
}

int affinity(vector<int> &S,
	vector<int> &R)
{
	int aff = 0;
	for (size_t j = 0; j < S.size(); ++j)
	{
		if (S[j] != R[j])
			++aff;
	}

	return aff;
}

bool compare(vector<int> &S,
	vector<int> &R)
{
	if (affinity(S, R) < 2)
		return true;
	else
		return false;
}

void createDetectors(vector<vector<int> > &S,
	vector<vector<int> > &R)
{
	//    for (size_t i = 0; i < S.size(); ++i)
	//        for(size_t j = 0; j < R.size(); ++j)
	//            if (!compare(S[i], R[j]))
	//            {
	//                R.erase(R.begin() + j);
	//                R.push_back(generateCandidateToDetector();
	//                --j;
	//            }
	while (R.size() < 50)
	{
		vector<int> vec = generateCandidateToDetector();
		for (size_t i = 0; i < S.size(); ++i)
			if (compare(S[i], vec))
				R.push_back(vec);
	}

	//    for (size_t i = 0; i < R.size(); ++i)
	//    {
	//        for (size_t j = 0; j < R[0].size(); ++j)
	//            std::cout << R[i][j] << " ";
	//        std::cout << "\n";
	//    }
}

void algorithm(vector<vector<int> > &S,
	vector<vector<int> > &R)
{
	createDetectors(S, R);
	//    print("Enter picture: ");
	//    vector<int> picture;
	//    for (size_t i = 0; i < S[0].size(); ++i)
	//    {
	//        int j;
	//        std::cin >> j;
	//        picture.push_back(j);
	//    }
	vector<vector<int>> vec;
	vec = {
			{ 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },//1 na 2
			{ 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1 },//6 na 1
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//someone else
			{ 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 },//9 na 4
			{ 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 }//7
	};
	bool ret;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		for (size_t j = 0; j < R.size(); ++j)
		{
			ret = compare(R[j], vec[i]);
			if (ret)
				break;
		}

		if (ret)
			print("Own!");
		else
			print("Someone else!");
	}
}

void print(const std::string &str)
{
	std::cout << str << std::endl;
}

vector<int> generateCandidateToDetector()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	vector<int> vec;
	vec.resize(12);
	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] = dis(gen);

	return vec;
}
