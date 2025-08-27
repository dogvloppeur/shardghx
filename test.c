#include "shardghx.h"

float data[] = {2, 4, 1, 5, 3, 6, 7, 4, 2, 1, 0.5, 3.5, 5.5, 6.5};

int main() {
    ghx_open_window(800, 600, "ShardGHX");

    while (!ghx_should_close()) {
        ghx_render_begin();
        ghx_clear(20, 20, 20);

        ghx_draw_text(20, 20, 20, "Data Analysis", 255, 255, 255);

        char txt[128];
        sprintf(txt, "Somme : %.2f", ghx_array_sum(data, 14));
        ghx_draw_text(20, 50, 18, txt, 255, 255, 100);

        sprintf(txt, "Moyenne : %.2f", ghx_array_mean(data, 14));
        ghx_draw_text(20, 80, 18, txt, 150, 255, 100);

        sprintf(txt, "Min : %.2f", ghx_array_min(data, 14));
        ghx_draw_text(20, 110, 18, txt, 255, 150, 150);

        sprintf(txt, "Max : %.2f", ghx_array_max(data, 14));
        ghx_draw_text(20, 140, 18, txt, 255, 150, 150);

        ghx_plot_line(data, 14, 50, 200, 700, 150, 100, 200, 255);
        ghx_plot_bar(data, 14, 50, 400, 700, 150, 255, 200, 100);

        ghx_render_end();
    }

    ghx_close_window();
    return 0;
}
