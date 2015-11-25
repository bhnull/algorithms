
void quicksort(int a[], int l, int r)
{
    if (l < r) {
        int i = l, j = r, p = a[l];

        while (i < j) {
            while (a[j] > p && i < j)
                j--;
            a[i] = a[j];
            while (a[i] <= p && i < j)
                i++;
            a[j] = a[i];
        }

        a[i] = p;

        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
    }
}

int main(void)
{
    int a[] = {500, 7, 899, 9, 9, 9, 9, 9, 9, 20, 60, 80};

    quicksort(a, 0, sizeof(a)/sizeof(a[0]) - 1);

    return 0;
}
