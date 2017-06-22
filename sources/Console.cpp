#include "Console.h"
#include "windows.h"

void showInfoOnConsole()
{
    system("cls");
    fprintf(stdout, "\t\tCurrent Setup\n");
    fprintf(stdout, "Projection: %s\n", (toggleProjection>0)?"Perspective":"Orthographic");
    fprintf(stdout, "Axes: %s\n", (toggleAxes>0)?"On":"Off");
    fprintf(stdout, "\n");
    fprintf(stdout, "\t\tCamera Setup\n");
    fprintf(stdout, "Aspect Ratio: %i\n", aspectRatio);
    fprintf(stdout, "Dimension of the Orthographic box: %i\n", dim );
    fprintf(stdout, "Field of View: %d\n", fov);
    fprintf(stdout, "(theta, phi) : (%d, %d)\n", theta, phi );
}
