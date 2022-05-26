#include <iostream>

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
    NhanVien(string mnv, string hoten )
    {
        this->mnv=mnv;
        this->hoten=hoten;
        luong=0;
    }
    void setMnv(string mnv)
    {
        this->mnv=mnv;
    }
    string getMnv()
    {
        return mnv;
    }
    void setHoten(string hoten)
    {
        this->hoten=hoten;
    }
    string getHoten()
    {
        return hoten;
    }
    void setLuong(long long luong)
    {
        this->luong=luong;
    }
    long long getLuong()
    {
        return luong;
    }
    virtual setLuongcoban(long long)=0;
    virtual getId()=0;
    virtual void Luong()=0;
    virtual  void display()=0;
};

class LapTrinhVien: public NhanVien
{
    int giotangca;
    long long luongcanban;
    int id;
    public:
    LapTrinhVien():NhanVien()
    {
        giotangca=0;
        id=1;
    }
    LapTrinhVien(string mnv, string hoten, long long luongcanban, int giotangca):NhanVien(mnv, hoten)
    {
        this->luongcanban=luongcanban;
        this->giotangca=giotangca;
        id=1;
    }
    void setGiotangca(int giotangca)
    {
        this->giotangca=giotangca;
    }
    int getGiotangca()
    {
        return giotangca;
    }
    void setLuongcanban(long long Luongcanban)
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
        setLuong(luongcanban+giotangca*250000);
    }
    void display()
    {
        cout << "LapTrinhVien: Ho ten: "<<getHoten() << endl;
        cout << "LapTrinhVien: MNV: "<<getMnv()<<endl;
        cout << "LapTrinhVien: So gio tang ca: "<<giotangca<<endl;
        cout << "LapTrinhVien: Luong: "<< getLuong()<<endl;
    }
};
class PhanTichVien:public LapTrinhVien
{
    int phucap;
    int id;
    public:
    PhanTichVien():LapTrinhVien()
    {
        phucap=0;
        id=2;
    }
    PhanTichVien(string mnv, string hoten, long long luongcanban, int giotangca, int phucap):LapTrinhVien(mnv, hoten, luongcanban, giotangca)
    {
        this->phucap=phucap;
        id=2;
    }
    void setPhucap(int phucap)
    {
        this->phucap=phucap;
    }
    int getPhucap()
    {
        return phucap;
    }
    int getId()
    {
        return id;
    }
    void Luong()
    {
        return setLuong(LapTrinhVien::getLuong()*1.8);
    }
    void display()
    {
        cout << "PhanTichVien: Ho ten: "<<getHoten() << endl;
        cout << "PhanTichVien: MNV: "<<getMnv()<<endl;
        cout << "PhanTichVien: So gio tang ca: "<<getGiotangca()<<endl;
        cout << "PhanTichVien: Phu cap: "<<phucap<<endl;
        cout << "PhanTichVien: Luong: "<< getLuong()<<endl;
    }
};
class NhanVienKiem: public NhanVien
{
    private:
    int soloi;
    long long luongcanban;
    int id;
    public:
    NhanVienKiem():NhanVien()
    {
        soloi=0;
    }
    NhanVienKiem(string mnv, string hoten, long long luongcanban, int soloi):NhanVien(mnv, hoten)
    {
        this->soloi=soloi;
        this->luongcanban=luongcanban;
    }
    void setSoloi(int soloi)
    {
        this->soloi=soloi;
    }
    int getSoloi()
    {
        return soloi;
    }
    void setLuongcanban(long long Luongcanban)
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
         setLuong(luongcanban+soloi*85000);
    }
    void display()
    {
        cout << "NhanVienKiem: Ho ten: "<<getHoten() << endl;
        cout << "NhanVienKiem: MNV: "<<getMnv()<<endl;
        cout << "NhanVienKiem: So loi: "<<soloi<<endl;
        cout << "NhanVienKiem: Luong: "<< getLuong()<<endl;
    }
};
 class NV
 {
     NhanVien* a[500];
     int n;
     public:
     void Nhap()
     {
        string hoten, mnv;
        long long luongcanban;
        int giotangca, soloi;
        int ltv, ptv, nvk;
        cout << "So nhan vien lap trinh vien :";
        cin >> ltv;
        n=ltv;
        for(int i=0; i<n;i++)
        {
            cin.ignore();
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            cin>>mnv;
            cout << "Nhap so gio lam: ";
            cin >> giotangca;
            cout << "Nhap luong co ban: ";
            cin >> luongcanban;
            a[i]= new LapTrinhVien(mnv,hoten,luongcanban, giotangca);
        }
        cout << "So nhan vien phan tich vien: ";
        cin >> ptv;
        n= n+ptv;
        for(int i=ltv; i<n; i++)
        {
            int phucap;
            cin.ignore();
            string hoten, mnv;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            cin>>mnv;
            cout << "Nhap so gio tang ca: ";
            cin >> sogiolam;
            cout << "Nhap luong co ban: ";
            cin >> luongcoban;
            cout << "Nhap phu cap: ";
            cin >> phucap;
            a[i]=new PhanTichVien(mnv,hoten,luongcoban,sogiolam, phucap);
        }
        cout << "So nhan vien nhan vien kiem :";
        cin >> nvk;
        n=n+nvk;
        for(int i=ptv; i<n;i++)
        {
            cin.ignore();
            string hoten, mnv;
            cout << "Nhap ten: ";
            getline(cin, hoten);
            cout << "Nhap MNV: ";
            cin>>mnv;
            cout << "Nhap so loi: ";
            cin >> sogiolam;
            cout << "Nhap luong co ban: ";
            cin >> luongcoban;
            a[i]=new LapTrinhVien(mnv,hoten,luongcoban, soloi);
        }
     }
    void Xuat()
    {
        for(int i=0; i<n; i++)
        {
            a[i]-> display();
        }
    }
    void TrungBinh()
    {
        int luongtrungbinh;
        cout << "Nhap muc luong trung binh: ";
        cin >> luongtrungbinh;
        cout << "Nhan vien co luong thap hon luong trung binh: "<<endl;
        for(int i=0; i<n;i++)
        {
            if(a[i]->getLuong()< luongtrungbinh)
            {
                a[i]->display();
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
    void LTVLuongCao()
    {
        NhanVien* max;
        max->setLuong(0);
        for(int i=0;i<n;i++)
        {
            if(a[i]->getId()==1&& a[i]->getLuong()>max->getLuong())
            {
                max=a[i];
            }
        }
        cout << "Nhan vien lap trinh vien luong cao nhat la: "<<endl;
        max->display();
    }
    void NVKLuongThap()
    {
        NhanVien* min;
        min->setLuong(0);
        for(int i=0;i<n;i++)
        {
            if(a[i]->getId()==3&& a[i]->getLuong()<min->getLuong())
            {
                min=a[i];
            }
        }
        cout << "Nhan vien kiem thu luong thap nhat la: "<<endl;
        min->display();
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
                cout << "Nhap luong co ban: ";
                int luongcoban;
                cin >> luongcoban;
                a[i]->setLuongcoban(luongcoban);
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
        cout << "Cau 2. Xuat thong tin nhan vien"<<endl;
        cout << "Cau 3. Xuat thong tin nhan vien co luong thap hon muc trung binh"<<endl;
        cout << "Cau 4. Tim nhan vien co luong cao nhat"<<endl;
        cout << "Cau 5. Tim nhan vien luong thap nhat"<<endl;
        cout << "Cau 6. Tim nhan vien lap trinh vien co luong cao nhat vien"<<endl;
        cout << "Cau 7. Tim nhan vien kiem thu luong thap nhat"<<endl;
        cout << "Cau 8. Cap nhat luong co ban"<<endl;
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
                nv.Xuat();
                break;
            }
        case 3:
            {
                nv.TrungBinh();
                break;
            }
        case 4:
            {
                nv.LuongCao();
                break;
            }
        case 5:
            {
                nv.LuongThap();
                break;
            }
        case 6:
            {
                nv.LTVLuongCao();
                break;
            }
        case 7:
            {
                nv.NVKLuongThap();
                break;
            }
        case 8:
            {
                nv.CapNhat();
                break;
            }
        }
    }
}


