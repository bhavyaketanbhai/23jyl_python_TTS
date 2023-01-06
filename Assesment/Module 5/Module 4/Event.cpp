#include<iostream>
#include<cmath>
using namespace std;
class event                                                                    
{
    public:
    string eventname,Firstname,Lastname;
    int min , guestnumber;
    int userinfo()                                                                
    {
        cout<<"********************Event Management System********************"<<endl;
        cout<<"Enter the name of event"<<endl;
        cin>>eventname;
        cout<<"Enter the customer's First name and Last name"<<endl;
        cin>>Firstname;
        cin>>Lastname;
        cout<<"Enter the number of guest"<<endl;
        cin>>guestnumber;
        cout<<endl<<"Enter the number of minutes in the event"<<endl;
        cin>>min;
        return 0;
    }
    
};
class estimate : public event                                      
{
    public:
    int x;
    float numofserver;
    double cost , cost1 , cost2 , ttlcostserver , TotalFoodCost , avgcost , Totalcost , percentage;
    const double CostPerHour = 18.50;
    const double CostPerMinute = 0.40;
    const double CostPerDinner = 20.70;

    int showdata()
    {
         numofserver = guestnumber / 20;                             
         cost1 = (min /60) * CostPerHour;
         cost2 = (min % 60) * CostPerMinute;
         cost = cost1 + cost2;                                 
         ttlcostserver = cost * ceil(numofserver);               

         TotalFoodCost = guestnumber * CostPerDinner;               

         avgcost = TotalFoodCost/guestnumber;                    

         Totalcost = ttlcostserver + TotalFoodCost ;

         percentage = Totalcost * 0.25;

         cout<<"====================*Event estimate for :"<<Firstname<<"\t"<<Lastname<<"*===================="<<endl;
         cout<<"Number of Servers : "<<ceil(numofserver)<<endl;
         cout<<"The cost for Servers : "<<ttlcostserver<<endl;
         cout<<"The Cost for Food is: "<<TotalFoodCost<<endl;
         cout<<"Average Cost Per Person: "<<avgcost<<endl<<endl;
         cout<<"Total cost is :"<<Totalcost<<endl;
         cout<<"Please deposit 25% deposit to reserve the event "<<endl;
         cout<<"The deposit needed is : "<<floor(percentage)<<endl;
         return 0;
    }
    int newcustomer()
    {
        do
        { 
            cout<<endl<<"Enter 1 For New Customer "<<endl;
            cout<<"Enter 0 for exit"<<endl;
            cin>>x;
            switch (x)
                {       
                    case 1 : 
                        {
                            userinfo();
                            showdata();
                            break;
                        }
                    case 0 :
                        {
                            break;
                        }
                    default :
                    cout<<"Invalid choice";
                }
        }while(x != 0);
    return 0;
    }
};

int main()
{
    int x;
    estimate obj1;
    obj1.userinfo();
    obj1.showdata();
    obj1.newcustomer();
   
    return 0;
}
