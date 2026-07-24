#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 最小のメモリ確保単位(1MB)
#define MB (1024 * 1024)
// 最大のメモリ確保容量
#define MAX_MEMORY 50000 //[MB]

//////////////////////////////
/// メイン関数
//////////////////////////////
int main(void) 
{
    // 確保したメモリ領域への汎用ポインタ(void*)を保持する配列
    void *ptMemArray[MAX_MEMORY];
    
    // 現在の総メモリ確保容量[MB]
    size_t total_count = 0;
    // メモリ確保容量[MB]
    size_t malloc_count;
    
    // 直ちに物理メモリに確保，memset関数の使用可否フラグ
    int memsetFlg = 0;     
    // memset関数の使用選択
    printf("Allocation mode (virtual memory(0) or physical memory(1)): ");
    scanf("%d", &memsetFlg);
    
    // メモリ確保処理の開始
    printf("Enter MB to allocate (0 to quit)\n");    
    // 最大確保容量を超える，もしくは0[MB]を指定されるまで繰り返し
    while (1) 
    {
        // 現在の確保済みメモリ量を表示
        printf("Current allocated: %zu MB\n", total_count);

        // メモリ確保容量を入力
        printf("Allocate (MB): ");
        scanf("%d", &malloc_count);
        // 0[MB]が指定された場合は終了
        if(malloc_count == 0) break;
        // 最大容量を超える場合も終了
        if(malloc_count + total_count > MAX_MEMORY)
        {
            printf("Maximum memory capacity (%d [MB]) exceeded.\n", MAX_MEMORY);
            break;
        }

        // メモリ確保
        printf("Allocating %zu MB...", malloc_count);
        // 指定の容量まで1MBずつ確保
        for (size_t i = 0; i < malloc_count; i++) 
        {
            // 1MBのメモリを確保して汎用ポインタに格納
            void *p = malloc(MB);
            
            // 物理メモリにも即時確保する場合
            if (memsetFlg) {
                // 指定の物理メモリを0で埋める
                memset(p, 0, MB);
            }

            // 確保したメモリ領域をポインタ配列に格納(後で解放するため)
            ptMemArray[total_count] = p;
            // 確保済みの総メモリ量を更新
            total_count++;
        }        
        // 確保結果を表示
        printf("Success!\n");
    }
    
    // 確保した全メモリの解放を開始
    printf("Freeing all memory (%zu MB)...\n", total_count);
    // ポインタ配列を走査
    for (size_t i = 0; i < total_count; i++)
    {
        // 確保されたメモリ領域を解放
        free(ptMemArray[i]);
    }
    
    return 0;
}