#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX_CAR = 1000000;

struct Car {
	int age;
	int partition;
	int engine;
	int price;
};

void buy(Car *car)
{
	car->age = rand() % 20;
	car->partition = 2 + rand() % 11;
	car->engine = 1000 + rand() % 4000;
	car->price = 10000 + rand() % 30000;
}

extern void store(Car car);

extern void filter_age(int from, int to);
extern void filter_partition(int from, int to);
extern void filter_engine(int from, int to);
extern void filter_price(int from, int to);

extern int sell();

extern void refund(int order_number);

extern int stock(void);

int main()
{
	int TS = 10;
	int order_number, refund_number = -1;

	srand(3);

	clock_t T1 = clock();

	for (int t = 1; t <= 10; t++)
	{
		for (int i = 1; i <= MAX_CAR; i++)
		{
			Car *car = new Car();

			buy(car);
			store(*car);

			if (i % 100 == 0)
			{
				filter_age(rand() % 20, rand() % 20);
				filter_partition(2 + rand() % 11, 2 + rand() % 11);
				filter_engine(1000 + rand() % 4000, 1000 + rand() % 4000);
				filter_price(10000 + rand() % 30000, 10000 + rand() % 30000);

				order_number = sell();
				if (rand() % 10 == 0)
					refund_number = order_number;
			}
			if (i % 10000 == 0)
			{
				if (refund_number != -1)
				{
					refund(refund_number);
					refund_number = -1;
				}
			}
		}

		int STOCK = stock();
		refund_number = -1;
		printf("STOCK : %d\n", STOCK);
	}

	clock_t T2 = clock();
	long PERFORMENCE = T2 - T1;

	printf("PERFORMENCE : %d", PERFORMENCE);
	return 0;
}
