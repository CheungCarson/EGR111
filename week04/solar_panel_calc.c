// SolarPanelCalculator
// This program determines what orientation of solar panels allows you to fit the most, how many solar panels fit on the given roof, and the final weight.
// Carson Cheung 02/02/23

#include <stdio.h>

int main()
{
    const int PANEL_WIDTH = 39;
    const int PANEL_HEIGHT_RES = 65;
    const int PANEL_HEIGHT_COM = 78;
    const double PANEL_WEIGHT_RES = 40;
    const double PANEL_WEIGHT_COM = 40;

    // Panel results
    int hor_cnt_panel_vert, hor_cnt_panel_hor, vert_cnt_panel_vert, vert_cnt_panel_hor, total_cnt_panel_vert, total_cnt_panel_hor, total_cnt;

    // weights
    double total_weight, weight_per_sq_ft;

    // Building dimensions
    double sidewall, endwall;

    printf("Enter length for the side wall in feet: ");
    scanf("%lf", &sidewall);
    printf("Enter length for the end wall in feet: ");
    scanf("%lf", &endwall);

    double roof_width = (endwall / 2) * 12;
    // Converting to inches
    sidewall = sidewall * 12;

    // Calcuating panels in the horizontal position
    hor_cnt_panel_hor = sidewall / PANEL_HEIGHT_RES;
    vert_cnt_panel_hor = roof_width / PANEL_WIDTH;
    total_cnt_panel_hor = (int)hor_cnt_panel_hor * vert_cnt_panel_hor;

    // Calculating panels in the vertical position
    hor_cnt_panel_vert = sidewall / PANEL_WIDTH;
    vert_cnt_panel_vert = roof_width / PANEL_HEIGHT_RES;
    total_cnt_panel_vert = (int)hor_cnt_panel_vert * vert_cnt_panel_vert;

    if (total_cnt_panel_hor > total_cnt_panel_vert)
    {
        total_cnt = total_cnt_panel_hor;
        printf("The best way is to use %d panels in the horizontal orientation\n", total_cnt);
    }
    else
    {
        total_cnt = total_cnt_panel_vert;
        printf("The best way is to use %d panels in the vertical orientation\n", total_cnt);
    }

    // Calculating weight
    total_weight = total_cnt * PANEL_WEIGHT_RES;
    total_weight = total_weight + (total_weight * 0.05);
    weight_per_sq_ft = (sidewall * roof_width) / total_weight;

    // Outputs
    printf("The total weight is %.1lf pounds\n", total_weight);
    printf("The load on your roof is %.1lf per square foot\n", weight_per_sq_ft);
}