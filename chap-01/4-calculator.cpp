#include <iostream>
#include <string>
#include <vector>

void display_result(int result)
{
    std::cout << "Result is " << result << std::endl;
}

bool parse_params(char& op, std::vector<int>& values, int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }

    std::string op_str = argv[1];

    if (op_str != "+" && op_str != "*" && op_str != "-")
    {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return false;
    }

    op = op_str[0];

    for (auto arg_i = 2; arg_i < argc; ++arg_i)
    {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value);
    }

    if (op == '-' && values.empty())
    {
        std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
        return false;
    }
    return true;
}

int sum(const std::vector<int>& values)
{
    int result = 0;
    for (auto value : values)
    {
        result += value;
    }
    return result;
}

int multiply(const std::vector<int>& values)
{
    int result = 1;
    for (auto value : values)
    {
        result *= value;
    }
    return result;
}

int sub(const std::vector<int>& values)
{
    int result = values[0];
    for (auto i = 1u; i < values.size(); i++)
    {
        result -= values[i];
    }
    return result;
}

int compute_result(char op, const std::vector<int>& values)
{
    switch (op)
    {
    case '-':
        return sub(values);
    case '+':
        return sum(values);
    case '*':
        return multiply(values);
    default:
        return 0;
    }
}

int main(int argc, char** argv)
{
    // Parsing program parameters.
    std::vector<int> values;
    char             op = '?';

    if (!parse_params(op, values, argc, argv))
    {
        return -1;
    }

    // Process operation, depending on the operator.
    auto result = compute_result(op, values);

    // Output result.
    display_result(result);

    return 0;
}
