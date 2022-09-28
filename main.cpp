#include <iostream>
#include <string>
#include <string_view>
#include <limits>    // for std::streamsize
#include <algorithm> // for reverse() function

// function prototypes
void menu();
int control_user_input(int);
int ascii_value(char);
char revalue_number(int);
int to_decimal(std::string_view, int);
std::string from_decimal(int, int);
std::string convert_bases(std::string_view, int, int);

int main()
{
    bool running{true};
    short int user_menu_opt{};
    std::string input_number_string{};

    while (running)
    {
        menu();
        std::cout << "Type the number you wish to do: ";
        user_menu_opt = control_user_input(user_menu_opt);

        switch (user_menu_opt)
        {
        case 1: // decimal to binary
        {
            std::cout << "Type the number in base 10: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 10, 2)
                      << std::endl
                      << std::endl;

            break;
        }

        case 2: // binary to decimal
        {
            std::cout << "Type the number in base 2: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 2, 10)
                      << std::endl
                      << std::endl;

            break;
        }

        case 3: // decimal to hexadecimal
        {
            std::cout << "Type the number in base 10: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 10, 16)
                      << std::endl
                      << std::endl;

            break;
        }

        case 4: // hexadecimal to decimal
        {
            std::cout << "Type the number in base 16: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 16, 10)
                      << std::endl
                      << std::endl;

            break;
        }

        case 5: // binary to hexadecimal
        {
            std::cout << "Type the number in base 2: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 2, 10)
                      << std::endl
                      << std::endl;

            break;
        }

        case 6: // hexadecimal to binary
        {
            std::cout << "Type the number in base 16: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, 16, 2)
                      << std::endl
                      << std::endl;

            break;
        }

        case 7: // free base to base conversion
        {
            int original_base{}, desired_base{};
            std::cout << "Type the number in base 16: ";
            std::cin.ignore();
            std::getline(std::cin, input_number_string);

            std::cout << "RESULT: "
                      << convert_bases(input_number_string, original_base, desired_base)
                      << std::endl
                      << std::endl;

            break;
        }

        case 8:
            std::cout << "Closing program." << std::endl;
            running = false;

            break;
        }
    }
}

/**
 * @brief
 * Shows the available options for the program.
 */
void menu()
{
    std::cout << "Main menu"
              << "\n1. Decimal to binary"
              << "\n2. Binary to decimal"
              << "\n3. Decimal to Hexadecimal"
              << "\n4. Hexadecimal to decimal"
              << "\n5. Binary to hexadecimal"
              << "\n6. Hexadecimal to binary"
              << "\n7. Base to base conversion"
              << "\n8. Exit program"
              << std::endl;
}

int control_user_input(int input_number)
{
    while (!(std::cin >> input_number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');

        std::cout << "Invalid Entry. Try again." << std::endl;
    }

    return input_number;
}

/**
 * @brief
 * Converts the given character to ASCII value.
 * @param character        Desired conversion character
 * @return uint
 */
int ascii_value(char character)
{
    if (character >= '0' && character <= '9')
        return static_cast<int>(character - '0');

    return static_cast<int>(character - 'A' + 10);
}

/**
 * @brief
 * Returns equivalent character of a given value.
 * @param number      Number to be converted
 * @return char
 */
char revalue_number(int number)
{
    if (number >= 0 && number <= 9)
        return static_cast<char>(number + '0');

    return static_cast<char>(number - 10 + 'A');
}

/**
 * @brief
 * Converts a number from a given base to a number in base 10
 * (decimal system).
 * @param read_string       Input number
 * @param base              Given base
 * @return int
 */
int to_decimal(std::string_view read_string, int base)
{
    std::string data_string(read_string.data(),
                            read_string.size());
    int power{1}, result{};

    for (int i{static_cast<int>(data_string.size() - 1)};
         i >= 0; i--)
    {
        if (ascii_value(data_string[i]) >= base)
            return -1;

        result += ascii_value(data_string[i]) * power;
        power *= base;
    }

    return result;
}

/**
 * @brief
 * Converts a given decimal number (base 10) to any base
 * @param base
 * @param input_number
 * @return std::string
 */
std::string from_decimal(int base, int input_number)
{
    std::string result{""};

    while (input_number > 0)
    {
        result += revalue_number(input_number % base);
        input_number /= base;
    }

    // reversing the result
    std::reverse(result.begin(), result.end());

    return result;
}

std::string convert_bases(std::string_view read_string,
                          int original_base, int desired_base)
{
    std::string data_string(read_string.data(),
                            read_string.size());

    int decimal_number =
        to_decimal(data_string, original_base);

    std::string result =
        from_decimal(desired_base, decimal_number);

    return result;
}
