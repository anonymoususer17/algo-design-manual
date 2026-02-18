void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int exists_in_array(int a, int b[], int length){
    int result = 0;
    for(int i = 0; i < length; i++){
        if(a ==  b[i]){
            result = 1;
            break;
        }
    }

    return result;
}
