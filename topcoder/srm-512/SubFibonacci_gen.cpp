#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
using namespace std;

void print(int S[], int N)
{
	printf("{");
	for (int i = 0; i < N; i++)
	{
		if (i) printf(", ");
		printf("%d", S[i]);
	}
	printf("}\n");
}

void print_add(int S[], int N, int M)
{
	for (int i = N; i < M; i++)
	{
		bool fail = true;
		while (fail)
		{
			fail = false;
			S[i] = rand() % 100000000 + 1;
			for (int j = 0; j < i; j++)
				if (S[i] == S[j])
					fail = true;
		}
	}
	
	print(S, M);
}

void randomize()
{
	int N = rand() % 49 + 2;
	int S[50];
	for (int i = 0; i < N; i++)
	{
		bool fail = true;
		while (fail)
		{
			fail = false;
			S[i] = rand() % 100000000 + 1;
			for (int j = 0; j < i; j++)
				if (S[i] == S[j])
					fail = true;
		}
	}
	print(S, N);
}

void cool(int a, int b)
{
	int n=0, s[50];
	s[n++] = a;
	s[n++] = b;
	
	while (true)
	{
		s[n] = s[n-1] + s[n-2];
		if (s[n] > 100000000)
			break;
		n++;
	}
	
	for (int i = 0; i < n; i++)
		printf("%d, ", s[i]);
	printf("\n");
}

bool comp[1000005];

int main()
{
	srand(time(NULL));
	
	int N, S[50];
	
	/*9
	printf("\n");
	cool(5, 12);
	printf("\n");
	cool(2, 10);
	printf("\n");
	return 0;
	*/
	
	// smallest case
	print(new int[2]{1, 2}, 2);
	
	// 1, 2, 3, ..., 50
	for (int i = 0; i < 50; i++)
		S[i] = i+1;
	print(S, 50);
	
	// 10^8, 10^8-1, ...
	for (int i = 0; i < 50; i++)
		S[i] = 100000000-i;
	print(S, 50);
	
	// 2^0, 2^1, 2^2, ...
	for (int i = 0; i < 27; i++)
		S[i] = 1<<i;
	print(S, 27);
	
	// 1, 2, 3, 5, ...
	S[0] = 1, S[1] = 2;
	for (int i = 2; i < 38; i++)
		S[i] = S[i-1] + S[i-2];
	print(S, 38);
	
	// 1, 3, 4, 7, ...
	S[0] = 1, S[1] = 3;
	for (int i = 2; i < 38; i++)
		S[i] = S[i-1] + S[i-2];
	print(S, 38);

	for (int i = 2; i*i <= 1000000; i++) if (!comp[i])
		for (int j = i*i; j <= 1000000; j += i)
			comp[j] = true;	
	int p;
	
	// 2, 3, 5, 7, ... (primes)
	p = 2;
	for (int i = 0; i < 50; i++)
	{
		while (comp[p]) p++;
		S[i] = p;
		p++;
	}
	print(S, 50);
	
	// 50 largest primes
	p = 1000000;
	for (int i = 49; i >= 0; i--)
	{
		while (comp[p]) p--;
		S[i] = p;
		p--;
	}
	print(S, 50);
	
	// tricky case
	print(new int[8]{5, 4, 3, 7, 8, 9, 17, 26}, 8);
	
	// very tricky case
	print(new int[6]{10, 14, 20, 100, 101, 201}, 6);
	
	// largest output (41)
	print(new int[41]{1, 2, 3, 5, 8, 13, 21, 34, 35, 39, 43, 82, 125, 207, 332, 539, 871, 1410, 2281, 3691, 5972, 9663, 15635, 25298, 40933, 66231, 107164, 173395, 280559, 453954, 734513, 1188467, 1922980, 3111447, 5034427, 8145874, 13180301, 21326175, 34506476, 55832651, 90339127}, 41);
	
	// result = 10
	print(new int[14]{1, 7, 8, 38, 61, 259, 353, 16454, 69700, 295254, 99999, 56, 8901, 23}, 14);
	
	// result = 6
	print(new int[8]{2673, 57, 906366, 22, 37, 17, 631, 7369}, 8);
	
	// result = 7
	print(new int[7]{29028664, 1, 7, 6, 13, 46969365, 75998029}, 7);
	
	// result = 12
	print_add(new int[12]{6, 10, 110, 178, 288, 466, 488, 3319, 8688, 22745, 31024085, 81222109}, 12, 50);

	// result = 13
	print_add(new int[13]{12, 42, 111, 471, 762, 1233, 1995, 3228, 41669, 67422, 109091, 1209838, 91963604}, 13, 44);
	
	// result = 8
	print_add(new int[8]{13, 512, 17681, 28602, 38849, 62859, 52990063, 85739723}, 8, 34);
	
	// result = 17
	print_add(new int[17]{1024, 2049, 3074, 5123, 21517, 34837, 56354, 91191, 113031, 295919, 774726, 1253533, 3281792, 5310051, 13901894, 22493737, 95284999}, 17, 50);
	
	// result = 11, 5 5 6
	print(new int[16]{104, 77, 181, 258, 439, 704, 1139, 1843, 2982, 4825, 451, 730, 1181, 1911, 3092, 5003}, 16);

	// result = 20
	print_add(new int[20]{10, 11, 32, 138, 223, 584, 1529, 2474, 4003, 16957, 27437, 44394, 304281, 74528, 5460101, 8834629, 14294730, 23129359, 37424089, 60553448}, 20, 50);

	// result = 25
	print_add(new int[25]{102085, 165177, 267262, 432439, 699701, 1132140, 1831841, 2963981, 4795822, 7759803, 12555625, 20315428, 32871053, 53186481, 86057534, 7, 110, 117, 227, 344, 571, 915, 1486, 2401, 3887}, 25, 49);

	// result = 30
	print_add(new int[30]{1, 9, 10, 19, 29, 48, 77, 125, 202, 327, 529, 856, 1385, 2241, 3626, 5867, 9493, 15360, 24853, 40213, 65066, 79206, 128158, 207364, 335522, 542886, 878408, 1421294, 2299702, 3720996}, 30, 50);
	
	// result = around 35
	print(new int[40]{5, 11, 16, 27, 43, 70, 113, 183, 296, 479, 775, 1254, 2029, 3283, 5312, 8595, 2, 100, 102, 202, 304, 506, 810, 1316, 2126, 3442, 5568, 9010, 14578, 23588, 38166, 61754, 99920, 161674, 261594, 423268, 684862, 1108130, 1792992}, 40);
	
	// result = 38
	print_add(new int[38]{2, 10, 12, 22, 34, 56, 90, 146, 236, 382, 618, 1000, 1618, 2618, 4236, 6854, 11090, 17944, 29034, 46978, 76012, 122990, 199002, 321992, 520994, 842986, 1363980, 2206966, 3570946, 5777912, 9348858, 15126770, 24475628, 39602398, 64078026}, 38, 50);
		
	for (int i = 0; i < 10; i++)
		randomize();
}
