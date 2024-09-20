#include<iostream>
#include<cmath>

double f(double x);
double f1(double x);
double bisectionMethod(double a ,double b,double tolr);
double newton_raph(double a,double tolr);
double secantMethod(double a,double b,double tolr);

using namespace std;

int main()
{
    double a,b,tolr = 0.0001;
    cout<<"Please , enter interval [a,b] :\t";
    cin>>a>>b;

    cout<<"Root by :\t\n";
    cout<<"BISECTION METHOD :\t"<<bisectionMethod(a,b,tolr)<<endl;
    cout<<"NEWTON-RAPHSON METHOD :\t"<<newton_raph(b,tolr)<<endl;
    cout<<"SECANT METHOD :\t"<<secantMethod(a,b,tolr)<<endl;

    return 0;
}
double f(double x)
{
    return pow(x,3) - 4*x -9;
}
double f1(double x)
{
    return 3*pow(x,2) - 4;
}
double bisectionMethod(double a ,double b,double tolr)
{
    double c=0;
    if(f(a)*f(b) > 0) return c;

    else 
    {
        while(b-a >=tolr)
        {
            c =(a+b)/2;

            if(f(c) ==0) break;
            else if(f(c)*f(a) < 0 ) b=c;
            else a=c;
        }
        return c;
    }
}
double newton_raph(double a,double tolr)
{
    double c=0;
    while(f(a)/f1(a) > tolr)
    {
        c = a - f(a)/f1(a);
        a = c;
    }
    return c;
}
double secantMethod(double a,double b,double tolr)
{
    double c=0,d=0;
    if(f(a)*f(b) > 0 ) return c;
    else 
    {
        c=a;
        d=b;
        while(fabs((c-d)/c) > tolr)
        {
            c = b - f(b)*(b-a)/(f(b)-f(a));

            if(f(c)*f(a) == 0) break;
            else
            {
                a=b;
                b=c;
                d= b - f(b)*(b-a)/(f(b)-f(a));
            }
        }
        return c;
    }
}