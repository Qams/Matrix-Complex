#include <iostream>
#include <cstdlib>
#include "matrix.h"
#include <string.h>
#include <string>
#include <sstream>
#include <iomanip>

// metody klasy Complex
double Complex::getx()
{
    return x;
}

double Complex::gety()
{
    return y;
}

Complex::Complex()
{
    x=1;
    y=1;
}

Complex::Complex(double x1, double y1)
{
    x=x1;
    y=y1;
}

Complex Complex::add(Complex a)
{
    Complex res;
    res.x=a.getx()+this->x;
    res.y=a.gety()+this->y;
    return res;

}

Complex Complex::sub(Complex a)
{
    Complex res;
    res.x=this->x-a.getx();
    res.y=this->y-a.gety();
    return res;
}

Complex Complex::mul(Complex a)
{
    Complex res;
    res.x=(this->x*a.getx())-(this->y*a.gety());
    res.y=(this->x*a.gety())+this->y*a.getx();
    return res;

}

Complex Complex::div(Complex a)
{
    Complex res;
    Complex mian;
    Complex licz;
    mian.x=a.x;
    mian.y=-a.y;
    a=a.mul(mian);
    licz=this->mul(mian);
    res.x=licz.x/(a.x+a.y);
    res.y=licz.y/((mian.x*mian.x)+(mian.y*mian.y));
    return res;

}

Complex Complex::pow(int a)
{
    Complex res;
    Complex res1;
    res.x=this->x;
    res.y=this->y;
    res1.x=this->x;
    res1.y=this->y;
    if (a==0)
    {
        res.x=1;
        res.y=1;
    }
    else{
    for(int i=0;i<a-1;i++)
    {
        res=res.mul(res1);
    }
    }
    return res;

}

Complex::~Complex()
{
    ;
}
void print(Complex a)
{
    if(a.y!=0)
    cout << a.x << "i" << a.y << endl;
    else
        cout << a.x << endl;
}
// *********************************************
//metody klasy Matrix

Matrix::Matrix()
{
    a=2;
    b=2;
    tab=new Complex*[2];
    for(int i=0;i<2;i++)
    {
        tab[i]=new Complex[2];
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            tab[i][j].x=1;
            tab[i][j].y=0;
        }
    }
}

Matrix::Matrix(int x, int y)
{
    a=x;
    b=y;
    tab=new Complex*[x];
    for(int i=0;i<x;i++)
    {
        tab[i]=new Complex[y];
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            tab[i][j].x=0;
            tab[i][j].y=0;
        }
    }
}


void Matrix::wypisz()
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(tab[i][j].y!=0)
                cout << tab[i][j].x <<"i" << tab[i][j].y << " ";
            else
                cout << tab[i][j].x << " ";
        }
        cout << endl;
    }
}

Matrix::Matrix(Matrix &wzor)
{
    a=wzor.a;
    b=wzor.b;
    tab=new Complex*[a];
    for(int i=0;i<a;i++)
    {
        tab[i]=new Complex[b];
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            tab[i][j].x=wzor.tab[i][j].x;
            tab[i][j].y=wzor.tab[i][j].y;
        }
    }
}

Matrix::Matrix(string mac)
{
    int ile=0;
    int sred=1;
    stringstream ss;
    string tmp;
    ss << mac;
    while(ss >> tmp)
    {
        ile++;
        for(int i=0;i<tmp.length();i++)
        {
            if(tmp[i]==';')
            {
                sred++;
                break;
            }
        }
    }
    
    tab=new Complex*[sred];
    for(int i=0;i<sred;i++)
    {
        tab[i]=new Complex[ile/sred];
    }
    double *tymx=new double[ile];
    double *tymy=new double[ile];
    a=sred;
    b=ile/sred;
    stringstream sups;
    sups << mac;
    int licznik=-1;
    while(sups >> tmp)
    {
        licznik++;
        string nowy;
        for(int i=0;i<tmp.length();i++)
        {
            if((tmp[i]!='[')&&(tmp[i]!=']')&&(tmp[i]!=';'))
            {
                nowy=nowy+tmp[i];
            }

        }
        //cout << nowy << endl;
        int pozi=0;
        for(int i=0;i<nowy.length();i++)
        {
            if(nowy[i]=='i') pozi=i;
        }
        string rz;
        for(int i=0;i<pozi;i++)
        {
            rz=rz+nowy[i];
        }
        if(pozi!=0){
        double x1=atof(rz.c_str());
        tymx[licznik]=x1;
        }
        else
        {
            double x1=atof(nowy.c_str());
            tymx[licznik]=x1;
        }
        string im;
        if(pozi!=0){
        for(int i=pozi+1;i<nowy.length();i++)
        {
            im=im+nowy[i];
        }
        double y1=atof(im.c_str());
        tymy[licznik]=y1;
        }
        else tymy[licznik]=0;


    }
    for(int i=0;i<sred;i++)
    {
        for(int j=0;j<(ile/sred);j++)
        {
            tab[i][j].x=tymx[i*(ile/sred)+j];
            tab[i][j].y=tymy[i*(ile/sred)+j];
        }
    }

}

void Matrix::sett(int x1, int y1, double re, double im)
{
    tab[x1][y1].x=re;
    tab[x1][y1].y=im;
}

Complex Matrix::get(int x1, int y1)
{
    Complex tym;
    tym.x=tab[x1][y1].x;
    tym.y=tab[x1][y1].y;
    return tym;
}

Matrix Matrix::add(Matrix mac1)
{
    if((a=mac1.a) && (b=mac1.b))
    {
        Matrix wyn(a,b);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                wyn.tab[i][j]=tab[i][j].add(mac1.tab[i][j]);
            }
        }
        return wyn;
    }
    else
    {
        cout << "BLEDNE WYMIARY MACIERZY" << endl;
        Matrix* blad=NULL;
        return *blad;
    }

}

Matrix Matrix::sub(Matrix mac1)
{
    if((a=mac1.a)&&(b=mac1.b))
    {
        Matrix wyn(a,b);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                wyn.tab[i][j]=tab[i][j].sub(mac1.tab[i][j]);
            }
        }
        return wyn;
    }
    else
    {
        cout << "BLEDNE WYMIARY MACIERZY" << endl;
        Matrix* blad=NULL;
        return *blad;
    }
}

Matrix Matrix::mul(Matrix mac1)
{
    if(b==mac1.a)
    {
        Matrix wyn(a,mac1.b);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<mac1.b;j++){
                wyn.tab[i][j].x=0;
                wyn.tab[i][j].y=0;
                for(int k=0;k<b;k++)
                {
                    wyn.tab[i][j]=wyn.tab[i][j].add(tab[i][k].mul(mac1.tab[k][j]));
                }
            }
        }
        return wyn;
    }
    else
    {
        cout << "BLEDNE WYMIARY MACIERZY" << endl;
        Matrix* blad=NULL;
        return *blad;
    }
}

Matrix Matrix::mul(Complex k)
{
    Matrix wyn(a,b);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            wyn.tab[i][j]=tab[i][j].mul(k);
        }
    }
    return wyn;
}

Matrix Matrix::div(Complex k)
{
    Matrix wyn(a,b);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            wyn.tab[i][j]=tab[i][j].div(k);
        }
    }
    return wyn;
}

Matrix Matrix::pow(int x)
{
    Matrix tmp(*this);
    Matrix tmp1(*this);
    for(int i=0;i<x-1;i++)
    {
        tmp=tmp.mul(tmp1);
    }
    return tmp;
}

Matrix Matrix::div(Matrix mac1)
{
    int wa = mac1.a;
    int wb = mac1.b;
    Matrix ma(mac1);
    if(wa==wb)
    {
        int n=wa;
        Complex temp;
        Matrix tym(wa,wb);
        Matrix wyn(wa,wb);

        for(int i=0;i<n;i++)
        {
            tym.tab[i][i].x=1;
            tym.tab[i][i].y=0;
        }

        for(int k=0;k<n;k++)
        {
            temp=ma.tab[k][k];
            for(int j=0;j<n;j++)
            {
                ma.tab[k][j]=ma.tab[k][j].div(temp);
                tym.tab[k][j]=tym.tab[k][j].div(temp);
            }

            for(int i=0;i<n;i++)
            {
                temp=ma.tab[i][k];
                for(int j=0;j<n;j++)
                {
                    if(i==k)
                        break;

                    ma.tab[i][j]=ma.tab[i][j].sub(ma.tab[k][j].mul(temp));
                    tym.tab[i][j]=tym.tab[i][j].sub(tym.tab[k][j].mul(temp));
                }
            }
        }
        // tym to macierz odwrotna
        wyn=(*this).mul(tym);
        return wyn;
    }

}

