#include <iostream>

using namespace std;

// Definisikan struktur Node
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Fungsi untuk menambahkan node di akhir
void append(Node *&head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == nullptr)
    {
        head = new_node;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *temp = head->prev;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = head;
        head->prev = new_node;
    }
}

// Fungsi untuk menambahkan node di awal
void prepend(Node *&head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (head == nullptr)
    {
        head = new_node;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *temp = head->prev;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

// Fungsi untuk menambahkan node di tengah
void insert_after(Node *&head, int after_data, int data)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;
    do
    {
        if (current->data == after_data)
        {
            Node *new_node = new Node();
            new_node->data = data;
            new_node->next = current->next;
            new_node->prev = current;
            current->next->prev = new_node;
            current->next = new_node;
            return;
        }
        current = current->next;
    } while (current != head);
}

// Fungsi untuk menghapus node di awal
void delete_head(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head->prev;
    temp->next = head->next;
    head->next->prev = temp;
    Node *to_delete = head;
    head = head->next;
    delete to_delete;
}

// Fungsi untuk menghapus node di tengah
void delete_node(Node *&head, int data)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;
    do
    {
        if (current->data == data)
        {
            Node *prev_node = current->prev;
            Node *next_node = current->next;
            prev_node->next = next_node;
            next_node->prev = prev_node;
            delete current;
            return;
        }
        current = current->next;
    } while (current != head);
}

// Fungsi untuk menghapus node di akhir
void delete_tail(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head->prev;
    Node *to_delete = temp;
    temp->prev->next = head;
    head->prev = temp->prev;
    delete to_delete;
}

// Fungsi untuk menghapus seluruh linked list
void clear(Node *&head)
{
    while (head != nullptr)
    {
        delete_head(head);
    }
}

// Fungsi untuk mencetak isi linked list
void print_list(Node *head)
{
    if (head == nullptr)
    {
        cout << "Tidak ada data didalamnya" << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Fungsi main untuk pengujian
int main()
{
    Node *head = nullptr;

    int pilihan = 0, tambahan, pengurangan, angka, index;
    do
    {
        cout << "Pilihan Menu:\n1. Lihat Data\n2. Tambah Data\n3. Hapus Data\n4. Reset Data\n0. Keluar\nMasukkan pilihan anda: ";
        cin >> pilihan;
        if (pilihan == 1)
        {
            print_list(head);
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan angka: ";
            cin >> angka;
            cout << "Menu penambahan data\n1. Tambah diawal\n2. Tambah ditengan\n3. Tambah diakhir\nMasukkan pilihan anda: ";
            cin >> tambahan;
            if (tambahan == 1)
            {
                prepend(head, angka);
            }
            else if (tambahan == 2)
            {
                if (head == nullptr)
                {
                    cout << "Tidak bisa manambah data karena data masih kosong!" << endl;
                }
                else
                {
                    print_list(head);
                    cout << "Anda ingin memasukan data setelah angka berapa? ";
                    cin >> index;
                    insert_after(head, index, angka);
                }
            }
            else if (tambahan == 3)
            {
                append(head, angka);
            }
            else
            {
                cout << "Pilihan yang anda masukkan salah!" << endl;
            }
        }
        else if (pilihan == 3)
        {
            print_list(head);
            cout << "Anda ingin menghapus data bagian mana?\n1. Bagian pertama\n2. Bagian tengah\n3. Bagian akhir\nMasukkan pilihan: ";
            cin >> pengurangan;
            if (pengurangan == 1)
            {
                delete_head(head);
            }
            else if (pengurangan == 2)
            {
                if (head == nullptr)
                {
                    cout << "Tidak bisa menghapus data karena data masih kosong!" << endl;
                }
                else
                {
                    print_list(head);
                    cout << "Anda ingin menghapus data nomor berapa? ";
                    cin >> angka;
                    delete_node(head, angka);
                }
            }
            else if (pengurangan == 3)
            {
                delete_tail(head);
            }
            else
            {
                cout << "Pilihan yang anda masukkan salah!" << endl;
            }
        }
        else if (pilihan == 4)
        {
            clear(head);
        }
        else if (pilihan == 0)
        {
            continue;
        }
        else
        {
            cout << "Pilihan yang anda masukkan salah!" << endl;
        }
        system("pause");
        system("cls");
    } while (pilihan != 0);
    return 0;
}
