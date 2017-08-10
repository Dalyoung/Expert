typedef long long ll;
const int Q = 1234567891;

struct mat_t {
	ll m[27][27];
	mat_t() : m{ 0, } {};
};

mat_t operator*(const mat_t &A, const mat_t &B) {
	mat_t ret;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			for (int k = 0; k < 27; k++) {
				ret.m[i][j] = (ret.m[i][j] + A.m[i][k] * B.m[k][j] % Q) % Q;
			}
		}
	}
	return ret;
}

mat_t operator*(const int A, const mat_t &B) {
	mat_t ret;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			ret.m[i][j] = B.m[i][j] * A % Q;
		}
	}
	return ret;
}

mat_t operator+(const mat_t &A, const mat_t &B) {
	mat_t ret;
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			ret.m[i][j] = (A.m[i][j] + B.m[i][j]) % Q;
		}
	}
	return ret;
}

bool operator==(const mat_t &A, const mat_t &B) {
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 27; j++) {
			if (A.m[i][j] != B.m[i][j]) return false;
		}
	}
	return true;
}

mat_t R[30];
mat_t E;
ll Ans[27]; // answer
ll B[27]; // base

mat_t r(int exponent) { // R^exponent
	mat_t retval(E);
	int p = 0;
	while (exponent > 0)
	{
		if (exponent & 1) retval = retval*R[p];
		exponent /= 2;
		p++;
	}
	return retval;
}

mat_t sum_r(int exponent) { // R + R^2 + R^3 + ... + R^exponent
	mat_t retval;
	int half = exponent / 2;
	if (exponent == 1) {
		return R[0];
	}
	else if (exponent & 1) { // 홀수
		retval = (E + r(half))*sum_r(half) + r(exponent);
	}
	else if (exponent > 0) {
		retval = (E + r(half))*sum_r(half);
	}
	return retval;
}
