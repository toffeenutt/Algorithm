#include <iostream>
#include <string>

class info
{
public:
	int age;
	std::string name;
	info() {}

	bool operator<=(const info& b)
	{
		if (this->age <= b.age) return true;
		else return false;
	}
};

template <typename T>
void merge_sort(T* a, int low, int high)
{
	if (low != high)	//low == high인 경우는 한칸짜리이므로 정렬된 것으로 취급
	{
		int mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid + 1, high);
		
		T* sorted = new T[high - low + 1];

		int k = 0, i = low, j = mid + 1;
		while (i <= mid && j <= high)
		{
			sorted[k++] = (a[i] <= a[j] ? a[i++] : a[j++]);	//왼쪽과 오른쪽 중 작은것을 sorted에 넣기
		}//단, stable sort이기 때문에 a[i] == a[j] 인 경우는 왼쪽이 작은것으로 판단

		if (j > high)	//왼쪽부분이 남은 경우 오른쪽 끝으로 옮겨줌(이미 정렬되어있고, 가장 큰 부분이므로)
		{
			while (i <= mid) a[--j] = a[mid--];
		}//오른쪽부분이 남은경우는 이미 제 위치에 있음
		
		for (int q = low, w = 0; w < k; ++q, ++w)	//sorted를 a로 옮겨줌
		{
			a[q] = sorted[w];
		}
	}
}

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	info* arr = new info[N];

	for (int i = 0; i < N; ++i) std::cin >> arr[i].age >> arr[i].name;
	merge_sort(arr, 0, N - 1);
	for (int i = 0; i < N; ++i) std::cout << arr[i].age << ' ' << arr[i].name << '\n';
}