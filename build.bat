@echo off
gcc test.c shardghx.c -o shardghx_test.exe -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm