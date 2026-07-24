#include <windows.h>
#include <stdio.h>

//最大生成スレッド数
#define MAX_THREAD 4

// スレッドの停止フラグ(0=実行, 1=停止）
static volatile LONG stopFlg = 0;

//////////////////////////////
/// 各スレッドの負荷用関数
//////////////////////////////
DWORD WINAPI worker(LPVOID arg) 
{
    // 最適化無効(volatile)で変数宣言
    volatile unsigned long x = 1;
    // 停止フラグが有効になるまでループ
    while (!stopFlg) {
        // 線形合同法による疑似乱数生成
        x = x * 1664525ULL + 1013904223ULL;
    }
    return 0;
}

//////////////////////////////
/// メイン関数
//////////////////////////////
int main(void) 
{    
    // 生成スレッド数
    int n;
    
    // 生成スレッド数の入力
    printf("How many threads? (1-%d): ", MAX_THREAD);
    scanf("%d", &n);
    // 不正な入力の場合は異常終了
    if( n < 1 || MAX_THREAD < n) return 1;

    // スレッドのハンドル格納用配列
    HANDLE threadArray[MAX_THREAD];
    // 生成スレッド数分だけ繰り返し
    for (int i = 0; i < n; i++) {
        // worker関数を実行するスレッドを生成し，そのハンドルを配列格納
        threadArray[i] = CreateThread(NULL, 0, worker, NULL, 0, NULL);
    }

    // 入力バッファをクリア(scanfの改行文字が残っているため)
    while (getchar() != '\n');
    // Enter待ち
    printf("Running... Press ENTER to stop.");
    getchar();

    // 停止フラグを有効化
    stopFlg = 1;
    // 各スレッドが停止するまで待機
    WaitForMultipleObjects(n, threadArray, TRUE, INFINITE);
    // 生成スレッド数分だけ繰り返し
    for (int i = 0; i < n; i++) 
    {
        // 各スレッドのハンドルを解放
        CloseHandle(threadArray[i]);
    }

    return 0;
}