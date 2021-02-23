// JKLM.fun Bomb Party Cheat by Pierre: pierre.tassan@telecom-st-etienne.fr
// For educational purposes only
// Some portion of code are credited to their original creators

#include <iostream>
#include <stdio.h>
#include <string>
#include<fstream>
#include<vector>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>
#include <windowsx.h>
#include <algorithm>

#pragma comment(lib, "Urlmon.lib")

using namespace std;

int majuscule;

bool legit = false;
int min1 = 100, max1 = 420;

void ClearWord() {
    //Initialize keyboard
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;




    //3 quick delete to remove what's left in the chat
    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);

    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);

    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = VK_BACK;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void WriteWord() {
    //Initialize keyboard
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ClearWord(); //Remove what's left in the chat
    Sleep(10);



    //Past the content with ctrl + V
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(10);
    
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));


    Sleep(20); //Quick sleep


    //Press enter to validate
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(500); //0.5 sec pause to avoid double click
}

void WriteLetter() {
    //Initialize keyboard
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;




    //Past the content with ctrl + V
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = 'V';
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(10);

    ip.ki.wVk = 'V';
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));


    Sleep(10); //Quick sleep
}

void PressEnter() {
    //Initialize keyboard
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;



    //Press enter to validate
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(10);
    ip.ki.wVk = VK_RETURN;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(500); //0.5 sec pause to avoid double click

}

//Source: https://stackoverflow.com/questions/56547966/pasting-after-setclipboarddata-in-c-does-not-include-newlines-for-notepad
void toClipboard(const std::string& s) {
    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}

//Source: https://codes-sources.commentcamarche.net/source/39796-keylogger-mail-envoie-les-touches-frappees-au-clavier-par-mail
int ismajpressed() {
    int result;

    result = GetKeyState(VK_SHIFT);
    if ((result == -127) || (result == -128)) return 1;
    else return 0;
}
//Source: https://codes-sources.commentcamarche.net/source/39796-keylogger-mail-envoie-les-touches-frappees-au-clavier-par-mail
int ismaj() {

    if (((majuscule) && (!ismajpressed())) || ((!majuscule) && (ismajpressed())))
        return 1;
    else return 0;
}
//Source (partial): https://codes-sources.commentcamarche.net/source/39796-keylogger-mail-envoie-les-touches-frappees-au-clavier-par-mail
char GetLetter(int lettre) {

    wchar_t window_title[256];
    string name = "JKLM";
    size_t found = string::npos;

    while (found == string::npos) {
        HWND foreground = GetForegroundWindow();
        if (foreground)
        {
            GetWindowText(foreground, window_title, 256);
        }

        wstring ws(window_title);
        string str(ws.begin(), ws.end());
        
        found = str.find(name);
    }

    char towrite = '1';

    if ((lettre < 106) && (lettre > 95)) towrite = lettre - 48;

    else if ((lettre < 91) && (lettre > 64) && (!ismaj())) towrite = lettre + 32;

    else if ((lettre < 91) && (lettre > 64)) towrite = lettre;

    else if (lettre == VK_RETURN || lettre == VK_ESCAPE) {
        towrite = '0'; // 0 = we wrote all the letters
    }

    else if (lettre == VK_DELETE) {
        towrite = '2'; // 2 = We erase what entered
        cout << "Efface!" << endl;
       }

    //cout << towrite;
    return towrite;
}

string getWord() {
    string word = "";
    srand(time(NULL));
    while (1) {
        int lettre, result, lastresult, lastletter = '1';
        char add_letter;
        lettre = 13;
        for (lettre == 13; lettre < 256; lettre++) {
            result = GetKeyState(lettre);
            if ((result != 0) && (result != 1) && (lettre != lastletter))
            {
                add_letter = GetLetter(lettre);
                if (add_letter == '0') {
                    if (word.size() > 1) {
                        cout << "Mot a trouver: " << word << endl;
                        return word;
                    }
                }
                else {
                    if (add_letter == '2') word = "";
                    else if (add_letter != '1') {
                        word.append(1, add_letter);
                        if (word.size() == 3) {
                            cout << "Mot a trouver: " << word << endl;
                            return word;
                        }
                    }
                }
                

                result = GetKeyState(lettre);
                lastresult = result;
                lastletter = lettre;
                lettre = 13;
                Sleep(60);
            }
        }
        Sleep(50);
    }
}




int main()
{
    locale::global(locale{ "" });

    cout << "JKLM.fun Bomb Party cheat by @TheDoctor Pierre -> pierre.tassan@telecom-st-etienne.fr" << endl;
    cout << "For educational purposes only!" << endl;
    cout << "Use only against friends" << endl;
    cout << endl;
    cout << "Just type de letters you have to use and enter after!" << endl;
    cout << "Change dico.txt with your language dictionnary: 1 word per line, no accents!" << endl;
    cout << endl << "Write all letter instantly or one by one? (y/n) ";
    char answer;
    cin >> answer;
    if (answer != 'y') {
        legit = true;
        cout << "Entrez un temps d'ecriture minimum (100ms conseille): ";
        cin >> min1;
        cout << "Entrez un temps d'ecriture maximum (400ms conseille): ";
        cin >> max1;

    }

    errno_t erreur;
    FILE* dictionnaire;
    erreur = fopen_s(&dictionnaire, "dico.txt", "r, ccs=UTF-8");
    if (erreur != 0) {
        cout << "Impossible de trouver le fichier dico.txt!" << endl;
        return 0;
    }

    //Programme
    int nb_of_line = 0;
    string line;

    ifstream file("dico.txt");
    while (std::getline(file, line)) {
        nb_of_line++;
    }
    file.close();
        

    //On créé le tableau
    bool* already_used = new bool[nb_of_line];
    for (unsigned int i = 0; i < nb_of_line; i++) {
        already_used[i] = false;
    }


    vector<string> dico(nb_of_line);

    int count = 0;
    file.open("dico.txt");
    while (std::getline(file, line)) {
        dico.at(count) = line;
        count++;
    }
    cout << endl << "Ready to answer!" << endl << endl;
    while (1) {
        string searching_for;
        searching_for = getWord();
        bool answer_found = false;
        for (unsigned int i = 0; i < dico.size() && answer_found == false; i++) {
            size_t string_found = dico.at(i).find(searching_for);
            if (string_found != string::npos && already_used[i] == false) {
                already_used[i] = true;

                size_t found_indesirable_space = dico.at(i).find(" ");
                size_t found_indesirable_dash = dico.at(i).find("-");
                if (!(found_indesirable_space != string::npos || found_indesirable_dash != string::npos)) {
                    cout << "Suggestion: " << dico.at(i) << endl;
                    toClipboard(dico.at(i));
                    if (legit) {
                        ClearWord();
                        string answer_legit = dico.at(i);
                        for (unsigned int i = 0; i < answer_legit.size(); i++) {
                            toClipboard(string(1, answer_legit.at(i)));
                            WriteLetter();
                            int range = max1 - min1 + 1;
                            int num = rand() % range + min1;
                            Sleep(num);
                        }
                        PressEnter();
                    }
                    else {
                        WriteWord();
                    }
                    

                    answer_found = true;
                }
            }
        }
        if (answer_found == false) {
            cout << "Mot impossible a trouver..." << endl;
            ClearWord();
        }
        else {
            Sleep(1000);
        }
    }
    return 0;
}