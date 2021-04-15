#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <time.h>

#include <string.h>

#include <stdbool.h>

void akhir();
void menu2(int arr[], int n, float pilihan);
void cetakAkhir();

void seedArray(int arr[], int n) { //untuk melakukan data random
    int i;
    srand(0);
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

}

void printArray(int arr[], int n) { //mencetak angka random
    int i;
    for (i = 0; i < n; i++) {
        printf("-Angka ke-%d : %d\n", i, arr[i]);
        printf("\n");
    }
}

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) { //mengurutkan angka secara bubble
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int sequentialSearch(int arr[], int n, int angka) { //mengurutkan data sequential
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == angka) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int angka) { //mengurutkan data binary
    bool inArray;
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == angka) {
            return mid;
        }
        if (arr[mid] > angka) {
            return binarySearch(arr, low, mid - 1, angka);
            return binarySearch(arr, mid + 1, high, angka);
        }
    }
    return -1;
}

int partition(int arr[], int low, int high) { //menentukan pivot quick
    int pivot = arr[high];
    int temp;
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) { //mengurutkan angka secara quick
    int pi = partition(arr, low, high);
    if (low < high) {
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float countBubbleSort(int arr[], int n) { //menhitung waktu bubble
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countInsertionSort(int arr[], int n) { //menhitung waktu insertion
    clock_t start = clock();
    insertionSort(arr, n);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countQuickSort(int arr[], int n) { ////menhitung waktu quick
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    return detik;
}

float countSequentialSearch(int arr[], int n, int angka) { //menhitung waktu sequential
    int inArray;
    clock_t start = clock();
    inArray = sequentialSearch(arr, n, angka);
    clock_t end = clock();

    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    if (inArray == -1) {
        printf("Angka %d tidak terdapat di array", angka);
    } else {
        printf("\n-Mencari dengan Sequential Search :");
        printf("\nAngka %d berada di array di indeks ke %d", angka, inArray);
    }
    return detik;
}

float countBinarySearch(int arr[], int n, int angka) { //menhitung waktu binary
    int inArray;
    quickSort(arr, 0, n - 1);
    clock_t start = clock();
    inArray = binarySearch(arr, 0, n - 1, angka);
    clock_t end = clock();
    float detik = (float)(end - start) / CLOCKS_PER_SEC;
    if (inArray == -1) {
        printf("Angka %d tidak terdapat di aray", angka);
    } else {
        printf("\n-Mencari dengan Binary Search :");
        printf("\nAngka %d berada di aray di indeks ke %d", angka, inArray);
    }
    return detik;
}

void dupArray(int source[], int target[], int n) { //membuat salinan array
    int i;
    for (i = 0; i < n; i++)
        target[i] = source[i];
}

int validasi() {
    int d;
    char checkchar;
    int cek;
    cek = scanf("%d%c", & d, & checkchar);

    if (cek != 2 || checkchar != '\n') {
        printf("\nInput Invalid!\n");
        printf("Masukkan sesuai dengan menu di atas = ");
        fflush(stdin);
        return validasi();
    } else {
        fflush(stdin);
        return d;
    }
}

void cetakAkhir() {
    system("cls");
    printf("-----------------------------------------------\n");
    printf("* TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM KAMI *\n");
    printf("|                GOOD BYE >_<                 |\n");
    printf("*             FROM KELOMPOK 13                *\n");
    printf("-----------------------------------------------\n");
}

void akhir() {
    char keluar;
    printf("Silahkan pilih langkah yang ingin anda lakukan selanjutnya\n");
    printf(" 1. Kembali ke Menu Utama\n");
    printf(" 2. Keluar\n");
    printf("Masukkan pilihan anda > ");
    keluar = validasi();

    if (keluar == 1) {
        system("cls");
        main();
    } else if (keluar == 2) {
        cetakAkhir();
    } else {
        printf("Perhatikan Lagi Inputan Anda!!!");
    }
}

void menu2(int arr[], int n, float pilihan) { //menu pilihan sorting atau searching
    int cek;
    float detik1, detik2, detik3;
    int angka;
    int arr2[n];
    int arr3[n];

    printf("Array %d data random sebelum di sort :\n", n);
    printArray(arr, n);
    if (pilihan == 2) {
        printf("\n=====================================================================================================");
        printf("\nMasukkan angka yang dicari : ");
        angka = validasi();

    }
    dupArray(arr, arr2, n);
    dupArray(arr, arr3, n);
    switch ((int) pilihan) {
        case 1:
            detik2 = countInsertionSort(arr, n);
            detik3 = countBubbleSort(arr2, n);
            detik1 = countQuickSort(arr3, n);
            break;
        case 2:
            detik1 = countSequentialSearch(arr, n, angka);
            detik2 = countBinarySearch(arr2, n, angka);
            break;
    }
    if (pilihan == 1) {
        printf("\n=====================================================================================================");
        printf("\nArray %d data random sesudah di sort :", n);
        printf("\n");
        printf("\n");
        printArray(arr, n);
        printf("\n=====================================================================================================");
        printf("\nperbandingan waktu:\n");
        printf("Waktu Quick Sort : %lf\nWaktu Insertion Sort : %lf\nWaktu Bubble Sort : %lf", detik1, detik2, detik3);
        if (detik2 <= detik3 && detik2 <= detik1) {
            printf("\nInsertion sort yang paling cepat");
        } else if (detik3 <= detik2 && detik2 <= detik1) {
            printf("\nBubble sort yang paling cepat");
        } else {
            printf("\nQuick sort yang paling cepat");
        }
    } else if (pilihan == 2) {
        printf("\n");
        printf("\n=====================================================================================================");
        printf("\nperbandingan waktu:\n");
        printf("Waktu Sequential Search : %lf\nWaktu Binary Search :%lf", detik1, detik2);
        if (detik1 == detik2) {
            printf("\nSequential Search dan Binary Search Setara");
        } else if (detik1 <= detik2) {
            printf("\nSequential Search yang paling cepat");
        } else {
            printf("\nBinary Search yang paling cepat");
        }
    }
    akhir();
}

int menu() { //menu pilihan data
    int pilihan;
    int pilihan1;
    char enterCheck;
    int n;
    
    printf("\n+-----------------------------------------------------+");
    printf("\n|             PROGRAM SORTING & SEARCHING             |");
    printf("\n+-----------------------------------------------------+");
    printf("\n|Pilih metode :                                       |");
    printf("\n|[1]Sorting(Bubble Sort,Insertion Sort,Quick Sort)    |");
    printf("\n|[2]Searching(Binary Search,SequentialSearch)         |");
    printf("\n|[3]Keluar                                            |");
    printf("\n+-----------------------------------------------------+");
	do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%d%c", & pilihan, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan < 3) {
                menu3();
                break;
            } else if (pilihan == 3) {
                return 0;
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);
}

int menu3 (){
	int pilihan;
	int n;
	char pilihan1;
	char enterCheck;
    printf("\n+-----------------------------------------------------+");
    printf("\n|             PROGRAM SORTING & SEARCHING             |");
    printf("\n+-----------------------------------------------------+");
    printf("\n|Pilih banyak data :                                  |");
    printf("\n|[1]1000 data                                         |");
    printf("\n|[2]16000 data                                        |");
    printf("\n|[3]64000 data                                        |");
    printf("\n|[4]kembali                                            |");
    printf("\n|[5]Keluar                                            |");
    printf("\n+-----------------------------------------------------+");
    
    do {
        printf("\nMasukkan pilihan: ");
        if (scanf("%d%c", & pilihan1, & enterCheck) != 2 || enterCheck != '\n') {
            printf("\nInput Invalid!\n");
            fflush(stdin);
        } else {
            if (pilihan1 == 1) {
                n = 1000;
                break;
            } else if (pilihan1 == 2) {
                n = 16000;
                break;
            } else if (pilihan1 == 3) {
                n = 64000;
                break;
            } else if (pilihan1 == 4) {
                menu();
                break;
            }else if (pilihan1 == 5) {
                cetakAkhir();
                break;
            } else {
                printf("\nInput Invalid!\n");
            }
        }
    } while (1);
        int arr[n];
        seedArray(arr, n);
        menu2(arr, n, pilihan);
}


int main() {
    menu();
    return 0;
}
