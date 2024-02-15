//#include "AI.h"
//
//int main()//(int argc, char *argv[])
//{
//    // srand(time(NULL));
//    srand(4);
//
//
//    double Xx[X_TRAIN_SIZE][Y_TRAIN_SIZE] = {
//            {1, 1},
//            {0, 1},
//            {1, 0},
//            {0, 0}
//    };
//
//    double yy[X_TRAIN_SIZE] = {
//            0,
//            1,
//            1,
//            0};
//    double learning_rate = 0.1;
//
//
//    // transform tabs to Matrix
//    Matrix *X = malloc(sizeof(Matrix));
//    X->sizeX = X_TRAIN_SIZE;
//    X->sizeY = Y_TRAIN_SIZE;
//    X->data = malloc(X_TRAIN_SIZE * Y_TRAIN_SIZE * sizeof(double));
//    for (int i = 0; i < Y_TRAIN_SIZE; i++) {
//        for (int j = 0; j < X_TRAIN_SIZE; j++) {
//            X->data[i * X_TRAIN_SIZE + j] = Xx[j][i];
//        }
//    }
//    Matrix *y = malloc(sizeof(Matrix));
//    y->sizeX = X_TRAIN_SIZE;
//    y->sizeY = 1;
//    y->data = malloc(X_TRAIN_SIZE * sizeof(double));
//    for (size_t i = 0; i < X_TRAIN_SIZE; i++) {
//        y->data[i] = yy[i];
//    }
//
//
//
//    Matrix *W_list;
//    Matrix *b_list;
//    int dim[] = {2, 3, 4, 3, 1};
//    init_network(dim, &W_list, &b_list);
////    for (size_t i = 0; i < DIMENSION - 1; i++)
////    {
////        printf("W_list:\n");
////        printMatrix(W_list[i]);
////        printf("b_list:\n");
////        printMatrix(b_list[i]);
////    }
//    Matrix *A_list;
//    forward_propagation(X, W_list, b_list, &A_list);
////    for (size_t i = 0; i < DIMENSION; i++)
////    {
////        printMatrix(A_list[i]);
////    }
//    Matrix *dW_gradients;
//    Matrix *db_gradients;
//    back_propagation(y, W_list, A_list, &dW_gradients, &db_gradients);
////    for (size_t i = 0; i < DIMENSION - 1; i++)
////    {
////        printf("dW:\n");
////        printMatrix(dW_gradients[i]);
////        printf("db:\n");
////        printMatrix(db_gradients[i]);
////    }
//    update(dW_gradients, db_gradients, W_list, b_list, learning_rate);
//    for (size_t i = 0; i < DIMENSION - 1; i++)
//    {
//        printf("W_list:\n");
//        printMatrix(W_list[i]);
//        printf("b_list:\n");
//        printMatrix(b_list[i]);
//    }
//
//
//
//
//
//
//
//    // Free all
//    for (size_t i = 0; i < DIMENSION - 1; i++)
//    {
//        free((W_list[i]).data);
//        free((b_list[i]).data);
//        free((A_list[i + 1]).data); //because of memcpy
//        free(dW_gradients[i].data);
//        free(db_gradients[i].data);
//    }
//
//    free(X->data);
//    free(X);
//    free(y->data);
//    free(y);
//
//    free(W_list);
//    free(b_list);
//    free(A_list);
//    free(dW_gradients);
//    free(db_gradients);
//
//    return 0;
//}

#include "AI.h"

int main()//(int argc, char *argv[])
{
    // srand(time(NULL));
    srand(4);


    double Xx[X_TRAIN_SIZE][Y_TRAIN_SIZE] = {
            {1, 1},
            {0, 1},
            {1, 0},
            {0, 0}
    };

    double yy[X_TRAIN_SIZE] = {
            0,
            1,
            1,
            0};
    double learning_rate = 0.1;


    // transform tabs to Matrix
    Matrix *X = malloc(sizeof(Matrix));
    X->sizeX = X_TRAIN_SIZE;
    X->sizeY = Y_TRAIN_SIZE;
    X->data = malloc(X_TRAIN_SIZE * Y_TRAIN_SIZE * sizeof(double));
    for (int i = 0; i < Y_TRAIN_SIZE; i++) {
        for (int j = 0; j < X_TRAIN_SIZE; j++) {
            X->data[i * X_TRAIN_SIZE + j] = Xx[j][i];
        }
    }
    Matrix *y = malloc(sizeof(Matrix));
    y->sizeX = X_TRAIN_SIZE;
    y->sizeY = 1;
    y->data = malloc(X_TRAIN_SIZE * sizeof(double));
    for (size_t i = 0; i < X_TRAIN_SIZE; i++) {
        y->data[i] = yy[i];
    }



    Matrix *W_list;
    Matrix *b_list;
    int dim[] = {2, 3, 4, 3, 1};
    init_network(dim, &W_list, &b_list);
    for (int i = 0; i < 10000; i++)
    {
        Matrix *A_list;
        forward_propagation(X, W_list, b_list, &A_list);
        Matrix *dW_gradients;
        Matrix *db_gradients;
        back_propagation(y, W_list, A_list, &dW_gradients, &db_gradients);
        update(dW_gradients, db_gradients, W_list, b_list, learning_rate);

        for (size_t j = 0; j < DIMENSION - 1; j++)
        {
            free((A_list[j + 1]).data); //because of memcpy
            free(dW_gradients[j].data);
            free(db_gradients[j].data);
        }
        free(A_list);
        free(dW_gradients);
        free(db_gradients);
    }


    for (size_t i = 0; i < DIMENSION - 1; i++)
    {
        printf("W_list:\n");
        printMatrix(W_list[i]);
//        printf("b_list:\n");
//        printMatrix(b_list[i]);
    }
    printf("\n\n\n\n\n\n\n\n\n\n");
    for (size_t i = 0; i < DIMENSION - 1; i++)
    {
//        printf("W_list:\n");
//        printMatrix(W_list[i]);
        printf("b_list:\n");
        printMatrix(b_list[i]);
    }




    // Free all
    for (size_t i = 0; i < DIMENSION - 1; i++)
    {
        free((W_list[i]).data);
        free((b_list[i]).data);
    }

    free(X->data);
    free(X);
    free(y->data);
    free(y);

    free(W_list);
    free(b_list);

    return 0;
}