#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	FILE* in = fopen("pairup.in", "r");
	int n, a, b, total = 0, numCows = 0;
	fscanf(in, "%d\n", &n);
	int i = 0;
	for (i = 0; i < n; i++) {
		fscanf(in, "%d %d\n", &a, &b);
		total += a*b;
		numCows += a;
	}
	double avg = (double) (total << 1) / numCows;
	//printf("%f\n", avg);
	rewind(in);
	fscanf(in, "%d\n", &n);
	int list[numCows], counter = 0, j = 0;

	for (i = 0; i < n; i++) {
		fscanf(in, "%d %d\n", &a, &b);
		for (j = 0; j < a; j++) {
			list[counter] = b;
			counter++;
		}
	}
	int min = -1;
	int minNum = 0;
	int max = 0;
	for (i = 0; i < numCows; i++) {
		//printf("%d\n", list[i]);
		for (j = 0; j < numCows; j++) {
			if (j == i) {
				continue;
			}
			//printf("%d %d\n", i, j);
			if (min == -1 || abs(list[j] + list[i] - avg) < min) {
				minNum = list[i] + list[j];
				min = abs(list[j] + list[i] - avg);
				//printf("%d\n\n", min);
			}
		}
		if (minNum > max) {
			max = minNum;
		}
	}
	//printf("%d\n", max);
	fclose(in);

	FILE* out = fopen("pairup.out", "w");
	fprintf(out, "%d", max);
	fclose(out);

	return 0;
}
