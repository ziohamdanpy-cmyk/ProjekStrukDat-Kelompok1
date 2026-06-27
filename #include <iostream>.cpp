#include <iostream>
#include <string>

#define MAX 100

using namespace std;

// Stack untuk menyimpan riwayat teks
string undoStack[MAX];
int top = -1;

// Mengecek apakah stack penuh
bool isFull() {
    return top == MAX - 1;
}

// Mengecek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Menambahkan state teks ke stack
void push(string text) {
    if (isFull()) {
        cout << "Stack penuh!\n";
        return;
    }

    undoStack[++top] = text;

    cout << "State berhasil disimpan ke Undo Stack.\n";
}

// Menghapus elemen teratas stack
void pop() {
    if (isEmpty()) {
        cout << "Undo Stack kosong!\n";
        return;
    }

    cout << "State terakhir dihapus dari Undo Stack.\n";
    top--;
}

// Mengambil elemen teratas tanpa menghapus
string peek() {
    if (isEmpty()) {
        return "";
    }

    return undoStack[top];
}

// Menampilkan isi stack
void display() {
    if (isEmpty()) {
        cout << "Undo Stack kosong!\n";
        return;
    }

    cout << "\n=== Isi Undo Stack ===\n";

    for (int i = top; i >= 0; i--) {
        cout << undoStack[i] << endl;
    }

    cout << endl;
}

int main() {

    string currentText = "";

    // ==================================================
    // State awal editor disimpan ke stack
    // ==================================================
    push(currentText);

    // User menulis teks pertama
    currentText = "Halo";
    push(currentText);

    // User menambahkan teks
    currentText = "Halo Dunia";
    push(currentText);

    cout << "\nTeks saat ini : " << currentText << endl;

    // ==================================================
    // Proses Undo
    // Hapus state sekarang lalu ambil state sebelumnya
    // ==================================================
    pop();
    currentText = peek();

    cout << "Setelah Undo : " << currentText << endl;

    // Menampilkan isi stack
    display();
    
}