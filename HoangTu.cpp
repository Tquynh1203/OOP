#include<iostream>
using namespace std;

class Cong
{
protected:
    int tritue, sucmanh, tien;
public:
    Cong(){};
    ~Cong(){};
    virtual void Nhap()=0;
    virtual void Xuat()=0;
    virtual int getTriTue()=0;
    virtual int getSucManh()=0;
    virtual int getTien()=0;
};
class GiaoThuong: public Cong
{
protected:
    int dongia;
    int sohang;
public:
    void Nhap()
    {
        cout << "Nhap vao don gia ten lai buon: ";
        cin >> dongia;
        cout << "Nhap vao so hang ten lai buon: ";
        cin >> sohang;
    }
    void Xuat()
    {
        cout << "Tien: "<< tien;
    }
    int getTien()
    {
        tien=dongia*sohang;
        return tien;
    }
    int getTriTue()
    {
        return 0;
    }
    int getSucManh()
    {
        return 0;
    }
};
class HocThuat: public Cong
{
public:
    void Nhap()
    {
        cout << "Nhap vao do tri tue cua nha hien triet: ";
        cin >> tritue;
    }
    void Xuat()
    {
        cout << "Tri tue: "<< tritue;
    }
    int getTriTue()
    {
        return tritue;
    }
    int getTien()
    {
        return 0;
    }
    int getSucManh()
    {
        return 0;
    }
};
class SucManh:public Cong
{
public:
    void Nhap()
    {
        cout << "Nhap vao suc manh cua dung si: ";
        cin >> sucmanh;
    }
    void Xuat()
    {
        cout << "Suc Manh: " <<sucmanh;
    }
    int getTien()
    {
        return 0;
    }
    int getTriTue()
    {
        return 0;
    }
    int getSucManh()
    {
        return sucmanh;
    }
};
int main()
{
    Cong* a[1000];
    int n;
    //Cau 1
    cout << "Nhap vao so cong: ";
    cin >> n;
    for(int i=0; i<n;i++)
    {
        int t;
        cout << "Cong: 1. Giao Thuong, 2. Hoc thuat, 3.Suc Manh"<<endl;
        cout << "Chon loai cong "<<i+1<<" : ";
        cin >> t;
        switch(t)
        {
        case 1:
            {
                a[i]= new GiaoThuong();
                a[i]->Nhap();
                break;
            }
        case 2:
            {
                a[i]=new HocThuat();
                a[i]->Nhap();
                break;
            }
        case 3:
            {
                a[i]= new SucManh();
                a[i]->Nhap();
                break;
            }
        }
    }
    //Cau 2
    int tien, sucmanh, tritue;
    cout <<endl;
    cout << "Nhap vao so tien cua hoang tu: ";
    cin >> tien;
    cout << "Nhap vao suc manh cua hoang tu: ";
    cin >> sucmanh;
    cout << "Nhap vao tri tue cua hoang tu: ";
    cin >> tritue;
    for(int i=0;i<=n;i++)
    {
        if(i==n)
        {
            cout << "Hoang tu da cuu duoc cong chua"<<endl;
            break;
        }
        tien=tien - a[i]->getTien();
        sucmanh=sucmanh - a[i]->getSucManh();
        if(tien <= 0)
        {
            cout << "Hoang tu bi loai vi het tien o cong "<< i+1<< endl;
            break;
        } else
        {if(sucmanh <= 0)
        {
            cout << "Hoang tu bi loai vi het suc manh o cong "<< i+1<< endl;
            break;
        }else
        {if(tritue < a[i]->getTriTue())
        {
            cout << "Hoang tu bi loai vi khong du tri tue o cong "<< i+1<< endl;
            break;
        }
        }
    }
}}
