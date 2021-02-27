
#include <iostream>
using namespace std;


class Array {
private:
    int *arr;
    int size;
    int defaultNumber = -1;
public:

    Array(int array[], int size)
    {
        this->size = size;
        arr = array;
    }
    void fillEmptiesWithDefaultNumber()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = defaultNumber;
            }
        }
    }
    void displayArray()
    {
        cout << "{";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] <<", ";
        }
        cout << "}" <<'\n';
    }
    int getArrayLength()       
    {
        int length = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
            {
                return length;
            }
            length++;
        }
        return size;
    }
    void append(int number)
    {
        arr[getArrayLength()] = number;
    }
 
    void insertByIndexAndNumber(int index, int number) 
    {
        int i = getArrayLength();
        while (i>index) 
        {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = number;
    }

    void deleteByIndex(int index) 
    {   
        int i = index;
        while (i<getArrayLength())
        {
            arr[i] = arr[i + 1];
            i++;
        }
    }
    int linearSearch(int number) 
    {
        for (int i = 0; i < getArrayLength(); i++)
        {
            if(arr[i] == number)
            {
                return i;
            }
        }
        return -2;
    }
    int optimizedLinearSearch(int number)
    {
        for (int i = 0; i < getArrayLength(); i++)
        {
            if (arr[i] == number)
            {
                if (isAvaibleToSwap(i))
                {
                    swapArrMembers(i, i - 1);
                    return i - 1;
                }
                else 
                {
                    return i;
                }
            }
        }
        return -2;
    }
    void swapArrMembers(int indeks1,int indeks2) 
    {
            int temp;
            temp = arr[indeks1];
            arr[indeks1] = arr[indeks2];
            arr[indeks2] = temp;
    }
    bool isAvaibleToSwap(int index)
    {
        if (index < 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void sort(int n = 0)
    {
        if (n + 1 > getArrayLength()-1)
        {
            return;
        }
        else 
        {
            if (arr[n] > arr[n+1])
            {
                swapArrMembers(n, n+1);
                sort(0);
            }
            sort(n + 1);
        }
    }

    int binarySearch(int number, int last, int first = 0) // 1,2,3,4
    {
        int mid = (last + first) / 2;
    
        if (number == arr[mid])
        {
            return mid;
        }
        else if (number > arr[mid])
        {
            binarySearch(number, last, mid);
        }
        else
            binarySearch(number, mid, 0);


    }
    
};

int main()
{
    int arr1[10] = { 2,1,4,3,7,5,10 };
    Array myArray(arr1, 10);
    myArray.fillEmptiesWithDefaultNumber();
    myArray.displayArray();
    myArray.sort();
    myArray.displayArray();
    cout<<myArray.binarySearch(10, myArray.getArrayLength());
 
    return 1;
}