//
//  Student Grade Calculator-Cpp Script
//
//  Created by Zacky Jamel on 2022/05/1
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void getData(char[], char[], char[], char, char[], short, short, short, short, int);
void calculteData(char[], char[], char[], char, char[], short, short, short, short, int);
void printTitle();  // this is the title of app when U first Open
int appCore();  // this func is about transfering data bcz all function are returing void


int main(int argc, char const *argv[])
{

    printTitle();
    appCore();
    return 0;
}

void printTitle()
{

    std::cout << "---------------------------------------------" << std::endl;
      std::cout << "  SOFTWARE ENGINEERING GRADE CALCULCULATOR" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
         std::cout << "\nInstructions:\n1. Calculate New Student Grade" << std::endl;
      std::cout << "2. Need Help\n";
    std::cout << "3. Exit The App\n";
    }

int appCore()
{
  // i try using array insteed of repeating short/char like this BUT using togather arrays of Inputs and loops are useless
  // arrays is good for non input variables
    char firstName[10];
    char lastName[20];
    char grandFatherName[10];
    char sex;
    char iD[30];
    short midExamMark;
    short assignmentMark;
    short labAssignmentMark;
    short finalExamMark;

    int varifyData;
    cin>>varifyData;
        // listening user Option
    if(varifyData == 1)

    {
          // Taking Student Detail from the User

    std::cout<< " ENTER STUDENT NAME: ";
      std::cin>> firstName;
        std::cout<< " STUDENT FATHER NAME: ";
          std::cin>> lastName;
           std::cout<< " STUDENT GRAND FATHER NAME: ";
        std::cin>> grandFatherName;
      correctSex:  // user error based return from line 79
      std::cout<< " STUDENT SEX (M/F):  ";
    std::cin>> sex;



      //Gender validation Logic
      if (sex == 'm' || sex == 'f' || sex == 'M' || sex == 'F') goto continueApp;  // from line 88
      else { cout<< " Please Enter Valid "; goto correctSex; }
      // from line 85
      continueApp:
        std::cout<< " STUDENT ID:  "; std::cout<< " ugr/jj/";
          std::cin>>iD;


              //adding Year in the last digit of the ID eg. /14 which is current year
              //i'm doing this bcz may be user type he's id with-Out typeing Year


              //first checking length of the id
              // i don't know why c++ not defined normal .length Liberery eg. iD.length()
              //insteed of converting char[] to string

              // Converting regular char-string to normal string
            string userID = iD;
            char targetChar = '/';
            int yearTyped;

            // this means if the length of the ID is 10; last2 = 10 -1; last3 = 10 - 3
            short last = userID.length();
            short last2 = userID.length() - 1;
            short last3 = userID.length() - 3;  //going back in two step left
            //typedChar = backWard_Last_Three_Digit
            char typedChar = userID[last3];
            //detecting if last three digits is contain / to know there is /14 in the Id or not
                   if(typedChar == targetChar)
                      yearTyped = 1;    // 1 means true year found
                   else
                     yearTyped = 0;     // 0 means false  not found


           std::cout<< " MID EXAM (30%):  ";
        midExamLabel:
      std::cin>> midExamMark;

      if(midExamMark >= 31) {

             /*
             assuming midExam is taking outOf 30
        why i'm doing this is that if the user enter value less then expected value (midExam)
        Then grade calculateData function will be useless

        */

            cout<<"Please Enter Valid Mark: ";
            goto midExamLabel;
        }

    std::cout<< " ASSIGNMENT MARK (10%):  ";
    std::cin>> assignmentMark;

                // asuming assingment is outOf 10,
                //if the user Enter number 10 its valid value so that i compired 11

      if(assignmentMark >= 11) {
            cout<<"Please Enter Valid Mark: ";
            goto midExamLabel;
        }
        
    std::cout<< " LAB ASSIGNMENT MARK (10%): ";
    std::cin>> labAssignmentMark;

      if(labAssignmentMark >= 11) {

            cout<<"Please Enter Valid Mark: ";
            goto midExamLabel;
        }
    std::cout<< " FINAL EXAM (50%):  ";
    std::cin>> finalExamMark;

      if(finalExamMark >= 51) {

            cout<<"Please Enter Valid Mark: ";
            goto midExamLabel;
        }

                    // passing all parameters i need about user
    getData(firstName, lastName, grandFatherName, sex, iD, midExamMark, assignmentMark, labAssignmentMark, finalExamMark, yearTyped);

    }

    else if(varifyData == 2) {

      cout<<"This Program Designed easy way that every user can USE! No Need Documentation:)\n";
      int anyKey;
      cout<<"type any key to exit";
      cin>>anyKey;

     }

    else
        cout<<"Exited! Good Bye:(";
}

//getting data from the user
void getData(char firstName[20], char lastName[20], char grandFatherName[20], char sex, char iD[20], short midExamMark, short assignmentMark, short labAssignmentMark, short finalExamMark, int yearTyped )
{

    //showing warring if the user type same input in three times

    if(firstName == lastName)
        cout<<"warning.. your name must d|f from your father-name";

    calculteData(firstName, lastName, grandFatherName, sex, iD, midExamMark, assignmentMark, labAssignmentMark, finalExamMark, yearTyped);
}

void calculteData(char firstName[20], char lastName[20], char grandFatherName[20], char sex, char iD[20], short midExamMark, short assignmentMark, short labAssignmentMark, short finalExamMark, int yearTyped )
{

    int skyp;
    char exitingCharecter = 'E';
    bool exited = false;
    short midExam = midExamMark;
    short finalExam = finalExamMark;
    short other = labAssignmentMark + assignmentMark;
    long totalMark = midExam + finalExam + other;
    char Grade;
    char I;
    int userYearTyped = yearTyped;



        //Sorry i did this style to reduse the space of the code

     if(totalMark <= 35)       { Grade = 'F'; I = 'N'; }
     else if(totalMark <= 39)  { Grade = 'F'; I = 'X'; }
     else if(totalMark <= 45)  { Grade = 'D'; I = 'N'; }
     else if(totalMark <= 50)  { Grade = 'C'; I = '-'; }
     else if(totalMark <= 60)  { Grade = 'C'; I = 'N'; }
     else if(totalMark <= 65)  { Grade = 'C'; I = '+'; }
     else if(totalMark <= 70)  { Grade = 'B'; I = '-'; }
     else if(totalMark <= 75)  { Grade = 'B'; I = 'N'; }
     else if(totalMark <= 80)  { Grade = 'B'; I = '+'; }
     else if(totalMark <= 85)  { Grade = 'A'; I = '-'; }
     else if(totalMark <= 90)  { Grade = 'A'; I = 'N'; }
     else if(totalMark <= 100) { Grade = 'A'; I = '+'; }

          //Printing Result

    cout<<"\n\n\n\n";
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "  GRADE RESULT COMPLETED." << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "  Name: " <<firstName<<" "<<lastName<<endl;
    std::cout << "  Sex: " <<sex<<endl;
      if(userYearTyped == 1) { std::cout << "  ID: "<<"CEP/JJ/"<<iD<<endl; }
      else { std::cout << "  ID: "<<"CEP/JJ/"<<iD<<"/14"<<endl; }
    std::cout << "  Total (100%): " <<totalMark<<"%"<<endl;
    std::cout << "  Grade: " <<Grade<<endl<<"\n\n";
    std::cout<< "Type E to exit: ";
    cin>>skyp;


          if(skyp == exitingCharecter)
                exited = true;
          else
              exited = false;



}


