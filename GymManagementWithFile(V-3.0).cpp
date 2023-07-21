#include <bits/stdc++.h>
#include <fstream> 
#include <string>
#include <sstream>

using namespace std;

int i = 1001,delct = 1001;
int maxHeight,maxWeight,minHeight,minWeight,totalHeight,totalWeight;

struct member{
public:
    int id;
    int height;
    int weight;
    bool exist;
}mem[10000];

void menu(){
    cout << "   <-----Menu----->" << endl;
    cout << "1.Add Member\n";
    cout << "2.Update Member Info\n";
    cout << "3.Remove Member\n";
    cout << "4.Readd Member\n";
    cout << "5.All Member's Info\n";
    cout << "6.One Member's info\n";
    cout << "7.Max Height & Weight\n";
    cout << "8.Min Height and Weight\n";
    cout << "9.Average Height and Weight\n";
    cout << "10.BMI Classification\n";
    cout << "0.Exit\n";
    cout << "Enter Your option(1 - 10) : ";
}

void showInfoAll(){
    for(int j = 1001; j < i; j++){
        if(mem[j-1000].exist == false){
            cout << "Member " << j << " Is Not Available!" << endl;
            continue;
        }
        cout << mem[j-1000].id << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
    }
    cout << endl;
}

void showInfoAlone(int x){
    if(mem[x-1000].exist == false){
        cout << "Member " << x << " Is Not Available!" << endl;
        cout << "Do You Want to Know the Info for Security Purpose?\n";
        cout << "Press Y for Yes,Otherwise N for No.";
        getchar();
        char c = getchar();
        if(c == 'Y' || c == 'y'){
            cout << "\n\nInformation Table\n";
            cout << "-----------------\n";
            cout << "\n ID   H  W \n";
            cout << mem[x-1000].id << " " << mem[x-1000].height << " " << mem[x-1000].weight << endl;
        }
        else{
            cout << "Thank You!\n";
        }
    }
    else{
        cout << mem[x-1000].id << " " << mem[x-1000].height << " " << mem[x-1000].weight << endl;
    }
    cout << endl;
}

void maxmin(){
    maxHeight = -1,maxWeight = -1,minHeight = 1e3,minWeight = 1e3;
    for(int j = 1; j < i-1000; j++){ 
        if(mem[j].exist == true && mem[j].height > maxHeight){
            maxHeight = mem[j].height;
        }
        if(mem[j].exist == true && mem[j].weight > maxWeight){
            maxWeight = mem[j].weight;
        }
        if(mem[j].exist == true && mem[j].height < minHeight){
            minHeight = mem[j].height;
        }
        if(mem[j].exist == true && mem[j].weight < minWeight){
            minWeight = mem[j].weight;
        }
    }
}

void add(){
    int b,c;
    cout << "\nMember ID : " << i << endl;
    cout << "Enter Member Height(cm) : ";
    cin >> b;
    cout << "Enter Member Weight(kg) : ";
    cin >> c; 
    mem[i-1000].id = i;
    mem[i-1000].height = b;
    mem[i-1000].weight = c;
    mem[i-1000].exist = true;
    maxmin();
}

void update(int a){  
    cout << "\nWhich one you want to Update?\n";
    cout << "1.Height\n";
    cout << "2.Weight\n";
    cout << "Enter Your Choice : ";
    int q,b,c;
    cin >> q;
    if(q == 1){
        cout << "Enter Member Height(cm) : ";
        cin >> b;
        mem[a-1000].height = b;
    }
    else if(q == 2){
        cout << "Enter Member Weight(kg) : ";
        cin >> c;
        mem[a-1000].weight = c;
    }
    maxmin();
}

void avg(){
    totalHeight = 0,totalWeight = 0;
    for(int j = 1001; j < i; j++){
        if(mem[j-1000].exist == true){
            totalHeight += mem[j - 1000].height;
            totalWeight += mem[j - 1000].weight;
        }
    }
}

void bmi(){
    cout << "\nEnter Member ID whome BMI you want to know(1001 - " << i << ") : ";
    int x;
    cin >> x;
    float h=mem[x-1000].height*1.0/100.0;
    float bmi = mem[x-1000].weight*1.0/(h*h);
    if(bmi < 16){
        cout << "\nBMI is " << bmi << " and Member " << x << " shows Severe Thinness.\n\n";
    }
    else if(bmi >= 16 && bmi <= 17){
        cout << "\nBMI is " << bmi << " and Member " << x << " shows Moderate Thinness.\n\n";
    }
    else if(bmi > 17 && bmi <= 18.5){
        cout << "\nBMI is " << bmi << " and Member " << x << " shows Mild Thinness.\n\n";
    }
    else if(bmi > 18.5 && bmi <= 25){
        cout << "\nCongratulations!\n";
        cout << "BMI is " << bmi << " and Member " << x << " has Normal weight.\n\n";
    }
    else if(bmi > 25 && bmi <= 30){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Overweight.\n\n";
    }
    else if(bmi > 30 && bmi <= 35){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Obesity class I.\n\n";
    }
    else if(bmi > 35 && bmi <= 40){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Obesity Class II.\n\n";
    }
    else if(bmi > 40){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Obesity Class III.\n\n";
    }
}

int main(){
    top: 
    string pass = "sajid1495";
    cout << "Identify Yourself To Initiate The Programme!\nEnter Your Password : ";
    string password;
    cin >> password;
    if(password == pass){
        cout << "Verification Successfull.\nWelcome To Gym_Management.\n";
    }
    else{
        cerr << "Incorrect Passowrd! Access Denied!\n";
        getchar();
        cout << "Press Enter To Re-Enter Password.";
        getchar();
        goto top;

    }

    fstream myFile;
    myFile.open("Data.txt", ios::app);
    myFile.close();

    ifstream inputFile("Data.txt");
    if (inputFile.is_open()) {
        member tempMember;
        while (inputFile >> tempMember.id >> tempMember.height >> tempMember.weight >> tempMember.exist) {
            mem[i-1000] = tempMember;
            if(mem[i-1000].exist == false){
                delct++;
            }
            i++;
        }
        inputFile.close();
    }
    else{
        cout << "Failed to open the file." << endl;
        return 1;
    }
    maxmin();

    start:

    menu();
    int op;
    cin >> op;

    if(op == 1){
        fstream myFile;
        myFile.open("Data.txt", ios::app);
        add();
        if(myFile.is_open()){
            myFile << mem[i-1000].id << " " << mem[i-1000].height << " " << mem[i-1000].weight << " " << mem[i-1000].exist << endl;
            myFile.close();
            i++;
        }
        else{
            cout << "Error Adding Data to File" << endl;
        }
        cout << "\nSuccessfully Added!" << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 2){
        cout << "Enter Member ID whome Info you want to Update(1001 - " << i << ") : ";
        int a;
        cin >> a;
        update(a);

        string filename = "Data.txt";
        ifstream inputFile(filename);
        ofstream outputFile("temp.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            for(int j = 1001; j < i; j++){
                outputFile << j << " " << mem[j-1000].height << " " << mem[j-1000].weight << " " << mem[j-1000].exist << endl;
            }

            inputFile.close();
            outputFile.close();

            remove(filename.c_str());
            rename("temp.txt", filename.c_str());

            cout << "\nFile Modified Successfully." << endl;
        } 
        else {
            cout << "Failed to open the file." << endl;
        }

        cout << "\nSuccessfully Updated!" << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 3){
        cout << "Enter Member ID whom Info you want to Delet(1001 - " << i << ") : ";
        int x;
        cin >> x;
        mem[x-1000].exist = false;
        delct++;
        maxmin();

        string filename = "Data.txt";
        ifstream inputFile(filename);
        ofstream outputFile("temp.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            for(int j = 1001; j < i; j++){
                 outputFile << mem[j-1000].id << " " << mem[j-1000].height << " " << mem[j-1000].weight << " " << mem[j-1000].exist << endl;
            }

            inputFile.close();
            outputFile.close();

            remove(filename.c_str());
            rename("temp.txt", filename.c_str());

            cout << "\nFile Modified Successfully." << endl;
        } 
        else {
            cout << "Failed to open the file." << endl;
        }
        
        cout << "\nSuccessfully Removed!" << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 4){
        cout << "Enter Member ID whome  you want to Readd(1001 - " << i << ") : ";
        int x;
        cin >> x;
        if (mem[x - 1000].exist == false){
            mem[x - 1000].exist = true;
            cout << "Member " << x << " Readded Successfully!\n";

            string filename = "Data.txt";
            ifstream inputFile(filename);
            ofstream outputFile("temp.txt");

            if (inputFile.is_open() && outputFile.is_open()){
                for (int j = 1001; j < i; j++){
                    outputFile << mem[j - 1000].id << " " << mem[j - 1000].height << " " << mem[j - 1000].weight << " " << mem[j - 1000].exist << endl;
                }

                inputFile.close();
                outputFile.close();

                remove(filename.c_str());
                rename("temp.txt", filename.c_str());

                cout << "\nFile Modified Successfully." << endl;
            }
            else{
                 cout << "Failed to open the file." << endl;
            }

            cout << "Press C for Clear Screen.\n";
            cout << "Press any other Key for Main Menu.......";
            getchar();
            char c = getchar();
            if (c == 'c' || c == 'C'){
                system("cls");
                goto start;
            }
            else{
                cout << "\n\n";
                goto start;
            }
        }
        else{
            cout << "This member is Already Admitted in This Gym.\n";
        }
    }
    else if(op == 5){
        cout << "\n\nInformation Table\n";
        cout << "-----------------\n";
        cout << "\n ID   H  W \n";
        showInfoAll();
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 6){
        cout << "Enter ID of Member(1001 - " << i << ") : ";
        int x;
        cin >> x;
        cout << "\n\nInformation Table\n";
        cout << "-----------------\n";
        cout << "\n ID   H  W \n";
        showInfoAlone(x);
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 7){
        maxmin();
        cout << "\nMax Height & Max Weight : " << maxHeight << " & " << maxWeight << endl << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 8){
        maxmin();
        cout << "\nMin Height & Min Weight : " << minHeight << " & " << minWeight << endl << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 9){
        int presentMem = i - delct;
        avg();
        float avgH,avgW;
        avgH = (totalHeight*1.0)/presentMem;
        avgW = (totalWeight*1.0)/presentMem;
        cout << "\nAverage Height & Average Weight : " << avgH << " & " << avgW << endl << endl;
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 10){
        bmi();
        cout << "Press C for Clear Screen.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == 'c' || c == 'C'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 0){
        cout << "\nThank You!" << endl;
        getchar();
        return 0;   
    }
    else{
        system("cls");
        menu();
    }
}
