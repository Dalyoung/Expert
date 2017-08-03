
struct Car {
	int age;
	int partition;
	int engine;
	int price;
};
const int MAX_CAR_NUM = 1000000;
Car car_list[MAX_CAR_NUM+1];
int check[MAX_CAR_NUM+1];
bool sel_list[100][MAX_CAR_NUM + 1];
bool is_sold[MAX_CAR_NUM + 1];
int index = 1;
int sel_index = -1;
int current_count = 100;

Car target_car_list[MAX_CAR_NUM + 1];
Car current_car_list[MAX_CAR_NUM + 1];

int age_count = 0;
Car after_age_car_list[MAX_CAR_NUM + 1];
int partition_count = 0;
Car after_partition_car_list[MAX_CAR_NUM + 1];
int engine_count = 0;
Car after_engine_car_list[MAX_CAR_NUM + 1];
int price_count = 0;
Car after_price_list[MAX_CAR_NUM + 1];

void store(Car car) {
	car_list[index] = car;
	index++;
}

void filter_age(int from, int to) {
	//printf("%d\n", current_count);
	if (from > to) {
		from ^= to;
		to ^= from;
		from ^= to;
	}
	for (int i = 1; i <= current_count; i++) {
		if (is_sold[i] == 0 && car_list[i].age >= from && car_list[i].age <= from) {
			check[i]++;
		}
	}
}

void filter_partition(int from, int to) {
	if (from > to) {
		from ^= to;
		to ^= from;
		from ^= to;
	}
	for (int i = 1; i <= current_count; i++) {
		if (is_sold[i] == 0 && car_list[i].partition >= from && car_list[i].partition <= from) {
			check[i]++;
		}
	}
}

void filter_engine(int from, int to) {
	if (from > to) {
		from ^= to;
		to ^= from;
		from ^= to;
	}
	for (int i = 1; i <= current_count; i++) {
		if (is_sold[i] == 0 && car_list[i].engine >= from && car_list[i].engine <= from) {
			check[i]++;
		}
	}
}

void filter_price(int from, int to) {
	if (from > to) {
		from ^= to;
		to ^= from;
		from ^= to;
	}
	for (int i = 1; i <= current_count; i++) {
		if (is_sold[i] == 0 && car_list[i].price >= from && car_list[i].price <= from) {
			check[i]++;
		}
	}
}

int sell() {
	sel_index++;
	
	for (int i = 1; i <= current_count; i++) {
		// filter에 모두 포함되면 check 가 4
		if (is_sold[i] == 0 && check[i] == 4) {
			sel_list[sel_index][i] = 1;
			is_sold[i] = 1;
		}
	}


	// sell 후 check 초기화..
	for (int i = 1; i <= current_count; i++) {
		check[i] = 0;
	}
	current_count += 100;
	return sel_index;
}

void refund(int order_number) {
}

int stock(void) {
		
	
	/*
	printf("---%d---", check[1]);
	sel_list[0][1] = true;
	printf("---%d---", sel_list[0][1]);
	for (int i = 1; i < 10; i++) {
		Car car = car_list[i];
		printf("%d, %d, %d, %d\n", car.age, car.engine, car.partition, car.price);
	}
	*/
	for (int i = 1; i <= MAX_CAR_NUM; i++) {
		check[i] = 0;
		is_sold[i] = 0;
	}
	for (int j = 0; j < 100; j++) {
		for (int i = 1; i <= MAX_CAR_NUM; i++) {
			sel_list[j][i] = 0;
		}
	}

	index = 1;
	sel_index = -1;
	current_count = 100;
	return 0;
}
