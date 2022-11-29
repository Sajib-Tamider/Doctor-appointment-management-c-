#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

    int total,aptotals,dk1;

    struct person{
        string name, password , address;
        int contact,serial_no;
    }p[100];
    struct apoint{
        string name, doctor_name;
        int hours, totals,mobile ;
    }ap[50];


class Patient{
private:
    string id;
    int contact_num;

public:
    Patient(){
        total = 0;
        aptotals = 0;

    }
    void choice();
    void signupData();
    void patientList();
    void updateData();
    void doctorList();
    void areaSpecialized();
    void bookAppointment();
    void bkAppointment();
    void existenAppointment();

    ~Patient(){

    }
};

class Doctor : public Patient{
private:
    int total;

public:
    struct doctor{
        string name, dept_name,address;
        int mobile;
    }dk[50];
    Doctor(){
        dk1 = 0;
    }

    void choice_d();
    void signup();
    void showdoc();
};

class Admin :public Patient{
private:
    int total;
public:
    Admin(){
        total = 0;
    }
    void choice_a();
    void eraseDocData();
    void erasePatData();
    struct admin{
        string name, address;
        int contact;
    };
};

bool Login(){
    cout<<"\n\n\t\t*************************************************"<<endl;
    cout<<"\n\t\tWelcome TAMIDER Nursing Room" <<endl;
    cout<<"\t\tIf you are new then at first sign up : "<<endl;
    cout<<"\n\n\t\t*************************************************"<<endl;

    string username, password;
    cout<<"\t\tEnter username       : ";
    cin>> username;
    cout<< "\t\tEnter password      : ";
    cin>> password;

    cout<< "\t\tYour account is creating please wait ..";
    for(int i=0; i<4; i++){
        cout<<".";
        Sleep(1000);
    }

    system("CLS");
    cout<< "\n\n\t\t================================================\n"<<endl;
    cout<< "\t\tYour account is created successfully : "<<endl;
    cout<< "\t\tAfter registration, You have to Log in : "<<endl;
    cout<< "\n\t\t================================================"<<endl;

    start:
    string user1, pass1;
    cout<<"\n\t\tEnter your user name           : ";
    cin>>user1;
    cout<<"\n\t\tEnter your password            : ";
    cin>>pass1;

    if(user1 == username && pass1 == password)
        return true;

    else
        cout << "\t\t You have entered wrong username or password"<<endl;
        goto start;
}


int main(){
    Doctor doc;
    Admin ad;
    Patient person;
    int n;
    bool ck = Login();
    if(ck==1){
        while(1){

            cout<< "\n\n\t\t================================================"<<endl;
            cout<<"\t\tLet me know who you are ??" <<endl;
            cout<<"\t\tPress [1] if you are a patient "<<endl;
            cout<<"\t\tPress [2] if you are a Doctor " <<endl;
            cout<<"\t\tPress [3] if you are Admin"<<endl;
            cout<<"\t\tPress [0] to Quit the program"<<endl;
            cout<< "\n\t\t================================================"<<endl;
            cin>>n;



            switch(n){
            case 1:
                person.choice();
                break;
            case 2:
                doc.choice_d();
                break;
            case 3:
               ad.choice_a();
               break;
            case 0:
                exit(1);

           }
        }
    }


    return 0;
}


/*All Patient type method are defined here*/
void Patient :: choice(){
    int n;
    while(1){
        //system("CLS");
        cout<<"\n\n\t\t*************************************************"<<endl;
        cout<<"\t\tPress [1] to complete your information: "<<endl;
        cout<<"\t\tPress [2] to View previous patient list : "<<endl;
        cout<<"\t\tPress [3] to update information : "<<endl;
        cout<<"\t\tPress [4] to see doctor list : "<<endl;
        cout<<"\t\tPress [5] to see specialized doctor in your area : "<<endl;
        cout<<"\t\tPress [6] to book appointment in any doctor :"<<endl;
        cout<<"\t\tPres  [0] to Go Back: \n"<<endl;
        cout<<"\n\n\t\t*************************************************"<<endl;

        cin>>n;

        if(n==0)
            break;

        system("CLS");
        switch(n){
        case 1:
            Patient :: signupData();
            break;
        case 2:
            Patient :: patientList();
            break;
        case 3:
            Patient :: updateData();
            break;
        case 4:
            Patient :: doctorList();
            break;
        case 5:
            Patient :: areaSpecialized();
            break;
        case 6:
            Patient :: bookAppointment();
            break;
        }


    }
}

void Patient :: signupData(){
    cout<< "\t\tEnter your full information here  "<<endl;
    cout<< "\t\tEnter user-name             : ";
    getchar();
    getline(cin, p[total].name);
    //cin>> p[total].name;
    cout<<"\t\tEnter Password               : ";
    cin >>p[total].password;
    getchar();
    cout<<"\t\tEnter your city              : ";
    getline(cin, p[total].address);
    //cin>>p[total].address;
    cout<<"\t\tEnter your contact number    : ";
    cin>>p[total].contact;
    cout << "\t\tYou have completed your data successfully "<<endl;
    total++;
}

void Patient :: patientList(){
    for(int i=0; i<total; i++){
        cout<< "\t\tOver all Patient List those are in serial : " <<endl;
        cout<< "\t\tData of patient                         : "<< i+1<<endl;
        cout<< "\t\tName                                    : "<<p[i].name<<endl;
        cout<< "\t\tCity                                    : "<<p[i].address<<endl;
        cout<< "\t\tFor Serial number your have to book appointment first"<<endl;
        break;
    }
}


void Patient :: updateData(){
    cout<< "\t\tEnter your contact number that you have registered : "<<endl;
    cin>>contact_num;
    for(int i=0; i<total; i++){
        if(contact_num == p[i].contact){
            /* Previous Data from here */

            cout<< "\t\tPrevious Data ..."<< endl;
            cout << "\t\tData of patient            : "<< i+1<<endl;
            cout<< "\t\tName                        : "<<p[i].name<<endl;
            cout<< "\t\tCity                        : "<<p[i].address<<endl;
            cout<< "\t\tSerial no                   : "<<i<<endl;

            /* Enter new data*/
            cout<< "\n\n\t\t Enter new data form here : "<<endl;
            cout<< "\t\tEnter user-name             : ";
            cin>> p[i].name;
            cout<<"\t\tEnter Password               : ";
            cin >>p[i].password;
            cout<<"\t\tEnter your city              : ";
            cin>>p[i].address;
            cout<<"\t\tEnter your contact number    : ";
            cin>>p[i].contact;

            break;
        }
        if(i == total-1){
            cout<< "\t\tNo such record found : "<<endl;
        }
    }
}

void Patient :: doctorList(){
    cout<< "\n\n\t\t================================================"<<endl;
    cout<< "\t\tAll the doctor in our program : "<<endl;
    cout<< "\t\tDr. Enayet Uddin"<<endl;
    cout<< "\t\tDr. Sajib"<<endl;
    cout<< "\t\tDr. Rajib Hossen"<<endl;
    cout<< "\t\tDr. Prokash Mahmud"<<endl;
    cout<< "\t\tDr. Monir Uddin"<<endl;
    cout<< "\t\tDr. Islam Uddin"<<endl;
    cout<< "\n\t\t================================================="<<endl;
}

void Patient :: areaSpecialized(){
    int n;
    cout<< "\n\n\t\t================================================"<<endl;
    cout<< "\t\tThere which doctor is specialized in specific disease "<< endl;
    cout<< "\t\tPress [1] for Cardiologists "<<endl;
    cout<< "\t\tPress [2] for Rectal Surgeons "<<endl;
    cout<< "\t\tPress [3] for Medicine Specialist "<<endl;
    cout<< "\t\tPress [4] for Dermatologists "<<endl;
    cout<< "\t\tPress [5] for Hematologists"<<endl;
    cout<< "\t\tPress [6] for Neurologists "<<endl;
    cout<< "\t\tPress [7] for Oncologists "<<endl;
    cout<< "\n\t\t================================================"<<endl;

    cin>>n;


    switch(n){
    case 1:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    case 2:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    case 3:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    case 4:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();

        break;
    case 5:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    case 6:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    case 7:
        cout<< "\n\n\t\t================================================"<<endl;
        cout<< "\t\tDr. Enayet Uddin"<<endl;
        cout<< "\t\tDr. Sajib"<<endl;
        cout<< "\t\tDr. Rajib Hossen"<<endl;
        cout<< "\t\tDr. Prokash Mahmud"<<endl;
        cout<< "\t\tDr. Monir Uddin"<<endl;
        cout<< "\t\tDr. Islam Uddin"<<endl;
        cout<< "\n\n\t\t================================================"<<endl;
        Patient :: bookAppointment();
        break;
    default:
        cout<<"\t\tInvalid Input : "<<endl;
    }

}

void Patient :: bookAppointment(){
    int n;
    cout<< "\n\n\t\t================================================"<<endl;
    cout<<"\t\tEnter your choice for Book Appointment : "<<endl;
    cout<<"\t\tPress [1] for Book appointment : "<<endl;
    cout<<"\t\tPress [2] to see the existential appointment : "<<endl;
    cout << "\t\tPress [0] to Go back "<<endl;
    cout << "\n \t\t ==============================================="<<endl;
    cin>>n;

    if (n==0){
        break;
    }

    switch(n){
    case 1:
        Patient :: bkAppointment();
        break;
    case 2:
        Patient :: existenAppointment();
        break;
    default:
        cout<< "Invalid Input";
    }
}

void Patient :: bkAppointment(){
    cout<< "\n\n\t\t================================================"<<endl;
    cout<< "\t\tEnter data for book appointment     : "<<endl;
    cout<< "\t\tWe have those doctor's in schedule"<<endl;


    Patient :: doctorList();

    cout<< "\t\tEnter your name                                     : ";
    getchar();
    getline(cin, ap[aptotals].name);
    //cin>>ap[aptotals].name;
    cout<< "\t\tEnter doctor name that was shown in display         : ";
    getline(cin, ap[aptotals].doctor_name);
    cout << "\t\tEnter your mobile number                           : ";
    cin >> ap[aptotals].mobile;
    cout<<"\n\n\t\tYour Appointment is confirmed "<<endl;
    cout <<"\t\tTo check your appoint Press [6] then Press [2] "<<endl;
    aptotals++;

}
void Patient :: existenAppointment(){
    int time ;
    for(int i=0; i<aptotals; i++){
        time = i;
        cout<< "\t\tName                    : "<<ap[i].name<<endl;
        cout<< "\t\tSerial number           : "<<i+1<<endl;
        cout<< "\t\tYour doctor name is     :"<<ap[i].doctor_name<<endl;
        if(i<6)
            cout<< "\t\tTime is                 :"<<time+7<<"PM"<<endl;
        else
            cout<< "\t\tTime is                 : "<< i+1 <<"AM"<<endl;

    }
}



/*All Doctor type method are defined here*/


void Doctor :: choice_d(){
    int n;
    while(1){
        cout<< "\n\n\t\t================================================"<<endl;
        cout<<"\t\tPress [1] to view the patient list"<<endl;
        cout<<"\t\tPress [2] SignUp as a doctor"<<endl;
        cout <<"\t\tPress [3] to show your confirmation data "<<endl;
        cout<<"\t\tPress [4] to Show area specialized doctor list" <<endl;
        cout<<"\t\tPress [0] to Go back "<<endl;
        cout<< "\n\t\t================================================"<<endl;
        cin>>n;

        if(n==0)
            break;
        system("CLS");

        switch(n){
        case 1:
            existenAppointment();
            break;
        case 2:
            Doctor :: signup();
            break;
        case 4:
            areaSpecialized();
            break;
        }
    }
}

ostream &operator << (ostream &output, Doctor &ob){
   for(int i=0; i<dk1; i++){
    output << "Your name                    : "<< ob.dk[i].name<<endl;
    output << "Your city                    : "<< ob.dk[i].address<<endl;
    output << "Your Department name         : "<< ob.dk[i].dept_name<<endl;
    output << "Your mobile                  : "<< ob.dk[i].mobile <<endl;
   }

   return output;
}

istream &operator >>(istream &input, Doctor &ob){
    cout<< "\t\tEnter your name             : ";
    input >> ob.dk[dk1].name;
    cout << "\t\tEnter your City             : ";
    input >> ob.dk[dk1].address;
    cout << "\t\tEnter your Department       : ";
    input >> ob.dk[dk1].dept_name;
    cout<< "\t\tEnter your Mobile number    : ";
    input >> ob.dk[dk1].mobile;
    dk1++;

    return input;
}

void Doctor :: signup(){
    Doctor ob1;
    cin >> ob1;
    cout << "\t\tPress [3] you want to show your data " << endl;
    int n;
    cin >> n;
    switch (n){
    case 3:
        cout << ob1;
        break;
    default :
         cout << "\t\tInvalid Input "<< endl;
    }


}


/*All Admin  type method are defined here*/

void Admin :: choice_a(){
    int n;
    while(1){
        cout<< "\n\n\t\t Press [1] to view Doctor list"<<endl;
        cout<< "\t\t Press [2] to erase specific Doctor Data" <<endl;
        cout<< "\t\t Press [3] to erase specific patient Data" <<endl;
        cout<< "\t\t Press [4] to erase all the data"<<endl;
        cout<< "\t\t Press [0] to Go back" <<endl;

        cin >> n;

        if(n==0){
            break;
        }

        system("CLS");
        switch(n){
        case 1:
            areaSpecialized();
            break;
        case 2:
            Admin :: eraseDocData();
            break;
        case 3:
            Admin :: erasePatData();
            break;
        }

    }
}

void Admin :: erasePatData(){
    int id,mob;
    cout << "\t\tPress [1] to remove specific patient record "<<endl;
    cout << "\t\tPress [2} to remove all Patient record : "<<endl;
    cout << "\t\tPress [0] to Go back" << endl;
    cin >> id ;

    if (id ==0){
        break;
    }
    switch (id){
    case 1:
        cout << "\t\tEnter the patient's mobile number" <<endl;
        cin >> mob;
        try{
        if(mob == 0)
            throw "String type error : ";
        for(int i=0; i<aptotals; i++){
            if(mob == ap[i].mobile){
                for(int j=i; j<aptotals; j++){
                    ap[j].name = ap[j+1].name;
                    ap[j].doctor_name = ap[j+1].doctor_name;
                    ap[j].mobile = ap[j+1].mobile;
                    aptotals--;
                    break;
                }
            }
            if(i == aptotals-1){
                cout << "\t\tNo such record found : "<<endl;
            }
        }
        }catch(const char *e){
            cout<< "exception occured"<<endl<<e;
        }
    break;
    case 2:
        aptotals = 0;
        cout<< "\t\tAll patient's record is deleting please wait ...";
        for(int i=0; i<4; i++){
            cout << ".";
            Sleep(1000);
        }
        cout << "\t\tAll Record has been deleted "<<endl;
        break;

    }

}

void Admin :: eraseDocData(){
    Doctor d;

    int mobi,n;
    cout << "\t\tPress [1] to remove specific data"<<endl;
    cout << "\t\tPress [2] to remove all doctor's data"<<endl;
    cout << "\t\tPress [0] to Go back"<<endl;

    cin >> n;

    if(n==2){
        break;
    }
    switch(n){
    case 1:
        cout<< "\t\tEnter the mobile number of the Doctor : "<<endl;
        cin >> mobi;
        for(int i=0; i<dk1; i++){
            if(mobi == d.dk[i].mobile){
                for(int j=0; j<dk1; i++){
                    d.dk[j].name = d.dk[j+1].name;
                    d.dk[j].dept_name = d.dk[j+1].dept_name;
                    d.dk[j].address = d.dk[j+1].address;
                    d.dk[j].mobile = d.dk[j+1].mobile;
                    dk1--;
                    break;
                }
            }
            if(i == dk1-1){
                cout<< "\t\tNo such record found : "<<endl;
            }
        }
        cout << "\t\t Data has been deleted successfully " <<endl;
        break;
    case 2:
        dk1 = 0;
        cout<< "\t\tAll record is deleting please wait ...";
        for(int i=0; i<4; i++){
            cout<<".";
            Sleep(1000);
        }
        cout<< "\t\tAll record has been deleted "<<endl;
        break;
    default:
        cout << "\t\tInvalid Input : "<<endl;

    }


}
