#include<iostream>
#include<string.h>
using namespace std;

class Tuong
{
private:
    string ten;
    int mauCB, satTT, satTP, giapCB, giapP;
public:
    virtual void Nhap()
    {
        cout << "Ten tuong: ";
        cin >> ten;
        cout << "Mau co ban: ";
        cin>> mauCB;
        cout << "Sat thuong tay: ";
        cin >> satTT;
        cout << "Sat thuong phep: ";
        cin >> satTP;
        cout << "Giap co ban: ";
        cin >> giapCB;
        cout << "Giap phep: ";
        cin >> giapP;
    }
    virtual void Xuat()
    {
        cout << "Ten tuong: "<<ten<<endl;
        cout << "Mau co ban: "<<mauCB<<endl;
        cout << "Sat thuong tay: "<<satTT<<endl;
        cout << "Sat thuong phep: "<<satTP<<endl;
        cout << "Giap co ban: "<<giapCB<<endl;
        cout << "Giap phep: "<<giapP<<endl;
    }
    virtual int getLoai()=0;
    virtual float getHutMau()
    {
        return 0;
    }
};
class PhapSu: public Tuong
{
private:
    string tenPS;
    string hieuUng;
    float hutMau;
public:
    void Nhap()
    {
        Tuong::Nhap();
        cout << "Ten phap su: ";
        cin >> tenPS;
        cout << "Hieu ung: ";
        cin >> hieuUng;
        cout << "Hut mau: ";
        cin >> hutMau;
    }
    void Xuat()
    {
        Tuong::Xuat();
        cout << "Ten phap su: "<<tenPS<<endl;
        cout << "Hieu ung: "<<hieuUng<<endl;
        cout << "Hut mau: "<<hutMau<<endl;
    }
    int getLoai()
    {
        return 1;
    }
};
class DauSi:public Tuong
{
private:
    float mienThuong, hutMau;
public:
    void Nhap()
    {
        Tuong::Nhap();
        cout << "Ti le mien thuong: ";
        cin >> mienThuong;
        cout << "Ti le hut mau: ";
        cin >> hutMau;
    }
    void Xuat()
    {
        Tuong::Xuat();
        cout << "Ti le mien thuong: "<<mienThuong<<endl;
        cout << "Ti le hut mau: "<<hutMau<<endl;
    }
    int getLoai()
    {
        return 2;
    }
};
class DoDon:public Tuong
{
private:
    float hoiMau, mienThuong;
    int mauTG;
public:
    void Nhap()
    {
        Tuong::Nhap();
        cout << "Ti le mien thuong: ";
        cin >> mienThuong;
        cout << "Ti le hoi mau: ";
        cin >> hoiMau;
        cout << "Hoi mau/giay: ";
        cin >> mauTG;
    }
    void Xuat()
    {
        Tuong::Xuat();
        cout << "Ti le mien thuong: "<<mienThuong<<endl;
        cout << "Ti le hoi mau: "<<hoiMau<<endl;
        cout << "Hoi mau/giay: "<<mauTG<<endl;
    }
    int getLoai()
    {
        return 3;
    }
};
class XaThu:public Tuong
{
private:
    float tamDanh, tocDanh, chiMang, hutMau;
public:
    void Nhap()
    {
        Tuong::Nhap();
        cout << "Tam danh: ";
        cin >> tamDanh;
        cout << "Toc danh: ";
        cin>> tocDanh;
        cout << "Chi mang: ";
        cin >> chiMang;
        cout << "Hut mau: ";
        cin >> hutMau;
    }
    void Xuat()
    {
        Tuong:: Xuat();
        cout << "Tam danh: "<<tamDanh<<endl;
        cout << "Toc danh: "<<tocDanh<<endl;
        cout << "Chi mang: "<<chiMang<<endl;
        cout << "Hut mau: "<<hutMau<<endl;
    }
    int getLoai()
    {
        return 4;
    }
    float getHutMau()
    {
        return hutMau;
    }
};
class Nguoi
{
private:
    int UID;
    string ranks;
    int soTran;
    float thang;
    Tuong* a[112];
    int n;
    int t;
public:
    void Nhap()
    {
        cout << "UID: ";
        cin >> UID;
        cout << "Rank: ";
        cin >> ranks;
        cout << "So tran: ";
        cin >> soTran;
        cout << "Ti le thang: ";
        cin >> thang;
        cout << "Nhap so tuong co: ";
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cout << "Tuong thu "<< i+1<< " la: 1. Phap Su, 2.Dau Si, 3.Do Don, 4.Xa Thu"<<endl;
            cout << "Chon: ";
            int y;
            cin>> y;
            switch(y)
            {
            case 1:
                {
                    a[i]= new PhapSu();
                    break;
                }
            case 2:
                {
                    a[i]=new DauSi();
                    break;
                }
            case 3:
                {
                    a[i]=new DoDon();
                    break;
                }
            case 4:
                {
                    a[i]=new XaThu();
                    break;
                }
            }
            a[i]->Nhap();
        }
        cout << "Tuong duoc chon: ";
        cin >> t;
    }
    void Xuat()
    {
        cout << "UID: "<<UID<<endl;
        cout << "Rank: "<<ranks<<endl;
        cout << "So tran: "<<soTran<<endl;
        cout << "Ti le thang: "<<thang<<endl;
        cout << "Thong tin tuong duoc chon : "<<endl;
        a[t-1]-> Xuat();
    }
    int DemPhapSu()
    {
        int dem =0;
        for(int i=0;i<n;i++)
        {
            if(a[i]->getLoai()==1)
            {
                dem++;
            }
        }
        return dem;
    }
    Tuong* DuocChon()
    {
        return a[t-1];
    }
};
class TranDau
{
private:
    string maTran;
    string thoiGian;
    Nguoi* dot;
    Nguoi* xanh;
public:
    void Nhap()
    {
        cout << "Ma tran: ";
        cin >> maTran;
        cout << "Thoi gian: ";
        cin >> thoiGian;
        cout << "Doi Do: "<<endl;
        dot =new Nguoi[5];
        xanh=new Nguoi[5];
        for(int i=0;i<1;i++)
        {
            dot[i].Nhap();
            xanh[i].Nhap();
        }
    }
    void Xuat()
    {
        cout << "Ma tran: "<<maTran<<endl;
        cout << "Thoi gian: "<< thoiGian << endl;
        cout << "Doi do"<<endl;
        cout << endl;
        for(int i=0; i<1;i++)
        {
            dot[i].Xuat();
        }
        cout << "Doi xanh"<<endl;
        cout << endl;

        for(int i=0;i<1;i++)
        {
            xanh[i].Xuat();
        }
    }
    void SachTruyHon()
    {
        float a,b;
        for(int i=0;i<1;i++)
        {
            a=a+dot[i].DuocChon()->getHutMau();
            b=b+ xanh[i].DuocChon()->getHutMau();
        }
        if((a>20)||(b>20))
        {
            cout << "Su dung sach truy hon"<<endl;
        }else cout << "Khong su dung sach"<<endl;
    }
    void PhapSu()
    {
        Nguoi max= dot[0];
        for(int i=0;i<1;i++)
        {
            if((dot[i].DemPhapSu())> (max.DemPhapSu()))
            {
                max=dot[i];
            }
        }
        for(int i=0;i<1;i++)
        {
            if((xanh[i].DemPhapSu())> (max.DemPhapSu()))
            {
                max=xanh[i];
            }
        }
        max. Xuat();
    }
};
int main()
{
    TranDau t;
    t.Nhap();
    t.Xuat();
    t.SachTruyHon();
    t.PhapSu();
}
