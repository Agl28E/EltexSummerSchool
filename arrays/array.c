#include <stdio.h>
#define N 5

int main(void) {
    int count = 1;
    int array[N][N];
    
    count = 1;
    
    printf("Первое задание: Вывод матрицы\n");
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            array[i][j] = count;
            count+= 1;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    printf("\nВторое задание: вывод массива в обратном порядке\n");
    for(int i = N - 1 ; i >= 0; i--){
        for(int j = N - 1; j >= 0; j--){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    printf("\nТретье задание: заполнить верхний треугольник матрицы единицами, нижний нулями\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i + j >= N){
                array[i][j] = 0;
            }
            else{
                array[i][j] = 1;
            }
            printf("%d ", array[i][j]);
            }
        printf("\n");
        }

    printf("\nЧетвертое задание: заполнение матрицы улиткой\n");  

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            array[i][j] = 0;
        }
    }
    count = 1;
    for(int i = 0; i < N / 2; i++) {
        
        for(int j = i; j < N - i; j++)
            array[i][j] = count++;

        for(int j = i + 1; j < N - i; j++)
            array[j][N-1-i] = count++;

        for(int j = N - 2 - i; j >= i; j--)
            array[N - 1 - i][j] = count++;
        
        for(int j = N - 2 - i; j > i; j--)
            array[j][i] = count++;
    }

    array[N / 2][N / 2] = N * N; 

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
