#include <iostream>
#include<windows.h>
#include<mysql.h>
#include<stdlib.h>
#include <iomanip>
#include <sstream>
#include<string>
#include<list>
using namespace std;
class login {
  string  username;
  string  password;
  login (){
   cout <<"enter you name and password" <<endl;
   cout <<" name=\t"<<username<<endl;
   cout <<" password=\t "<<endl;
  }
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

    cout <<"*****************************Your detils*******************************************"<<endl;
    cout <<setw(20)<<"customer_ID"<<setw(20)<<"name"<<setw(20)<<"age"<<setw(20)<<"phone"<<endl;
    cout <<setw(20)<<ID<<setw(20)<<name<<setw(20)<<age<<setw(20)<<phone<<endl;
    cout <<"***********************************************************************************"<<endl;
}
};
class product {
public:
string ID;
string product_name;
string price;
string quantity;
void show(product ){

    cout <<"*******************************Product's details*******************************"<<endl;
    cout <<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"price"<<setw(20)<<"quantity"<<endl;
    cout <<setw(20)<<ID<<setw(20)<<product_name<<setw(20)<<price<<setw(20)<<quantity<<endl;
    cout <<"*****************************************************************************"<<endl;
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
                cout <<q4<<endl;

                qstate = mysql_query(conn,q4);

                if(!qstate)
                        cout<<"record inserted successfully..."<<endl;
                else
                        cout<<"query problem: "<<mysql_error(conn)<<endl;

     }
void prod_delete(string id){

     string q3 = "DELETE FROM `products`  where ID="+id;
                const char* q4 = q3.c_str();
                cout <<q4<<endl;

                qstate = mysql_query(conn,q4);

                if(!qstate)
                        cout<<"record inserted successfully..."<<endl;
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

    cout <<"1 - enter the  product and show all products at same time"<<endl;
	cout <<"2 - delete product"<<endl;
	cout <<"3 - show total sale for each product by given id"<<endl;
	cout <<"4 - show total sale"<<endl;
	cout <<"5 - back"<<endl;
}
void buy_prod_menu_print(){
   cout<<"**************Sale Menu****************"<<endl;
   cout<<"1 - buy a product "<<endl;
   cout<<"2 - back"<<endl;
   cout<<"***************************************"<<endl;
}
void cust_printmenu(){

    cout<<"1-enter your name"<<endl;
    cout<<"2-enter your age"<<endl;
    cout<<"3-enter your phone"<<endl;
}
void printgeneralmenu(){

     cout<<"************general menu*************"<<endl;
     cout<<"1-admin"<<endl;
     cout<<"2-customer"<<endl;
     cout<<"*************************************"<<endl;
}
void print_status_product_menu(){
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"1 - show products and next menu"<<endl;
    cout<<"2 - show his bought products each with price and at the end total price"<<endl;
    cout<<"3 - back"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
}
string NumberToString ( int Number ){

     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }
void show_product_list(){
    DB_connection db;
cout <<"*******************************Product's details*******************************"<<endl;
                          cout <<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"price"<<setw(20)<<"quantity"<<endl;
                          list<product> products;
                          products=db.show_allproducts();
                            for ( pro : products){
                             cout <<setw(20)<<pro.ID<<setw(20)<<pro.product_name<<setw(20)<<pro.price<<setw(20)<<pro.quantity<<endl;
                             }
}
void show_sale_byid(string id){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<"*******************************Product's details*******************************"<<endl;
                  cout <<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<< endl;
                  list<order_t> sales;
                  sales=db.show_total_saleby_ID(id);
                  for ( ord : sales){
                  cout <<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                 cout <<"*******************************************************************************"<<endl;
                 cout <<"the total sales of this items is =\t"<<sum<<endl;
                 cout <<"*******************************************************************************"<<endl;
}
void show_sales(){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<"*******************************Product's details*******************************"<<endl;
                  cout <<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<< endl;
                  list<order_t> sales;
                  sales = db.total_sales();
                  for ( ord : sales){
                  cout <<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                 cout <<"*******************************************************************************"<<endl;
                 cout <<"the total sales  is =\t"<<sum<<endl;
                 cout <<"*******************************************************************************"<<endl;
}
void show_sale_byname(string name){
    DB_connection db;
    order_t ord;
    int sum=0;
                  cout <<"*******************************Product's details*******************************"<<endl;
                  cout <<setw(20)<<"poduct_ID"<<setw(20)<<"product_name"<<setw(20)<<"customer_name"<<setw(20)<<"price"<< endl;
                  list<order_t> sales;
                  sales= db.view_customer_purchese(name);
                  for ( ord : sales){
                  cout <<setw(20)<<ord.ID<<setw(20)<<ord.product_name<<setw(20)<<ord.customer_name<<setw(20)<<ord.price<<endl;

                   sum = sum + atoi(ord.price.c_str());
                 }
                 cout <<"*******************************************************************************"<<endl;
                 cout <<"all your purchases =\t"<<sum<<endl;
                 cout <<"*******************************************************************************"<<endl;
}
bool verification(login){
}
int main(){

    product pro;
    order_t ord;
    DB_connection db;
    bool j = false;
    string idd,id;
   int menu_choice, menu_choice_admin,menu_ch,t;
    char y;
    customer cust;
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
                          cout <<"*******************************************************************************"<<endl;
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
                 cout<< "enter your name ";
                 cin>> name;
                 cust=db.cust_selectbyname(name);
                 if (!cust.ID.empty()){
                      goto efter_case1;
                 }
                 else{
                     cust.name=name;
                     cust.add(cust);
                     db.cust_insert(cust);
                     goto efter_case1;
                 }
                efter_case1:{
                        bool goback1=false;
                         cust.show(cust);
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
                                                         ord.cust_ID=cust.ID;
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
                                show_sale_byname(name);
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


