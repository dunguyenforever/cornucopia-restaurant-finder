#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

/*
From lists of preferences, stable marriages can always be created (See references for proof). The Gale-Shapley algorithm to locate a stable matching is as follows:
The goal is to cycle through every available free man as long as there are any accessible free men. Every free man visits every woman on his preference list in the order that they are listed. 
He asks each lady he approaches if she is available, and if she is, they become engaged. If the woman is not free, 
she has the option of rejecting him or breaking off her engagement with the man, depending on her preference list. 
Hence, if a woman has a better option, a previously established engagement may be broken. The Gale-Shapley algorithm has an time complexity O(n^2).


Input & Output: Input is a 2D matrix of size (2*N)*N where N is number of women or men. 
Rows from 0 to N-1 represent preference lists of men and rows from N to 2*N – 1 represent preference lists of women. 
So men are numbered from 0 to N-1 and women are numbered from N to 2*N – 1. The output is list of married pairs. 

Following is the implementation of the above algorithm.  

*/


#define N 5

string namelist[2*N];
int Matchlist[2*N][N];
//Function returns true if woman w prefers m1 over m
bool preflist(int prefs[2*N][N], int w, int m, int m1)
{
    int i = 0;
    //loop over the preference list for w's preference
    for(i; i < N; i++)
    {
        //if woman w prefers w1 (i.e w1 comes first in the list)
        // then we don't need to touch anything
        if(prefs[w][i] == m1)
            return true;
        //else if we see m before m1 then we change the status to false
        //changing her free status
        if(prefs[w][i] == m)
            return false;
    }
    return true;

}

void stableMatching(int prefs[2*N][N])
{
    // Stores partner of women, main array for storing preference priority
    // The value of wDates[i] indicates the partner assigned to woman N+i. 
    // The value -1 indicates that (N+i)'th woman is free
    int wDates[N];
    

    // An array to store availability of men.
    // If mFree[i] is false, then man 'i' is free, otherwise free to date.
    bool mDateFree[N];

    memset(wDates, -1, sizeof(wDates));
    memset(mDateFree, false, sizeof(mDateFree));

    //Track the number of free male dates
    int isAvailable = N;


    // While there are free men
    while (isAvailable > 0)
    {
        // Pick the first free man
        int m;
        for (m = 0; m < N; m++)
            if (mDateFree[m] == false)
                break;
 
        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for (int i = 0; i < N && mDateFree[m] == false; i++)
        {
            int w = prefs[m][i];
 
            // The woman of preference is free, w and m become
            // partners(Can be changed). So we can say they are taken
            if (wDates[w-N] == -1)
            {
                wDates[w-N] = m;
                mDateFree[m] = true;
                isAvailable--;
            }
 
            else  // If w is not free
            {
                // Find current engagement of w
                int m1 = wDates[w-N];
 
                // If w prefers m over her current engagement m1,
                // then break the date between w and m1 and match m with w.
                if (preflist(prefs, w, m, m1) == false)
                {
                    wDates[w-N] = m;
                    mDateFree[m] = true;
                    mDateFree[m1] = false;
                }
            }
        } // Finish assigning all w to m
    } 

    // Print the solution
    cout << "Best matching:\n-----------------------------------------------------------\n";
    cout << "Woman  <->  Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << namelist[i+N] << "\t" << namelist[wDates[i]] << endl;


}

//Initialize the matching
void initializeMatch()
{
    for(int i = 0; i < 2*N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Matchlist[i][j] = -1;
        }
    }

}

//Function to show the entire preference list used to generate stable matching
void showPreftable(int prefs[2*N][N])
{

    int i, j = 0;
    //Iterating through the list
    cout << "Date name\t\t\t\t" << "1st choice\t\t\t\t" << "2nd choice\t\t\t\t"<< "3rd choice\t\t\t\t"<< "4th choice\t\t\t\t" << "5th choice\n";
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for(i; i < 2*N; i++)
    {
        //Matching the name of the dates with its index
        cout << namelist[i] << "\t\t\t\t";
        for(j = 0; j < N; j++)
        {
            cout << namelist[prefs[i][j]] << "\t\t\t\t";
        }
        cout << "\n";
    }


}

//As the name implies
int matchNametoIndex(string name)
{
    int i = 0;
    for(i; i < 2*N; i++)
    {
        int temp = namelist[i].compare(name);
        if(temp == 0)
            return i;
    }
    return -1;
}

//Return the index of the inputed preference for checking duplicates
int getValueIndex(int Arr[N], int tofind)
{
    for(int i = 0; i < N; i++)
    {
        if(Arr[i] == tofind)
            return i;
    }
    return -1;

}

//Get all the names of the matching dates for better display
void getNames()
{
    int count = 0;
    cout << "Welcome to stable matching: We will help 10 lucky people find their dates!\n";
    cout << "Let's start with the first 5 male dates:\n";
    while( count < N)
    {
        cout << "Male Date " << count + 1 << " name:";
        cin >> namelist[count];
        cout << "\n";
        count++;
    }
    cout << "Now for our 5 female dates:\n";
    while( count < 2*N)
    {
        cout << "Female Date " << count + 1 << " name:";
        cin >> namelist[count];
        cout << "\n";
        count++;
    }

}

void generatePreflist()
{
    int date_num = 0;
    int count;
    int flag;
    string names;

    //Initialize the matching list
    initializeMatch();
    cout << "Time for you to tell us about everyone's preference!\n(Order will be from most liked to least liked!)\n";
    //Go through each date members and record their preferences
    for(date_num; date_num < 2*N; date_num++)
    {
        cout << "For " << namelist[date_num] << ":\t";
        count = 0;
        for(count; count < N; count ++)
        {
            cin >> names;
            while(matchNametoIndex(names) == -1)
            {
                cout << "Name is not on date list! Try again: ";
                cin >> names;
            }
            //Generate an error flag to mark certain invalid inputs
            flag = 1;
            while(flag != 0)
            {
                if(matchNametoIndex(names) == -1)
                {
                    cout << "Name is not on date list! Try again: ";
                    cin >> names;
                    flag = 1;
                }
                //No LGBTQ+ support yet matching same gender number with each other is not ready :)))
                else if((date_num < 5 && matchNametoIndex(names) < 5) || (date_num >= 5 && matchNametoIndex(names) >= 5))
                {
                    cout << "Cannot pair people of the same gender! Try again: ";
                    cin >> names;
                    flag = 1;
                }
                else if(getValueIndex(Matchlist[date_num], matchNametoIndex(names)) != -1)
                {
                    cout << namelist[matchNametoIndex(names)] << " is already in the preference list! Try again: ";
                    cin >> names;
                    flag = 1;
                }
                else
                    flag = 0;
            }
            Matchlist[date_num][count] = matchNametoIndex(names);
        }
    }
}



int main()
{
    int demoprefs[2*N][N] = { {7, 5, 9, 6, 8},
        {7, 5, 6, 9, 8},
        {5, 8, 6, 7, 9},
        {9, 5, 6, 7, 8},
        {5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4},
        {0, 1, 2, 3, 4},
        {0, 1, 2, 3, 4},
        {0, 1, 2, 3, 4},
        {0, 1, 2, 3, 4},
    };
    getNames();
    for(int i = 0; i < 2*N; i++)
    {
        cout << namelist[i] << " ";
    }
    cout << "\n";
    generatePreflist();
    //showPreftable(demoprefs);
    cout << "----------------------------------------------\n";
    //stableMatching(demoprefs);
    showPreftable(Matchlist);
    cout << "----------------------------------------------\n";
    stableMatching(Matchlist);

    return 0;
}