#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void menuUtama() {
    printf("\n\n");
    printf("\t\t\t\t\t==========[ MENU SORTING DAN SEARCHING ]===========\n");
    printf("\t\t\t\t\t              1. Sorting                	\n");
    printf("\t\t\t\t\t              2. Searching                 	\n");
    printf("\t\t\t\t\t              3. Exit                  	\n");
    printf("\t\t\t\t\t==========================================\n");
}

void swap(int * i1, int * i2) {
    int temp = * i1;
    * i1 = * i2;
    * i2 = temp;
}

void bubbleSort(int arr[], int size) {
    int i, a;
    for (i = 0; i < size - 1; i++) {
        int flag = 0;
        for (a = 0; a < size - i - 1; a++) {
            if (arr[a] > arr[a + 1]) {
                swap( & arr[a], & arr[a + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

}

int Partition(int * A, int start, int end) {
    int pivot = A[end];
    int i;
    int partitionIndex = start;
    for (i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap( & A[partitionIndex], & A[i]);
            partitionIndex++;
        }
    }
    swap( & A[partitionIndex], & A[end]);
    return partitionIndex;
}

void quickSort(int * A, int start, int end) {
    if (start < end) {
        int partitionIndex = Partition(A, start, end);
        quickSort(A, start, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, end);
    }
}

void insertionSort(int angka[], int size) {
    int i, j, patokan;

    for (i = 1; i < size; i++) {
        patokan = angka[i];

        j = i - 1;

        while (j >= 0 && angka[j] > patokan) {
            angka[j + 1] = angka[j];
            j--;
        }

        angka[j + 1] = patokan;
    }
}

void Sorting() {
    clock_t waktu;
    double waktu_dibutuhkan[3];
    int i;
    int size;
    int menu;
    int exit = 1;
    do {
        // system("cls");
        printf("\t\t\t\t\t==========[ MENU SORTING ]===========\n");
        printf("\t\t\t\t\t              1. 1000 Angka             	\n");
        printf("\t\t\t\t\t              2. 16000 Angka             	\n");
        printf("\t\t\t\t\t              3. 64000 Angka            	\n");
        printf("\t\t\t\t\t==========================================\n");
        printf("\t\t\t\t\t   Masukkan menu : ");
        scanf("%d", & menu);
        switch (menu) {
            case 1: {
                int angka[1000], temp[1000];

                // system("cls");
                size = sizeof(angka) / sizeof(angka[0]);
                srand((unsigned) time(NULL));

                for (i = 0; i < size; i++) {
                    angka[i] = rand();
                    temp[i] = angka[i];
                }

                //Insertion Sort
                waktu = clock();
                insertionSort(temp, size);
                waktu = clock() - waktu;

                waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Bubble Sort
                waktu = clock();
                bubbleSort(temp, size);
                waktu = clock() - waktu;
                waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Quick Sort
                waktu = clock();
                quickSort(temp, 0, size - 1);
                waktu = clock() - waktu;
                waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
                printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
                printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);
                break;
            }
            case 2: {
                int angka[16000], temp[16000];

                // system("cls");
                size = sizeof(angka) / sizeof(angka[0]);
                srand((unsigned) time(NULL));

                for (i = 0; i < size; i++) {
                    angka[i] = rand();
                    temp[i] = angka[i];
                }

                //Insertion Sort
                waktu = clock();
                insertionSort(temp, size);
                waktu = clock() - waktu;

                waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Bubble Sort
                waktu = clock();
                bubbleSort(temp, size);
                waktu = clock() - waktu;
                waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Quick Sort
                waktu = clock();
                quickSort(temp, 0, size - 1);
                waktu = clock() - waktu;
                waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
                printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
                printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);

                break;
            }
            case 3: {
                int angka[64000], temp[64000];

                // system("cls");
                size = sizeof(angka) / sizeof(angka[0]);
                srand((unsigned) time(NULL));

                for (i = 0; i < size; i++) {
                    angka[i] = rand();
                    temp[i] = angka[i];
                }

                //Insertion Sort
                waktu = clock();
                insertionSort(temp, size);
                waktu = clock() - waktu;

                waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Bubble Sort
                waktu = clock();
                bubbleSort(temp, size);
                waktu = clock() - waktu;
                waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                //Quick Sort
                waktu = clock();
                quickSort(temp, 0, size - 1);
                waktu = clock() - waktu;
                waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;

                for (i = 0; i < size; i++) {
                    if (i == size - 1) {
                        printf(" dan %d.", temp[i]);
                    } else {
                        printf(" %d,", temp[i]);
                    }
                    temp[i] = angka[i];
                }
                printf("\n\nInsertion Sort Membutuhkan %f Detik Untuk Mensortir Data, Sedangkan\n", waktu_dibutuhkan[0]);
                printf("Bubble Sort Membutuhkan %f Detik Untuk Mensortir Data, dan\n", waktu_dibutuhkan[1]);
                printf("Quick Sort Membutuhkan %f Detik Untuk Mensortir Data\n", waktu_dibutuhkan[2]);
                break;
            }
        }
        printf("Tekan '1' untuk ke menu, tekan '0' untuk keluar");
        scanf("%d", & exit);
    } while (exit == 1);
}

//sequentialSearch(int arr[], int n, int angka) 
double sequentialSearch(int arr[], int n, int angkaDicari) {
    clock_t waktu;
    double waktu_dibutuhkan;
    int i, counter = 0;

    waktu = clock();
    for (i = 0; i < n; i++) {
//        if (i == n - 1) {
//            printf(" dan %d.", arr[i]);
//        } else {
//            printf("-Angka ke-%d : %d", i, arr[i]);
//        	printf("\n");
//        }
        if (arr[i] == angkaDicari) {
            counter++;
        }
printf("-Angka ke-%d : %d", i, arr[i]);
        	printf("\n");
    }
    waktu = clock() - waktu;
    waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

    if (counter == 0) {
        printf("\n\nTidak Ada Angka Yang Sesuai!");
    } else {
        int indexAngkaDicari[counter];
        counter = 0;

        for (i = 0; i < n; i++) {
            if (arr[i] == angkaDicari) {
                indexAngkaDicari[counter] = i;
                counter++;
            }
        }

        printf("\n\nAngka Ditemukan Pada Index:");
        for (i = 0; i < counter; i++) {
            if (i == 0 && i == counter - 1) {
                printf(" %d.", indexAngkaDicari[i]);
            } else {
                if (i == counter - 1) {
                    printf(" dan %d.", indexAngkaDicari[i]);
                } else {
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }

    return waktu_dibutuhkan;
}
//binarySearch(int arr[], int low, int high, int angka)
double binarySearch(int arr[], int low, int high, int angkaDicari) {
    clock_t waktu;
    double waktu_dibutuhkan;
    int i, counter = 0;

    waktu = clock();
    while (low <= high) {
        int tengah = low + (high - low) / 2;

        if (arr[tengah] == angkaDicari) {
            counter++;
            for (i = tengah + 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                counter++;
            }
            for (i = tengah - 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                counter++;
            }
            break;
        } else if (arr[tengah] > angkaDicari) {
            high = tengah - 1;
        } else {
            low = tengah + 1;
        }
    }
    waktu = clock() - waktu;
    waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

    if (counter == 0) {
        printf("\n\nTidak Ada Angka Yang Sesuai!");
    } else {
        int indexAngkaDicari[counter];
        counter = 0;

        while (low <= high) {
            int tengah = low + (high - low) / 2;

            if (arr[tengah] == angkaDicari) {
                indexAngkaDicari[counter] = tengah;
                counter++;
                for (i = tengah + 1; i < high + 1 && arr[i] == angkaDicari; i++) {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                for (i = tengah - 1; i > 0 && arr[i] == angkaDicari; i--) {
                    indexAngkaDicari[counter] = i;
                    counter++;
                }
                break;
            } else if (arr[tengah] > angkaDicari) {
                high = tengah - 1;
            } else {
                low = tengah + 1;
            }
        }

        printf("\n\nAngka Ditemukan Pada Index:");
        bubbleSort(indexAngkaDicari, counter);
        for (i = 0; i < counter; i++) {
            if (i == 0 && i == counter - 1) {
                printf(" %d.", indexAngkaDicari[i]);
            } else {
                if (i == counter - 1) {
                    printf(" dan %d.", indexAngkaDicari[i]);
                } else {
                    printf(" %d,", indexAngkaDicari[i]);
                }
            }
        }
    }

    return waktu_dibutuhkan;
}
void seedArray(int arr[], int n) {
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("-Angka ke-%d : %d", i, arr[i]);
        printf("\n");
    }
}

void Searching() {
    clock_t waktu;
    double waktu_dibutuhkan[3];
    int i;
    int n;
    int menu;
    int angkaDicari;
    int enterCheck;
    int exit = 1;
    char pilihan;


    // system("cls");
    printf("\t\t\t\t\t==========[ MENU SORTING ]===========\n");
    printf("\t\t\t\t\t              1. 1000 Angka             	\n");
    printf("\t\t\t\t\t              2. 16000 Angka             	\n");
    printf("\t\t\t\t\t              3. 64000 Angka            	\n");
    printf("\t\t\t\t\t==========================================\n");
    printf("\t\t\t\t\t   Masukkan menu : ");
    do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%c%c", & pilihan, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan == '1') {
                n = 1000;
                break;
            } else if (pilihan == '2') {
                n = 16000;
                break;
            } else if (pilihan == '3') {
                n = 64000;
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);
    // int angka[1000], temp[1000];
//    int arr[n];
//    n = sizeof(arr) / sizeof(arr[0]);
//    srand((unsigned) time(NULL));



//    for (i = 0; i < n; i++) {
//        arr[i] = rand();
//    }
	int arr[n];
	seedArray(arr,n);
    printArray(arr,n); 


    do {
        printf("\t\t\tMasukkan Angka Yang Ingin Dicari: ");
        if (((scanf("%d%c", & angkaDicari, & enterCheck)) != 2 || enterCheck != '\n')) {
            printf("Please enter an integer: ");
            while (getchar() != '\n');
        } else {
            if (angkaDicari < 0) {
                printf("Inputan tidak boleh dibawah '0'");
            } else {
                break;
            }
        }
    } while (1);

    printf("\nMasukkan Menu : ");
    bubbleSort(arr,n);
    waktu_dibutuhkan[0] = sequentialSearch(arr, n, angkaDicari);
    waktu_dibutuhkan[1] = binarySearch(arr, 0, n - 1, angkaDicari);

    printf("\n\nSequential Search Membutuhkan %f Detik Untuk Mencari Data", waktu_dibutuhkan[0]);
    printf("Sedangkan\nBinary Search Membutuhkan %f Detik Untuk Mencari Data\n", waktu_dibutuhkan[1]);
    if (waktu_dibutuhkan[0] <= waktu_dibutuhkan[1]) {
        printf("Maka Pada Pencarian Kali Ini, Sequential Search Lebih Cepat Dari Binary Search\n\n");
    } else {
        printf("Maka Pada Pencarian Kali Ini, Binary Search Lebih Cepat Dari Sequential Search\n\n");
    }
}
int main() {
    int menu;
    int enterCheck;
    do {
        menuUtama();
        printf("\t\t\t\t\t Masukkan Menu : ");
        if (((scanf(" %d%c", & menu, & enterCheck)) != 2 || enterCheck != '\n')) {
            printf("Masukkan Bilangan yang Valid: ");
            while (getchar() != '\n');
        } else {
            switch (menu) {
                case 1: {
                    Searching();
                    break;
                }
                case 2: {
                    Searching();
                    break;
                }
                case 3: {

                    break;
                }
            }
        }
    } while (menu != 3);
}
