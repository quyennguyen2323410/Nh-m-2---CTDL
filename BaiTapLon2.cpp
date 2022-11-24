#include<bits/stdc++.h>
using namespace std;

struct Student{
    string name, mssv, gioitinh, lop, namsinh;
    double dtb; 
    float toan, ly, hoa;
    char hocluc [10] ; 
};

struct SV{
    Student s;
    SV *next;
};

typedef struct SV* sv;
void sapxep(SV a[], int n);

// cap nhat dong mot node moi du lieu
sv makeNode(){
    Student s;
    cout << "NHAP THONG TIN SINH VIEN\n";
    cout << "Nhap MSSV: "; cin >> s.mssv; 
    cout << "Nhap ho & ten: "; cin.ignore();
    getline(cin, s.name);
    cout << "Nhap lop: "; cin >> s.lop;
    cout << "Nhap gioi tinh: "; cin >> s.gioitinh;
    cout << "Nhap nam sinh: "; cin >> s.namsinh;
    cout << "Nhap diem toan: "; cin >> s.toan;
    cout << "Nhap dien ly: "; cin >> s.ly;
    cout << "Nhap diem hoa: "; cin >> s.hoa;
   // cout << "Nhap DTB: "; cin >> s.dtb; 
    sv tmp = new SV();
    tmp->s=s; 
    tmp->next = NULL;
    return tmp;
}
//kiem tra rong
bool empty(sv a){
    return a== NULL;
}

int Size(sv a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a=a->next;
    }
    return cnt;
}
//them sinh viên vao dau danh sach
void insertFirst(sv &a){
    sv tmp = makeNode();
    if(a == NULL){
        a=tmp;
    }
    else{
        tmp->next=a;
        a=tmp;
    }
}
//them sinh viên vao cuoi danh sach
void insertLast(sv &a){
    sv tmp = makeNode();
    if(a == NULL){
        a = tmp;
    }
    else{
        sv p = a;
        while(p->next !=NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}
//them sinh viên tùy ý
void insertMiddle(sv &a, int pos){
    int n=Size(a);
    if(pos <= 0 || pos > n+1){
        cout << "Vi tri chen khong hop le! \n";
        return;
    }
    if(pos==1){
        insertFirst(a); return;
    }
    else if(pos == n + 1){
        insertLast(a); return;
    }
    sv p=a;
    for(int i=1; i < pos - 1; i++){
        p=p->next;
    }
    sv tmp=makeNode();
    tmp->next=p->next;
    p->next=tmp;
}
//xoa phan tu o đầu
void deleteFirst(sv &a){
    if(a==NULL)
    return;
    a=a->next;
}

//xoa phan tu o cuoi
void deleteLast(sv &a){
    if(a==NULL) return; 
    sv truoc = NULL, sau = a;
    while(sau->next != NULL){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc==NULL){
        a=NULL;
    }
    else {
        truoc -> next = NULL;
    }
}
//xóa tùy ý
void deleteMiddle(sv &a, int pos){
    if(pos <= 0||pos>Size(a)) return;
    sv truoc = NULL, sau = a;
    for(int i=1; i<pos; i++){
        truoc =sau;
        sau=sau->next;
    }
    if(truoc == NULL){
        a=a->next;
    }
    else{
        truoc -> next=sau->next;
    }
}

//s.gpa = (s.toan+s.ly+s.hoa)/3

void in(Student s){
    cout << "------------------\n";
    cout << "MSSV: "<<s.mssv <<endl;
    cout << "Ho ten: "<< s.name<<endl;
    cout << "Lop: "<< s.lop <<endl;
    cout << "Gioi Tinh: "<< s.gioitinh<<endl;
    cout << "Nam sinh: "<< s.namsinh<<endl;
    cout << "Toan: "<< s.toan<<endl;
    cout << "Ly: "<< s.ly<<endl;
    cout << "Hoa: "<< s.hoa<<endl;
    s.dtb=(s.toan+s.ly+s.hoa)/3;
    cout << "DTB: "<<fixed<<setprecision(2) <<s.dtb << endl;
    if(s.dtb >= 8) strcpy(s.hocluc, "Gioi");
    else if(s.dtb >= 6.5) strcpy(s.hocluc, "Kha");
    else if(s.dtb >= 5) strcpy(s.hocluc, "Trung binh");
    else strcpy(s.hocluc, "Yeu");
    cout << "Xep loai hoc luc: "<< s.hocluc<<endl;
    cout << "----------------------------------------\n";
}
// chức năng lưu và tin ra danh sách sinh viên
void inds(sv a){
    cout << "Danh sach sinh vien\n";
    while(a != NULL){
        in(a->s);
        a=a->next;
    }
    cout << endl;
}
// chức năng sắp xếp sinh viên theo điểm trung bình
void sapxep(sv &a){
    for(sv p=a; p->next != NULL; p=p->next){
        sv min = p;
        for(sv q=p->next; q != NULL; q=q->next){
            if(q-> s.hocluc < min-> s.hocluc){
                min = q;
            }
        }
        Student tmp = min->s;
        min->s=p->s;
        p->s=tmp;
    }
}

int main(){
    sv head = NULL;
    while(1){
        cout << "***********************************************************\n";
        cout << "********                ***********                 *******\n";
        cout << "*****                      *****                      *****\n";
        cout << "***                        MENU                         ***\n";     
        cout << "**         1. Chen sinh vien vao dau danh sach           **\n";
        cout << "*          2. Chen sinh vien vao cuoi danh sach           *\n";
        cout << "*          3. Chen sinh vien bat ky vao danh sach         *\n";
        cout << "*          4. Xoa sinh vien o dau danh sach               *\n";
        cout << "*          5. Xoa sinh vien o cuoi danh sach              *\n";
        cout << "**         6. Xoa sinh vien bat ky trong danh sach       **\n";
        cout << "***        7. Luu va hien thi danh sach lien ket        ***\n";
        cout << "****       8. Sap xep sinh vien theo DTB               ****\n";
        cout << "******     0. Thoat!                                 ******\n";
        cout << "*******                                             *******\n";
        cout << "*********                                         *********\n";
        cout << "************                                   ************\n";
        cout << "**************                               **************\n";
        cout << "*****************                         *****************\n";
        cout << "*********************                 *********************\n";
        cout << "************************           ************************\n";
        cout << "***************************** *****************************\n";
        cout << "-----------------------------------------------------------\n";
        cout << "Nhap lua chon: ";
        int lc; cin >> lc;
        if(lc == 1){
            insertFirst(head);
            cout << "Them thong tin thanh cong\n";
        }
        else if(lc == 2){
            insertLast(head);
            cout << "Them thong tin thanh cong\n";
        }
        else if(lc==3){
            int pos; cout << "Nhap vao vi tri can chen: "; cin >> pos;
            insertMiddle(head, pos);
            cout << "Them thong tin thanh cong\n";
        }
        else if(lc==4){
            deleteFirst(head);
            cout << "Xoa sinh vien thanh cong\n";
        }
        else if(lc==5){
            deleteLast(head);
            cout << "Xoa sinh vien thanh cong\n";
        }
        else if(lc==6){
            int pos; cout <<"Nhap vi tri can chen: "; cin >> pos;
            deleteMiddle(head, pos);
            cout << "Xoa sinh vien thanh cong\n";
        }
        else if(lc==7){
            inds(head);
        }
        else if(lc==8){
            sapxep(head);
        }
        else if(lc==0){
            break;
        }
    }
    return 0;
}