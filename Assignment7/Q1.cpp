// Write a program to implement following sorting techniques:
// a. Selection Sort
// b. Insertion Sort
// c. Bubble Sort
// d. Merge Sort
// e. Quick Sort

// Time Complexity: O(n^2) for Selection, Insertion, Bubble; O(n log n) for Merge and Quick
// Space Complexity: O(1) for Selection, Insertion, Bubble; O(n) for Merge; O(log n) for Quick

#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int m = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[m])
        m = j;
    }
    int t = a[i];
    a[i] = a[m];
    a[m] = t;
  }
}

void insertionSort(int a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int x = a[i], j = i - 1;
    while (j >= 0 && a[j] > x)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
  }
}

void bubbleSort(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        int t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
    }
  }
}

void merge(int a[], int l, int m, int r)
{
  int n1 = m - l + 1, n2 = r - m;
  int x[n1], y[n2];
  for (int i = 0; i < n1; i++)
    x[i] = a[l + i];
  for (int i = 0; i < n2; i++)
    y[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (x[i] <= y[j])
      a[k++] = x[i++];
    else
      a[k++] = y[j++];
  }
  while (i < n1)
    a[k++] = x[i++];
  while (j < n2)
    a[k++] = y[j++];
}

void mergeSort(int a[], int l, int r)
{
  if (l >= r)
    return;
  int m = (l + r) / 2;
  mergeSort(a, l, m);
  mergeSort(a, m + 1, r);
  merge(a, l, m, r);
}

int partition(int a[], int l, int r)
{
  int p = a[r], i = l - 1;
  for (int j = l; j < r; j++)
  {
    if (a[j] <= p)
    {
      i++;
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  int t = a[i + 1];
  a[i + 1] = a[r];
  a[r] = t;
  return i + 1;
}

void quickSort(int a[], int l, int r)
{
  if (l < r)
  {
    int p = partition(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
  }
}

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << "\n";
}

int main()
{
  int n;
  cin >> n;
  int a[n], b[n], c[n], d[n], e[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = c[i] = d[i] = e[i] = a[i];
  }

  selectionSort(b, n);
  insertionSort(c, n);
  bubbleSort(d, n);
  mergeSort(a, 0, n - 1);
  quickSort(e, 0, n - 1);

  cout << "Selection Sort: ";
  print(b, n);
  cout << "Insertion Sort: ";
  print(c, n);
  cout << "Bubble Sort: ";
  print(d, n);
  cout << "Merge Sort: ";
  print(a, n);
  cout << "Quick Sort: ";
  print(e, n);

  return 0;
}
