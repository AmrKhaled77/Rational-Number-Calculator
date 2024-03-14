#include <iostream>
#include <regex>
using namespace std;
// Function to convert improper fraction to mixed fraction
int MakeMixedFraction(int& numerator, int& denominator){
// Calculate the whole number part of the mixed fraction
    int wholeNumber=numerator/denominator;
    // Update the numerator to be the remainder after subtracting the whole number part
    numerator=numerator-(wholeNumber*denominator);
    return wholeNumber;


}

// Function to simplify a fraction
void Simplifay(int& numerator, int& denominator ){
    // get the  greatest common divisor
    if(denominator>numerator){
        for(int i=numerator;i>0;i--){
            if(numerator%i==0&&denominator%i==0){
                numerator=numerator/i;
                denominator=denominator/i;}}
    } else{
        for(int i=denominator;i>0;i--){
            if(numerator%i==0&&denominator%i==0){
                numerator=numerator/i;
                denominator=denominator/i;}}}}

// Function to perform arithmetic operation on fractions
void DoOP(int numerator1,int numerator2,int denominator1,int denominator2 ,string op){
    int newNumerator,newDenominator;
    if(op=="+"){
        newNumerator=(numerator1*denominator2)+(numerator2*denominator1);
        newDenominator=(denominator1*denominator2);
    }
    else if(op=="-"){
        newNumerator=(numerator1*denominator2)-(numerator2*denominator1);
        newDenominator=(denominator1*denominator2);
    }else if(op=="*"){
        newNumerator=(numerator1*numerator2);
        newDenominator=(denominator1*denominator2);
    }else if(op=="/"){
        newNumerator=(numerator1*denominator2);
        newDenominator=(denominator1*numerator2);
    }
    int wholeNumber;
    // Check for special cases and simplify the result
    if(newNumerator==0){
        cout<<"= 0"<<endl;
    } else if (newDenominator==newNumerator ){
        cout<<" = 1"<<endl;
    } else if (newDenominator==1){
        cout<<" = " <<newNumerator<<endl;
    }
    else{
        Simplifay(newNumerator,newDenominator);
        cout<<" = "<<newNumerator<<"/"<<newDenominator<<endl;
        // Convert the result to a mixed fraction if possible
        wholeNumber=MakeMixedFraction(newNumerator,newDenominator);
        wholeNumber&& newDenominator?cout<<" = "<<wholeNumber<<" "<<newNumerator<<"/"<<newDenominator<<endl
                   :cout<<" ";

    }}

// Function to test whether the user input matches the regex pattern and perform operations
bool test(string User_input){
    int numerator1,denominator1,numerator2,denominator2;
    string OP;
    smatch match;
    regex rgx("\\s*(-?\\d+)(?:\\s*\\/\\s*(-?\\d+))?\\s*([-+*/])\\s*(-?\\d+)(?:\\s*\\/\\s*(-?\\d+))?\\s*");
    if(regex_search(User_input, match, rgx)){
        // Extract numerator, denominator, and operator from the input
        numerator1= stoi(match[1]);
        denominator1= match[2].matched? stoi(match[2]):1;
        OP=match[3];
        numerator2= stoi(match[4]);
        denominator2= match[5].matched? stoi(match[5]) : 1;
        DoOP( numerator1, numerator2, denominator1, denominator2 , OP);
        return true;
    } else{
        return false;
    }

}


int main() {

    cout<<" Please enter a rational number operations (or 'z' to exit) :"<<endl;
    string  User_input;
    getline(cin, User_input);
    if (User_input=="z"){
        cout<<"app end";
    }
    else if(test(User_input)){
        while (true){
            cout<<" Please enter a rational number operations (or 'z' to exit) :"<<endl;
            string  User_input;
            getline(cin, User_input);
            test(User_input);
            if (User_input=="z"){
                cout<<"app end";
                break;
            }
        }
    }else{
        cout<<"Please enter a valid rational number operations (or 'z' to exit) :"<<endl;
        string  User_input;
        getline(cin, User_input);
        test(User_input);
    }
    return 0;}