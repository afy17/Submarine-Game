#include <iostream>
using namespace std;

// Declare functions, declared before main so can use in any function (global)
void FindBestTarget();
void SetSubmarinePosition();
void GetPriorityTarget();
bool CalculateIfClosestEnemy(int InEnemy); // InEnemy = parameter
string GetTurnDirection();

int enemy1;
int enemy2;
int enemy3;
int enemy4;
int priorityTarget;
int closestEnemy = 5000; 
string TargetedEnemy;

bool turnRight;

bool Enemy1IsAlive = true;  // checking to see if enemy unit is alive or dead
bool Enemy2IsAlive = true;
bool Enemy3IsAlive = true;
bool Enemy4IsAlive = true;

int main()
{

    constexpr int kEasy = 1;     // constants for each difficulty level, these values don't change
    constexpr int kMedium = 2;
    constexpr int kHard = 3;

    int enemyLocation;           
    int submarineCurrentLocation = 0;  // default location is 0
    int degrees;

    cout << " --------------- Welcome to the Submarine Game ---------------" << endl;
    cout << "Select a difficulty level: " << endl;
    cout << "  1) Easy" << endl;
    cout << "  2) Medium" << endl;
    cout << "  3) Hard" << endl;
    cout << "press 1, 2 or 3: " << endl;

    int input;
    cin >> input;

    switch (input)
    {
    case kEasy:
    {
        cout << "You have selected: Easy." << endl;
        cout << "Enter the enemy location between 0 - 360 degrees: ";  
        cin >> enemyLocation;  
        if (enemyLocation >= 0 && enemyLocation <= 180)  // 0-180 = RIGHT half of circle
        {
            turnRight = true;
            cout << "Enemy unit detected at " << enemyLocation << " degrees! Turn 'RIGHT' " << enemyLocation << " degrees!" << endl;
            cout << "Enemy unit defeated." << endl;
        }
        else if (enemyLocation >= 180 && enemyLocation <= 360)  // 180-360 = LEFT half of circle
        {
            turnRight = false;
            degrees = 360 - enemyLocation;  // this gives correct amount of degrees for turning left 
            cout << "Enemy unit detected at " << enemyLocation << " degrees! Turn 'LEFT' " << degrees << " degrees!" << endl;
            cout << "Enemy unit defeated." << endl;
        }
        else
            cout << "Invalid input. Please try again." << endl;
        break;
    }

    case kMedium:  // second difficulty level
    {
        cout << "You have selected: Medium." << endl;
        cout << "Enter the first enemy location between 0 - 360 degrees: ";  
        cin >> enemy1;
        cout << "Enter the second enemy location between 0 - 360 degrees: ";
        cin >> enemy2;
        cout << "Enter the third enemy location between 0 - 360 degrees: ";
        cin >> enemy3;
        cout << "Enter the last enemy location between 0 - 360 degrees: ";
        cin >> enemy4;

        FindBestTarget();  // call this function to find the closest enemy 
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Enemy unit defeated." << endl;
        SetSubmarinePosition(); // call this function to reset the submarine position to the new closest enemy location 
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Enemy unit defeated." << endl;
        SetSubmarinePosition();
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Enemy unit defeated." << endl;
        SetSubmarinePosition();
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "All enemy units defeated." << endl;
        SetSubmarinePosition();
        break;
    }
    case kHard:
    {
        cout << "You have selected: Hard." << endl;
        cout << "Enter the first enemy location between 0 - 360 degrees: ";
        cin >> enemy1;
        cout << "Enter the second enemy location between 0 - 360 degrees: ";
        cin >> enemy2;
        cout << "Enter the third enemy location between 0 - 360 degrees: ";
        cin >> enemy3;
        cout << "Enter the last enemy location between 0 - 360 degrees: ";
        cin >> enemy4;

        GetPriorityTarget();
        cout << "Priority enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Priority enemy unit defeated." << endl;
        SetSubmarinePosition();
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Enemy unit defeated." << endl;
        SetSubmarinePosition();
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "Enemy unit defeated." << endl;
        SetSubmarinePosition();
        FindBestTarget();
        cout << "Enemy unit detected at " << closestEnemy << " degrees! Turn " << GetTurnDirection() << closestEnemy << " degrees!" << endl;
        cout << "All enemy units defeated." << endl;
        SetSubmarinePosition();
        break;
    }
    }
}
    
//Define Functions
void FindBestTarget()  // void function does not return values.. this function checks to see if the closest enemy location is alive 
{
    if (Enemy1IsAlive)  // shorter way of writing if (Enemy1IsAlive == true)
    {
        if (CalculateIfClosestEnemy(enemy1))
            TargetedEnemy = "One";
    }

    if (Enemy2IsAlive)
    {
        if (CalculateIfClosestEnemy(enemy2))
        TargetedEnemy = "Two";
    }
        
    if (Enemy3IsAlive)
    {
        if (CalculateIfClosestEnemy(enemy3))
        TargetedEnemy = "Three";
    }

    if (Enemy4IsAlive)
    {
        if (CalculateIfClosestEnemy(enemy4))
        TargetedEnemy = "Four";
    }
}

bool CalculateIfClosestEnemy(int InEnemy)  // takes a parameter which is an integer, bool function returns true/false
{
    if (InEnemy >= 0 && InEnemy <= 180)  // if between 0-180, submarine turns right
    {
        if (InEnemy < closestEnemy)
        {
            closestEnemy = InEnemy;  // closest enemy on the right 
            turnRight = true;
            return true;
        }
    }
    else   // if between 180-360, submarine turns left
    {
        if (InEnemy < closestEnemy)
        {
            closestEnemy = 360 - InEnemy;  // closest enemy on the left  
            turnRight = false;
            return true;
        }
    }
    return false;
}

string GetTurnDirection()  // returns a string to get correct direction/rotation 
{
    if (turnRight == true)
        return "right ";
    else
        return "left ";
}

void SetSubmarinePosition()  
{
    if (TargetedEnemy == "One")
    {
        if (turnRight)
        {
            enemy2 -= closestEnemy;     // if submarine is turning right, all of the enemy locations are subtracted by the closestEnemy value as the whole compass is turning 
            enemy3 -= closestEnemy;
            enemy4 -= closestEnemy;
        }
        else
        {
            enemy2 += closestEnemy;    // if submarine is turning left, enemy location values increase by the closestEnemy value
            enemy3 += closestEnemy; 
            enemy4 += closestEnemy;
        }
        Enemy1IsAlive = false;
    }
    else if (TargetedEnemy == "Two")
    {
        if (turnRight)
        {
            enemy1 -= closestEnemy;
            enemy3 -= closestEnemy;
            enemy4 -= closestEnemy;
        }
        else
        {
            enemy1 += closestEnemy;
            enemy3 += closestEnemy;
            enemy4 += closestEnemy;
        }
        Enemy2IsAlive = false;
    }
    else if (TargetedEnemy == "Three")
    {
        if (turnRight)
        {
            enemy2 -= closestEnemy;
            enemy1 -= closestEnemy;
            enemy4 -= closestEnemy;
        }
        else
        {
            enemy2 += closestEnemy;
            enemy1 += closestEnemy;
            enemy4 += closestEnemy;
        }
        Enemy3IsAlive = false;
    }
    else if (TargetedEnemy == "Four")
    {
        if (turnRight)
        {
            enemy2 -= closestEnemy;
            enemy3 -= closestEnemy;
            enemy1 -= closestEnemy;
        }
        else
        {
            enemy2 += closestEnemy;
            enemy3 += closestEnemy;
            enemy1 += closestEnemy;
        }
        Enemy4IsAlive = false;
    }
    closestEnemy = 5000;  
}

void GetPriorityTarget()
{
    closestEnemy = enemy2;  // sets priority target to enemy2, enemy2 will always be defeated first
}

       


