#include<iostream>
using namespace std;

class NhanVien
{
private:
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    long long luongCoBan;
    long long tongLuong;
public:
    NhanVien()
    {
        maNhanVien = "";
        hoTen = "";
        ngaySinh = "";
        luongCoBan = 0;
        tongLuong = 0;
    }
    NhanVien(string maNhanVien, string hoTen, string ngaySinh, long long luongCoBan )
    {
        this -> maNhanVien = maNhanVien;
        this -> hoTen = hoTen;
        this -> ngaySinh = ngaySinh;
        this -> luongCoBan = luongCoBan;
        tongLuong = 0;
    }
    void setMaNhanVien(string maNhanVien)
    {
        this -> maNhanVien = maNhanVien;
    }
    string getMaNhanVien()
    {
        return maNhanVien;
    }
    void setHoTen(string hoTen)
    {
        this -> hoTen = hoTen;
    }
    string getHoTen()
    {
        return hoTen;
    }
    void setNgaySinh(string ngaySinh)
    {
        this -> ngaySinh = ngaySinh;
    }
    string getNgaySinh()
    {
        return ngaySinh;
    }
    void setLuongCoBan(long long luongCoBan)
    {
        this -> luongCoBan = luongCoBan;
    }
    long long getLuongCoBan()
    {
        return luongCoBan;
    }
    void setTongLuong(long long tongLuong)
    {
        this->tongLuong=tongLuong;
    }
    long long getTongLuong()
    {
        return tongLuong;
    }
    virtual void TongLuong() = 0;
    virtual void Xuat() = 0;
};
class VanPhong : public NhanVien
{
private:
    int soNgayLam;
    int troCap;
public:
    VanPhong() : NhanVien()
    {
        soNgayLam = 0;
        troCap = 0;
    }
    VanPhong(string maNhanVien, string hoTen, string ngaySinh, long long luongCoBan, int soNgayLam, int troCap) : NhanVien(maNhanVien, hoTen, ngaySinh, luongCoBan)
    {
        this -> soNgayLam = soNgayLam;
        this -> troCap = troCap;
    }
    void setSoNgayLam(int soNgayLam)
    {
        this -> soNgayLam = soNgayLam;
    }
    int getSoNGayLam()
    {
        return soNgayLam;
    }
    void setTroCap(int troCap)
    {
        this -> troCap = troCap;
    }
    int getTroCap()
    {
        return troCap;
    }
    void TongLuong()
    {
        setTongLuong ( getLuongCoBan() + soNgayLam * 220000 + troCap );
    }
    void Xuat()
    {
        cout << "Ma Nhan Vien: " << getMaNhanVien() ;
        cout << " - Ho Ten: " << getHoTen() ;
        cout << " - Ngay Sinh: " << getNgaySinh() ;
        cout << " - Tong Luong: " << getTongLuong();
        cout << " - Chuc vu: Nhan vien van phong " << endl;
    }
};
class SanXuat : public NhanVien
{
private:
    int soSanPham;
public:
    SanXuat() : NhanVien()
    {
        soSanPham = 0;
    }
    SanXuat(string maNhanVien, string hoTen, string ngaySinh, long long luongCoBan, int soSanPham) : NhanVien(maNhanVien, hoTen, ngaySinh, luongCoBan)
    {
        this -> soSanPham = soSanPham;
    }
    void setSoSanPham(int soSanPham)
    {
        this -> soSanPham = soSanPham;
    }
    int getSoSanPham()
    {
        return soSanPham;
    }
    void TongLuong()
    {
        setTongLuong( getLuongCoBan() + soSanPham * 175000);
    }
    void Xuat()
    {
        cout << "Ma Nhan Vien: " << getMaNhanVien() ;
        cout << " - Ho Ten: " << getHoTen() ;
        cout << " - Ngay Sinh: " << getNgaySinh() ;
        cout << " - Tong Luong: " << getTongLuong();
        cout << " - Chuc vu: Nhan vien san xuat " << endl;
    }
};
class QuanLy : public NhanVien
{
private:
    double heSoChucVu;
    int thuong;
public:
    QuanLy() : NhanVien()
    {
        heSoChucVu = 0;
        thuong=0;
    }
    QuanLy(string maNhanVien, string hoTen, string ngaySinh, long long luongCoBan, double heSoChucVu, int thuong) : NhanVien(maNhanVien, hoTen, ngaySinh, luongCoBan)
    {
        this -> heSoChucVu = heSoChucVu;
        this -> thuong = thuong;
    }
    void setHeSoChucVu(int heSoChucVu)
    {
        this -> heSoChucVu = heSoChucVu;
    }
    double getHeSoChucVu()
    {
        return heSoChucVu;
    }
    void setThuong(int thuong)
    {
        this -> thuong = thuong;
    }
    double getThuong()
    {
        return thuong;
    }
    void TongLuong()
    {
        setTongLuong( getLuongCoBan() * heSoChucVu + thuong);
    }
    void Xuat()
    {
        cout << "Ma Nhan Vien: " << getMaNhanVien() ;
        cout << " - Ho Ten: " << getHoTen() ;
        cout << " - Ngay Sinh: " << getNgaySinh() ;
        cout << " - Tong Luong: " << getTongLuong();
        cout << " - Chuc vu: Quan Ly " << endl;
    }
};
class CongTy
{
private:
    NhanVien* a[300];
    int n;
public:
    void Nhap()
    {
        a[0] = new SanXuat ( "21522539", "Nguyen Van A", "23/04/2003" , 230000 , 2000);
        a[1] = new QuanLy ( "21522538", "Nguyen Van B", "03/04/2003" , 230000 , 1.2, 300000);
        a[2] = new VanPhong ( "21522537", "Nguyen Van C", "05/06/2003", 230000, 23, 30000);
        a[3] = new QuanLy ( "21522536", "Nguyen Van D", "03/04/2003" , 230000 , 2.4, 300000);
        a[4] = new SanXuat ( "21522535", "Nguyen Van E", "04/04/2003" , 230000 , 5000);
        a[5] = new VanPhong ( "21522534", "Nguyen Van G", "25/04/2003" , 230000 , 25, 40000);
        n=6;
    }
    void Xuat()
    {
        for(int i=0; i<n;i++)
        {
            a[i]->Xuat();
        }
    }
    void Luong()
    {
        for(int i=0; i<n;i++)
        {
            a[i]->TongLuong();
        }
    }
    void KhoiTao()
    {
        a[6] = new SanXuat ( "21522533", "Nguyen Van H", "23/04/2003" , 230000 , 4000);
        n = n + 1;
    }
    void Tong()
    {
        long long tong=0;
        for( int i = 0; i < n ; i++)
        {
            tong+= a[i]->getTongLuong();
        }
        long long trungbinh=0;
        trungbinh=tong/n;
        cout << "Tong luong: " << tong << endl;
        cout << "Trung binh luong: " << trungbinh << endl;
    }
    void Tim()
    {
        string maNhanVien = "21522536";
        cout << "Nhan vien can tim co ma nhan vien " << maNhanVien << " la: " << endl;
        for(int i = 0; i < n ; i++)
        {
            if(a[i]->getMaNhanVien()==maNhanVien)
            {
                a[i]->Xuat();
            }
        }
    }
    void LuongCao()
    {
        NhanVien* max = a[0];
        for(int i = 0; i < n ; i++)
        {
            if(a[i]->getTongLuong() > max->getTongLuong() )
            {
                max = a[i];
            }
        }
        cout << "Nhan vien luong cao nhat la: " << max->getHoTen() << endl;
    }
};
int main()
{
    CongTy congty;
    congty.Nhap();
    congty.Luong();
    congty.KhoiTao();
    congty.Luong();
    congty.Xuat();
    cout << "-------------------------------------------" << endl;
    congty.LuongCao();
    cout << "-------------------------------------------" << endl;
    congty.Tim();
    cout << "-------------------------------------------" << endl;
    congty.Tong();
    cout << "-------------------------------------------" << endl;
}
