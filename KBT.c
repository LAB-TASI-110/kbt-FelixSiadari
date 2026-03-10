// Felix Abdiel Siadari - 12S25043

#include <stdio.h>
#include <string.h>

#define MAX_TIKET 100

// Struktur tiket
struct Ticket {
    int id;
    char nama[50];
    char layanan[50];
    char deskripsi[100];
    char status[20];
};

struct Ticket tiket[MAX_TIKET];
int jumlahTiket = 0;

// Fungsi membuat tiket
void buatTiket() {
    if (jumlahTiket >= MAX_TIKET) {
        printf("Kapasitas tiket penuh!\n");
        return;
    }

    struct Ticket t;

    t.id = jumlahTiket + 1;

    printf("Masukkan Nama Anggota: ");
    scanf(" %[^\n]", t.nama);

    printf("Masukkan Jenis Layanan: ");
    scanf(" %[^\n]", t.layanan);

    printf("Masukkan Deskripsi Masalah: ");
    scanf(" %[^\n]", t.deskripsi);

    strcpy(t.status, "Open");

    tiket[jumlahTiket] = t;
    jumlahTiket++;

    printf("Tiket berhasil dibuat dengan ID: %d\n", t.id);
}

// Fungsi melihat tiket
void lihatTiket() {
    if (jumlahTiket == 0) {
        printf("Belum ada tiket.\n");
        return;
    }

    for (int i = 0; i < jumlahTiket; i++) {
        printf("\nID Tiket: %d\n", tiket[i].id);
        printf("Nama Anggota: %s\n", tiket[i].nama);
        printf("Jenis Layanan: %s\n", tiket[i].layanan);
        printf("Deskripsi: %s\n", tiket[i].deskripsi);
        printf("Status: %s\n", tiket[i].status);
    }
}

// Fungsi update status tiket
void updateStatus() {
    int id;
    printf("Masukkan ID tiket yang ingin diubah: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahTiket; i++) {
        if (tiket[i].id == id) {
            printf("Masukkan status baru (Open / InProgress / Closed): ");
            scanf(" %[^\n]", tiket[i].status);
            printf("Status berhasil diperbarui.\n");
            return;
        }
    }

    printf("Tiket tidak ditemukan.\n");
}

// Menu utama
int main() {
    int pilihan;

    do {
        printf("\n=== SISTEM TICKETING KBT ===\n");
        printf("1. Buat Tiket\n");
        printf("2. Lihat Tiket\n");
        printf("3. Update Status Tiket\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                buatTiket();
                break;
            case 2:
                lihatTiket();
                break;
            case 3:
                updateStatus();
                break;
            case 4:
                printf("Terima kasih.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 4);

    return 0;
}