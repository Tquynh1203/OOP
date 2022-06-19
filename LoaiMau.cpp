#include<iostream>
#include<string.h>
using namespace std;

class Mau
{
protected:
    int Rb;
    string ten;
public:
    Mau(){};
    ~Mau(){};
    void Nhap()
    {
        cout << "Ten: ";
        cin >> ten;
        cout << "Nhap vao Rb: 1.+, 0.-";
        cout << endl;
        cin >> Rb;

    }
    string getTen()
    {
        return ten;
    }
    int getRb()
    {
        return Rb;
    }
    virtual bool KiemTra(Mau&,Mau&)=0;
    virtual bool KiemTraRb(Mau&)=0;
    virtual char getLoaimau()=0;
};
class A:public Mau
{
protected:
    char loaimau;
public:
    A()
    {
        loaimau='A';
    }
    char getLoaimau()
    {
        return loaimau;
    }
    bool KiemTra(Mau &me,Mau&con)
    {

        if(me.getLoaimau()=='A')
           {
            if((con.getLoaimau()=='A')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
           }
        if(me.getLoaimau()=='B')
        {
            return true;
        }
        if(me.getLoaimau()=='AB')
        {
            if(con.getLoaimau()=='O')
            {
                return false;
            }else return true;
        }
        if(me.getLoaimau()=='O')
        {
            if((con.getLoaimau()=='A')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
        }
    }
    bool KiemTraRb(Mau &m)
    {
        if(Rb==0)
        {
            if(m.getRb()==1)
            {
                return false;
            }else
            {
                if((m.getLoaimau()!='O')||(m.getLoaimau()!='A'))
                {
                    return false;
                }else return true;
            }
        }else
        {
            if((m.getLoaimau()!='O')||(m.getLoaimau()!='A'))
                {
                    return false;
                }else return true;
        }
    }
};
class B:public Mau
{
protected:
    char loaimau;
public:
    B()
    {
        loaimau='B';
    }
    char getLoaimau()
    {
        return loaimau;
    }
    bool KiemTra(Mau &me,Mau&con)
    {

        if(me.getLoaimau()=='A')
           {
            return true;
           }
        if(me.getLoaimau()=='B')
        {
           if((con.getLoaimau()=='B')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
        }
        if(me.getLoaimau()=='AB')
        {
            if(con.getLoaimau()=='O')
            {
                return false;
            }else return true;
        }
        if(me.getLoaimau()=='O')
        {
            if((con.getLoaimau()=='B')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
        }
    }
    bool KiemTraRb(Mau &m)
    {
        if(Rb==0)
        {
            if(m.getRb()==1)
            {
                return false;
            }else
            {
                if((m.getLoaimau()!='O')||(m.getLoaimau()!='B'))
                {
                    return false;
                }else return true;
            }
        }else
        {
            if((m.getLoaimau()!='O')||(m.getLoaimau()!='B'))
                {
                    return false;
                }else return true;
        }
    }
};
class AB:public Mau
{
protected:
    char loaimau;
public:
    AB()
    {
        loaimau='AB';
    }
    char getLoaimau()
    {
        return loaimau;
    }
    bool KiemTra(Mau &me,Mau&con)
    {

        if(me.getLoaimau()=='A')
           {
            if(con.getLoaimau()=='O')
            {
                return false;
            }else return true;
           }
        if(me.getLoaimau()=='B')
        {
           if(con.getLoaimau()=='O')
            {
                return false;
            }else return true;
        }
        if(me.getLoaimau()=='AB')
        {
            if(con.getLoaimau()=='O')
            {
                return false;
            }else return true;
        }
        if(me.getLoaimau()=='O')
        {
            if((con.getLoaimau()=='A')||(con.getLoaimau()=='B'))
            {return true;}
            else return false;
        }
    }
    bool KiemTraRb(Mau &m)
    {
        if(Rb==0)
        {
            if(m.getRb()==1)
            {
                return false;
            }else
            {
                 return true;
            }
        }else return true;
    }
};
class O:public Mau
{
protected:
    char loaimau;
public:
    O()
    {
        loaimau='O';
    }
    char getLoaimau()
    {
        return loaimau;
    }
    bool KiemTra(Mau &me, Mau &con)
    {

        if(me.getLoaimau()=='A')
           {
            if((con.getLoaimau()=='A')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
           }
        if(me.getLoaimau()=='B')
        {
           if((con.getLoaimau()=='B')||(con.getLoaimau()=='O'))
            {return true;}
            else return false;
        }
        if(me.getLoaimau()=='AB')
        {
            if((con.getLoaimau()=='B')||(con.getLoaimau()=='A'))
            {return true;}
            else return false;
        if(me.getLoaimau()=='O')
        {
            if(con.getLoaimau()=='O')
            {return true;}
            else return false;
        }
    }}
    bool KiemTraRb(Mau &m)
    {
        if(Rb==0)
        {
            if(m.getRb()==1)
            {
                return false;
            }else
            {
                 if(m.getLoaimau()!='O')
                 {
                     return false;
                 } else return true;}}
            else {if(m.getLoaimau()!='O')
                 {
                     return false;
                 } else return true;
            }
    }
};
int main()
{
    Mau* a[100];
    int n;
    cout << "Nhap so nguoi trong danh sach: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "Chon: 1. mau A, 2. mau B, 3. mau AB, 4. mau O"<<endl;
        cout << "Chon: ";
        int t;
        cin >> t;
        switch(t)
        {
        case 1:
            {
                a[i]=new A();
            }
        case 2:
            {
                a[i]=new B();
            }
        case 3:
            {
                a[i]=new AB();
            }
        case 4:
            {
                a[i]=new O();
            }

        }
        a[i]->Nhap();
    }
    cout << "Kiem tra tuong thich nguoi 1 2 3 "<<endl;
    if(a[0]->KiemTra(*a[1], *a[2]))
    {
        cout << "Tuong thich"<<endl;
    }else cout << "Khong tuong thich"<<endl;
    cout << "Chon nguoi muon tim nhom mau theo quy luat"<<endl;
    int t;
    cin >> t;
    for(int i=0;i<n;i++)
    {
        if(a[t]->KiemTraRb(*a[i]))
        {
            cout << a[i]-> getTen()<<endl;
        }
    }
}

