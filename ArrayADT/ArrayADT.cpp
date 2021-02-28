
#include <iostream>
using namespace std;


class Array {
private:
    int *arr;
    int size;
    int defaultNumber = -1;
public:

    Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    
    void fillEmptiesWithDefaultNumber()
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < 0)
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
    int findMax(int n = 1)
    {
        static int compareNumber = arr[n-1];
        int result = compareNumber;
        if (n<getArrayLength()) 
        {
            if (arr[n] > compareNumber)
            {
                compareNumber = arr[n];
                return findMax(n + 1);
            }
            return findMax(n + 1);
        }
        else
        {
            compareNumber = 0;
            return result;
        }

    }
    int findMin(int n = 1)
    {
        static int compareNumber = arr[n-1];
        int result = compareNumber;
        if (n < getArrayLength())
        {
            if (arr[n] < compareNumber)
            {
                compareNumber = arr[n];
                return findMax(n + 1);
            }
            return findMax(n + 1);
        }
        else
        {
            compareNumber = 0;
            return result;
        }

    }
    int findSum(int n = 1) 
    {
        static int compareNumber = arr[n - 1];
        int result = compareNumber;
        if (n < getArrayLength())
        {
                compareNumber = compareNumber + arr[n];
                return findSum(n + 1); 
        }
        else
        {
            compareNumber = 0;
            return result;
        }
    }
    int findAverage(int n = 1)
    {
        static int compareNumber = arr[n - 1];
        int result = compareNumber;
        if (n < getArrayLength())
        {
            compareNumber = compareNumber + arr[n];
            return findSum(n + 1);
        }
        else
        {
            compareNumber = 0;
            return result/getArrayLength();
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

    int binarySearch(int number, int last , int first = 0) 
    {       
   
        int mid = (last + first) / 2;
        if (first <= last)
        {

            if (number == arr[mid])
            {
                return mid;
            }
            else if (number > arr[mid])
            {
                binarySearch(number, last, mid + 1);
            }
            else
                binarySearch(number, mid - 1, first);
        }
        else
            return -2;
    }

    void reverse() 
    {
        int j = 0;

        for (int i = getArrayLength()-1; i > getArrayLength()/2; i--)
        {
            swapArrMembers(i, j);
            j++;
        }
    }

    void leftRotate()
    {
        arr[getArrayLength()] = arr[0];
        deleteByIndex(0);
    }
    void leftShift(int fromThisIndex = 0)
    {
        deleteByIndex(fromThisIndex);
    }
    void rightRotate()
    {
        int i = getArrayLength()-1;
        int temp = arr[i];
        while (i>-1) 
        {
            if (i == 0)
            {
                arr[i] = temp;
                break;
            }
            arr[i] = arr[i - 1];
            i--;
        }
    }
    void rightShift(int fromThisIndex = 0)
    {
        int i = getArrayLength() - 1;
        while (i > fromThisIndex-1)
        {
            if (i == fromThisIndex)
            {
                arr[i] = -1;
                break;
            }
            arr[i] = arr[i - 1];
            i--;
        }
    }
    void InsertToSortedList(int number) 
    {
        int i = getArrayLength() - 1;
        while (arr[i] > number)
        {
            i--;
        }
        insertByIndexAndNumber(i, number);          
    }
    void fillArrayRandomly(int howManyNumberToAdd)
    {
        int randomNumber; 
        for (int i = 0; i < howManyNumberToAdd; i++)
        {
            randomNumber = rand() % 99 + 1;
            arr[i] = randomNumber;
        }
    }


    
};

int main()
{
    
    Array myArray(25);
    myArray.fillArrayRandomly(12);
    myArray.fillEmptiesWithDefaultNumber();
    myArray.displayArray();
    myArray.sort();
    myArray.displayArray();
    cout << myArray.binarySearch(54,myArray.getArrayLength());




 
    return 1;

}