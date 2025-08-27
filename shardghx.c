#include "shardghx.h"
#include <raylib.h>
#include <math.h>

void ghx_open_window(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);
}

void ghx_close_window() {
    CloseWindow();
}

int ghx_should_close() {
    return WindowShouldClose();
}

void ghx_render_begin() {
    BeginDrawing();
}

void ghx_render_end() {
    EndDrawing();
}

void ghx_clear(unsigned char r, unsigned char g, unsigned char b) {
    ClearBackground((Color){r, g, b, 255});
}

void ghx_draw_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    DrawPixel(x, y, (Color){r, g, b, 255});
}

void ghx_draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
    DrawLine(x1, y1, x2, y2, (Color){r, g, b, 255});
}

void ghx_draw_rect(int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    DrawRectangle(x, y, w, h, (Color){r, g, b, 255});
}

void ghx_draw_text(int x, int y, int size, const char* text, unsigned char r, unsigned char g, unsigned char b) {
    DrawText(text, x, y, size, (Color){r, g, b, 255});
}

float ghx_array_sum(float* arr, int len) {
    float s = 0;
    for (int i = 0; i < len; i++) s += arr[i];
    return s;
}

float ghx_array_mean(float* arr, int len) {
    if (len == 0) return 0;
    return ghx_array_sum(arr, len) / len;
}

float ghx_array_min(float* arr, int len) {
    if (len == 0) return 0;
    float m = arr[0];
    for (int i = 1; i < len; i++) if (arr[i] < m) m = arr[i];
    return m;
}

float ghx_array_max(float* arr, int len) {
    if (len == 0) return 0;
    float m = arr[0];
    for (int i = 1; i < len; i++) if (arr[i] > m) m = arr[i];
    return m;
}

void ghx_plot_line(float* arr, int len, int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    if (len < 2) return;
    float min = ghx_array_min(arr, len);
    float max = ghx_array_max(arr, len);
    if (max == min) max += 1;
    float dx = (float)w / (len - 1);
    for (int i = 0; i < len - 1; i++) {
        float v1 = (arr[i] - min) / (max - min);
        float v2 = (arr[i + 1] - min) / (max - min);
        int x1 = x + i * dx;
        int x2 = x + (i + 1) * dx;
        int y1 = y + h - (v1 * h);
        int y2 = y + h - (v2 * h);
        ghx_draw_line(x1, y1, x2, y2, r, g, b);
    }
}

void ghx_plot_bar(float* arr, int len, int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    if (len == 0) return;
    float max = ghx_array_max(arr, len);
    if (max == 0) max = 1;
    float barW = (float)w / len;
    for (int i = 0; i < len; i++) {
        float norm = arr[i] / max;
        int barH = norm * h;
        ghx_draw_rect(x + i * barW, y + h - barH, barW - 1, barH, r, g, b);
    }
}
