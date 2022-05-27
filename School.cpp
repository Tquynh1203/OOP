#include <iostream>

using namespace std;

class SinhVien
{
    private:
    string msv, hoten;
    double dtb;
    public:
    SinhVien()
    {
        msv="";
        hoten="";
        dtb=0;
    }
    SinhVien(string msv, string hoten, double dtb)
    {
        this->msv=msv;
        this->hoten=hoten;
        this->dtb=dtb;
    }
    string getMsv()
    {
        return msv;
    }
    void setMsv(string msv)
    {
        this->msv=msv;
    }
    string getHoten()
    {
        return hoten;
    }
    void setHoten()
    {
        this->hoten=hoten;
    }
    void setDtb(double dtb)
    {
        this->dtb=dtb;
    }
    double getDtb()
    {
        return dtb;
    }
    virtual void Dtb()=0;
    virtual void display()
    {
        cout << "MSV: "<<msv<<endl;
        cout << "Ho ten: "<<hoten<<endl;
        cout << "Dtb: "<< dtb<<endl;
    }
};
class Chuan: public SinhVien
{
    public:
    Chuan():SinhVien(){};
    Chuan(string msv, string hoten, double dtb):SinhVien(msv, hoten, dtb)
    {
    }
    void Dtb()
    {

    }
    void display()
    {
        cout << "MSV: "<<getMsv()<<endl;
        cout << "Ho ten: "<<getHoten()<<endl;
        cout << "Dtb: "<< getDtb()<<endl;
    }
};
class ChatLuongCao:public SinhVien
{
    private:
    double dqt;
    public:
    ChatLuongCao():SinhVien()
    {
        dqt=0;
    }
    ChatLuongCao(string msv, string hoten, double dtb, double dqt):SinhVien(msv, hoten, dtb)
    {
        this->dqt= dqt;
    }
    void setDqt(double dqt)
    {
        this->dqt=dqt;
    }
    double getDqt()
    {
        return dqt;
    }
    void Dtb()
    {
        setDtb((getDtb()+dqt)/2) ;
    }
    void display()
    {
        cout << "MSV: "<<getMsv()<<endl;
        cout << "Ho ten: "<<getHoten()<<endl;
        cout << "Dtb: "<< getDtb()<<endl;
    }
};
class LopChuan
{
private:
    SinhVien* a[50];
    int n;
public:
    void Nhap()
    {
        cout << "Nhap so sinh vien chuan: ";
        cin >> n;
        for(int i=0; i<n;i++)
        {
            string hoten, msv;
            double dtb;
            cin.ignore();
            cout << "Nhap vao ho ten :";
            getline(cin, hoten);
            cout << "Nhap vao msv: ";
            cin >> msv;
            cout<< "Nhap diem trung binh: ";
            cin >> dtb;
            a[i]= new Chuan(msv, hoten, dtb);
        }
    }
    void KhoiTao()
    {
            string hoten, msv;
            double dtb;
            cin.ignore();
            cout << "Nhap vao ho ten :";
            getline(cin, hoten);
            cout << "Nhap vao msv: ";
            cin >> msv;
            cout<< "Nhap diem trung binh: ";
            cin >> dtb;
            a[n]= new Chuan(msv, hoten, dtb);
            n++;
    }
    void Xuat()
    {
        for(int i=0;i<n;i++)
        {
            a[i]->display();
        }
    }
    void Tim(string msv)
    {
        cin.ignore();
        getline(cin, msv);
        for(int i=0;i<n;i++)
        {
            if(a[i]->getMsv()==msv)
            {
                a[i]->display();
            }
        }
    }
    void ThoiHoc()
    {
        cout << "Danh sach sinh vien thoi hoc: "<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]->getDtb()<5)
            {
                cout <<"Ho ten: "<< a[i]->getHoten();
            }
        }
    }
    void Dtb()
    {
        cout << "Sinh vien diem trung binh cao nhat: "<<endl;
        SinhVien* max=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]->getDtb()>max->getDtb())
            {
                max=a[i];
            }
        }
        cout <<"Ho ten: "<< max->getHoten();
    }
};
class LopChatLuongCao
{
private:
    SinhVien* a[50];
    int n;
public:
    void Nhap()
    {
        cout << "Nhap so sinh vien chat luong cao: ";
        cin >> n;
        for(int i=0; i<n;i++)
        {
            string hoten, msv;
            double dtb, dqt;
            cin.ignore();
            cout << "Nhap vao ho ten :";
            getline(cin, hoten);
            cout << "Nhap vao msv: ";
            cin >> msv;
            cout<< "Nhap diem trung binh: ";
            cin >> dtb;
            cout<< "Nhap diem qua trinh: ";
            cin >> dqt;
            a[i]= new ChatLuongCao(msv, hoten, dtb, dqt);
        }
    }
    void KhoiTao()
    {
            string hoten, msv;
            double dtb,dqt;
            cin.ignore();
            cout << "Nhap vao ho ten :";
            getline(cin, hoten);
            cout << "Nhap vao msv: ";
            cin >> msv;
            cout<< "Nhap diem trung binh: ";
            cin >> dtb;
            cout<< "Nhap diem qua trinh: ";
            cin >> dqt;
            a[n]=new ChatLuongCao(msv, hoten, dtb, dqt);
            n=n+1;
    }
    void Xuat()
    {
        for(int i=0;i<n;i++)
        {
            a[i]->Dtb();
        }
        for(int i=0;i<n;i++)
        {
            a[i]->display();
        }
    }
    void Tim(string msv)
    {
        cin.ignore();
        getline(cin, msv);
        for(int i=0;i<n;i++)
        {
            if(a[i]->getMsv()==msv)
            {
                a[i]->display();
            }
        }
    }
    void ThoiHoc()
    {
        cout << "Danh sach sinh vien thoi hoc: "<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]->getDtb()<5)
            {
                cout <<"Ho ten: "<< a[i]->getHoten();
            }
        }
    }
    void Dtb()
    {
        cout << "Sinh vien diem trung binh cao nhat: "<<endl;
        SinhVien* max=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]->getDtb()>max->getDtb())
            {
                max=a[i];
            }
        }
        cout <<"Ho ten: "<< max->getHoten();
    }
};
class Truong
{
private:
    LopChuan lopc[40];
    int n;
    LopChatLuongCao lopclc[40];
    int m;
    public:
        void Nhap()
        {
            cout << "Nhap so lop chuan: "<<endl;
            cin >> n;
            for(int i=0;i<n;i++)
            {
                cout << "Nhap danh sach lop chuan "<<i++<<endl;
                lopc[i].Nhap();
            }
            cout << "Nhap so lop chat luong cao: "<<endl;
            cin >> m;
            for(int i=0;i<n;i++)
            {
                cout << "Nhap danh sach lop chat luong cao "<<i++<<endl;
                lopclc[i].Nhap();
            }
        }
        void Xuat()
        {
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chuan "<<i+1<<endl;
                lopc[i].Xuat();
            }
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chat Luong Cao "<<i+1<<endl;
                lopclc[i].Xuat();
            }
        }
        void KhoiTao()
        {

            for(int i=0; i<n;i++)
            {
                lopc[i].KhoiTao();
            }
            for(int i=0; i<n;i++)
            {
                lopclc[i].KhoiTao();
            }
        }
        void Tim()
        {
            cout << "Nhap vao msv can tim"<<endl;
            string msv;
            cin.ignore();
            getline(cin, msv);
            cout << "Sinh vien can tim la: "<<endl;
            for(int i=0; i<n;i++)
            {
                lopc[i].Tim(msv);
            }
            for(int i=0; i<n;i++)
            {
                lopclc[i].Tim(msv);
            }
        }
        void ThoiHoc()
        {
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chuan "<<i+1<<endl;
                lopc[i].ThoiHoc();
            }
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chat luong cao "<<i+1<<endl;
                lopclc[i].ThoiHoc();
            }
        }
        void Dtb()
        {
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chuan "<<i+1<<endl;
                lopc[i].Dtb();
            }
            for(int i=0; i<n;i++)
            {
                cout<<"Lop Chat luong cao "<<i+1<<endl;
                lopclc[i].Dtb();
            }
        }
};
int main()
{
    Truong t;
    while(1)
    {
        cout << "================MENU==============="<<endl;
        cout << "Cau 1. Nhap du lieu cho nhieu lop "<<endl;
        cout << "Cau 2. Khoi tao ngau nhien sinh vien "<<endl;
        cout << "Cau 3. Xuat thong tin sinh vien"<<endl;
        cout << "Cau 4. Tim sinh vien theo msv"<<endl;
        cout << "Cau 5. Xuat cac sinh vien dang thoi hoc "<<endl;
        cout << "Cau 6. Tim sinh vien co diem trung binh cao nhat lop"<<endl;
        cout << "==================================="<<endl;
        cout << "Chon cau: ";
        int chon;
        cin >> chon;
        switch (chon)
        {
        case 1:
            {
                t.Nhap();
                break;
            }
        case 2:
            {
                t.KhoiTao();
                break;
            }
        case 3:
            {
                t.Xuat();
                break;
            }
        case 4:
            {
                t.Tim();
                break;
            }
        case 5:
            {
                t.ThoiHoc();
                break;
            }
        case 6:
            {
                t.Dtb();
                break;
            }
        }
    }
}
