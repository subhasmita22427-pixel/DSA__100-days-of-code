#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

// Comparator for descending position
int compare(const void *a, const void *b) {

    struct Car *x = (struct Car *)a;
    struct Car *y = (struct Car *)b;

    return y->position - x->position;
}

int carFleet(int target, int position[], int speed[], int n) {

    struct Car cars[n];

    // Store car details
    for (int i = 0; i < n; i++) {

        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort by descending position
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double prevTime = 0;

    for (int i = 0; i < n; i++) {

        double time =
            (double)(target - cars[i].position) / cars[i].speed;

        // New fleet
        if (time > prevTime) {

            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}

int main() {

    int target, n;

    printf("Enter target: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    int ans = carFleet(target, position, speed, n);

    printf("Number of car fleets = %d\n", ans);

    return 0;
}
