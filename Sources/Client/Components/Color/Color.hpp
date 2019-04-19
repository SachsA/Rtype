//
// Created by thomas on 20/12/18.
//

#ifndef COLOR_HPP
#define COLOR_HPP

class Color {
public:
    Color() = default;
    Color(unsigned int const &red, unsigned int const &green, unsigned int const &blue, unsigned int const &alpha);
    ~Color() = default;

    void setRed(unsigned int const &red);
    void setGreen(unsigned int const &green);
    void setBlue(unsigned int const &blue);
    void setAlpha(unsigned int const &alpha);

    unsigned int const &getRed() const;
    unsigned int const &getGreen() const;
    unsigned int const &getBlue() const;
    unsigned int const &getAlpha() const;

private:
    unsigned int _red;
    unsigned int _green;
    unsigned int _blue;
    unsigned int _alpha;
};

#endif //COLOR_HPP
