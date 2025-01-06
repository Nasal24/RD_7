#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));

    int rounds_number, wins_counter = 0, losses_counter = 0, draws_counter = 0;

    cout << "Welcome to \"Rock paper scissors\"" << endl;
    while (true) {
        while (true) {
            cout << "Enter number of rounds(-1 or less to quit): ";
            cin >> rounds_number;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered a letter or something else, but not a number, try again" << endl;
            }
            else if (rounds_number == 0 || rounds_number <= -1) { cout << "Your number is 0 or less than -1, try again" << endl; }
            else { break; }//проверки ввода^
        }
        if (rounds_number == -1) { cout << "Thank you for playing" << endl; break; } //выход из основного цикла

        //цикл раундов
        for (int i = 0; i < rounds_number; i++) {
            int user_choice, machine_choice;

            while (true) {
                cout << "\tEnter your choice (1 - rock, 2 - paper, 3 - scissors): ";
                cin >> user_choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "You entered a letter or something else, but not a number, try again" << endl;
                }
                else if (user_choice <= 0 || user_choice > 3) { cout << "Your number is less than 1 or more than 3, try again" << endl; }
                else { break; }//проверки ввода^
            }
            if (user_choice == 1) { cout << "Your choice is 1(rock)" << endl; }
            else if (user_choice == 2) { cout << "Your choice is 2(paper)" << endl; }
            else { cout << "Your choice is 3(scissors)" << endl; }

            machine_choice = rand() % 3 + 1;

            if (machine_choice == 1) { cout << "Machine choise is 1(rock)" << endl; }
            else if (machine_choice == 2) { cout << "Machine choice is 2(paper)" << endl; }
            else { cout << "Machine choice is 3(scissors)" << endl; }

 
            if (user_choice == machine_choice) {
                cout << "Its a DRAW" << endl;
                draws_counter += 1;
            }
            else if ((user_choice == 1 && machine_choice == 3) ||
                (user_choice == 2 && machine_choice == 1) ||
                (user_choice == 3 && machine_choice == 2)) {
                cout << "You WIN!!!!" << endl;
                wins_counter += 1;
            }
            else {
                cout << "You LOSE" << endl;
                losses_counter += 1;
            }
        }

        cout << "Stats for this game are: " << endl;
        cout << "\tROUNDS: " << rounds_number << endl;
        cout << "\tWINS: " << wins_counter << endl;
        cout << "\tDRAWS: " << draws_counter << endl;
        cout << "\tLOSSES: " << losses_counter << endl;
        if (wins_counter > losses_counter) { cout << "You WON!!!!" << endl; }
        else if (losses_counter > wins_counter) { cout << "You LOST....." << endl; }
        else { cout << "Its a DRAW" << endl; }
        wins_counter = 0, draws_counter = 0, losses_counter = 0;
    }

}

//дублирование проверок можно было бы убрать через функции но мы их еще не проходили 
//через функции можно было бы еще добавить уровни сложности к примеру: 
//рандомайзер в котором в 5 случаях из 20 машина не предугадывает ход игрока а играет с ним на равных 
// if rand == 1,2,3,4,5 - normal_mode()
//else - hard_mode()