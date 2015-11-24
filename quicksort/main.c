
void quicksort(int a[], int min, int max)
{
    int temp, i = min, j = max;

    if (min >= max)
        return;

    while (i < j) {
        while (a[j] >= a[i] && i < j)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

        while (a[i] <= a[j] && i < j)
            i++;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    quicksort(a, min, i - 1);
    quicksort(a, j + 1, max);
}

int main(void)
{
    int a[] = {500, 7, 899, 9, 20, 60, 20};

    quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);

    return 0;
}
