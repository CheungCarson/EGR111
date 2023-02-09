// Carson Cheung
// This program asks the suer for an RGB color using hexadecimal format and provide the user with alternative color formats in RGB arithmetic, RGB percentages, RGB 8-bit,
//(C,M,Y,K), and color name when appropiate.
//  2/9/23

#include <stdio.h>

int main(void)
{
    char color_code[7];
    int red, green, blue;
    double r_arithmetic, g_arithmetic, b_arithmetic;
    int r_percentage, g_percentage, b_percentage;
    double cyan, magenta, yellow, black;

    printf("Enter the RGB color code to convert: (#000000)\nColor Code: ");
    scanf("%s", color_code);
    // Input validation
    while (color_code[0] != '#')
    {
        printf("Invalid\n");
        printf("Enter the RGB color code to convert: (#000000)\nColor Code: ");
        scanf("%s", color_code);
    }
    sscanf(color_code, "#%2x%2x%2x", &red, &green, &blue);

    int rgb_value = (red * 65536) + (green * 256) + blue;
    printf("RGB Value: %d\n", rgb_value);

    r_arithmetic = (double)red / 255;
    g_arithmetic = (double)green / 255;
    b_arithmetic = (double)blue / 255;
    printf("RGB Arithmetic: (%.1lf, %.1lf, %.1lf)\n", r_arithmetic, g_arithmetic, b_arithmetic);

    r_percentage = r_arithmetic * 100;
    g_percentage = g_arithmetic * 100;
    b_percentage = b_arithmetic * 100;
    printf("RGB Percentage: (%d%%, %d%%, %d%%)\n", r_percentage, g_percentage, b_percentage);

    printf("RGB 8-Bit: (%d, %d, %d)\n", red, green, blue);

    // Finding min black value
    // I looked into the equation, because it was not giving me the right answer,-
    // and I found out that you are supposed to use the min value between the three black values of the indiviual colors.
    double lowest_black[3];
    lowest_black[0] = 1 - r_arithmetic;
    lowest_black[1] = 1 - g_arithmetic;
    lowest_black[2] = 1 - b_arithmetic;
    double min = lowest_black[0];

    for (int i = 0; i < 3; i++)
    {
        if (lowest_black[i] < min)
        {
            min = lowest_black[i];
        }
    }
    // Im sure there's a better way to make the output not a decimal but I couldn't think of it.
    black = min;
    cyan = ((1 - r_arithmetic - black) / (1 - black)) * 100;
    magenta = ((1 - g_arithmetic - black) / (1 - black)) * 100;
    yellow = ((1 - b_arithmetic - black) / (1 - black)) * 100;
    black *= 100;

    printf("(C,M,Y,K): (%.0lf, %.0lf, %.0lf, %.0lf)\n", cyan, magenta, yellow, black);

    switch (rgb_value)
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

    return 0;
}
