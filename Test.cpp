#include <iostream>

using namespace std;

class NhanVien
{
private:
    string hoTen;
    string maNhanVien;
    string ngaySinh;
    int tongLuong;
public:
    NhanVien()
    {
        hoTen="";
        maNhanVien="";
        ngaySinh="";
        tongLuong=0;
    }
    NhanVien(string hoTen,string maNhanVien, string ngaySinh)
    {
        this->hoTen=hoTen;
        this->maNhanVien=maNhanVien;
        this->ngaySinh=ngaySinh;
    }
    void setHoTen(string hoTen)
    {
        this->hoTen=hoTen;
    }
    string getHoten()
    {
        return hoTen;
    }
    void setMaNhanVien(string maNhanVien)
    {
        this->maNhanVien=maNhanVien;
    }
    string getMaNhanVien()
    {
        return maNhanVien;
    }
    void setNgaySinh(string ngaySinh)
    {
        this->ngaySinh=ngaySinh;
    }
    string getNgaySinh()
    {
        return ngaySinh;
    }
    void setTongLuong(int tongLuong)
    {
        this->tongLuong=tongLuong;
    }
    int getTongLuong()
    {
        return tongLuong;
    }
    virtual int getId()=0;
    virtual void Luong()=0;
    virtual void display()=0;
    virtual void setLuongCoBan(int )=0;
};
class VanPhong:public NhanVien
{
private:
    int luongCoBan;
    int soNgayLam;
    int troCap;
    int id;
public:
    VanPhong():NhanVien()
    {
        luongCoBan=0;
        soNgayLam=0;
        troCap=0;
        id=1;
    }
    VanPhong(string hoTen,string maNhanVien, string ngaySinh, int luongCoBan, int soNgayLam, int troCap):NhanVien(hoTen, maNhanVien, ngaySinh)
    {
        this->luongCoBan=luongCoBan;
        this->soNgayLam=soNgayLam;
        this->troCap=troCap;
        id=1;
    }
    int getId()
    {
        return id;
    }
    void Luong()
    {
        setTongLuong(luongCoBan+soNgayLam*220000+troCap);
    }
     void setLuongCoBan(int luongCoBan)
    {
        this->luongCoBan=luongCoBan;
    }
    void display()
    {
        cout << "VanPhong: Ten: "<<getHoten()<<endl;
        cout << "VanPhong: Ma Nhan Vien: " <<getMaNhanVien()<<endl;
        cout << "VanPhong: Ngay Sinh: "<<getNgaySinh()<<endl;
        cout << "VanPhong: Tong Luong: "<<getTongLuong()<<endl;
    }
};
class SanXuat:public NhanVien
{
private:
    int luongCoBan;
    int soSanPham;
    int id;
public:
    SanXuat():NhanVien()
    {
        luongCoBan=0;
        soSanPham=0;
        id=2;
    }
    SanXuat(string hoTen,string maNhanVien, string ngaySinh, int luongCoBan, int soSanPham):NhanVien(hoTen, maNhanVien, ngaySinh)
    {
        this->luongCoBan=luongCoBan;
        this->soSanPham=soSanPham;
        id=2;
    }
    int getId()
    {
        return id;
    }
     void setLuongCoBan(int luongCoBan)
    {
        this->luongCoBan=luongCoBan;
    }
    void Luong()
    {
        setTongLuong(luongCoBan+soSanPham*175000);
    }
    void display()
    {
        cout << "SanXuat: Ten: "<<getHoten()<<endl;
        cout << "SanXuat: Ma Nhan Vien: " <<getMaNhanVien()<<endl;
        cout << "SanXuat: Ngay Sinh: "<<getNgaySinh()<<endl;
        cout << "SanXuat: Tong Luong: "<<getTongLuong()<<endl;
    }
};
class QuanLy:public NhanVien
{
private:
    int luongCoBan;
    double heSoChucVu;
    int thuong;
    int id;
public:
    QuanLy():NhanVien()
    {
        luongCoBan=0;
        heSoChucVu=0;
        thuong=0;
        id=3;
    }
    QuanLy(string hoTen,string maNhanVien, string ngaySinh, int luongCoBan, double heSoChucVu,int thuong ):NhanVien(hoTen, maNhanVien, ngaySinh)
    {
        this->luongCoBan=luongCoBan;
        this-> heSoChucVu= heSoChucVu;
        this-> thuong= thuong;
        id=3;
    }
    int getId()
    {
        return id;
    }
    void setLuongCoBan(int luongCoBan)
    {
        this->luongCoBan=luongCoBan;
    }
    void Luong()
    {
        setTongLuong(luongCoBan*heSoChucVu+thuong);
    }
    void display()
    {
        cout << "QuanLy: Ten: "<<getHoten()<<endl;
        cout << "QuanLy: Ma Nhan Vien: " <<getMaNhanVien()<<endl;
        cout << "QuanLy: Ngay Sinh: "<<getNgaySinh()<<endl;
        cout << "QuanLy: Tong Luong: "<<getTongLuong()<<endl;
    }
};
class CongTy
{
private:
    NhanVien* a[10];
    int n;
public:
    void Nhap()
    {
        n=5;
        a[0]= new SanXuat("Nguyen Van A","2324259","12/04/2003",300000,45);
        a[1]=new VanPhong("Nguyen Van B","2324258","3/04/2003", 300000, 27, 40000);
        a[2]=new VanPhong("Nguyen Van C","2324257","01/04/2003", 300000, 25, 40000);
        a[3]=new QuanLy("Nguyen Van D","2324256","02/04/2003",300000, 2.3, 30000);
        a[4]= new SanXuat("Nguyen Van E","2324255","15/04/2003",300000,60);
    }
    void Xuat()
    {
        for(int i=0; i<n;i++)
        {
            a[i]->display();
            cout << "----------------"<<endl;
        }

    }
    void KhoiTao()
    {
        n=6;
        a[5]=new QuanLy("Nguyen Van G","2324254","23/04/2003",300000, 2.5, 30000);
        Xuat();
    }
    void Luong()
    {
        for(int i=0; i<n;i++)
        {
            a[i]->Luong();

        }
        Xuat();
    }
    void TongLuong()
    {
        long long max=0;
        long long tb=0;
        for(int i=0; i<n;i++)
        {
            max+= a[i]->getTongLuong();
        }
        tb=max/n;
        cout << "Tong luong: "<< max<<endl;
        cout << "Trung binh luong: "<<tb<<endl;
    }
    void Tim()
    {
        string mnv="2324259";
        cout << "Nhan vien can tim la: "<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]->getMaNhanVien()==mnv)
            {
                a[i]->display();
            }
        }
    }
    void LuongCao()
    {
        NhanVien* max= a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]->getTongLuong()>max->getTongLuong())
            {
                max=a[i];
            }
        }
        cout << "Nhan vien luong cao nhat la: "<< max->getHoten()<<endl;
    }
    void LuongCoBan()
    {
        cout << "Cap nhat luong cho quan li: "<<endl;
        cout << endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]->getId()==3)
            {
                a[i]->setLuongCoBan(400000);
            }
        }
        Luong();
    }
    void Xoa()
    {
        int k=2;
        for(int i=k-1;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n=n-1;
        Xuat();
    }


};
int main()
{
    cout << "\tCau 1"<<endl;
    cout <<endl;
    CongTy congty;
    congty.Nhap();
    cout << "======================================================"<<endl;
    cout << "\tCau 2"<<endl;
    cout <<endl;
    congty.KhoiTao();
    cout << "======================================================"<<endl;
    cout << "\tCau 3"<<endl;
    cout <<endl;
    congty.Luong();
    cout << "======================================================"<<endl;
    cout << "\tCau 4"<<endl;
    cout <<endl;
    congty.Xuat();
    cout << "======================================================"<<endl;
    cout << "\tCau 5"<<endl;
    cout <<endl;
    congty.TongLuong();
    cout << "======================================================"<<endl;
    cout << "\tCau 6"<<endl;
    cout <<endl;
    congty.Tim();
    cout << "======================================================"<<endl;
    cout << "\tCau 7"<<endl;
    cout <<endl;
    congty.LuongCao();
    cout << "======================================================"<<endl;
    cout << "\tCau 8"<<endl;
    cout <<endl;
    congty.LuongCoBan();
    cout << "======================================================"<<endl;
    cout << "\tCau 9"<<endl;
    cout <<endl;
    congty.Xoa();
    cout << "======================================================"<<endl;
}
