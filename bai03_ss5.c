#include <stdio.h>

#define MAX 100
#define GIA_KHAM 150000

int chiPhi(int bhyt)
{
    if (bhyt == 1) {
        return GIA_KHAM * 20 / 100;
    }
    return GIA_KHAM;
}

long long tongDoanhThu(int bhyt[], int n)
{
    long long tong = 0;
    for (int i = 0; i < n; i++) {
        tong += chiPhi(bhyt[i]);
    }
    return tong;
}

int demUuTien(int tuoi[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (tuoi[i] >= 70) {
            dem++;
        }
    }
    return dem;
}

void inDanhSach(int stt[], int tuoi[], int bhyt[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Vi tri %d | STT %d | Tuoi %d | BHYT %d | Chi phi %d\n",
               i, stt[i], tuoi[i], bhyt[i], chiPhi(bhyt[i]));
    }
    printf("So benh nhan: %d\n", n);
    printf("Tong doanh thu: %lld VND\n", tongDoanhThu(bhyt, n));
    printf("So benh nhan uu tien: %d\n", demUuTien(tuoi, n));
}

int huyLuot(int stt[], int tuoi[], int bhyt[], int n, int k)
{
    for (int i = k; i < n - 1; i++) {
        stt[i] = stt[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }
    return n - 1;
}

int main(void)
{
    int stt[MAX], tuoi[MAX], bhyt[MAX];
    int n, k;

    do {
        printf("Nhap so benh nhan n (0..%d): ", MAX);
        scanf("%d", &n);
    } while (n < 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        stt[i] = i + 1;
        printf("Benh nhan %d\n", i + 1);
        do {
            printf("  Tuoi (1..120): ");
            scanf("%d", &tuoi[i]);
        } while (tuoi[i] < 1 || tuoi[i] > 120);
        do {
            printf("  BHYT (0/1): ");
            scanf("%d", &bhyt[i]);
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    printf("\n--- Hang cho ban dau ---\n");
    inDanhSach(stt, tuoi, bhyt, n);

    if (n == 0) {
        printf("Hang cho rong, khong the huy.\n");
        return 0;
    }

    printf("\nNhap vi tri K can huy: ");
    scanf("%d", &k);
    if (k < 0 || k >= n) {
        printf("Vi tri K khong hop le.\n");
        return 0;
    }

    n = huyLuot(stt, tuoi, bhyt, n, k);

    printf("\n--- Hang cho sau khi huy ---\n");
    inDanhSach(stt, tuoi, bhyt, n);
    return 0;
}