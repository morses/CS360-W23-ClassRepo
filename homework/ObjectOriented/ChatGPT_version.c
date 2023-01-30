#include <stdio.h>
#include <stdlib.h>     // ChatGPT forgot to include this header file
#include <string.h>

int main() {
    FILE *fp, *svg;
    char line[100];
    double latitude, longitude;

    fp = fopen("gps_track.txt", "r");
    svg = fopen("gpsdata.svg", "w");

    // Write the SVG file header
    fprintf(svg, "<svg xmlns='http://www.w3.org/2000/svg'>\n");

    while (fgets(line, 100, fp) != NULL) {
        if (strstr(line, "GPRMC") != NULL) {
            char *token = strtok(line, ",");
            int i = 0;
            while (token != NULL) {
                if (i == 3) {
                    latitude = atof(token);
                } else if (i == 4) {
                    if (strcmp(token, "N") == 0) {
                        latitude = latitude;
                    } else {
                        latitude = -latitude;
                    }
                } else if (i == 5) {
                    longitude = atof(token);
                } else if (i == 6) {
                    if (strcmp(token, "E") == 0) {
                        longitude = longitude;
                    } else {
                        longitude = -longitude;
                    }
                }
                token = strtok(NULL, ",");
                i++;
            }
            // Write the point to the SVG file
            fprintf(svg, "<circle cx='%lf' cy='%lf' r='3' fill='red' />\n", longitude, latitude);
        }
    }

    // Write the SVG file footer
    fprintf(svg, "</svg>\n");

    fclose(fp);
    fclose(svg);

    return 0;
}
