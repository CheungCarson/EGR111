// Carson Cheung
// This program asks the suer for an RGB color using hexadecimal format and provide the user with alternative color formats in RGB arithmetic, RGB percentages, RGB 8-bit,
//(C,M,Y,K), and color name when appropiate.
//  2/18/23

#include <stdio.h>

void get_color_code(char *rgb_delimiter, int *r, int *g, int *b)
{
    printf("Enter the RGB color code to convert: (#000000)\nColor Code: ");
    scanf("%c%02x%02x%02x", &*rgb_delimiter, &*r, &*g, &*b);
    // Input validation
    while (*rgb_delimiter != '#')
    {
        printf("Invalid\n");
        printf("Enter the RGB color code to convert: (#000000)\nColor Code: ");
        scanf("%c%02x%02x%02x", &*rgb_delimiter, &*r, &*g, &*b);
    }
}

void get_arithmetic_values(double *r_arithmetic, double *g_arithmetic, double *b_arithmetic, int *r, int *g, int *b)
{
    *r_arithmetic = (double)*r / 255;
    *g_arithmetic = (double)*g / 255;
    *b_arithmetic = (double)*b / 255;
}

void get_percentages(int *r_percentage, int *g_percentage, int *b_percentage, double *r_arithmetic, double *g_arithmetic, double *b_arithmetic)
{
    *r_percentage = *r_arithmetic * 100;
    *g_percentage = *g_arithmetic * 100;
    *b_percentage = *b_arithmetic * 100;
}

void get_CMYK(double *r_arithmetic, double *g_arithmetic, double *b_arithmetic, double *black, double *cyan, double *magenta, double *yellow)
{
    double lowest_black[3];
    lowest_black[0] = 1 - *r_arithmetic;
    lowest_black[1] = 1 - *g_arithmetic;
    lowest_black[2] = 1 - *b_arithmetic;
    double min = lowest_black[0];

    for (int i = 0; i < 3; i++)
    {
        if (lowest_black[i] < min)
        {
            min = lowest_black[i];
        }
    }
    // Im sure there's a better way to make the output not a decimal but I couldn't think of it.
    *black = min;
    *cyan = ((1 - *r_arithmetic - *black) / (1 - *black)) * 100;
    *magenta = ((1 - *g_arithmetic - *black) / (1 - *black)) * 100;
    *yellow = ((1 - *b_arithmetic - *black) / (1 - *black)) * 100;
    *black *= 100;
}

void outputs(int *rgb_value, double *r_arithmetic, double *g_arithmetic, double *b_arithmetic, double *black, double *cyan, double *magenta, double *yellow, int *r_percentage, int *g_percentage, int *b_percentage, int *r, int *g, int *b)
{
    printf("RGB Value: %d\n", *rgb_value);
    printf("RGB Arithmetic: (%.1lf, %.1lf, %.1lf)\n", *r_arithmetic, *g_arithmetic, *b_arithmetic);
    printf("RGB Percentage: (%d%%, %d%%, %d%%)\n", *r_percentage, *g_percentage, *b_percentage);
    printf("RGB 8-Bit: (%d, %d, %d)\n", *r, *g, *b);
    printf("(C,M,Y,K): (%.0lf, %.0lf, %.0lf, %.0lf)\n", *cyan, *magenta, *yellow, *black);

    switch (*rgb_value)
    {
    case 0:
        printf("Color Name: Black");
        break;
    case 16777215:
        printf("Color Name: White");
        break;
    case 16711680:
        printf("Color Name: Red");
        break;
    case 65280:
        printf("Color Name: Green");
        break;
    case 255:
        printf("Color Name: Blue");
        break;
    case 65535:
        printf("Color Name: Cyan");
        break;
    case 16776960:
        printf("Color Name: Yellow");
        break;
    case 16711935:
        printf("Color Name: Magenta");
        break;
    default:
        printf("N/A");
        break;
    }
}

int main(void)
{
    char rgb_delimiter;
    int r, g, b;
    double r_arithmetic, g_arithmetic, b_arithmetic;
    int r_percentage, g_percentage, b_percentage;
    double cyan, magenta, yellow, black;

    get_color_code(&rgb_delimiter, &r, &g, &b);
    int rgb_value = (r * 65536) + (g * 256) + b;
    get_arithmetic_values(&r_arithmetic, &g_arithmetic, &b_arithmetic, &r, &g, &b);
    get_percentages(&r_percentage, &g_percentage, &b_percentage, &r_arithmetic, &g_arithmetic, &b_arithmetic);
    get_CMYK(&r_arithmetic, &g_arithmetic, &b_arithmetic, &black, &cyan, &magenta, &yellow);
    outputs(&rgb_value, &r_arithmetic, &g_arithmetic, &b_arithmetic, &black, &cyan, &magenta, &yellow, &r_percentage, &g_percentage, &b_percentage, &r, &g, &b);

    return 0;
}
