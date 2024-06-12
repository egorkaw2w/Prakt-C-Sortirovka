#include <iostream>
#include <thread>
#include <vector>
#include <limits>
#include <locale>
#include <codecvt>

using namespace std;
class MergeSort {
public:
    void Sort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            Sort(arr, left, mid);
            Sort(arr, mid + 1, right);

            Merge(arr, left, mid, right);
        }
    }

    void Merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

int main() {
    locale::global(locale("ru_RU.UTF-8"));

    vector<int> arr(10);

    MergeSort mergeSort;
    while (true) {


        for (int i = 0; i < 10; i++) {
            cout << "Введите число " << i + 1 << ": ";

            int num;
            while (!(cin >> num)) {
                cout << "Некорректный ввод. Пожалуйста, введите число." << endl;
                cout << "Введите число " << i + 1 << ": ";
            }

            arr[i] = num;
        }

        thread mergeSortThread([&]() {
            mergeSort.Sort(arr, 0, arr.size() - 1);
            });

        mergeSortThread.join();

        cout << "Отсортированный массив: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }
        return 0;
}