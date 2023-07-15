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
};
vector <member> mem(10000);

void menu(){
    cout << "   <-----Menu----->" << endl;
    cout << "1.Add Member\n";
    cout << "2.Update Member Info\n";
    cout << "3.Remove Member\n";
    cout << "4.All Member's Info\n";
    cout << "5.One Member's info\n";
    cout << "6.Max Height & Weight\n";
    cout << "7.Min Height and Weight\n";
    cout << "8.Average Height and Weight\n";
    cout << "9.BMI Classification\n";
    cout << "10.Exit\n";
    cout << "Enter Your option(1 - 10) : ";
}

void showInfoAll(){
    for(int j = 1001; j < i; j++){
        if(mem[j-1000].id == 0){
            continue;
        }
        cout << mem[j-1000].id << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
    }
    cout << endl;
}

void showInfoAlone(int x){
    if(mem[x].id == 0){
        cout << "\nMember Is Not Available\n";
    }
    else{
        cout << mem[x-1000].id << " " << mem[x-1000].height << " " << mem[x-1000].weight << endl;
    }
    cout << endl;
}

void maxmin(){
    maxHeight = -1,maxWeight = -1,minHeight = 1e3,minWeight = 1e3;
    for(int j = 1; j < i-1000; j++){ 
        if(mem[j].id != 0 && mem[j].height > maxHeight){
            maxHeight = mem[j].height;
        }
        if(mem[j].id != 0 && mem[j].weight > maxWeight){
            maxWeight = mem[j].weight;
        }
        if(mem[j].id != 0 && mem[j].height < minHeight){
            minHeight = mem[j].height;
        }
        if(mem[j].id != 0 && mem[j].weight < minWeight){
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
        if(mem[j-1000].id != 0){
            totalHeight += mem[j-1000].height;
            totalWeight += mem[j-1000].weight;
        }
    }
}

void bmi(){
    cout << "\nEnter Member ID whome BMI you want to know : ";
    int x;
    cin >> x;
    float h=mem[x-1000].height*1.0/100.0;
    float bmi = mem[x-1000].weight*1.0/(h*h);
    if(bmi < 16){
        cout << "\nBMI is " << bmi << " and Memeber " << x << " shows Severe Thinness.\n\n";
    }
    else if(bmi >= 16 && bmi <= 17){
        cout << "\nBMI is " << bmi << " and Memeber " << x << " shows Moderate Thinness.\n\n";
    }
    else if(bmi > 17 && bmi <= 18.5){
        cout << "\nBMI is " << bmi << " and Memeber " << x << " shows Mild Thinness.\n\n";
    }
    else if(bmi > 18.5 && bmi <= 25){
        cout << "\nCongratulations!\n";
        cout << "BMI is " << bmi << " and Member " << x << " has Normal weight.\n\n";
    }
    else if(bmi > 25 && bmi <= 30){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Overweight.\n\n";
    }
    else if(bmi > 30 && bmi <= 35){
        cout << "\nBMI is "<< bmi<<",Member " << x << " shows Obesity class I.\n\n";
    }
    else if(bmi > 35 && bmi <= 40){
        cout << "\nBMI is "<< bmi<<" ,Member " << x << " shows Obesity Class II.\n\n";
    }
    else if(bmi > 40){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Obesity Class III.\n\n";
    }
}

int main(){
    
    fstream myFile;
    myFile.open("Data.txt", ios::app);
    myFile.close();

    ifstream inputFile("Data.txt");
    if (inputFile.is_open()) {
        member tempMember;
        while (inputFile >> tempMember.id >> tempMember.height >> tempMember.weight) {
            mem[i-1000] = tempMember;
            if(mem[i-1000].id == 0){
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
            myFile << mem[i-1000].id << " " << mem[i-1000].height << " " << mem[i-1000].weight << endl;
            myFile.close();
            i++;
        }
        else{
            cout << "Error Adding Data to File" << endl;
        }
        cout << "\nSuccessfully Added!" << endl;
        cout << "Press C for Clear Screan.\n";
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
        cout << "Enter Member ID whome Info you want to Update : ";
        int a;
        cin >> a;
        update(a);

        string filename = "Data.txt";
        ifstream inputFile(filename);
        ofstream outputFile("temp.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            for(int j = 1001; j < i; j++){
                if(mem[j-1000].id == 0){
                    outputFile << "0000" << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
                    continue;
                }
                outputFile << j << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
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
        cout << "Press C for Clear Screan.\n";
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
        cout << "Enter Member ID whome Info you want to Delet : ";
        int x;
        cin >> x;
        mem[x-1000].id = 0;
        delct++;
        maxmin();

        string filename = "Data.txt";
        ifstream inputFile(filename);
        ofstream outputFile("temp.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            for(int j = 1001; j < i; j++){
                if(j == x || mem[j-1000].id == 0){
                    outputFile << "0000" << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
                }
                else{
                    outputFile << mem[j-1000].id << " " << mem[j-1000].height << " " << mem[j-1000].weight << endl;
                }
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
        cout << "Press C for Clear Screan.\n";
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
        cout << "\n\n   Information Table.\n\n ID   H  W\n";
        showInfoAll();
        cout << "Press C for Clear Screan.\n";
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
    else if(op == 5){
        cout << "Inter ID of Member : ";
        int x;
        cin >> x;
        cout << "\n\n   Information Table.\n\n ID   H  W\n";
        showInfoAlone(x);
        cout << "Press C for Clear Screan.\n";
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
        maxmin();
        cout << "\nMax Height & Max Weight : " << maxHeight << " & " << maxWeight << endl << endl;
        cout << "Press C for Clear Screan.\n";
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
        cout << "\nMin Height & Min Weight : " << minHeight << " & " << minWeight << endl << endl;
        cout << "Press C for Clear Screan.\n";
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
        int presentMem = i - delct;
        avg();
        float avgH,avgW;
        avgH = (totalHeight*1.0)/presentMem;
        avgW = (totalWeight*1.0)/presentMem;
        cout << "\nAvarage Height & Avarage Weight : " << avgH << " & " << avgW << endl << endl;
        cout << "Press C for Clear Screan.\n";
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
        bmi();
        cout << "Press C for Clear Screan.\n";
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
        cout << "\nThank You!" << endl;
        getchar();
        return 0;   
    }
    else{
        system("cls");
        menu();
    }
}