#include "../Header/Basic.hpp"
#include "../Header/Color.hpp"

int RandColorRGB(int * R, int * G, int * B)
{
	Sleep(rand() % (1 + 150));
	srand((unsigned int)time(NULL));
	int INNER_R = rand() % (1 + 255);
	Sleep(rand() % (1 + 150));
	srand((unsigned int)time(NULL));
	int INNER_G = rand() % (1 + 255);
	Sleep(rand() % (1 + 150));
	srand((unsigned int)time(NULL));
	int INNER_B = rand() % (1 + 255);

#ifdef _DEBUG
	printf("STR   INNER_R=%d,INNER_G=%d,INNER_B=%d\n", INNER_R, INNER_G, INNER_B);
#endif // _DEBUG

	while (abs(INNER_R - INNER_G) <= 10)
	{
		srand((unsigned int)time(NULL));
		if ((rand() % (1 + 10)) >= 6)
		{
			Sleep(rand() % (1 + 50));
			srand((unsigned int)time(NULL));
			INNER_R -= rand() % (1 + 50);
		}
		else
		{
			Sleep(rand() % (1 + 50));
			srand((unsigned int)time(NULL));
			INNER_R -= rand() % (1 + 50);
		}
		if (INNER_R > 255)
		{
			INNER_R = 255;
		}
		if (INNER_R < 0)
		{
			INNER_R = 0;
		}
	}
	Sleep(250);
	while (abs(INNER_G - INNER_B) <= 10)
	{
		srand((unsigned int)time(NULL));
		if ((rand() % (1 + 10)) >= 6)
		{
			Sleep(rand() % (1 + 50));
			srand((unsigned int)time(NULL));
			INNER_G -= rand() % (1 + 50);
		}
		else
		{
			Sleep(rand() % (1 + 50));
			srand((unsigned int)time(NULL));
			INNER_G += rand() % (1 + 50);
		}
		if (INNER_G > 255)
		{
			INNER_G -= 255;
		}
		if (INNER_G < 0)
		{
			INNER_G += 255;
		}
	}
#ifdef _DEBUG
	printf("FIN   INNER_R=%d,INNER_G=%d,INNER_B=%d\n", INNER_R, INNER_G, INNER_B);
#endif // _DEBUG

	*R = INNER_R;
	*G = INNER_G;
	*B = INNER_B;

	return 0;
}