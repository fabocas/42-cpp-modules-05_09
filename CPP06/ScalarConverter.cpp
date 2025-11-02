

#include "ScalarConverter.hpp"

static bool hasNoFraction(double v, double eps = 1e-12)
{
    return std::isfinite(v) && std::fabs(v - static_cast<int>(v)) < eps;
}

void ScalarConverter::convert(const std::string &literal)
{
    long int_;
    double double_;
    float float_;
    char char_;
    char *endptr = NULL;
    errno = 0;
    double value = std::strtod(literal.c_str(), &endptr);   

    if (endptr == literal.c_str())
    {
        if (!(literal.size() == 1 && !isdigit(static_cast<unsigned char>(literal[0]))))
        {
            std::cout << "char : non displayable" << std::endl;
            std::cout << "int : impossible" << std::endl;
            std::cout << "float : impossible" << std::endl;
            std::cout << "double : impossible" << std::endl;
            return;
        }
    }
    if (std::isnan(value))
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
        return ;
    }
    if (std::isinf(value))
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : " << (value < 0 ? "-inff" : "+inff") << std::endl;
        std::cout << "double : " << (value < 0 ? "-inf" : "+inf") << std::endl;
        return ;
    }
    if (literal.size() == 1 && !isdigit(static_cast<unsigned char>(literal[0])))
    {
        char_ = literal[0];
        int_ = static_cast<int>(char_);
        double_ = static_cast<double>(char_);
        float_ = static_cast<float>(char_);
        const bool tol_d = hasNoFraction(double_);
        std::cout << "char : '" << char_ << "'" << std::endl;
        std::cout << "int : " << int_ << std::endl;
        std::cout << "float : " << float_ << (tol_d ? ".0f" : "f")  << std::endl;
        std::cout << "double : " << double_ << (tol_d ? ".0" : "") << std::endl;
        return ;
    }
    if (fromString<long>(literal, int_))
    {
        const bool tol_d = hasNoFraction(int_);
        if (int_ >= 32 && int_ <= 126)
            std::cout << "char : '" << static_cast<char>(int_) << "'" << std::endl;
        else
            std::cout << "char : non displayable" << std::endl;
        if (int_ < std::numeric_limits<int>::min() || int_ > std::numeric_limits<int>::max())
            std::cout << "int : impossible";
        else
            std::cout << "int : " << static_cast<int>(int_) << std::endl;
        std::cout << "float : " << static_cast<float>(int_) << (tol_d ? ".0f" : "f") << std::endl;
        std::cout << "double : " << static_cast<double>(int_) << (tol_d ? ".0" : "") << std::endl;
        return ;
    }
    if (endptr != NULL && endptr != literal.c_str() && *endptr == 'f' && endptr[1] == '\0')
    {
        float_ = static_cast<float>(value);
        const bool tol_f = hasNoFraction(static_cast<double>(float_));
        if (float_ >= 32 && float_ <= 126)
            std::cout << "char : '" << static_cast<char>(float_) << "'" << std::endl;
        else
            std::cout << "char : non displayable" << std::endl;
        std::cout << "int : " << static_cast<int>(float_) << std::endl;
        std::cout << "float : " << float_ << (tol_f ? ".0f" : "f") << std::endl;
        std::cout << "double : " << static_cast<double>(float_) << (tol_f ? ".0" : "") << std::endl;
        return;
    }
    if (errno == ERANGE)
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return ;
    }
    if (fromString<double>(literal, double_))
    {
        const bool tol_d = hasNoFraction(double_);
        if (double_ >= 32 && double_ <= 126)
            std::cout << "char : '" << static_cast<char>(double_) << "'" << std::endl;
        else
            std::cout << "char : non displayable" << std::endl;
        if (double_ < std::numeric_limits<int>::min() || double_ > std::numeric_limits<int>::max())
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(double_) << std::endl;
        if (double_ < std::numeric_limits<float>::min() || double_ > std::numeric_limits<int>::max())
            std::cout << "float : impossible" << std::endl;
        else
            std::cout << "float : " << static_cast<float>(double_) << (tol_d ? ".0f" : "f") << std::endl;
        std::cout << "double : " << double_  << (tol_d ? ".0" : "") << std::endl;
        return ;
    }
    if (fromString<float>(literal, float_))
    {
        const bool tol_f = hasNoFraction(static_cast<double>(float_));
        if (float_ >= 32 && float_ <= 126)
            std::cout << "char : '" << static_cast<char>(float_) << "'" << std::endl;
        else
            std::cout << "char : non displayable" << std::endl;
        if (float_ < std::numeric_limits<int>::min() || float_ > std::numeric_limits<int>::max())
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(float_) << std::endl;
        std::cout << "float : " << float_ << (tol_f ? ".0f" : "f") << std::endl;
        std::cout << "double : " << static_cast<float>(float_) << (tol_f ? ".0" : "") << std::endl;
        return ;
    }
}