/******************************************************************************
https://www.onlinegdb.com/online_c++_compiler#editor_1
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
class Boatingcompany{
    public:
    char deal_nodeal;
    char engine,buy_Rent;
    int noofB1=4,noofB2_L=2,noofB2_M=2,noofB2_H=2,noofB3=2;
    void rent(int n){
    cout<<"Rented for 1 day"<<endl;
    cout<<"Total price $"<<n<<endl;
    cout<<"$"<<n<<" to be paid"<<endl;
                    }
    void buy(int n){
    cout<<"Buying price $"<<n<<endl;
    cout<<"$"<<n<<" to be paid"<<endl;
      }
     bool d_nd(){
    cout<<"Was deal done? (d/nd)"<<endl;
        cin>>deal_nodeal;
        if(deal_nodeal=='d')
        return true;
        else
        return false;
     }
    void customerdetails(string boat,string b_R){
        string name,address;
        string phoneno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phoneno: ";
        cin >> phoneno;
       string data="Name : "+name+"\nPhone no : "+phoneno+"\nAddress : "+address+"\nBoat name(B1/B2/B3) : "+boat
       +"\nBought or rent (B/R) : "+b_R+"\n------------------------------------------------------------------------";
       // Creation of fstream class object
    fstream fio;
     // by default openmode = ios::in|ios::out mode
    // Automatically overwrites the content of file, To append
    // the content, open in ios:app
    // fio.open("sample.txt", ios::in|ios::out|ios::app)
    // ios::trunc mode delete all content before open
    fio.open("customer details.txt", ios::app | ios::out );
 
    
        // Write line in file
        fio << data << endl;
    
    // Close the file
    fio.close();
  }
};
class B1:virtual public Boatingcompany{
    public:
    
    void B1module(){
     
     if(noofB1!=0){
         cout<<"Okay for B1,we have boat available "<<endl;
           cout<<"Need for buying/Renting (B/R) "<<endl;
           cin>>buy_Rent;
      
            if(buy_Rent=='R')
                 {rent(1000);
                     if(d_nd())
                      {noofB1-=1;
                        customerdetails("B1","R");
                      }
                      
                    }
             else
                  {buy(20000);
                       if(d_nd())
                        {noofB1-=1;
                          customerdetails("B1","B");
                        }
                        
                   }
     }
     else {cout<<"Sorry, given boat is not available."<<endl;}
  }
};
class B2:virtual public Boatingcompany{
    public:
    void B2module(){
    cout<<"Okay for B2, we have boats available in different type of engines"<<endl<<" Low   Medium   High"<<endl<<" 50Hp   100HP   200HP"<<endl;
       cout<<"which boat do you want to drive (L/M/H) "<<endl;
       cin>>engine;
       if(engine=='L')
       {
           if(noofB2_L!=0)
            {
                 cout<<"Need for buying/Renting (B/R) "<<endl;
                 cin>>buy_Rent;
                 if(buy_Rent=='R')
                  {
                    rent(2000);
                     if(d_nd())
                     {noofB2_L-=1;
                       customerdetails("B2_L","L");
                     }
                      
                  }
                 else
                 {
                    buy(30000);
                    if(d_nd())
                      {noofB2_L-=1;
                        customerdetails("B2_L","B");
                      }
                      
                  }  
            }
           else {cout<<"Sorry, given boat is not available."<<endl;}
       }
       if(engine=='M')
       {   
           if(noofB2_M!=0)
           {
                cout<<"Need for buying/Renting (B/R) "<<endl;
                cin>>buy_Rent;
                if(buy_Rent=='R')
                {
                     rent(2500);
                     if(d_nd())
                     {noofB2_M-=1;
                      customerdetails("B2_M","R");
                     }
                     
                }
                else
               {     buy(35000);
                     if(d_nd())
                     {noofB2_M-=1;
                      customerdetails("B2_M","B");
                     }
                      
               }
           }
           else {cout<<"Sorry, given boat is not available."<<endl;}
       }
       if(engine=='H')
       {     
           if(noofB2_H!=0)
           {
                   cout<<"Need for buying/Renting (B/R) "<<endl;
                   cin>>buy_Rent;
                   if(buy_Rent=='R')
                       { rent(3000);
                        if(d_nd())
                        {noofB2_H-=1;
                          customerdetails("B2_H","R");
                        }
                          
                       }    
                   else
                        {
                        buy(40000);
                        if(d_nd())
                         {noofB2_H-=1;
                          customerdetails("B2_H","B");
                         }
                        }   
           }
           else {cout<<"Sorry, given boat is not available."<<endl;}
      }
        
    }
};
class B3:virtual public Boatingcompany{
    public:
    void B3module(){
    cout<<"Great boat choice sir, fully equipped with all kinds of leisure. Pub,kitchen,bedroom,fully air conditioned,proper ventilationEconomic class facilities with boat captain,chefs,servants at your service every moment"<<endl;
      if(noofB3!=0)
      {     cout<<"Need for buying/Renting (B/R) "<<endl;
           cin>>buy_Rent;
           if(buy_Rent=='R')
           {
                 rent(50000);
                 if(d_nd())
                  {noofB3-=1;
                   customerdetails("B3","R");
                  }
                  
           }
          else
          {
                 buy(900000);
                 if(d_nd())
                  {noofB3-=1;
                    customerdetails("B3","B");
                  }
                   
          }
          
      }
      else {cout<<"Sorry, given boat is not available."<<endl;}
    }
};
class stats:public B1,public B2,public B3{
    public:
    void display(){
        cout<<"-----------------------Company stats-----------------------"<<endl;
    cout<<"No of smallboats(Available) :"<<noofB1<<"\nNo of motorboats(Available) : \n  Low : "
       <<noofB2_L<<"\n  Medium : "<<noofB2_M<<"\n  High : "<<noofB2_H<<" \nNo of luxuriousboats(Available) : "<<noofB3<<endl;
         cout<<"-----------------------------------------------------------"<<endl;
    }
};

int main()
{    
  stats lovely;
   char y_n;
   
   string Boat;
   cout<<"if you want to continue (y/n) "<<endl;
   cin>>y_n;
   if(y_n=='n')
   exit(0);
   cout<<endl<<endl<<endl<<endl;
   cout<<"Welcome to 'Lovely boating company' "<<endl ;
    cout<<"Kindly look into our portfolio to start with";
   fstream fout;
    
    fout.open("portfolio.txt",ios::in);
    if(!fout){
        cout<<"no such file";
    }
    else 
   { string c;
     while(!fout.eof())
     {c=fout.get();
     cout<<c;}
   }
   fout.close();
    cout<<endl;
   lovely.display();
   do{
       cout<<"which boat customer need "<<endl;
        cin>>Boat;
        if(Boat=="B1"){
         lovely.B1module();
        }
       if(Boat=="B2"){
       lovely.B2module();
        }
       if(Boat=="B3"){
      lovely.B3module(); 
        }
      lovely.display();
      cout<<"if you want to continue (y/n) "<<endl;
      cin.ignore();
     
      cin>>y_n;
   
   }
   while(y_n=='y');

    return 0;
}


