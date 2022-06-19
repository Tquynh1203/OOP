#include<iostream>
using namespace std;

class web
{
protected:
    int x, y, d, r;
    int maunen;
    int mauchu;
public:
    web(){};
    ~web(){};
    virtual void Nhap()
    {
        cout << "Nhap hoanh do: ";
        cin >> x;
        cout << "Nhap tung do: ";
        cin >> y;
        cout << "Nhap chieu dai: ";
        cin >> d;
        cout << "Nhap chieu rong: ";
        cin >> r;
        cout << "Nhap mau nen: 1. Do, 2.Cam, 3.Vang, 4.Xanh Nhat, 5.Xanh, 6.";
        cin >> maunen;
        cout << "Nhap mau chu: 1. Do, 2.Cam, 3.Vang, 4.Xanh Nhat, 5.Xanh, 6.";
        cin >> mauchu;
    }
    virtual void Xuat()
    {
        cout << "Hoanh: "<< x << "Tung: "<< y<<"Dai: "<< d<<"Rong: "<<r<<endl;
        cout << "Mau nen: "<< maunen<<endl;
        cout << "Mau chu: "<< mauchu<<endl;
    }
    bool MauBoTucTrucTiep()
    {
        if((maunen==mauchu-6)||(maunen==maunen+6))
        {
            return true;
        }
        return false;
    }
    int getMauNen()
    {
        return maunen;
    }
};
class Label: public web
{
protected:
    char text[50];
public:
    void Nhap()
    {
        web::Nhap();
        cout << "nhap vao text: ";
        cin >> text;
    }
    void Xuat()
    {
        web:: Xuat();
        cout << "Text: "<< text<<endl;
    }
};
class Button: public web
{
protected:
    char text[50];
    char hinhanh[50];
public:
    void Nhap()
    {
        web::Nhap();
        cout << "nhap vao text: ";
        cin >> text;
        cout << "Nhap vao anh: ";
        cin >> hinhanh;
    }
    void Xuat()
    {
        web:: Xuat();
        cout << "Text: "<< text<<endl;
        cout << "Hinh anh: "<<hinhanh<<endl;
    }
};
int main()
{
    web* a[100];
    int n;
    //Cau 1
    cout << "Nhap so thanh phan co mau cua web: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int t;
        cout << "Chon: 1.Label, 2.Button: "<<endl;
        cout << "Chon thanh phan: ";
        cin >> t;
        switch(t)
        {
        case 1:
            {
                a[i]=new Label();
                a[i]->Nhap();
                break;
            }
        case 2:
            {
                a[i]=new Button();
                a[i]->Nhap();
                break;
            }
        }
    }
    //Cau 2
    cout << endl;
    if(a[0]->MauBoTucTrucTiep()==true)
    {
        cout << "Phu hop voi mau bo tuc truc tiep"<<endl;
    }else cout <<"Khong phu hop voi mau bo tuc truc tiep"<<endl;
    //Cau 3
    //Mau don sac
    cout << endl;
    int color= a[0]->getMauNen();
    for(int i=0;i<=n;i++)
    {
        if(i==n)
        {
            cout << "Mau don sac"<<endl;
            break;
        }
        if(a[i]->getMauNen()!=color)
        {
            cout << "Khong don sac"<<endl;
            break;
        }
    }
    //MauBoTucTrucTiep
    cout << endl;
    for(int i=0;i<n;i++)
    {
        int t=1;
        if(i==n)
        {
            cout << "Phu hop mau bo tuc truc tiep"<<endl;
            break;
        }
        for(int j=i+1;j<n;j++)
        {
            int c= a[i]->getMauNen();
            int b=a[j]->getMauNen();
            if((c!=b+6)||(c!=b-6))
            {
                t=0;
                break;
            }
        }
        if(t==0)
        {
            cout << "Khong phu hop voi mau bo tuc truc tiep"<<endl;
            break;
        }
    }
    //Mautuongdong
    cout <<endl;
        if((color >1)&& (color <12))
        {

            for(int i=0;i<=n;i++)
            {
                if(i==n)
                {
                    cout << "Tuong dong";
                    break;
                }
            if((a[i]->getMauNen()!=color+1)&&(a[i]->getMauNen()!=color-1)&&(a[i]->getMauNen()!=color))
            {
                cout << "Khong tuong dong";
                break;
            }
            }
        }else{
        if(color == 1)
        {

            for(int i=0;i<=n;i++)
            {
                if(i==n)
                {
                    cout << "Tuong dong";
                    break;
                }
            if((a[i]->getMauNen()!=12)&&(a[i]->getMauNen()!=1)&&(a[i]->getMauNen()!=2))
            {
                cout << "Khong tuong dong";
                break;
            }
            }
        }else
        {
            for(int i=0;i<=n;i++)
            {
                if(i==n)
                {
                    cout << "Tuong dong";
                    break;
                }
            if((a[i]->getMauNen()!=12)&&(a[i]->getMauNen()!=11)&&(a[i]->getMauNen()!=1))
            {
                cout << "Khong tuong dong";
                break;
            }
            }
        }}

}
