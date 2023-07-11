#include <bits/stdc++.h>

using namespace std;

int i = 1,delct = 1;
int maxHeight = -1,maxWeight = -1,minHeight = 1e3,minWeight = 1e3,totalHeight = 0,totalWeight = 0;

struct member{
public:
    int id;
    int height;
    int weight;
}mem[1000];

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
    for(int j = 1; j < i; j++){
        if(mem[j].id == 0){
            continue;
        }
        cout << mem[j].id << " " << mem[j].height << " " << mem[j].weight << endl;
    }
    cout << endl;
}

void showInfoAlone(int x){
    if(x == 0){
        cout << "Member Is Not Available\n";
    }
    else{
        cout << mem[x].id << " " << mem[x].height << " " << mem[x].weight << endl;
    }
    cout << endl;
}

void add(){
    int b,c; 
    cout << "Member ID : " << i << endl;
    cout << "Enter Member Height(cm) : ";
    cin >> b;
    cout << "Enter Member Weight(kg) : ";
    cin >> c;
    mem[i].id = i;
    mem[i].height = b;
    mem[i].weight = c;
    if(b > maxHeight){
        maxHeight = b;
    }
    if(c > maxWeight){
        maxWeight = c;
    }
    if(b < minHeight){
        minHeight = b;
    }
    if(c < minWeight){
        minWeight = c;
    }
    totalHeight += b;
    totalWeight += c; 
}

void update(){
    cout << "Enter Member ID whome Info you want to Update : ";
    int a;
    cin >> a;
    cout << "Which one you want to Update?\n";
    cout << "1.Height\n";
    cout << "2.Weight\n";
    cout << "Enter Your Choice : ";
    int q,b,c;
    cin >> q;
    if(q == 1){
        cout << "Enter Member Height(cm) : ";
        cin >> b;
        totalHeight -= mem[a].height;
        mem[a].height = b;
        totalHeight += b;
    }
    else if(q == 2){
        cout << "Enter Member Weight(kg) : ";
        cin >> c;
        totalHeight -= mem[a].weight;
        mem[a].weight = c;
        totalHeight += c;
    }

}

void bmi(){
    cout << "Enter Member ID whome BMI you want to know : ";
    int x;
    cin >> x;
    float h=mem[x].height*1.0/100.0;
    float bmi = mem[x].weight*1.0/(h*h);
    if(bmi < 16){
        cout << "\nBMI is " << bmi << "and Memeber " << x << " shows Severe Thinness.\n\n";
    }
    else if(bmi >= 16 && bmi <= 17){
        cout << "\nBMI is " << bmi << "and Memeber " << x << " shows Moderate Thinness.\n\n";
    }
    else if(bmi > 17 && bmi <= 18.5){
        cout << "\nBMI is " << bmi << "and Memeber " << x << " shows Mild Thinness.\n\n";
    }
    else if(bmi > 18.5 && bmi <= 25){
        cout << "\nCongratulations!\n";
        cout << "BMI is " << bmi << "and Member " << x << " has Normal weight.\n\n";
    }
    else if(bmi > 25 && bmi <= 30){
        cout << "\nBMI is " << bmi << ",Member " << x << " shows Overweight.\n\n";
    }
    else if(bmi > 30 && bmi <= 35){
        cout << "\nBMI is "<< bmi<<",Member " << x << " shows Obesity class I.\n\n";
    }
    else if(bmi > 35 && bmi <= 40){
        cout << "\nBMI is"<< bmi<<" ,Member " << x << " shows Obesity Class II.\n\n";
    }
    else if(bmi > 40){
        cout << "\nBMI is" << bmi << ",Member " << x << " shows Obesity Class III.\n\n";
    }
}

int main(){
    start:
    menu();
    int op;
    cin >> op;
    if(op == 1){
        add();
        i++;
        cout << "Successfully Added!" << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 2){
        update();
        cout << "Successfully Updated!" << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
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
        mem[x].id = 0;
        totalHeight -= mem[x].height;
        totalWeight -= mem[x].weight;
        delct++;
        cout << "Successfully Removed!" << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 4){
        cout << "\n\n   Information Table.\n\nID  H  W\n";
        showInfoAll();
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
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
        cout << "\n\n   Information Table.\n\nID  H  W\n";
        showInfoAlone(x);
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 6){
        cout << "\nMax Height & Max Weight : " << maxHeight << " & " << maxWeight << endl << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else if(op == 7){
        cout << "\nMin Height & Min Weight : " << minHeight << " & " << minWeight << endl << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
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
        float avgH,avgW;
        cout << totalHeight << " " << totalWeight << " " << presentMem << endl;
        avgH = (totalHeight*1.0)/presentMem;
        avgW = (totalWeight*1.0)/presentMem;
        cout << "\nAvarage Height & Avarage Weight : " << avgH << " & " << avgW << endl << endl;
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
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
        cout << "Press 0 for Clear Screan.\n";
        cout << "Press any other Key for Main Menu.......";
        getchar();
        char c = getchar();
        if(c == '0'){
            system("cls");
            goto start;
        }
        else{
            cout << "\n\n";
            goto start;
        }
    }
    else{
        cout << "\n\n";
        system("cls");
        goto start;
    }
    return 0;
}
