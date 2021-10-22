/**
 * Recherche par dichotomie dans un tableau d'entiers
 * @param array The array of values
 * @param size_t The size of the array
 * @param value The value to find
 * @return The position of the value found or -1
 */

int find_by_dichotomy(int array[], int size_t, int value){
    int position, first, last, mid;
    first = array[0];
    last = array[size_t-1];
    mid = (first + last) / 2;

    while(first <= 1){
        if (array[mid] < value){
            first = mid + 1;
        }else if(array[mid] == value){
            position = mid;
            break;
        }else{
            last = mid - 1;
        }
        mid = (first + last) / 2;
        position = mid;
    }
    return position;
}