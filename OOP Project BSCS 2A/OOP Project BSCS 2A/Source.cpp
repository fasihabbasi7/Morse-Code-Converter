#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <sstream>


using namespace std;

class MorseCodeConverter
{
private:
    map<char, string> morseCodeMap;
    map<string, char> reverseMorseCodeMap;
    sf::SoundBuffer dotBuffer, dashBuffer, spaceBuffer, thanksBuffer;

public:
    MorseCodeConverter()
    {
        initializeMorseCodeMap();
        initializeReverseMorseCodeMap();
        initializeAudioBuffers();
    }

    void initializeMorseCodeMap()
    {
        // Initialize the map with Morse code representations
        morseCodeMap['A'] = ".-";
        morseCodeMap['B'] = "-...";
        morseCodeMap['C'] = "-.-.";
        morseCodeMap['D'] = "-..";
        morseCodeMap['E'] = ".";
        morseCodeMap['F'] = "..-.";
        morseCodeMap['G'] = "--.";
        morseCodeMap['H'] = "....";
        morseCodeMap['I'] = "..";
        morseCodeMap['J'] = ".---";
        morseCodeMap['K'] = "-.-";
        morseCodeMap['L'] = ".-..";
        morseCodeMap['M'] = "--";
        morseCodeMap['N'] = "-.";
        morseCodeMap['O'] = "---";
        morseCodeMap['P'] = ".--.";
        morseCodeMap['Q'] = "--.-";
        morseCodeMap['R'] = ".-.";
        morseCodeMap['S'] = "...";
        morseCodeMap['T'] = "-";
        morseCodeMap['U'] = "..-";
        morseCodeMap['V'] = "...-";
        morseCodeMap['W'] = ".--";
        morseCodeMap['X'] = "-..-";
        morseCodeMap['Y'] = "-.--";
        morseCodeMap['Z'] = "--..";
        morseCodeMap['0'] = "-----";
        morseCodeMap['1'] = ".----";
        morseCodeMap['2'] = "..---";
        morseCodeMap['3'] = "...--";
        morseCodeMap['4'] = "....-";
        morseCodeMap['5'] = ".....";
        morseCodeMap['6'] = "-....";
        morseCodeMap['7'] = "--...";
        morseCodeMap['8'] = "---..";
        morseCodeMap['9'] = "----.";
        morseCodeMap[' '] = "/";
    }


    string charToMorseCode(char c)
    {
        char upperC = toupper(c);
        auto it = morseCodeMap.find(upperC);
        if (it != morseCodeMap.end())
        {
            playMorseCodeSound(it->second); // Play the corresponding Morse code sound
            return it->second;
        }
        else {
            return "";
        }
    }

    void initializeReverseMorseCodeMap()
    {
        // Initialize the reverse map
        for (auto entry : morseCodeMap)
        {
            reverseMorseCodeMap[entry.second] = entry.first;
        }
    }

    void playMorseCodeSound(string morseCode)
    {
        for (char dotOrDash : morseCode)
        {
            switch (dotOrDash)
            {
            case '.':
                playDot();
                break;
            case '-':
                playDash();
                break;
            default:
                break;
            }
        }
    }


    void initializeAudioBuffers()
    {
        // Load audio files for dot, dash, and space
        dotBuffer.loadFromFile("C:/Users/hp/source/repos/OOP Project BSCS 2A/OOP Project BSCS 2A/awaz/dotsound.wav");
        dashBuffer.loadFromFile("C:/Users/hp/source/repos/OOP Project BSCS 2A/OOP Project BSCS 2A/awaz/dashsound.wav");
        thanksBuffer.loadFromFile("C:/Users/hp/source/repos/OOP Project BSCS 2A/OOP Project BSCS 2A/awaz/thankyou.wav");
    }

    void playDot() {
        sf::Sound sound(dotBuffer);
        sound.play();

        sf::sleep(sf::milliseconds(250)); //  sleep duration 
    }

    void playDash() {
        sf::Sound sound(dashBuffer);
        sound.play();
        sf::sleep(sf::milliseconds(500)); // sleep duration
    }

    void playThanks() {
        sf::Sound sound(thanksBuffer);
        sound.play();
        sf::sleep(sf::milliseconds(2000)); // sleep duration 
    }
    void playSpace() {
        sf::Sound sound(spaceBuffer);
        sound.play();
        sf::sleep(sf::milliseconds(300)); //  sleep duration
    }

    string textToMorseCode(string text)
    {
        string morseCode;
        for (char c : text) {
            morseCode += charToMorseCode(c) + " ";
        }
        return morseCode;
    }



    void playMorseCode(char c) {
        switch (c) {
        case '.':
            playDot();
            break;
        case '-':
            playDash();
            break;
        case ' ':
            playSpace();
            break;
        default:
            break;
        }
    }

    string morseCodeToText(string morseCode)
    {
        istringstream iss(morseCode);
        string word, result;

        while (iss >> word)
        {
            if (word == "/")
            {
                result += " ";
            }
            else {
                auto it = reverseMorseCodeMap.find(word);
                if (it != reverseMorseCodeMap.end()) {
                    result += it->second;
                }
                else {
                    result += "?"; // Handle unrecognized Morse code
                }
            }
        }

        return result;
    }

    void handleTextToMorse()
    {
        string inputText;
        //  char playSoundChoice;

        cout << "Enter text to convert to Morse code: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, inputText);

        string morseCode = textToMorseCode(inputText);
        cout << "Morse Code: " << morseCode << endl;

    }

    void handleMorseToText() {
        string morseCode;
        //char playSoundChoice1;
        cout << "Enter Morse code to convert to text: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, morseCode);

        string decodedText = morseCodeToText(morseCode);
        cout << "Decoded Text: " << decodedText << endl;


    }

    void handleTryAgain()
    {
        char choice;
        cout << "Do you want to try again? (Y/N): ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            handleTextToMorse(); // Restart the process
        }
        else
        {
            cout << "Exiting program. Goodbye!" << endl;
        }
    }
};
int main() {
    MorseCodeConverter morseConverter;
    char conversionChoice;
    cout << "\033[1;32m";
    cout << "************************************************************************************************************************" << endl;
    // Print the message
    cout << "                                              WELCOME TO MORSE CODE CONVERTER " << endl;
    cout << "************************************************************************************************************************" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }
    cout << "                                              Morse Code Definition:  " << endl;
    cout << endl;

    string s2;
    s2 = "Morse Code is a method used for encoding text characters through the use of sequences of "
        "dots and dashes. Developed by Samuel Morse and Alfred Vail in the early 1830s"
        "it served as a vital means of long-distance communication via telegraphy. "
        "In Morse Code, each letter or numeral is uniquely represented by a sequence of dots (.) and dashes (-), ";




    cout << s2;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "************************************************************************************************************************" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    // Reset text color to default
    cout << "\033[0m";


    do {
        cout << "Choose conversion type" << endl;
        cout << endl;
        cout << "1.Text to Morse" << endl;
        cout << endl;
        cout << "2.Morse to Text" << endl;
        cout << endl;
        cout << "Enter 1 to Convert Text to Morse or Enter 2 to Convert Text to Morse : ";
        cin >> conversionChoice;


        for (int i = 0; i < 2; i++)
        {
            cout << endl;
        }


        if (conversionChoice == '1') {
            morseConverter.handleTextToMorse();
        }
        else if (conversionChoice == '2') {
            morseConverter.handleMorseToText();
        }
        else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;

        }

        cout << "Do you want to Convert again? (Y/N): ";
        cin >> conversionChoice;

    } while (toupper(conversionChoice) == 'Y');

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }


    cout << "\033[1;32m";
    cout << "Thank you and Have a Good day. Good Bye!" << endl;
    cout << "\033[0m";

    morseConverter.playThanks();
    system("pause");
    return 0;


}