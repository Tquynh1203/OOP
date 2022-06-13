#include<iostream>
using namespace std;

class NhanVien
{
    private:
    string mnv, hoten;
    long long luong;
    public:
    NhanVien()
    {
        mnv="";
        hoten="";
        luong=0;
    }
    NhanVien(string mnv, string hoten)
    {
        this->mnv=mnv;
        this->hoten=hoten;
        luong=0;
    }
    void setHoten(string hoten)
    {
        this->hoten=hoten;
    }
    string getHoten()
    {
        return hoten;
    }
    void setMnv(string mnv)
    {
        this->mnv=mnv;
    }
    string getMnv()
    {
        return mnv;
    }
    void setLuong(long long luong)
    {
        this->luong=luong;
    }
    long long getLuong()
    {
        return luong
    }
    virtual void Luong()=0;
    virtual int SanPham()=0;
    virtual void Nhap()=0;
    virtual int getId()=0;
    virtual void display()=0;

};
class SanXuat: public NhanVien
{
    private:
    int sosanpham;
    int luongcanban;
    int id;
    public:
    SanXuat():NhanVien()
    {
        sosanpham=0;
        luongcanban=0;
        id=1;
    }
    SanXuat(string mnv, string hoten, int sosanpham): NhanVien(mnv,hoten)
    {
       luongcanban=5300000;
       this-> sosanpham=sosanpham;
       id=1;
    }
    void setSosanpham(int sosanpham)
    {
        this->sosanpham=sosanpham;
    }
    int getSosanpham()
    {
        return sosanpham;
    }
    void setLuongcanban(long long luongcanban)
    {
        this->luongcanban=luongcanban;
    }
    long long getLuongcanban()
    {
        return luongcanban;
    }
    int getId()
    {
        return id;
    }
    void Luong()
    {
        setLuong( sosanpham*170000+ luongcanban);
    }
    void Nhap()
    {
            cin.ignore();
            string hoten, mnv;
            cout << "Nhap ten: ";
            getline(cin,hoten);
            setHoten(hoten);
            cout << "Nhap MNV: ";
            getline(cin,mnv);
            setMnv(mnv);
            cout << "Nhap so san pham: ";
            cin >> sosanpham;
    }
    int SanPham()
    {
        int i=getSosanpham();
        return i;
    }
    void display()
    {
        cout << "San Xuat: Ten: "<< getHoten()<<endl;
        cout << "San Xuat: MNV: "<<getMnv()<<endl;
        cout << "San Xuat: So san pham: "<< sosanpham<<endl;
        cout << "San Xuat: Luong: "<<getLuong() <<endl;
    }
};
class VanPhong: public NhanVien
{
    private:
    int songaylam;
    int luongcanban;
    int id;
    public:
    VanPhong():NhanVien()
    {
        songaylam=0;
        luongcanban=0;
        id=2;
    }
    VanPhong(string mnv, string hoten, int songaylam):NhanVien(mnv,hoten)
    {
        this->songaylam=songaylam;
        luongcanban=4800000;
        id=2;
    }
    void setSongaylam(int songaylam)
    {
        this->songaylam=songaylam;
    }
    int getSongaylam()
    {
        return songaylam;
    }
    void setLuongcanban(long long luongcanban)
    {
        this->luongcanban=luongcanban;
    }
    long long getLuongcanban()
    {
        return luongcanban;
    }
    int getId()
    {
        return id;
    }
    void Luong()
    {
        setLuong(songaylam*220000+luongcanban);
    }
    void Nhap()
    {
            cin.ignore();
            string hoten, mnv;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            setHoten(hoten);
            cout << "Nhap MNV: ";
            cin >>mnv;
            setMnv(mnv);
            cout << "Nhap so ngay lam : ";
            cin >> songaylam;
    }
    int SanPham()
    {
        int i=0;
        return i;
    }
    void display()
    {
        cout << "VanPhong: Ten: "<< getHoten()<<endl;
        cout << "VanPhong: MNV: "<<getMnv()<<endl;
        cout << "VanPhong: So ngay lam: "<< songaylam<<endl;
        cout << "VanPhong: Luong: "<<getLuong()<<endl;
    }
};
class NV
{
    NhanVien* a[200];
    int n;
    public:
    void Nhap()
    {
        string hoten, mnv, songaylam, sosanpham;
        int sx, vp;
        cout << "So nhan vien san xuat:";
        cin >> sx;
        for(int i=0; i<sx;i++)
        {
            cin.ignore();
            string hoten, mnv;
            int sosanpham;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            cin>>mnv;
            cout << "Nhap so san pham: ";
            cin >> sosanpham;
            a[i]=new SanXuat(mnv,hoten,sosanpham);
        }
        cout << "So nhan vien van phong: ";
        cin >> vp;
        n= sx+vp;
        for(int i=sx; i<n; i++)
        {
            cin.ignore();
            string hoten, mnv;
            int songaylam;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            getline(cin,mnv);
            cout << "Nhap so ngay lam: ";
            cin >> songaylam;
            a[i]=new VanPhong(mnv,hoten,songaylam);
        }
    }
    void Xuat()
    {
        for(int i=0; i<n; i++)
        {
            a[i]-> display();
        }
    }
    void TaoNgauNhien()
    {
        cout << "Nhap kieu nhan vien muon tao SanXuat(1), VanPhong(0): ";
        int t;
        cin >> t;
        cout << "Nhap so nhan vien muon tao: ";
        int k;
        cin >> k;
        if(t==1)
        {
            for(int i=n; i<n+k;i++)
        {
            cin.ignore();
            string hoten, mnv;
            int sosanpham;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            getline(cin,mnv);
            cout << "Nhap so san pham: ";
            cin >> sosanpham;
             a[i]=new SanXuat(mnv,hoten,sosanpham);
        }
        }else
        {
            for(int i=n; i<n+k; i++)
        {
            cin.ignore();
            string hoten, mnv;
            int songaylam;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            getline(cin,mnv);
            cout << "Nhap so ngay lam: ";
            cin >> songaylam;
             a[i]=new VanPhong(mnv,hoten,songaylam);
        }
        }
        n=n+k;
    }
    void TimMnv()
    {
        string mnv;
        cout << "Nhap mnv";
        cin.ignore();
        getline(cin, mnv);
        for(int i=0; i<n;i++)
        {
            if(a[i]->getMnv()==mnv)
            {
                a[i]->display();
            }
        }
    }
    void Luong()
    {
        for(int i=0; i<n;i++)
        {
            a[i]->Luong();
        }
    }
    void CapNhat()
    {
        cin.ignore();
        string mnv;
        cout << "Nhap mnv";
        getline(cin, mnv);
        for(int i=0; i<n;i++)
        {
            if(a[i]->getMnv()==mnv)
            {
                a[i]->Nhap();
            }
        }
    }
    void LuongCao()
    {
        NhanVien* max= a[0];
        for(int i=0; i<n;i++)
        {
            if(a[i]->getLuong()>max->getLuong())
            {
                max= a[i];
            }
        }
        cout << "Nhan vien luong cao nhat la: "<<endl;
        max->display();
    }
    void LuongThap()
    {
        NhanVien* min= a[0];
        for(int i=0; i<n;i++)
        {
            if(a[i]->getLuong()<min->getLuong())
            {
                min= a[i];
            }
        }
        cout << "Nhan vien luong thap nhat la: "<<endl;
        min->display();
    }
    void SanPham()
    {
        for(int i=0; i<n;i++)
        {
            for(int j=i;j<n;j++)
            if(a[i]->SanPham()> a[j]->SanPham())
            {
                NhanVien* t =a[i];
                a[i]= a[j];
                a[j]= t;
            }
        }
        cout << "Top 10 nhan vien nhieu san pham: "<<endl;
        for(int i=0;i<10;i++)
        {
            if(a[i]->getId()==1)
            {
                a[i]->display();
            }
        }
    }

};
int main()
{
    NV nv;
    while(1)
    {
        cout <<"=========== MENU=========="<<endl;
        cout << "Cau 1. Nhap vao nhan vien"<<endl;
        cout << "Cau 2. Cho phep tao them k nhan vien"<<endl;
        cout << "Cau 3. Xuat thong tin nhan vien"<<endl;
        cout << "Cau 4. Tinh va cap nhat tien luong"<<endl;
        cout << "Cau 5. Tim nhan vien theo ma nhan vien"<<endl;
        cout << "Cau 6. Cap nhat thong tin theo ma nhan vien"<<endl;
        cout << "Cau 7. Tim nhan vien co luong cao nhat"<<endl;
        cout << "Cau 8. Tim nhan vien luong thap nhat"<<endl;
        cout << "Cau 9. Top 10 nhan vien co nhieu san pham nhat"<<endl;
        cout << "========================="<<endl;
        int chon;
        cout << "Ban hay chon cau: ";
        cin>>chon;
        switch(chon)
        {
        case 1:
            {
                nv.Nhap();
                break;
            }
        case 2:
            {
                nv.TaoNgauNhien();
                break;
            }
        case 3:
            {
                nv.Xuat();
                break;
            }
        case 4:
            {
                nv.Luong();
                break;
            }
        case 5:
            {
                nv.TimMnv();
                break;
            }
        case 6:
            {
                nv.CapNhat();
                break;
            }
        case 7:
            {
                nv.LuongCao();
                break;
            }
        case 8:
            {
                nv.LuongThap();
                break;
            }
        case 9:
            {
                nv. SanPham();
                break;
            }
        }
    }
}
