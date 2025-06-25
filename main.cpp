#include <iostream>
#include <iomanip>

using namespace std;


void step(int arr[], int siz) //Вывод
{
    for (int i=0; i<siz; i++) cout<<arr[i];
}

double na(int num=10,int coun=1)
{
    double cur=1;
    for (int i=0; i<coun; i++) cur*=num;
    if (coun<0) coun*=-1;
    for (int i=0; i<coun; i++) cur/=num;
    return cur;

}

int main()
{
    double ina =0.0;
    int const eps = 1000;
    double up = 1.0, down = 0.0;

    int meter = 0, meter2 =0;
    int bin[eps], bin2[eps];

    std::cout<<std::setprecision(1000);

    cin>>ina;//Ввод

    if (ina>=up || ina<=down) //Проверка
    {
        cout<<"Введёное число "<< (double)ina <<" не подходит в данный диапазон от "<< down<<" до "<<up<<endl;
        return 1;
    }
    up=ina;
    //cout<<"Binary1\t"<<bin<<endl<<endl;

    for (int i = 0; i<eps ; i++)   //Счёт
    {
        cout<<ina<<endl;
        down = ina;
        if (ina==0.0) break;
        /*if (ina==0.0)
        {
            ina+=1.0;
            if (meter>eps) break;
        }*/

        //cout<<"Binary2\t"<<ina<<endl;

        ina*=2.0;
        if (ina >=1)
        {
            bin[meter] = 1;
            ina-=1.0;
        }
        else
            bin[meter] = 0;

        meter++;
        //cout<<"Binary3\t"<<ina<<endl<<endl;
    }
    //cout<<down<<na(10,4)<<meter;

    cout<<"\nКоличество проходов: "<<meter<<endl;
    cout<<"\nПрограммный ноль: ";
    ina=2*na(2,-meter);
    cout<<ina<<endl;

    std::cout<<std::setprecision(1);
    cout<<"\nЦикл for\nКоличество проходов: "<<meter<<endl;
    cout<<"Введёное число: "<<up<<endl;
    cout<<"Его двоичная запись: 0.";
    step(bin,meter); cout<<endl<<endl;
    /*
    ina = up;
    do {

        if (ina==0) break;

        //cout<<"Binary2\t"<<ina<<endl;

        ina*=2;
        if (ina >=1)
        {
            bin2[meter2] = 1;
            ina-=1;

        }
        else
            bin2[meter2] = 0;
        meter2++;
        //cout<<"Binary3\t"<<ina<<endl<<endl;

    } while (meter2<eps);

    cout<<"Цикл do while\nКоличество проходов: "<<meter2<<endl;
    cout<<"Введёное число: "<<up<<endl;
    cout<<"Его двоичная запись: 0.";
    step(bin2,meter2); cout<<endl;
    */



    return 0;
}
