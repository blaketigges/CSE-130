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
    sickHuman(); // constructor
};
class symptomChecker {
    public:
        void checkSymptoms(sickHuman);
        void printSymptoms();
        void printGuide();
        int numPatients;
    private:
        int covid = 0;
        int cold = 0;
        int flu = 0;
        int other = 0;

};
int main(){
    srand(time(NULL)); // seed random number generator
    symptomChecker checker; // create symptom checker object
    checker.printGuide(); // print guide
    cout << "Enter number of patients ";
    cin >> checker.numPatients; 
    cout << "Thank you..." << endl;
    for (int i = 0; i < checker.numPatients; i++){ // make patients and check symptoms
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
    cout << "=========================================================" << endl;
    cout << "Symptoms Checker..." << endl;
    cout << covid << " patients have symptoms of COVID-19" << endl;
    cout << cold << " patients have symptoms of Cold" << endl;
    cout << flu << " patients have symptoms of Flu" << endl;
    cout << other << " patients may have some other illness" << endl;
    cout << "=========================================================" << endl << endl;
    cout << "Percentage of each illness: " << endl;
    cout << "COVID-19: \t[" << ((covid * 1.0) / (numPatients* 1.0)) * 100 << "%]"; // print percentage of covid
    for ( int i = 0; i < ((covid * 1.0) / (numPatients* 1.0)) * 100; i++){  
        cout << "+";
    }
    cout << endl << "Cold: \t\t[" << ((cold * 1.0) / (numPatients* 1.0)) * 100 << "%]"; // print percentage of cold
    for ( int i = 0; i < ((cold * 1.0) / (numPatients* 1.0)) * 100; i++){
        cout << "+";
    }
    cout << endl << "Flu: \t\t[" << ((flu * 1.0) / (numPatients* 1.0)) * 100 << "%]"; // print percentage of flu
    for ( int i = 0; i < ((flu * 1.0) / (numPatients* 1.0)) * 100; i++){
        cout << "+";
    }
    cout << endl << "Other: \t\t[" << ((other * 1.0) / (numPatients* 1.0)) * 100 << "%]"; // print percentage of other
    for ( int i = 0; i < ((other * 1.0) / (numPatients* 1.0)) * 100; i++){
        cout << "+";
    }
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
    cout << "Guide: \t* Common \t+ Sometimes/Rarely \t- NO" << endl;
    cout << "=========================================================" << endl;
    cout << "Symptoms\t|\tCOVID-19  |   Cold   |   Flu    |" << endl;
    cout << "=========================================================" << endl;
    cout << "Fever\t\t|\t* \t  |    +     |   *      |" << endl;
    cout << "Cough\t\t|\t* \t  |    +     |   *      |" << endl;
    cout << "Shortness of Breath|\t* \t  |    -     |   -      |" << endl;
    cout << "Runny Nose\t|\t+ \t  |    *     |   +      |" << endl;
    cout << "Headaches\t|\t+ \t  |    +     |   *      |" << endl;
    cout << "Sneezing\t|\t- \t  |    *     |   -      |" << endl;    
    cout << "Fatigue\t\t|\t+ \t  |    +     |   *      |" << endl;
    cout << "=========================================================" << endl << endl;
}