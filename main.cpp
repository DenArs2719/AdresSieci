#include <iostream>
#include <string>

using namespace std;

string inBinary(int num); ///int to binary

void inDecimal(int num[] ,int s); ///binary to decimal

int* notMaska(int arr[] ,int s); ///not mask

string Broadcast(int arr[] ,int s); ///find broadcast

void print(int arr[],int s); /// print info

int main()
{
    const int size = 4;
    int adresIp[size];
    int mask[size];

    cout<<"Enter adress IP(like 172 16 177 77): "<<endl;

    for(int i=0;i<size;i++)
    {
        cin>>adresIp[i];
    }

    for(int i=0;i<size;i++)
    {
        if(i<size-1)
        {
          cout<<inBinary(adresIp[i])<<".";
        }
        else
        {
           cout<<inBinary(adresIp[i]);
        }
    }
    cout<<endl;

    cout<<"Enter mask IP (like 255 255 255 255): "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>mask[i];
    }

    for(int i=0;i<size;i++)
    {
        if(i<size-1)
        {
          cout<<inBinary(mask[i])<<".";
        }
        else
        {
           cout<<inBinary(mask[i]);
        }
    }
    cout<<endl;

    int adresSieci[size];


    cout<<endl;


    string rezult;
    for(int i=0;i<size;i++)
    {
        string num1 = inBinary(adresIp[i]);
        string num2 = inBinary(mask[i]);

        int counter = 8;

        for(int i=0;i<num1.length();i++)
        {

            if(num1[i] == '1' && num2[i] == '1')
            {
               rezult = rezult + "1";
            }
            else
            {
               rezult = rezult + "0";
            }
        }
        adresSieci[i] = stoi(rezult);
        rezult = "";

    }

    cout<<endl;

    cout<<"adres sieci is ";
    inDecimal(adresSieci,size);

    cout<<endl;
    cout<<"adres pierwszego hosta "<<endl;
    adresSieci[3]+=1;
    inDecimal(adresSieci,size);
    cout<<endl;


    return 0;
}

string inBinary(int num)
{
    int copy = 0;
    int a = 0;
    string str,rezult;
    int counter = 8;

    while(counter > 0)
    {
        copy = num;
        copy = copy/2;
        a = num%2;
        num = copy;
        str = str + to_string(a);
        counter--;
    }

    for(int i=str.length()-1;i>=0;i--)
    {
        rezult = rezult + str[i];
    }

    return rezult;
}

void inDecimal(int num[] ,int s)
{
    int a = 0;
    int b = 0;
    int rezult[s];
    int help_num[s];
    int wynik = 0;

    for(int i = 0;i<s;i++)
    {
        help_num[i] = num[i];
    }

    for(int i=0;i<s;i++)
    {
        while(help_num[i] != 0)
        {
            a = help_num[i]%10;
            help_num[i] = help_num[i]/10;
            if(b == 0)
            {
                b = 1;
            }
            if(b != 0)
            {
                a = a *b;
            }
            wynik = wynik + a;
            b = b * 2;
        }
        rezult[i] = wynik;
        wynik = 0;
        a = 0;
        b = 0;
    }

    for(int i=0;i<s;i++)
    {
        if(i<s-1)
        {
            cout<<rezult[i]<<".";
        }
        else
        {
            cout<<rezult[i];
        }
    }


}

int*  notMaska(int arr[] ,int s)
{
    int* help_arr = new int [s];
    int not_arr[s];
    string rezult;

    for(int i=0;i<s;i++)
    {
        help_arr[i] = arr[i];
        not_arr[i] = arr[i];
    }

    for(int i=0;i<s;i++)
    {
       string num = inBinary(arr[i]);

       for(int i=0;i<num.length();i++)
       {
           if(num[i] == '0')
           {
               rezult = rezult + "1";
           }
           else
           {
               rezult = rezult + "0";
           }
       }
       help_arr[i] = stoi(rezult);
       rezult = " ";
    }

    return help_arr;

}



