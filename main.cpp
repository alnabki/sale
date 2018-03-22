#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<stdlib.h>
#include <iomanip>
#include <sstream>
#include<string>
#include<list>
using namespace std;
class account {
  public:
  string id;
  string  username;
  string  password;
  string customer_ID;
  bool login;

};
class customer {
public :
   string ID ;
   string name;
   string age;
   string phone;
void add(customer){

      cout<<"enter the age"<<endl;
       cin>>age;
       cout<<"enter the phone"<<endl;
       cin>>phone;
            }
 void show(customer ){
    cout <<" ___________________________________________________________________________________"<<endl;
    cout <<"|                             Your detils                                           |"<<endl;
    cout <<"|___________________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(20)<<"customer_ID"<<setw(20)<<"name"<<setw(20)<<"age"<<setw(20)<<"phone"<<"   |"<<endl;
    cout <<"|"<<setw(20)<<ID<<setw(20)<<name<<setw(20)<<age<<setw(20)<<phone<<"   |"<<endl;
    cout <<"|___________________________________________________________________________________|"<<endl;
}
};
class product {
public:
string ID;
string product_name;
string price;
string quantity;
void show(product ){
    cout <<" __________________________________________________________________________________"<<endl;
    cout <<"|                              _Product's details                                  |"<<endl;
    cout <<"|__________________________________________________________________________________|"<<endl;
    cout <<"|"<<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"price"<<setw(20)<<"quantity"<<"  |"<<endl;
    cout <<setw(20)<<ID<<setw(20)<<product_name<<setw(20)<<price<<setw(20)<<quantity<<"   |"<<endl;
    cout <<"|__________________________________________________________________________________|"<<endl;
}
};
class order_t {
  public:
string ID;
string cust_ID;
string prod_ID;
string price;
string customer_name;
string product_name;
};
class DB_connection{
protected:
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        int qstate ;
public:
 DB_connection(){

       conn = mysql_init(0);

         if(conn)
         {
             cout<<"connection object ok, conn="<<conn<<endl;
         }
         else
         {
              cout<<"conn object problem: "<<mysql_error(conn);
         }
         conn = mysql_real_connect(conn,"localhost","root","","sale_products",0,NULL,0);
         if(conn)
         {
             cout<<"connected to database sale_products"<<endl;
         }
         else
         {
            cout<<"connection problem: "<<mysql_error(conn)<<endl;
         }
}
product prod_select(string id){

    product pro;
       string query = "select * from  products where ID=" + id;
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              pro.ID = row[0];
               pro.product_name = row[1];
               pro.price = row[2];
                pro.quantity = row[3];
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return pro;
}
customer cust_select(string id){


customer cust;
       string query = "select * from  customer where ID=" + id;
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate){
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              cust.ID = row[0];
               cust.name = row[1];
               cust.age = row[2];
                cust.phone = row[3];
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return cust;
}
customer cust_selectbyname(string name){

    customer cust;

       string query = "select * from  customer where name ='"+name+"'";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              cust.ID = row[0];
               cust.name = row[1];
               cust.age = row[2];
                cust.phone = row[3];
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return cust;
}
account account_select(string name){
account acc;
       string query = "select * from  account where username='"+name+"'";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              acc.id = row[0];
               acc.username = row[1];
               acc.password = row[2];
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return acc;
}
account account_search (string password){
account acc;
       string query = "select * from  account where password='"+password+"'";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              acc.id=row[0];
              acc.username = row[1];
               acc.password = row[2];
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return acc;
}
void account_insert(account acc){
    string query = "INSERT INTO `account`( username, password,cust_id) VALUES ('"+acc.username+"','"+acc.password+"','"+acc.customer_ID+"')";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
    if(!qstate)
            cout<<"record inserted successfully..."<<endl;
    else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

}
void prod_insert(product pro ){

    string query = "INSERT INTO `products`( `product_name`, `price`, `quantity`) VALUES ('"+pro.product_name+"','"+pro.price+"','"+pro.quantity+"')";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
    if(!qstate)
            cout<<"record inserted successfully..."<<endl;
    else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

}
void cust_insert(customer cust ){

    string query = "INSERT INTO `customer`( `name`, `age`, `phone`) VALUES ('"+cust.name+"','"+cust.age+"','"+cust.phone+"')";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
    if(!qstate)
            cout<<"record inserted successfully..."<<endl;
    else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

}
void ord_insert(order_t ord){

    string query = "INSERT INTO `order_t`( `cust_ID`, `prod_ID`) VALUES ('"+ord.cust_ID+"','"+ord.prod_ID+"')";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
    if(!qstate)
            cout<<"record inserted successfully..."<<endl;
    else
            cout<<"query problem: "<<mysql_error(conn)<<endl;

}
void prod_update(product pro){
                string q3 = "update  products set product_name='"+pro.product_name+"',price="+pro.price+",quantity="+pro.quantity+" where ID ="+pro.ID;
                const char* q4 = q3.c_str();
                qstate = mysql_query(conn,q4);
                if(!qstate)
                        cout<<"record updated successfully..."<<endl;
                else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;
     }
void prod_delete(string id){

     string q3 = "DELETE FROM `products`  where ID="+id;
                const char* q4 = q3.c_str();
                cout <<q4<<endl;

                qstate = mysql_query(conn,q4);

                if(!qstate)
                        cout<<"record deleted successfully..."<<endl;
                else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;
}
list<product> show_allproducts(){
    list <product> products;
       string query = "select * from  products" ;
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);

       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
              product pro;
              pro.ID = row[0];
              pro.product_name = row[1];
              pro.price = row[2];
              pro.quantity = row[3];
              products.push_back(pro);
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return products;
}
list<order_t> show_total_saleby_ID(string id){
     list<order_t> sales;
       string query =  "select products.ID,product_name,name ,price from order_t RIGHT join customer on order_t.cust_ID=customer.ID INNER join products on products.ID = order_t.prod_ID";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                 order_t ord;
                 ord.ID = row[0];
                 ord.product_name = row[1];
                 ord.customer_name = row[2];
                 ord.price=row[3];
                 if (id==ord.ID){
                   sales.push_back(ord);
                 }
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return sales;
}
list<order_t> total_sales(){
     list<order_t> sales;
       string query =  "select products.ID,product_name,name ,price from order_t inner join customer on order_t.cust_ID=customer.ID INNER join products on products.ID = order_t.prod_ID";
       const char* q = query.c_str();
       qstate = mysql_query(conn,q);
       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                 order_t ord;
                 ord.ID = row[0];
                 ord.product_name = row[1];
                 ord.customer_name = row[2];
                 ord.price=row[3];
                 sales.push_back(ord);
           }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }

        return sales;
}
list<order_t> view_customer_purchese(string name){

list<order_t> sales;
       string query = "select products.ID,product_name,name ,price from order_t RIGHT join customer on order_t.cust_ID=customer.ID INNER join products on products.ID = order_t.prod_ID";
 const char* q = query.c_str();
       qstate = mysql_query(conn,q);
       if(!qstate)
        {
           res = mysql_store_result(conn);
            while(row=mysql_fetch_row(res))
            {
                 order_t ord;
                 ord.ID = row[0];
                 ord.product_name = row[1];
                 ord.customer_name = row[2];
                 ord.price=row[3];
                 if (name==ord.customer_name){
                   sales.push_back(ord);
                 }
            }
        }
       else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
        return sales;
}
};
void admin_printmenu(){
    cout <<" ____________________________________________________________"<<endl;
    cout <<"|  1 - enter the  product and show all products at same time |"<<endl;
	cout <<"|  2 - delete product                                        |"<<endl;
	cout <<"|  3 - show total sale for each product by given id          |"<<endl;
	cout <<"|  4 - show total sale                                       |"<<endl;
	cout <<"|  5 - back                                                  |"<<endl;
	cout <<"|____________________________________________________________|"<<endl;
}
void buy_prod_menu_print(){
   cout <<"______________________________"<<endl;
   cout<<"|             Sale Menu        |"<<endl;
   cout<<"|______________________________|"<<endl;
   cout<<"|  1 - buy a product           |"<<endl;
   cout<<"|  2 - back                    |"<<endl;
   cout<<"|______________________________|"<<endl;
}
void cust_printmenu(){
    cout<<" ________________________________"<<endl;
    cout<<"|    1-enter your name           |"<<endl;
    cout<<"|    2-enter your age            |"<<endl;
    cout<<"|    3-enter your phone          |"<<endl;
    cout<<"|________________________________|"<<endl;

}
void printgeneralmenu(){
     cout<<" ___________________________ "<<endl;
     cout<<"|       general menu        |"<<endl;
     cout<<"|___________________________|"<<endl;
     cout<<"|  1-admin                  |"<<endl;
     cout<<"|  2-customer               |"<<endl;
     cout<<"|___________________________|"<<endl;

}
void print_status_product_menu(){
    cout<<" _____________________________________________________________________________"<<endl;
    cout<<"|   1 - show products and next menu                                           |"<<endl;
    cout<<"|   2 - show his bought products each with price and at the end total price   |"<<endl;
    cout<<"|   3 - back                                                                  |"<<endl;
    cout<<"|_____________________________________________________________________________|"<<endl;
}
string NumberToString ( int Number ){

     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }
void show_product_list(){
    DB_connection db;
cout <<" ________________________________________________________________________________"<<endl;
cout <<"|                               Product's details                                |"<<endl;
cout <<"|________________________________________________________________________________|"<<endl;
                          cout <<"|"<<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"price"<<setw(20)<<"quantity"<<"|"<<endl;
                          list<product> products;
                          products=db.show_allproducts();
                            for ( pro : products){
                             cout <<"|"<<setw(20)<<pro.ID<<setw(20)<<pro.product_name<<setw(20)<<pro.price<<setw(20)<<pro.quantity<<"|"<<endl;
                             }
cout <<"|________________________________________________________________________________|"<<endl;
}
void show_sale_byid(string id){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<" ________________________________________________________________________________"<<endl;
                  cout <<"|                               Product's details                                |"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|"<<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<<"|"<< endl;
                  list<order_t> sales;
                  sales=db.show_total_saleby_ID(id);
                  for ( ord : sales){
                  cout <<"|"<<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<"|"<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|the total sales of this items is =\t"<<setw(20)<<sum<<setw(22)<<"|"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
}
void show_sales(){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<" ________________________________________________________________________________"<<endl;
                  cout <<"|                               Product's details                                |"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|"<<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<<"|"<< endl;
                  list<order_t> sales;
                  sales = db.total_sales();
                  for ( ord : sales){
                  cout <<"|"<<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<"|"<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|   the total sales  is =\t "<<setw(20)<<sum<<setw(29)<<"|"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
}
void show_sale_byname(string name){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<" ________________________________________________________________________________"<<endl;
                  cout <<"|                               Product's details                                |"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|"<<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<<"|"<< endl;
                  list<order_t> sales;
                  sales= db.view_customer_purchese(name);
                  for ( ord : sales){
                  cout <<"|"<<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<"|"<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                  cout <<"|________________________________________________________________________________|"<<endl;
                  cout <<"|    all your purchases =\t"<<setw(20)<<sum<<setw(30)<<"|"<<endl;
                  cout <<"|________________________________________________________________________________|"<<endl;
}
account verification(string name){
    account acc;
    customer cust;
    string password;
    DB_connection db;
    acc.login=false;
    cout <<" ___________________________________________"<<endl;
    cout <<"|enter your name=\t";
    cin>>name;
    cout <<"|___________________________________________"<<endl;
    acc=db.account_select(name);
    if(!acc.id.empty()){
        cout <<"| password       =\t";
        cin>>password;
        cout <<"|_____________________________________"<<endl;
         acc = db.account_search(password);
          if (!acc.id.empty()){
             cust= db.cust_selectbyname(name);
             cust.show(cust);
              acc.customer_ID=cust.ID;
              acc.username=cust.name;
              acc.login=true;
          }
          else{
            cout <<" _____________________________________________"<<endl;
            cout <<"|our password not correct write password again|"<<endl;
            cout <<"|_____________________________________________|"<<endl;
                    acc.login=false;
                     cin.get();
                     cin.ignore();
          }
    }
    else {
            cout<<"|******************************************|"<<endl;
            cout<<"|you don't have an account in the DataBase | "<<endl;
            cout<<"|******************************************|"<<endl;
            cout<<"|add your account                          |"<<endl;
            cout<<"|__________________________________________|"<<endl;
            cout<<"|enter you name and password\t             "<<endl ;
            cout<<"| name=\t";
            cin>>cust.name;
            acc.username=cust.name;
            cout<<"|__________________________________________ "<<endl;
            cout<<"| password=\t ";
            cin>>acc.password;
            cout<<"|__________________________________________"<<endl;
            cout<<"| enter the age=\t";
            cin>>cust.age;
            cout<<"|__________________________________________"<<endl;
            cout<<"| enter the phone=\t";
            cin>>cust.phone;
            cout<<"|__________________________________________"<<endl;
            db.cust_insert(cust);
            cust=db.cust_selectbyname(cust.name);
            acc.customer_ID=cust.ID;
            db.account_insert(acc );
            cust.show(cust);
            acc.login=true;
    }
  return acc;
}
int main(){
    cout <<"-----------------------------------------------------------------"<<endl;
    cout <<"                      Hello in my company                        "<<endl;
    cout <<"-----------------------------------------------------------------"<<endl;
  string name;
  product pro;
  order_t ord;
  account acc;
  customer cust;
  DB_connection db;
  bool j = false;
  string id;
  int menu_choice, menu_choice_admin,menu_ch,t;
  string  postFix="-1";
  bool goback=false;
      do{
            printgeneralmenu();
            cout << "Enter a menu choice: ";
            cin >> menu_choice;

            switch(menu_choice){
              case 1:{// for admin:
                  admin_printmenu();
                  cout << "Enter a menu choice: ";
                  cin >> menu_choice_admin;
                  switch(menu_choice_admin){
                      case 1:{//add new product and show the all.
                          cout <<" insert the product "<<endl;
                          cout <<"enter the product's name=\t"<<endl;
                          cin >> pro.product_name;
                          cout <<"enter the product's price=\t"<<endl;
                          cin>> pro.price;
                          cout <<"enter the product's quantity=\t"<<endl;
                          cin>>pro.quantity;
                          db.prod_insert(pro);
                          show_product_list();
                          cin.get();
                          cin.ignore();

                      break;
                      }
                      case 2:{
                          cout <<"enter the id you need to delete it  "<<endl;
                          cin >>  id;
                          pro=db.prod_select( id);
                          pro.show(pro);
                          db.prod_delete(id);
                          cin.get();
                          cin.ignore();
                      break;
                      }
                      case 3:{//show total sale for each product by given id
                            show_product_list();
                            cout <<"enter id = "<<endl;
                            cin >>  id;
                             show_sale_byid(id);
                             cin.get();
                             cin.ignore();
                      break;
                      }
                      case 4:{// show total sale
                          show_sales();
                          cin.get();
                          cin.ignore();
                      break;
                      }
                      case 5:{
                           goto backtomenu;
                      break;
                      }
                      default:{
                          cout << "You have entered an invalid menu choice.\n"<<endl;
                      cout  << "Please try again.\n\n";
                      break;
                     }
                    }
           break;
            }
              case 2:{//  for customer
                string name;
                acc =verification(name);
                if (acc.login==true){
                    bool goback1=false;
                    do{
                         print_status_product_menu();
                         cout<<"enter your choice=";
                         cin >> menu_ch;
                           switch(menu_ch){
                             case 1: {// show products and next menu
                                       show_product_list();
                                       buy_prod_menu_print();
                                       cout<<"enter your choice=";
                                       cin >> menu_ch;
                                       switch(menu_ch){// buy a product
                                              case 1:{//buy a product when chose ask to enter product id if quantity more than 0 else show him message the product is sold
                                                      cout <<"enter the product ID that you need to pay it :"<<endl;
                                                      cin >>id;
                                                      pro=db.prod_select(id);
                                                      pro.show(pro);
                                                      int  ch=0;
                                                      string check = NumberToString ( ch );
                                                      if ( pro.quantity == check){
                                                         cout<< "the product is sold"<<endl;
                                                         }
                                                      else{
                                                         int value = atoi(pro.quantity.c_str());
                                                         --value;
                                                         string s = NumberToString ( value );
                                                         pro.quantity =s;
                                                         db.prod_update(pro);
                                                         ord.prod_ID= pro.ID;
                                                         ord.cust_ID=acc.customer_ID;
                                                         db.ord_insert(ord);
                                                         }
                                                break;
                                                }
                                              case 2:{//back
                                                  goback1=true;
                                                 break;
                                              }

                                              default:{
                                                     cout << "You have entered an invalid menu choice.\n"<<endl;
                                                     cout  << "Please try again.\n\n";
                                               break;
                                             }
                                            }
                                 break;
                                }
                             case 2:{//show his bought products each with price and at the end total price
                                show_sale_byname(acc.username);
                              break;
                              }
                             case 3:{//back
                                 goto backtomenu;
                             break;
                             }
                             default :{
                                       cout << "You have entered an invalid menu choice.\n"<<endl;
                                       cout  << "Please try again.\n\n";
                             break;
                             }
                             }
                    }while (goback1=true);
               }
              }
              default :{
                       cout << "You have entered an invalid menu choice.\n"<<endl;
                       cout  << "Please try again.\n\n";
               break;
              }
            }
            backtomenu : {
         goback=true;
         system("cls") ;
         }
       } while (goback=true);
      return 0;
      }


