/*
Final Project - Symptom Checker
4/16/2022
Section 1A
Blake Tigges 
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std; 

class human {
    bool hasSymptoms = false;
};
class sickHuman : public human {
    public: 
    bool hasSymptoms = true;
    int fever;
    int cough;
    int shortness;
    int runnyNose;
    int headache;
    int sneezing;
    int fatigue;
    sickHuman();
};
class symptomChecker {
    public:
        void checkSymptoms(sickHuman);
        void printSymptoms();
        void printGuide();
    private:
        int covid;
        int cold;
        int flu;
        int other;

};
int main(){
    symptomChecker checker;
    checker.printGuide();
    cout << "Enter number of patients" << endl;
    int numPatients;
    cin >> numPatients;
    cout << "Thank you" << endl;
    for (int i = 0; i < numPatients; i++){
        sickHuman patient;
        checker.checkSymptoms(patient);
    }   
    checker.printSymptoms();


}
sickHuman::sickHuman(){ // randomly initialize symptoms
    fever = rand() % 2;
    cough = rand() % 2;
    shortness = rand() % 2;
    runnyNose = rand() % 2;
    headache = rand() % 2;
    sneezing = rand() % 2;
    fatigue = rand() % 2;
}
void symptomChecker::printSymptoms(){
    cout << "Covid: " << covid << endl;
    cout << "Cold: " << cold << endl;
    cout << "Flu: " << flu << endl;
    cout << "Other: " << other << endl;
}
void symptomChecker::checkSymptoms(sickHuman patient){
    if (patient.fever == 1 && patient.cough == 1 && patient.shortness == 1 ){
        covid++;
    } else if (patient.runnyNose == 1 && patient.sneezing == 1){
        cold++;
    } else if (patient.fever == 1 && patient.cough == 1 && patient.headache == 1 && patient.fatigue == 1){
        flu++;
    } else {
        other++;
    }
}
void symptomChecker::printGuide(){
    cout << "Welcome to Symptom Checker" << endl << endl;
    cout << "Guide: \t* Common \t+ Sometimes/Rarely \t- No" << endl;
    cout << "=========================================================" << endl;
    cout << "Symptoms\t|\tCOVID-19  |   Cold   |   Flu   |" << endl;
    cout << "=========================================================" << endl;
    cout << "Fever\t\t|\t* \t  |    +     |   -      |" << endl;
    cout << "Cough\t\t|\t* \t  |    +     |   -      |" << endl;
    cout << "Shortness of Breath|\t* \t  |    +     |   -      |" << endl;
    cout << "Runny Nose\t|\t* \t  |    +     |   -      |" << endl;
    cout << "Headaches\t|\t* \t  |    +     |   -      |" << endl;
    cout << "Sneezing\t|\t* \t  |    +     |   -      |" << endl;    
    cout << "Fatigue\t\t|\t* \t  |    +     |   -      |" << endl;
    cout << "=========================================================" << endl;
}