#ifndef SHARDGHX_H
#define SHARDGHX_H

typedef struct { float x, y; } ghx_vec2;

void ghx_open_window(int width, int height, const char* title);
void ghx_close_window();
int ghx_should_close();
void ghx_render_begin();
void ghx_render_end();
void ghx_clear(unsigned char r, unsigned char g, unsigned char b);
void ghx_set_fps(int fps);
void ghx_set_window_title(const char* title);
void ghx_draw_fps(int x, int y);
void ghx_draw_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_rect(int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_rect_outline(int x, int y, int w, int h, int thickness, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_circle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_circle_outline(int x, int y, int radius, int thickness, unsigned char r, unsigned char g, unsigned char b);
void ghx_draw_text(int x, int y, int size, const char* text, unsigned char r, unsigned char g, unsigned char b);
int ghx_key_down(int key);
int ghx_is_key_pressed(int key);
int ghx_mouse_down(int button);
int ghx_is_mouse_pressed(int button);
int ghx_mouse_x();
int ghx_mouse_y();
double ghx_sin(double x);
double ghx_cos(double x);
double ghx_tan(double x);
double ghx_sqrt(double x);
double ghx_pow(double base, double exp);
double ghx_log(double x);
double ghx_exp(double x);
double ghx_abs(double x);
float ghx_array_sum(float* arr, int len);
float ghx_array_mean(float* arr, int len);
float ghx_array_min(float* arr, int len);
float ghx_array_max(float* arr, int len);
void ghx_plot_line(float* arr, int len, int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b);
void ghx_plot_bar(float* arr, int len, int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b);
ghx_vec2 ghx_vec2_add(ghx_vec2 a, ghx_vec2 b);
ghx_vec2 ghx_vec2_sub(ghx_vec2 a, ghx_vec2 b);
ghx_vec2 ghx_vec2_scale(ghx_vec2 v, float s);
float ghx_vec2_length(ghx_vec2 v);
float ghx_vec2_dot(ghx_vec2 a, ghx_vec2 b);
ghx_vec2 ghx_vec2_normalize(ghx_vec2 v);
double ghx_get_time();
void ghx_sleep(int ms);
int ghx_random_int(int min, int max);
void* ghx_load_texture(const char* path);
void ghx_draw_texture(void* texture, int x, int y);
void ghx_draw_texture_part(void* texture, int sx, int sy, int sw, int sh, int dx, int dy);
void ghx_unload_texture(void* texture);
int ghx_rect_collide(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int ghx_button(int x, int y, int w, int h, const char* label);
int ghx_input_text(char* buffer, int maxlen, int x, int y, int w, int h);
void ghx_play_sound(const char* path);

typedef struct {
    float x, y;
    float zoom;
} ghx_camera2d;

void ghx_camera2d_init(ghx_camera2d* cam, float x, float y, float zoom);
void ghx_camera2d_begin(ghx_camera2d* cam);
void ghx_camera2d_end();
void ghx_camera2d_move(ghx_camera2d* cam, float dx, float dy);
void ghx_camera2d_set_zoom(ghx_camera2d* cam, float zoom);

#endif
