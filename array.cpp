#include "array.h"
#include <math.h>

Array::Array()
{
    arr = nullptr;
    size = 0;
}

Array::Array(int numb)
{
    number* n_arr = new number[numb];
    arr = n_arr;
    size = numb;
}

int Array::sizeo()
{
    return size;
}

istream& operator>> (istream& is, Array& a)
{
    for (int i = 0; i < a.size; i++)
    {
        is >> a.arr[i];
    }
    return is;
}

ostream& operator<< (ostream& os, Array& a)
{
    for (int i = 0; i < a.size; i++)
    {
        os << a.arr[i] << " ";
    }
    os << endl;
    return os;
}

void Array::change_size(int new_size)
{
    number* n_arr = new number[new_size];
    if (new_size > size)
    {
        for (int i = 0; i < size; i++)
            n_arr[i] = arr[i];
    }
    else
    {
        for (int i = 0; i < new_size; i++)
            n_arr[i] = arr[i];
    }
    if(arr != nullptr)
        delete[] arr;

    arr = n_arr;
    size = new_size;
}

void Array::change_element(int index, number new_elem)
{
    arr[index] = new_elem;
}

number Array::calculate_arefmetic_avarage()
{
    number avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg += arr[i];
    }
    return avg/size;
}

number Array::calculate_square()
{
    number avg = calculate_arefmetic_avarage();
    number sum_dif = 0;

    for (int i = 0; i < size; i++)
    {
        sum_dif += (avg-arr[i])*(avg-arr[i]);
    }
    number average_square = sqrt(sum_dif/(size-1));
    return average_square;
}

void swap(number *a, number *b)
{
    number temp = *a;
    *a = *b;
    *b = temp;
}

void Array::qsort(int left, int right, bool rev) {
    int i, j;
    bool swapped;
    for(i = 0; i < right; i++)
    {
        swapped = false;
        for(j = 0; j < right - i; j++)
        {
            if(rev == true)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    swapped = true;
                }
            }
            else if(rev == false)
            {
                if (arr[j] < arr[j + 1])
                {
                    swap(&arr[j], &arr[j + 1]);
                    swapped = true;
                }
            }
        }

        if (swapped == false)
            break;
    }
}
